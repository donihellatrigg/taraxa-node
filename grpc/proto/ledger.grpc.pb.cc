// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: proto/ledger.proto

#include "proto/ledger.pb.h"
#include "proto/ledger.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace ledger {

static const char* LedgerService_method_names[] = {
  "/ledger.LedgerService/IsTestnet",
  "/ledger.LedgerService/GetNetworkName",
  "/ledger.LedgerService/GetVersion",
  "/ledger.LedgerService/GetSubversion",
  "/ledger.LedgerService/GetCoinName",
  "/ledger.LedgerService/GetChainInfo",
  "/ledger.LedgerService/GetBestBlockHash",
  "/ledger.LedgerService/GetBestBlockHeight",
  "/ledger.LedgerService/GetBlockHash",
  "/ledger.LedgerService/GetBlockHeader",
  "/ledger.LedgerService/GetBlock",
  "/ledger.LedgerService/GetBlockInfo",
};

std::unique_ptr< LedgerService::Stub> LedgerService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< LedgerService::Stub> stub(new LedgerService::Stub(channel));
  return stub;
}

LedgerService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_IsTestnet_(LedgerService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetNetworkName_(LedgerService_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetVersion_(LedgerService_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetSubversion_(LedgerService_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetCoinName_(LedgerService_method_names[4], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetChainInfo_(LedgerService_method_names[5], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetBestBlockHash_(LedgerService_method_names[6], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetBestBlockHeight_(LedgerService_method_names[7], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetBlockHash_(LedgerService_method_names[8], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetBlockHeader_(LedgerService_method_names[9], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetBlock_(LedgerService_method_names[10], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetBlockInfo_(LedgerService_method_names[11], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status LedgerService::Stub::IsTestnet(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::ledger::IsTestnetResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_IsTestnet_, context, request, response);
}

void LedgerService::Stub::experimental_async::IsTestnet(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::ledger::IsTestnetResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_IsTestnet_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ledger::IsTestnetResponse>* LedgerService::Stub::AsyncIsTestnetRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::IsTestnetResponse>::Create(channel_.get(), cq, rpcmethod_IsTestnet_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ledger::IsTestnetResponse>* LedgerService::Stub::PrepareAsyncIsTestnetRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::IsTestnetResponse>::Create(channel_.get(), cq, rpcmethod_IsTestnet_, context, request, false);
}

::grpc::Status LedgerService::Stub::GetNetworkName(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::ledger::GetNetworkNameResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetNetworkName_, context, request, response);
}

void LedgerService::Stub::experimental_async::GetNetworkName(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::ledger::GetNetworkNameResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetNetworkName_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ledger::GetNetworkNameResponse>* LedgerService::Stub::AsyncGetNetworkNameRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetNetworkNameResponse>::Create(channel_.get(), cq, rpcmethod_GetNetworkName_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ledger::GetNetworkNameResponse>* LedgerService::Stub::PrepareAsyncGetNetworkNameRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetNetworkNameResponse>::Create(channel_.get(), cq, rpcmethod_GetNetworkName_, context, request, false);
}

::grpc::Status LedgerService::Stub::GetVersion(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::ledger::GetVersionResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetVersion_, context, request, response);
}

void LedgerService::Stub::experimental_async::GetVersion(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::ledger::GetVersionResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetVersion_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ledger::GetVersionResponse>* LedgerService::Stub::AsyncGetVersionRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetVersionResponse>::Create(channel_.get(), cq, rpcmethod_GetVersion_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ledger::GetVersionResponse>* LedgerService::Stub::PrepareAsyncGetVersionRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetVersionResponse>::Create(channel_.get(), cq, rpcmethod_GetVersion_, context, request, false);
}

::grpc::Status LedgerService::Stub::GetSubversion(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::ledger::GetSubversionResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetSubversion_, context, request, response);
}

void LedgerService::Stub::experimental_async::GetSubversion(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::ledger::GetSubversionResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetSubversion_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ledger::GetSubversionResponse>* LedgerService::Stub::AsyncGetSubversionRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetSubversionResponse>::Create(channel_.get(), cq, rpcmethod_GetSubversion_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ledger::GetSubversionResponse>* LedgerService::Stub::PrepareAsyncGetSubversionRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetSubversionResponse>::Create(channel_.get(), cq, rpcmethod_GetSubversion_, context, request, false);
}

::grpc::Status LedgerService::Stub::GetCoinName(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::ledger::GetCoinNameResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetCoinName_, context, request, response);
}

void LedgerService::Stub::experimental_async::GetCoinName(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::ledger::GetCoinNameResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetCoinName_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ledger::GetCoinNameResponse>* LedgerService::Stub::AsyncGetCoinNameRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetCoinNameResponse>::Create(channel_.get(), cq, rpcmethod_GetCoinName_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ledger::GetCoinNameResponse>* LedgerService::Stub::PrepareAsyncGetCoinNameRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetCoinNameResponse>::Create(channel_.get(), cq, rpcmethod_GetCoinName_, context, request, false);
}

::grpc::Status LedgerService::Stub::GetChainInfo(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::ledger::GetChainInfoResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetChainInfo_, context, request, response);
}

void LedgerService::Stub::experimental_async::GetChainInfo(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::ledger::GetChainInfoResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetChainInfo_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ledger::GetChainInfoResponse>* LedgerService::Stub::AsyncGetChainInfoRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetChainInfoResponse>::Create(channel_.get(), cq, rpcmethod_GetChainInfo_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ledger::GetChainInfoResponse>* LedgerService::Stub::PrepareAsyncGetChainInfoRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetChainInfoResponse>::Create(channel_.get(), cq, rpcmethod_GetChainInfo_, context, request, false);
}

::grpc::Status LedgerService::Stub::GetBestBlockHash(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::ledger::GetBestBlockHashResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetBestBlockHash_, context, request, response);
}

void LedgerService::Stub::experimental_async::GetBestBlockHash(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::ledger::GetBestBlockHashResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetBestBlockHash_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ledger::GetBestBlockHashResponse>* LedgerService::Stub::AsyncGetBestBlockHashRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetBestBlockHashResponse>::Create(channel_.get(), cq, rpcmethod_GetBestBlockHash_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ledger::GetBestBlockHashResponse>* LedgerService::Stub::PrepareAsyncGetBestBlockHashRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetBestBlockHashResponse>::Create(channel_.get(), cq, rpcmethod_GetBestBlockHash_, context, request, false);
}

::grpc::Status LedgerService::Stub::GetBestBlockHeight(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::ledger::GetBestBlockHeightResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetBestBlockHeight_, context, request, response);
}

void LedgerService::Stub::experimental_async::GetBestBlockHeight(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::ledger::GetBestBlockHeightResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetBestBlockHeight_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ledger::GetBestBlockHeightResponse>* LedgerService::Stub::AsyncGetBestBlockHeightRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetBestBlockHeightResponse>::Create(channel_.get(), cq, rpcmethod_GetBestBlockHeight_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ledger::GetBestBlockHeightResponse>* LedgerService::Stub::PrepareAsyncGetBestBlockHeightRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetBestBlockHeightResponse>::Create(channel_.get(), cq, rpcmethod_GetBestBlockHeight_, context, request, false);
}

::grpc::Status LedgerService::Stub::GetBlockHash(::grpc::ClientContext* context, const ::ledger::GetBlockHashRequest& request, ::ledger::GetBlockHashResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetBlockHash_, context, request, response);
}

void LedgerService::Stub::experimental_async::GetBlockHash(::grpc::ClientContext* context, const ::ledger::GetBlockHashRequest* request, ::ledger::GetBlockHashResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetBlockHash_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ledger::GetBlockHashResponse>* LedgerService::Stub::AsyncGetBlockHashRaw(::grpc::ClientContext* context, const ::ledger::GetBlockHashRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetBlockHashResponse>::Create(channel_.get(), cq, rpcmethod_GetBlockHash_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ledger::GetBlockHashResponse>* LedgerService::Stub::PrepareAsyncGetBlockHashRaw(::grpc::ClientContext* context, const ::ledger::GetBlockHashRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetBlockHashResponse>::Create(channel_.get(), cq, rpcmethod_GetBlockHash_, context, request, false);
}

::grpc::Status LedgerService::Stub::GetBlockHeader(::grpc::ClientContext* context, const ::ledger::GetBlockHeaderRequest& request, ::ledger::GetBlockHeaderResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetBlockHeader_, context, request, response);
}

void LedgerService::Stub::experimental_async::GetBlockHeader(::grpc::ClientContext* context, const ::ledger::GetBlockHeaderRequest* request, ::ledger::GetBlockHeaderResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetBlockHeader_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ledger::GetBlockHeaderResponse>* LedgerService::Stub::AsyncGetBlockHeaderRaw(::grpc::ClientContext* context, const ::ledger::GetBlockHeaderRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetBlockHeaderResponse>::Create(channel_.get(), cq, rpcmethod_GetBlockHeader_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ledger::GetBlockHeaderResponse>* LedgerService::Stub::PrepareAsyncGetBlockHeaderRaw(::grpc::ClientContext* context, const ::ledger::GetBlockHeaderRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetBlockHeaderResponse>::Create(channel_.get(), cq, rpcmethod_GetBlockHeader_, context, request, false);
}

::grpc::Status LedgerService::Stub::GetBlock(::grpc::ClientContext* context, const ::ledger::GetBlockRequest& request, ::ledger::GetBlockResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetBlock_, context, request, response);
}

void LedgerService::Stub::experimental_async::GetBlock(::grpc::ClientContext* context, const ::ledger::GetBlockRequest* request, ::ledger::GetBlockResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetBlock_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ledger::GetBlockResponse>* LedgerService::Stub::AsyncGetBlockRaw(::grpc::ClientContext* context, const ::ledger::GetBlockRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetBlockResponse>::Create(channel_.get(), cq, rpcmethod_GetBlock_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ledger::GetBlockResponse>* LedgerService::Stub::PrepareAsyncGetBlockRaw(::grpc::ClientContext* context, const ::ledger::GetBlockRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetBlockResponse>::Create(channel_.get(), cq, rpcmethod_GetBlock_, context, request, false);
}

::grpc::Status LedgerService::Stub::GetBlockInfo(::grpc::ClientContext* context, const ::ledger::GetBlockInfoRequest& request, ::ledger::GetBlockInfoResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetBlockInfo_, context, request, response);
}

void LedgerService::Stub::experimental_async::GetBlockInfo(::grpc::ClientContext* context, const ::ledger::GetBlockInfoRequest* request, ::ledger::GetBlockInfoResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetBlockInfo_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ledger::GetBlockInfoResponse>* LedgerService::Stub::AsyncGetBlockInfoRaw(::grpc::ClientContext* context, const ::ledger::GetBlockInfoRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetBlockInfoResponse>::Create(channel_.get(), cq, rpcmethod_GetBlockInfo_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ledger::GetBlockInfoResponse>* LedgerService::Stub::PrepareAsyncGetBlockInfoRaw(::grpc::ClientContext* context, const ::ledger::GetBlockInfoRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ledger::GetBlockInfoResponse>::Create(channel_.get(), cq, rpcmethod_GetBlockInfo_, context, request, false);
}

LedgerService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LedgerService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LedgerService::Service, ::google::protobuf::Empty, ::ledger::IsTestnetResponse>(
          std::mem_fn(&LedgerService::Service::IsTestnet), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LedgerService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LedgerService::Service, ::google::protobuf::Empty, ::ledger::GetNetworkNameResponse>(
          std::mem_fn(&LedgerService::Service::GetNetworkName), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LedgerService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LedgerService::Service, ::google::protobuf::Empty, ::ledger::GetVersionResponse>(
          std::mem_fn(&LedgerService::Service::GetVersion), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LedgerService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LedgerService::Service, ::google::protobuf::Empty, ::ledger::GetSubversionResponse>(
          std::mem_fn(&LedgerService::Service::GetSubversion), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LedgerService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LedgerService::Service, ::google::protobuf::Empty, ::ledger::GetCoinNameResponse>(
          std::mem_fn(&LedgerService::Service::GetCoinName), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LedgerService_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LedgerService::Service, ::google::protobuf::Empty, ::ledger::GetChainInfoResponse>(
          std::mem_fn(&LedgerService::Service::GetChainInfo), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LedgerService_method_names[6],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LedgerService::Service, ::google::protobuf::Empty, ::ledger::GetBestBlockHashResponse>(
          std::mem_fn(&LedgerService::Service::GetBestBlockHash), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LedgerService_method_names[7],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LedgerService::Service, ::google::protobuf::Empty, ::ledger::GetBestBlockHeightResponse>(
          std::mem_fn(&LedgerService::Service::GetBestBlockHeight), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LedgerService_method_names[8],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LedgerService::Service, ::ledger::GetBlockHashRequest, ::ledger::GetBlockHashResponse>(
          std::mem_fn(&LedgerService::Service::GetBlockHash), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LedgerService_method_names[9],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LedgerService::Service, ::ledger::GetBlockHeaderRequest, ::ledger::GetBlockHeaderResponse>(
          std::mem_fn(&LedgerService::Service::GetBlockHeader), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LedgerService_method_names[10],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LedgerService::Service, ::ledger::GetBlockRequest, ::ledger::GetBlockResponse>(
          std::mem_fn(&LedgerService::Service::GetBlock), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LedgerService_method_names[11],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LedgerService::Service, ::ledger::GetBlockInfoRequest, ::ledger::GetBlockInfoResponse>(
          std::mem_fn(&LedgerService::Service::GetBlockInfo), this)));
}

LedgerService::Service::~Service() {
}

::grpc::Status LedgerService::Service::IsTestnet(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::ledger::IsTestnetResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LedgerService::Service::GetNetworkName(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::ledger::GetNetworkNameResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LedgerService::Service::GetVersion(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::ledger::GetVersionResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LedgerService::Service::GetSubversion(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::ledger::GetSubversionResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LedgerService::Service::GetCoinName(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::ledger::GetCoinNameResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LedgerService::Service::GetChainInfo(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::ledger::GetChainInfoResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LedgerService::Service::GetBestBlockHash(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::ledger::GetBestBlockHashResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LedgerService::Service::GetBestBlockHeight(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::ledger::GetBestBlockHeightResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LedgerService::Service::GetBlockHash(::grpc::ServerContext* context, const ::ledger::GetBlockHashRequest* request, ::ledger::GetBlockHashResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LedgerService::Service::GetBlockHeader(::grpc::ServerContext* context, const ::ledger::GetBlockHeaderRequest* request, ::ledger::GetBlockHeaderResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LedgerService::Service::GetBlock(::grpc::ServerContext* context, const ::ledger::GetBlockRequest* request, ::ledger::GetBlockResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LedgerService::Service::GetBlockInfo(::grpc::ServerContext* context, const ::ledger::GetBlockInfoRequest* request, ::ledger::GetBlockInfoResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace ledger

