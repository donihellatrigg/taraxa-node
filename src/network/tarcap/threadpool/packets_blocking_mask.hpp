#pragma once

#include <libp2p/Common.h>

#include <atomic>
#include <shared_mutex>
#include <unordered_map>

#include "network/tarcap/packet_types.hpp"
#include "network/tarcap/threadpool/packet_data.hpp"

namespace taraxa::network::tarcap {

class PacketsBlockingMask {
 private:
  struct TimeBlock {
    // How many packets (of the same type & received from the same peer) are currently being processed concurrently.
    // It is used to decide when to delete TimeBlock -> delete time block when concurrent_processing_count_ == 0
    // Note: concurrent_processing_count_ != times_.size() as in some edge case packets could have the same receive
    // times and concurrent_processing_count_ would be > times_.size() in such case
    size_t concurrent_processing_count_;
    // Packet is blocked if its "receive time" >= times_.begin()
    std::set<std::chrono::steady_clock::time_point> times_;
  };

 public:
  // Note: calling markPacketAsHardBlocked and markPacketAsPeerTimeBlocked on the same packet_type would not work
  void markPacketAsHardBlocked(PriorityQueuePacketType packet_type);
  void markPacketAsHardUnblocked(PriorityQueuePacketType packet_type);
  void markPacketAsPeerTimeBlocked(const PacketData& blocking_packet, PriorityQueuePacketType packet_to_be_blocked);
  void markPacketAsPeerTimeUnblocked(const PacketData& blocking_packet, PriorityQueuePacketType packet_to_be_unblocked);

  bool isPacketBlocked(const PacketData& packet_data) const;

 private:
  // Mask with all packets types that are currently hard blocked for processing in another threads due to dependencies,
  // e.g. syncing packets must be processed synchronously one by one, etc... blocked_packets_types_mask_ OR
  // QueuePacketType -> sets QueuePacketType as blocked packet blocked_packets_types_mask_ XOR QueuePacketType -> sets
  // QueuePacketType as unblocked packet (note: packet must be marked as blocked - 1 for XOR to work correctly)
  std::atomic<uint32_t> blocked_packets_types_mask_{0};

  // "Mask" with all packets that are blocked only for processing when received from specific peers & after specific
  // time, e.g.: new dag block packet processing is blocked until all transactions packets that were received before it
  // are processed. This blocking dependency is applied only for the same peer so transaction packet from one peer does
  // not block new dag block packet from another peer
  std::unordered_map<PriorityQueuePacketType, std::unordered_map<dev::p2p::NodeID, TimeBlock>>
      blocked_packets_peers_time_;
};

}  // namespace taraxa::network::tarcap