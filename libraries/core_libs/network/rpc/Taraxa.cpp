#include "Taraxa.h"

#include <jsonrpccpp/common/exception.h>
#include <libdevcore/CommonData.h>
#include <libdevcore/CommonJS.h>
#include <libp2p/Common.h>

#include "dag/dag.hpp"
#include "dag/dag_block_manager.hpp"
#include "pbft/pbft_manager.hpp"
#include "transaction_manager/transaction_manager.hpp"

using namespace std;
using namespace jsonrpc;
using namespace dev;
using namespace taraxa;
using namespace ::taraxa::final_chain;

namespace taraxa::net {

Taraxa::Taraxa(std::shared_ptr<FullNode> const& _full_node) : full_node_(_full_node) {}

string Taraxa::taraxa_protocolVersion() { return toJS(TARAXA_NET_VERSION); }

string Taraxa::taraxa_getVersion() { return TARAXA_VERSION; }

string Taraxa::taraxa_dagBlockLevel() {
  try {
    auto node = tryGetNode();
    return toJS(node->getDagManager()->getMaxLevel());
  } catch (...) {
    BOOST_THROW_EXCEPTION(JsonRpcException(Errors::ERROR_RPC_INVALID_PARAMS));
  }
}

string Taraxa::taraxa_dagBlockPeriod() {
  try {
    auto node = tryGetNode();
    return toJS(node->getDagManager()->getLatestPeriod());
  } catch (...) {
    BOOST_THROW_EXCEPTION(JsonRpcException(Errors::ERROR_RPC_INVALID_PARAMS));
  }
}

Taraxa::NodePtr Taraxa::tryGetNode() {
  if (auto full_node = full_node_.lock()) {
    return full_node;
  }
  BOOST_THROW_EXCEPTION(jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_RPC_INTERNAL_ERROR));
}

Json::Value Taraxa::taraxa_getDagBlockByHash(string const& _blockHash, bool _includeTransactions) {
  try {
    auto node = tryGetNode();
    auto block = node->getDagBlockManager()->getDagBlock(blk_hash_t(_blockHash));
    if (block) {
      auto block_json = block->getJson();
      auto period = node->getPbftManager()->getDagBlockPeriod(block->getHash());
      if (period.first) {
        block_json["period"] = toJS(period.second);
      } else {
        block_json["period"] = "-0x1";
      }
      if (_includeTransactions) {
        block_json["transactions"] = Json::Value(Json::arrayValue);
        for (auto const& t : block->getTrxs()) {
          block_json["transactions"].append(node->getTransactionManager()->getTransaction(t)->toJSON());
        }
      }
      return block_json;
    }
  } catch (...) {
    BOOST_THROW_EXCEPTION(JsonRpcException(Errors::ERROR_RPC_INVALID_PARAMS));
  }
  return Json::Value();
}

Json::Value Taraxa::taraxa_getScheduleBlockByPeriod(std::string const& _period) {
  try {
    auto node = tryGetNode();
    auto db = node->getDB();
    auto blk = db->getPbftBlock(std::stoull(_period, 0, 16));
    if (!blk.has_value()) {
      return Json::Value();
    }
    return PbftBlock::toJson(*blk, db->getFinalizedDagBlockHashesByPeriod(std::stoull(_period, 0, 16)));
  } catch (...) {
    BOOST_THROW_EXCEPTION(JsonRpcException(Errors::ERROR_RPC_INVALID_PARAMS));
  }
}

Json::Value Taraxa::taraxa_getDagBlockByLevel(string const& _blockLevel, bool _includeTransactions) {
  try {
    auto node = tryGetNode();
    auto blocks = node->getDB()->getDagBlocksAtLevel(std::stoull(_blockLevel, 0, 16), 1);
    auto res = Json::Value(Json::arrayValue);
    for (auto const& b : blocks) {
      auto block_json = b->getJson();
      auto period = node->getPbftManager()->getDagBlockPeriod(b->getHash());
      if (period.first) {
        block_json["period"] = toJS(period.second);
      } else {
        block_json["period"] = "-0x1";
      }
      if (_includeTransactions) {
        block_json["transactions"] = Json::Value(Json::arrayValue);
        for (auto const& t : b->getTrxs()) {
          block_json["transactions"].append(node->getTransactionManager()->getTransaction(t)->toJSON());
        }
      }
      res.append(block_json);
    }
    return res;
  } catch (...) {
    BOOST_THROW_EXCEPTION(JsonRpcException(Errors::ERROR_RPC_INVALID_PARAMS));
  }
}

Json::Value Taraxa::taraxa_getConfig() { return enc_json(tryGetNode()->getConfig().chain); }

Json::Value Taraxa::taraxa_queryDPOS(Json::Value const& _q) {
  std::optional<EthBlockNumber> blk_n;
  auto const& blk_n_json = _q["block_number"];
  if (!blk_n_json.isNull()) {
    blk_n = dev::jsToInt(blk_n_json.asString());
  }
  state_api::DPOSQuery q;
  dec_json(_q, q);

  state_api::DPOSQueryResult res;
  try {
    res = tryGetNode()->getFinalChain()->dpos_query(q, blk_n);
  } catch (state_api::ErrFutureBlock& c) {
    std::stringstream err;
    err << "Block number " << blk_n_json << " is too far ahead of DPOS. " << c.what();
    BOOST_THROW_EXCEPTION(JsonRpcException(Errors::ERROR_RPC_INVALID_PARAMS, err.str()));
  }

  return enc_json(res, &q);
}

}  // namespace taraxa::net