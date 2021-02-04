#pragma once

#include <network/http_server.hpp>

namespace taraxa::net {

class JsonRpcConnection;

class JsonRpcServer : public HttpServer {
 public:
  using HttpServer::HttpServer;
  virtual std::shared_ptr<HttpConnection> createConnection() override;
};

class JsonRpcConnection : public HttpConnection {
 public:
  using HttpConnection::HttpConnection;
  virtual std::string processRequest(std::string request) override;
};

}  // namespace taraxa::net
