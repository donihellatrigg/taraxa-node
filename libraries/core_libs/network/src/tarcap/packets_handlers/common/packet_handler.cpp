#include "network/tarcap/packets_handlers/common/packet_handler.hpp"

#include "network/tarcap/stats/packets_stats.hpp"

namespace taraxa::network::tarcap {

PacketHandler::PacketHandler(std::shared_ptr<PeersState> peers_state, std::shared_ptr<PacketsStats> packets_stats,
                             const addr_t& node_addr, const std::string& log_channel_name)
    : peers_state_(std::move(peers_state)), packets_stats_(std::move(packets_stats)) {
  LOG_OBJECTS_CREATE(log_channel_name);
}

void PacketHandler::processPacket(const PacketData& packet_data) {
  try {
    SinglePacketStats packet_stats{packet_data.from_node_id_, packet_data.rlp_.data().size(),
                                   std::chrono::microseconds(0), std::chrono::microseconds(0)};
    const auto begin = std::chrono::steady_clock::now();

    auto tmp_peer = peers_state_->getPeer(packet_data.from_node_id_);
    if (!tmp_peer && packet_data.type_ != SubprotocolPacketType::StatusPacket) {
      LOG(log_er_) << "Peer " << packet_data.from_node_id_.abridged()
                   << " not in peers map. He probably did not send initial status message - will be disconnected.";
      disconnect(packet_data.from_node_id_, dev::p2p::UserReason);
      return;
    }

    // Main processing function
    process(packet_data, tmp_peer);

    auto processing_duration =
        std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin);
    auto tp_wait_duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() -
                                                                                  packet_data.receive_time_);
    packet_stats.processing_duration_ = processing_duration;
    packet_stats.tp_wait_duration_ = tp_wait_duration;

    packets_stats_->addReceivedPacket(packet_data.type_str_, packet_stats);

  } catch (...) {
    handle_read_exception(packet_data);
  }
}

void PacketHandler::handle_read_exception(const PacketData& packet_data) {
  try {
    throw;
  } catch (std::exception const& _e) {
    LOG(log_er_) << "Read exception: " << _e.what() << ". PacketType: " << packet_data.type_str_ << " ("
                 << packet_data.type_ << ")";
    disconnect(packet_data.from_node_id_, dev::p2p::DisconnectReason::BadProtocol);
  }
}

bool PacketHandler::sealAndSend(const dev::p2p::NodeID& node_id, SubprotocolPacketType packet_type,
                                dev::RLPStream&& rlp) {
  auto host = peers_state_->host_.lock();
  if (!host) {
    LOG(log_er_) << "sealAndSend failed to obtain host";
    return false;
  }

  const auto [peer, is_pending] = peers_state_->getAnyPeer(node_id);
  if (!peer) [[unlikely]] {
    LOG(log_wr_) << "sealAndSend failed to find peer";
    return false;
  }

  if (is_pending && packet_type != SubprotocolPacketType::StatusPacket) [[unlikely]] {
    LOG(log_wr_) << "sealAndSend failed initial status check, peer " << node_id.abridged() << " will be disconnected";
    host->disconnect(node_id, dev::p2p::UserReason);
    return false;
  }

  const auto begin = std::chrono::steady_clock::now();
  const size_t packet_size = rlp.out().size();

  host->send(node_id, TARAXA_CAPABILITY_NAME, packet_type, rlp.invalidate(),
             [begin, node_id, packet_size, packet_type, this]() {
               SinglePacketStats packet_stats{
                   node_id, packet_size,
                   std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin),
                   std::chrono::microseconds{0}};
               packets_stats_->addSentPacket(convertPacketTypeToString(packet_type), packet_stats);
             });

  return true;
}

void PacketHandler::disconnect(dev::p2p::NodeID const& node_id, dev::p2p::DisconnectReason reason) {
  if (auto host = peers_state_->host_.lock(); host) {
    host->disconnect(node_id, reason);
  } else {
    LOG(log_wr_) << "Invalid host " << node_id.abridged();
  }
}

}  // namespace taraxa::network::tarcap
