#pragma once

#include "network/ws_server.hpp"

namespace taraxa::net {

class GraphQlWSSession : public WSSession {
 public:
  using WSSession::WSSession;
  virtual std::string processRequest(std::string request) override;
};

class GraphQlWsServer : public WSServer {
 public:
  using WSServer::WSServer;
  virtual std::shared_ptr<WSSession> createSession(tcp::socket &socket) override;
};

}  // namespace taraxa::net