#include "transaction/transaction.hpp"

#include <gtest/gtest.h>
#include <libdevcore/CommonJS.h>

#include <thread>
#include <vector>

#include "common/static_init.hpp"
#include "logger/logger.hpp"
#include "transaction_manager/transaction_manager.hpp"
#include "transaction_manager/transaction_queue.hpp"
#include "util_test/samples.hpp"

namespace taraxa::core_tests {

const unsigned NUM_TRX = 40;
const unsigned NUM_BLK = 4;
const unsigned BLK_TRX_LEN = 4;
const unsigned BLK_TRX_OVERLAP = 1;
auto g_secret = Lazy([] {
  return dev::Secret("3800b2875669d9b2053c1aff9224ecfdc411423aac5b5a73d7a45ced1c3b9dcd",
                     dev::Secret::ConstructFromStringType::FromHex);
});
auto g_key_pair = Lazy([] { return dev::KeyPair(g_secret); });
auto g_trx_samples = Lazy([] { return samples::createMockTrxSamples(0, NUM_TRX); });
auto g_signed_trx_samples = Lazy([] { return samples::createSignedTrxSamples(0, NUM_TRX, g_secret); });
auto g_blk_samples = Lazy([] { return samples::createMockDagBlkSamples(0, NUM_BLK, 0, BLK_TRX_LEN, BLK_TRX_OVERLAP); });

struct TransactionTest : BaseTest {};

TEST_F(TransactionTest, status_table_lru) {
  using TestStatus = StatusTable<int, int>;
  TestStatus status_table(100);
  for (int i = 0; i < 100; i++) {
    status_table.insert(i, i * 10);
  }
  for (int i = 0; i < 50; ++i) {
    status_table.get(i);
  }
  for (int i = 101; i < 150; i++) {
    status_table.insert(i, i * 10);
  }
  for (int i = 50; i < 100; ++i) {
    auto [exist, val] = status_table.get(51);
    EXPECT_FALSE(exist);
  }
  EXPECT_LE(status_table.size(), 100);
}

TEST_F(TransactionTest, sig) {
  /* The test data was generated via web3.py v5.12.0 in the following way
   * in the order of appearance:
  import web3
  acc = web3.Account.from_key(
    "0xb6a431fe9f5a79da0c53702ca5dd619846e21ce5c3b7b77148aa8478240087cd")
  print(acc.privateKey.hex())
  print(acc.address)
  print(acc.sign_transaction(dict(chainId=0, nonce=0, gas=0,
    gasPrice=0)).rawTransaction.hex())
  for chain_id in [None, 1, 1 << 32]:
      print(acc.sign_transaction(dict(
          nonce=1,
          value=2,
          gasPrice=3,
          gas=4,
          data='0xabcd',
          to='0xd3CdA913deB6f67967B99D67aCDFa1712C293601',
          chainId=chain_id
      )).hash.hex())
   */
  secret_t sk("0xb6a431fe9f5a79da0c53702ca5dd619846e21ce5c3b7b77148aa8478240087cd");
  addr_t sender("0x9DeAC03F89e7819a241Ee3856715A1Ab76248023");
  ASSERT_THROW(Transaction(dev::jsToBytes("0xf84980808080808024a01404adc97c8b58fef303b2862d0e72378"
                                          "4fb635e7237e0e8d3ea33bbea19c36ca0229e80d57ba91a0f347686"
                                          "30fd21ad86e4c403b307de9ac4550d0ccc81c90fe3")),
               Transaction::InvalidSignature);
  std::vector<std::pair<uint64_t, string>> valid_cases{
      {0, "0xf647d1d47ce927ce2fb9f57e4e2a3c32b037c5e544b44611077f5cc6980b0bc2"},
      {1, "0x49c1cb845df5d3ed238ca37ad25ca96f417e4f22d7911224cf3c2a725985e7ff"},
      {uint64_t(1) << uint(32), "0xc1651c53d21ad6ddaac0af7ad93947074ef9f3b03479a36b29fa577b9faba8a9"},
  };
  for (auto& [chain_id, hash_str] : valid_cases) {
    Transaction t(1, 2, 3, 4, dev::jsToBytes("0xabcd"), sk, addr_t("0xd3CdA913deB6f67967B99D67aCDFa1712C293601"),
                  chain_id);
    for (auto i : {1, 0}) {
      ASSERT_EQ(t.getSender(), sender);
      ASSERT_EQ(t.getChainID(), chain_id);
      ASSERT_EQ(t.getHash(), h256(hash_str));
      if (i) {
        t = Transaction(t.rlp());
        continue;
      }
      dev::RLPStream with_modified_payload(9);
      dev::RLPStream with_invalid_signature(9);
      uint fields_processed = 0;
      for (auto const el : dev::RLP(t.rlp())) {
        if (auto el_modified = el.toBytes(); ++fields_processed <= 6) {
          for (auto& b : el_modified) {
            b = ~b;
          }
          with_modified_payload << el_modified;
          with_invalid_signature << el.toBytes();
        } else {
          for (auto& b : el_modified) {
            b = 0;
          }
          with_modified_payload << el.toBytes();
          with_invalid_signature << el_modified;
        }
      }
      ASSERT_NE(Transaction(with_modified_payload.out()).getSender(), sender);
      ASSERT_THROW(Transaction(with_invalid_signature.out()).getSender(), Transaction::InvalidSignature);
    }
  }
}

TEST_F(TransactionTest, verifiers) {
  TransactionManager trx_mgr(FullNodeConfig(), std::make_shared<DbStorage>(data_dir), nullptr, addr_t());
  // insert trx
  std::thread t([&trx_mgr]() {
    for (auto const& t : *g_trx_samples) {
      trx_mgr.insertTransaction(t);
    }
  });

  // insert trx again, should not duplicated
  for (auto const& t : *g_trx_samples) {
    trx_mgr.insertTransaction(t);
  }
  t.join();
  thisThreadSleepForMilliSeconds(100);
  EXPECT_EQ(trx_mgr.getTransactionPoolSize(), g_trx_samples->size());
}

TEST_F(TransactionTest, transaction_limit) {
  TransactionManager trx_mgr(FullNodeConfig(), std::make_shared<DbStorage>(data_dir), nullptr, addr_t());
  // insert trx
  std::thread t([&trx_mgr]() {
    for (auto const& t : *g_trx_samples) {
      trx_mgr.insertTransaction(t);
    }
  });

  // insert trx again, should not duplicated
  for (auto const& t : *g_trx_samples) {
    trx_mgr.insertTransaction(t);
  }
  t.join();
  thisThreadSleepForMilliSeconds(100);
  SharedTransactions verified_trxs1, verified_trxs2, verified_trxs3;
  verified_trxs1 = trx_mgr.packTrxs(10);
  verified_trxs2 = trx_mgr.packTrxs(20);
  verified_trxs3 = trx_mgr.packTrxs(0);
  EXPECT_EQ(verified_trxs1.size(), 10);
  EXPECT_EQ(verified_trxs2.size(), 20);
  EXPECT_EQ(verified_trxs3.size(), g_trx_samples->size());
}

TEST_F(TransactionTest, prepare_signed_trx_for_propose) {
  auto db = std::make_shared<DbStorage>(data_dir);
  TransactionManager trx_mgr(FullNodeConfig(), db, nullptr, addr_t());
  std::thread insertTrx([&trx_mgr]() {
    for (auto const& t : *g_signed_trx_samples) {
      trx_mgr.insertTransaction(*t);
    }
  });

  thisThreadSleepForMilliSeconds(500);

  insertTrx.join();
  SharedTransactions total_packed_trxs, packed_trxs;
  std::cout << "Start block proposing ..." << std::endl;
  std::thread wakeup([]() { thisThreadSleepForSeconds(2); });
  auto batch = db->createWriteBatch();

  do {
    packed_trxs = trx_mgr.packTrxs();
    total_packed_trxs.insert(total_packed_trxs.end(), packed_trxs.begin(), packed_trxs.end());
    trx_mgr.saveTransactionsFromDagBlock(packed_trxs);
    thisThreadSleepForMicroSeconds(100);
  } while (!packed_trxs.empty());
  wakeup.join();
  EXPECT_EQ(total_packed_trxs.size(), NUM_TRX) << " Packed Trx: " << ::testing::PrintToString(total_packed_trxs);
}

TEST_F(TransactionTest, transaction_concurrency) {
  auto db = std::make_shared<DbStorage>(data_dir);
  TransactionManager trx_mgr(FullNodeConfig(), db, nullptr, addr_t());
  bool stopped = false;
  // Insert transactions to memory pool and keep trying to insert them again on separate thread, it should always fail
  std::thread insertTrx([&trx_mgr, &stopped]() {
    for (auto const& t : *g_signed_trx_samples) {
      trx_mgr.insertTransaction(*t);
    }
    while (!stopped) {
      for (auto const& t : *g_signed_trx_samples) {
        EXPECT_FALSE(trx_mgr.insertTransaction(*t).first);
      }
    }
  });

  // 2/3 of transactions removed from pool and saved to db
  for (size_t i = 0; i < g_signed_trx_samples->size() * 2 / 3; i++) {
    trx_mgr.saveTransactionsFromDagBlock({g_signed_trx_samples[i]});
  }

  // 1/3 transactions finalized
  for (size_t i = 0; i < g_signed_trx_samples->size() / 3; i++) {
    db->saveTransactionPeriod(g_signed_trx_samples[i]->getHash(), 1, i);
    SyncBlock sync_block;
    sync_block.transactions = {*g_signed_trx_samples[i]};
    trx_mgr.updateFinalizedTransactionsStatus(sync_block);
  }

  // Stop the thread which is trying to indert transactions to pool
  stopped = true;
  insertTrx.join();

  // Verify all transactions are in correct state in pool, db and finalized
  std::set<trx_hash_t> pool_trx_hashes;
  for (auto const& t : trx_mgr.packTrxs()) {
    pool_trx_hashes.insert(t->getHash());
  }

  EXPECT_EQ(pool_trx_hashes.size(), g_signed_trx_samples->size() - g_signed_trx_samples->size() * 2 / 3);

  for (size_t i = 0; i < g_signed_trx_samples->size() / 3; i++) {
    EXPECT_FALSE(pool_trx_hashes.count(g_signed_trx_samples[i]->getHash()) > 0);
    EXPECT_TRUE(db->transactionInDb(g_signed_trx_samples[i]->getHash()));
    EXPECT_TRUE(db->transactionFinalized(g_signed_trx_samples[i]->getHash()));
  }

  for (size_t i = g_signed_trx_samples->size() / 3; i < g_signed_trx_samples->size() * 2 / 3; i++) {
    EXPECT_FALSE(pool_trx_hashes.count(g_signed_trx_samples[i]->getHash()) > 0);
    EXPECT_TRUE(db->transactionInDb(g_signed_trx_samples[i]->getHash()));
    EXPECT_FALSE(db->transactionFinalized(g_signed_trx_samples[i]->getHash()));
  }

  for (size_t i = g_signed_trx_samples->size() * 2 / 3; i < g_signed_trx_samples->size(); i++) {
    EXPECT_TRUE(pool_trx_hashes.count(g_signed_trx_samples[i]->getHash()) > 0);
    EXPECT_FALSE(db->transactionInDb(g_signed_trx_samples[i]->getHash()));
  }
}

TEST_F(TransactionTest, priority_queue) {
  // Check ordering by same sender and different nonce
  {
    TransactionQueue priority_queue;
    uint32_t nonce = 0;
    auto trx = Transaction(nonce++, 1, 1, 100, str2bytes("00FEDCBA9876543210000000"), g_secret, addr_t::random());
    auto trx2 = Transaction(nonce, 1, 1, 100, str2bytes("00FEDCBA9876543210000000"), g_secret, addr_t::random());
    priority_queue.insert(std::make_shared<Transaction>(trx2));
    priority_queue.insert(std::make_shared<Transaction>(trx));
    EXPECT_EQ(priority_queue.get(1)[0]->getHash(), trx.getHash());
    EXPECT_EQ(priority_queue.size(), 2);
  }

  // Check double insertion
  {
    TransactionQueue priority_queue;
    uint32_t nonce = 0;
    auto trx = Transaction(nonce, 1, 1, 100, str2bytes("00FEDCBA9876543210000000"), g_secret, addr_t::random());
    EXPECT_TRUE(priority_queue.insert(std::make_shared<Transaction>(trx)));
    EXPECT_FALSE(priority_queue.insert(std::make_shared<Transaction>(trx)));
    EXPECT_EQ(priority_queue.size(), 1);
  }

  // Check ordering by same sender, same nonce but different gas_price
  {
    TransactionQueue priority_queue;
    uint32_t nonce = 0;
    auto trx = Transaction(nonce, 1, 10, 100, str2bytes("00FEDCBA9876543210000000"), g_secret, addr_t::random());
    auto trx2 = Transaction(nonce, 1, 1, 100, str2bytes("00FEDCBA9876543210000000"), g_secret, addr_t::random());
    priority_queue.insert(std::make_shared<Transaction>(trx2));
    priority_queue.insert(std::make_shared<Transaction>(trx));
    EXPECT_EQ(priority_queue.get(1)[0]->getHash(), trx.getHash());
    EXPECT_EQ(priority_queue.size(), 2);
  }

  /*
  sender A:
  - TXA1, nonce 1, fee 5
  - TXA2, nonce 2, fee 6
  sender B
  - TXB1, nonce 1, fee 4
  Should be TXA1, TXB1, TXA2
  */
  {
    TransactionQueue priority_queue;
    auto trxa1 =
        Transaction(1 /*nonce*/, 1, 5 /*fee*/, 100, str2bytes("00FEDCBA9876543210000000"), g_secret, addr_t::random());
    auto trxa2 =
        Transaction(2 /*nonce*/, 1, 6 /*fee*/, 100, str2bytes("00FEDCBA9876543210000000"), g_secret, addr_t::random());
    auto trxb1 = Transaction(1 /*nonce*/, 1, 4 /*fee*/, 100, str2bytes("00FEDCBA9876543210000000"), secret_t::random(),
                             addr_t::random());
    priority_queue.insert(std::make_shared<Transaction>(trxb1));
    priority_queue.insert(std::make_shared<Transaction>(trxa2));
    priority_queue.insert(std::make_shared<Transaction>(trxa1));
    EXPECT_EQ(priority_queue.size(), 3);
    EXPECT_EQ(priority_queue.get(3)[0]->getHash(), trxa1.getHash());
    EXPECT_EQ(priority_queue.get(3)[1]->getHash(), trxa2.getHash());
    EXPECT_EQ(priority_queue.get(3)[2]->getHash(), trxb1.getHash());
  }
}

}  // namespace taraxa::core_tests

using namespace taraxa;
int main(int argc, char** argv) {
  static_init();
  auto logging = logger::createDefaultLoggingConfig();
  logging.verbosity = logger::Verbosity::Error;

  addr_t node_addr;
  logger::InitLogging(logging, node_addr);

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
