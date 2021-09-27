#pragma once

#include "network/tarcap/packets_handlers/common/packet_handler.hpp"

namespace taraxa {
class DagBlockManager;
class DbStorage;
class TransactionManager;
}  // namespace taraxa

namespace taraxa::network::tarcap {

class SyncingState;
class SyncingHandler;
class TestState;

class DagPacketsHandler : public PacketHandler {
 public:
  using PeersPtrVector = std::vector<std::shared_ptr<TaraxaPeer>>;

  DagPacketsHandler(std::shared_ptr<PeersState> peers_state, std::shared_ptr<PacketsStats> packets_stats,
                    std::shared_ptr<SyncingState> syncing_state, std::shared_ptr<SyncingHandler> syncing_handler,
                    std::shared_ptr<TransactionManager> trx_mgr, std::shared_ptr<DagBlockManager> dag_blk_mgr,
                    std::shared_ptr<DbStorage> db, std::shared_ptr<TestState> test_state, const addr_t &node_addr = {});

  virtual ~DagPacketsHandler() = default;

  void sendBlock(dev::p2p::NodeID const &peer_id, DagBlock block);
  void onNewBlockReceived(DagBlock block, std::vector<Transaction> transactions);
  void onNewBlockVerified(DagBlock const &block, bool proposed);

 private:
  void process(const PacketData &packet_data, const std::shared_ptr<TaraxaPeer> &peer) override;

  std::shared_ptr<SyncingState> syncing_state_;
  std::shared_ptr<SyncingHandler> syncing_handler_;
  std::shared_ptr<TransactionManager> trx_mgr_;
  std::shared_ptr<DagBlockManager> dag_blk_mgr_;
  std::shared_ptr<DbStorage> db_;
  std::shared_ptr<TestState> test_state_;

  thread_local static std::mt19937_64 urng_;
};

}  // namespace taraxa::network::tarcap
