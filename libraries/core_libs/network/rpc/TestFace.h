/**
 * This file is generated by jsonrpcstub, DO NOT CHANGE IT MANUALLY!
 */

#ifndef JSONRPC_CPP_STUB_TARAXA_NET_TESTFACE_H_
#define JSONRPC_CPP_STUB_TARAXA_NET_TESTFACE_H_

#include <libweb3jsonrpc/ModularServer.h>

namespace taraxa {
namespace net {
class TestFace : public ServerInterface<TestFace> {
 public:
  TestFace() {
    this->bindAndAddMethod(jsonrpc::Procedure("insert_dag_block", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT,
                                              "param1", jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::insert_dag_blockI);
    this->bindAndAddMethod(jsonrpc::Procedure("get_dag_block", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT,
                                              "param1", jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::get_dag_blockI);
    this->bindAndAddMethod(jsonrpc::Procedure("get_nf_blocks", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT,
                                              "param1", jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::get_nf_blocksI);
    this->bindAndAddMethod(jsonrpc::Procedure("get_sortition_change", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT,
                                              "param1", jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::get_sortition_changeI);
    this->bindAndAddMethod(jsonrpc::Procedure("send_coin_transaction", jsonrpc::PARAMS_BY_POSITION,
                                              jsonrpc::JSON_OBJECT, "param1", jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::send_coin_transactionI);
    this->bindAndAddMethod(
        jsonrpc::Procedure("get_num_proposed_blocks", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, NULL),
        &taraxa::net::TestFace::get_num_proposed_blocksI);
    this->bindAndAddMethod(
        jsonrpc::Procedure("get_account_address", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, NULL),
        &taraxa::net::TestFace::get_account_addressI);
    this->bindAndAddMethod(jsonrpc::Procedure("get_account_balance", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT,
                                              "param1", jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::get_account_balanceI);
    this->bindAndAddMethod(
        jsonrpc::Procedure("get_node_count", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, NULL),
        &taraxa::net::TestFace::get_node_countI);
    this->bindAndAddMethod(
        jsonrpc::Procedure("get_peer_count", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, NULL),
        &taraxa::net::TestFace::get_peer_countI);
    this->bindAndAddMethod(
        jsonrpc::Procedure("get_node_status", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, NULL),
        &taraxa::net::TestFace::get_node_statusI);
    this->bindAndAddMethod(
        jsonrpc::Procedure("get_packets_stats", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, NULL),
        &taraxa::net::TestFace::get_packets_statsI);
    this->bindAndAddMethod(
        jsonrpc::Procedure("get_node_version", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, NULL),
        &taraxa::net::TestFace::get_node_versionI);
    this->bindAndAddMethod(jsonrpc::Procedure("get_all_peers", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::get_all_peersI);
    this->bindAndAddMethod(jsonrpc::Procedure("get_all_nodes", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::get_all_nodesI);
    this->bindAndAddMethod(jsonrpc::Procedure("get_vote_weight", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT,
                                              "param1", jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::get_vote_weightI);
    this->bindAndAddMethod(jsonrpc::Procedure("place_vote", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",
                                              jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::place_voteI);
    this->bindAndAddMethod(jsonrpc::Procedure("get_votes", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",
                                              jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::get_votesI);
    this->bindAndAddMethod(jsonrpc::Procedure("draw_graph", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",
                                              jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::draw_graphI);
    this->bindAndAddMethod(jsonrpc::Procedure("get_transaction_count", jsonrpc::PARAMS_BY_POSITION,
                                              jsonrpc::JSON_OBJECT, "param1", jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::get_transaction_countI);
    this->bindAndAddMethod(jsonrpc::Procedure("get_executed_trx_count", jsonrpc::PARAMS_BY_POSITION,
                                              jsonrpc::JSON_OBJECT, "param1", jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::get_executed_trx_countI);
    this->bindAndAddMethod(jsonrpc::Procedure("get_executed_blk_count", jsonrpc::PARAMS_BY_POSITION,
                                              jsonrpc::JSON_OBJECT, "param1", jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::get_executed_blk_countI);
    this->bindAndAddMethod(jsonrpc::Procedure("get_dag_size", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT,
                                              "param1", jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::get_dag_sizeI);
    this->bindAndAddMethod(jsonrpc::Procedure("get_dag_blk_count", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT,
                                              "param1", jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::get_dag_blk_countI);
    this->bindAndAddMethod(
        jsonrpc::Procedure("get_pbft_chain_size", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, NULL),
        &taraxa::net::TestFace::get_pbft_chain_sizeI);
    this->bindAndAddMethod(jsonrpc::Procedure("get_pbft_chain_blocks", jsonrpc::PARAMS_BY_POSITION,
                                              jsonrpc::JSON_OBJECT, "param1", jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::get_pbft_chain_blocksI);
    this->bindAndAddMethod(jsonrpc::Procedure("get_db_stats", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, NULL),
                           &taraxa::net::TestFace::get_db_statsI);
  }

  inline virtual void insert_dag_blockI(const Json::Value &request, Json::Value &response) {
    response = this->insert_dag_block(request[0u]);
  }
  inline virtual void get_dag_blockI(const Json::Value &request, Json::Value &response) {
    response = this->get_dag_block(request[0u]);
  }
  inline virtual void get_nf_blocksI(const Json::Value &request, Json::Value &response) {
    response = this->get_nf_blocks(request[0u]);
  }
  inline virtual void get_sortition_changeI(const Json::Value &request, Json::Value &response) {
    response = this->get_sortition_change(request[0u]);
  }
  inline virtual void send_coin_transactionI(const Json::Value &request, Json::Value &response) {
    response = this->send_coin_transaction(request[0u]);
  }
  inline virtual void get_num_proposed_blocksI(const Json::Value &request, Json::Value &response) {
    (void)request;
    response = this->get_num_proposed_blocks();
  }
  inline virtual void get_account_addressI(const Json::Value &request, Json::Value &response) {
    (void)request;
    response = this->get_account_address();
  }
  inline virtual void get_account_balanceI(const Json::Value &request, Json::Value &response) {
    response = this->get_account_balance(request[0u]);
  }
  inline virtual void get_node_countI(const Json::Value &request, Json::Value &response) {
    (void)request;
    response = this->get_node_count();
  }
  inline virtual void get_peer_countI(const Json::Value &request, Json::Value &response) {
    (void)request;
    response = this->get_peer_count();
  }
  inline virtual void get_node_statusI(const Json::Value &request, Json::Value &response) {
    (void)request;
    response = this->get_node_status();
  }
  inline virtual void get_packets_statsI(const Json::Value &request, Json::Value &response) {
    (void)request;
    response = this->get_packets_stats();
  }
  inline virtual void get_node_versionI(const Json::Value &request, Json::Value &response) {
    (void)request;
    response = this->get_node_version();
  }
  inline virtual void get_all_peersI(const Json::Value &request, Json::Value &response) {
    (void)request;
    response = this->get_all_peers();
  }
  inline virtual void get_all_nodesI(const Json::Value &request, Json::Value &response) {
    (void)request;
    response = this->get_all_nodes();
  }
  inline virtual void get_vote_weightI(const Json::Value &request, Json::Value &response) {
    response = this->get_vote_weight(request[0u]);
  }
  inline virtual void place_voteI(const Json::Value &request, Json::Value &response) {
    response = this->place_vote(request[0u]);
  }
  inline virtual void get_votesI(const Json::Value &request, Json::Value &response) {
    response = this->get_votes(request[0u]);
  }
  inline virtual void draw_graphI(const Json::Value &request, Json::Value &response) {
    response = this->draw_graph(request[0u]);
  }
  inline virtual void get_transaction_countI(const Json::Value &request, Json::Value &response) {
    response = this->get_transaction_count(request[0u]);
  }
  inline virtual void get_executed_trx_countI(const Json::Value &request, Json::Value &response) {
    response = this->get_executed_trx_count(request[0u]);
  }
  inline virtual void get_executed_blk_countI(const Json::Value &request, Json::Value &response) {
    response = this->get_executed_blk_count(request[0u]);
  }
  inline virtual void get_dag_sizeI(const Json::Value &request, Json::Value &response) {
    response = this->get_dag_size(request[0u]);
  }
  inline virtual void get_dag_blk_countI(const Json::Value &request, Json::Value &response) {
    response = this->get_dag_blk_count(request[0u]);
  }
  inline virtual void get_pbft_chain_sizeI(const Json::Value &request, Json::Value &response) {
    (void)request;
    response = this->get_pbft_chain_size();
  }
  inline virtual void get_pbft_chain_blocksI(const Json::Value &request, Json::Value &response) {
    response = this->get_pbft_chain_blocks(request[0u]);
  }
  inline virtual void get_db_statsI(const Json::Value &request, Json::Value &response) {
    (void)request;
    response = this->get_db_stats();
  }
  virtual Json::Value insert_dag_block(const Json::Value &param1) = 0;
  virtual Json::Value get_dag_block(const Json::Value &param1) = 0;
  virtual Json::Value get_nf_blocks(const Json::Value &param1) = 0;
  virtual Json::Value get_sortition_change(const Json::Value &param1) = 0;
  virtual Json::Value send_coin_transaction(const Json::Value &param1) = 0;
  virtual Json::Value get_num_proposed_blocks() = 0;
  virtual Json::Value get_account_address() = 0;
  virtual Json::Value get_account_balance(const Json::Value &param1) = 0;
  virtual Json::Value get_node_count() = 0;
  virtual Json::Value get_peer_count() = 0;
  virtual Json::Value get_node_status() = 0;
  virtual Json::Value get_packets_stats() = 0;
  virtual Json::Value get_node_version() = 0;
  virtual Json::Value get_all_peers() = 0;
  virtual Json::Value get_all_nodes() = 0;
  virtual Json::Value get_vote_weight(const Json::Value &param1) = 0;
  virtual Json::Value place_vote(const Json::Value &param1) = 0;
  virtual Json::Value get_votes(const Json::Value &param1) = 0;
  virtual Json::Value draw_graph(const Json::Value &param1) = 0;
  virtual Json::Value get_transaction_count(const Json::Value &param1) = 0;
  virtual Json::Value get_executed_trx_count(const Json::Value &param1) = 0;
  virtual Json::Value get_executed_blk_count(const Json::Value &param1) = 0;
  virtual Json::Value get_dag_size(const Json::Value &param1) = 0;
  virtual Json::Value get_dag_blk_count(const Json::Value &param1) = 0;
  virtual Json::Value get_pbft_chain_size() = 0;
  virtual Json::Value get_pbft_chain_blocks(const Json::Value &param1) = 0;
  virtual Json::Value get_db_stats() = 0;
};

}  // namespace net
}  // namespace taraxa
#endif  // JSONRPC_CPP_STUB_TARAXA_NET_TESTFACE_H_
