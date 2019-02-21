// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: google/api/expr/v1alpha1/conformance_service.proto
// Original file comments:
// Copyright 2018 Google LLC.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//
#ifndef GRPC_google_2fapi_2fexpr_2fv1alpha1_2fconformance_5fservice_2eproto__INCLUDED
#define GRPC_google_2fapi_2fexpr_2fv1alpha1_2fconformance_5fservice_2eproto__INCLUDED

#include "google/api/expr/v1alpha1/conformance_service.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace google {
namespace api {
namespace expr {
namespace v1alpha1 {

// Access a CEL implementation from another process or machine.
// A CEL implementation is decomposed as a parser, a static checker,
// and an evaluator.  Every CEL implementation is expected to provide
// a server for this API.  The API will be used for conformance testing
// and other utilities.
class ConformanceService final {
 public:
  static constexpr char const* service_full_name() {
    return "google.api.expr.v1alpha1.ConformanceService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // Transforms CEL source text into a parsed representation.
    virtual ::grpc::Status Parse(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::ParseRequest& request, ::google::api::expr::v1alpha1::ParseResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::ParseResponse>> AsyncParse(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::ParseRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::ParseResponse>>(AsyncParseRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::ParseResponse>> PrepareAsyncParse(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::ParseRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::ParseResponse>>(PrepareAsyncParseRaw(context, request, cq));
    }
    // Runs static checks on a parsed CEL representation and return
    // an annotated representation, or a set of issues.
    virtual ::grpc::Status Check(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::CheckRequest& request, ::google::api::expr::v1alpha1::CheckResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::CheckResponse>> AsyncCheck(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::CheckRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::CheckResponse>>(AsyncCheckRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::CheckResponse>> PrepareAsyncCheck(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::CheckRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::CheckResponse>>(PrepareAsyncCheckRaw(context, request, cq));
    }
    // Evaluates a parsed or annotation CEL representation given
    // values of external bindings.
    virtual ::grpc::Status Eval(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::EvalRequest& request, ::google::api::expr::v1alpha1::EvalResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::EvalResponse>> AsyncEval(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::EvalRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::EvalResponse>>(AsyncEvalRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::EvalResponse>> PrepareAsyncEval(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::EvalRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::EvalResponse>>(PrepareAsyncEvalRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      // Transforms CEL source text into a parsed representation.
      virtual void Parse(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::ParseRequest* request, ::google::api::expr::v1alpha1::ParseResponse* response, std::function<void(::grpc::Status)>) = 0;
      // Runs static checks on a parsed CEL representation and return
      // an annotated representation, or a set of issues.
      virtual void Check(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::CheckRequest* request, ::google::api::expr::v1alpha1::CheckResponse* response, std::function<void(::grpc::Status)>) = 0;
      // Evaluates a parsed or annotation CEL representation given
      // values of external bindings.
      virtual void Eval(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::EvalRequest* request, ::google::api::expr::v1alpha1::EvalResponse* response, std::function<void(::grpc::Status)>) = 0;
    };
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::ParseResponse>* AsyncParseRaw(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::ParseRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::ParseResponse>* PrepareAsyncParseRaw(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::ParseRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::CheckResponse>* AsyncCheckRaw(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::CheckRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::CheckResponse>* PrepareAsyncCheckRaw(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::CheckRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::EvalResponse>* AsyncEvalRaw(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::EvalRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::google::api::expr::v1alpha1::EvalResponse>* PrepareAsyncEvalRaw(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::EvalRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status Parse(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::ParseRequest& request, ::google::api::expr::v1alpha1::ParseResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::ParseResponse>> AsyncParse(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::ParseRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::ParseResponse>>(AsyncParseRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::ParseResponse>> PrepareAsyncParse(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::ParseRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::ParseResponse>>(PrepareAsyncParseRaw(context, request, cq));
    }
    ::grpc::Status Check(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::CheckRequest& request, ::google::api::expr::v1alpha1::CheckResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::CheckResponse>> AsyncCheck(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::CheckRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::CheckResponse>>(AsyncCheckRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::CheckResponse>> PrepareAsyncCheck(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::CheckRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::CheckResponse>>(PrepareAsyncCheckRaw(context, request, cq));
    }
    ::grpc::Status Eval(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::EvalRequest& request, ::google::api::expr::v1alpha1::EvalResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::EvalResponse>> AsyncEval(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::EvalRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::EvalResponse>>(AsyncEvalRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::EvalResponse>> PrepareAsyncEval(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::EvalRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::EvalResponse>>(PrepareAsyncEvalRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void Parse(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::ParseRequest* request, ::google::api::expr::v1alpha1::ParseResponse* response, std::function<void(::grpc::Status)>) override;
      void Check(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::CheckRequest* request, ::google::api::expr::v1alpha1::CheckResponse* response, std::function<void(::grpc::Status)>) override;
      void Eval(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::EvalRequest* request, ::google::api::expr::v1alpha1::EvalResponse* response, std::function<void(::grpc::Status)>) override;
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::ParseResponse>* AsyncParseRaw(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::ParseRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::ParseResponse>* PrepareAsyncParseRaw(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::ParseRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::CheckResponse>* AsyncCheckRaw(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::CheckRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::CheckResponse>* PrepareAsyncCheckRaw(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::CheckRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::EvalResponse>* AsyncEvalRaw(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::EvalRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::google::api::expr::v1alpha1::EvalResponse>* PrepareAsyncEvalRaw(::grpc::ClientContext* context, const ::google::api::expr::v1alpha1::EvalRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Parse_;
    const ::grpc::internal::RpcMethod rpcmethod_Check_;
    const ::grpc::internal::RpcMethod rpcmethod_Eval_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // Transforms CEL source text into a parsed representation.
    virtual ::grpc::Status Parse(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::ParseRequest* request, ::google::api::expr::v1alpha1::ParseResponse* response);
    // Runs static checks on a parsed CEL representation and return
    // an annotated representation, or a set of issues.
    virtual ::grpc::Status Check(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::CheckRequest* request, ::google::api::expr::v1alpha1::CheckResponse* response);
    // Evaluates a parsed or annotation CEL representation given
    // values of external bindings.
    virtual ::grpc::Status Eval(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::EvalRequest* request, ::google::api::expr::v1alpha1::EvalResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Parse : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Parse() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Parse() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Parse(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::ParseRequest* request, ::google::api::expr::v1alpha1::ParseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestParse(::grpc::ServerContext* context, ::google::api::expr::v1alpha1::ParseRequest* request, ::grpc::ServerAsyncResponseWriter< ::google::api::expr::v1alpha1::ParseResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_Check : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Check() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_Check() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Check(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::CheckRequest* request, ::google::api::expr::v1alpha1::CheckResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCheck(::grpc::ServerContext* context, ::google::api::expr::v1alpha1::CheckRequest* request, ::grpc::ServerAsyncResponseWriter< ::google::api::expr::v1alpha1::CheckResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_Eval : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Eval() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_Eval() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Eval(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::EvalRequest* request, ::google::api::expr::v1alpha1::EvalResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestEval(::grpc::ServerContext* context, ::google::api::expr::v1alpha1::EvalRequest* request, ::grpc::ServerAsyncResponseWriter< ::google::api::expr::v1alpha1::EvalResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Parse<WithAsyncMethod_Check<WithAsyncMethod_Eval<Service > > > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Parse : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_Parse() {
      ::grpc::Service::experimental().MarkMethodCallback(0,
        new ::grpc::internal::CallbackUnaryHandler< ::google::api::expr::v1alpha1::ParseRequest, ::google::api::expr::v1alpha1::ParseResponse>(
          [this](::grpc::ServerContext* context,
                 const ::google::api::expr::v1alpha1::ParseRequest* request,
                 ::google::api::expr::v1alpha1::ParseResponse* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   return this->Parse(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithCallbackMethod_Parse() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Parse(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::ParseRequest* request, ::google::api::expr::v1alpha1::ParseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Parse(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::ParseRequest* request, ::google::api::expr::v1alpha1::ParseResponse* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Check : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_Check() {
      ::grpc::Service::experimental().MarkMethodCallback(1,
        new ::grpc::internal::CallbackUnaryHandler< ::google::api::expr::v1alpha1::CheckRequest, ::google::api::expr::v1alpha1::CheckResponse>(
          [this](::grpc::ServerContext* context,
                 const ::google::api::expr::v1alpha1::CheckRequest* request,
                 ::google::api::expr::v1alpha1::CheckResponse* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   return this->Check(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithCallbackMethod_Check() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Check(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::CheckRequest* request, ::google::api::expr::v1alpha1::CheckResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Check(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::CheckRequest* request, ::google::api::expr::v1alpha1::CheckResponse* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Eval : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_Eval() {
      ::grpc::Service::experimental().MarkMethodCallback(2,
        new ::grpc::internal::CallbackUnaryHandler< ::google::api::expr::v1alpha1::EvalRequest, ::google::api::expr::v1alpha1::EvalResponse>(
          [this](::grpc::ServerContext* context,
                 const ::google::api::expr::v1alpha1::EvalRequest* request,
                 ::google::api::expr::v1alpha1::EvalResponse* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   return this->Eval(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithCallbackMethod_Eval() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Eval(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::EvalRequest* request, ::google::api::expr::v1alpha1::EvalResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Eval(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::EvalRequest* request, ::google::api::expr::v1alpha1::EvalResponse* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  typedef ExperimentalWithCallbackMethod_Parse<ExperimentalWithCallbackMethod_Check<ExperimentalWithCallbackMethod_Eval<Service > > > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_Parse : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Parse() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Parse() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Parse(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::ParseRequest* request, ::google::api::expr::v1alpha1::ParseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_Check : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Check() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_Check() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Check(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::CheckRequest* request, ::google::api::expr::v1alpha1::CheckResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_Eval : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Eval() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_Eval() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Eval(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::EvalRequest* request, ::google::api::expr::v1alpha1::EvalResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Parse : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_Parse() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Parse() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Parse(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::ParseRequest* request, ::google::api::expr::v1alpha1::ParseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestParse(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_Check : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_Check() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_Check() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Check(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::CheckRequest* request, ::google::api::expr::v1alpha1::CheckResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCheck(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_Eval : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_Eval() {
      ::grpc::Service::MarkMethodRaw(2);
    }
    ~WithRawMethod_Eval() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Eval(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::EvalRequest* request, ::google::api::expr::v1alpha1::EvalResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestEval(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Parse : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_Parse() {
      ::grpc::Service::experimental().MarkMethodRawCallback(0,
        new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this](::grpc::ServerContext* context,
                 const ::grpc::ByteBuffer* request,
                 ::grpc::ByteBuffer* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->Parse(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithRawCallbackMethod_Parse() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Parse(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::ParseRequest* request, ::google::api::expr::v1alpha1::ParseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Parse(::grpc::ServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Check : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_Check() {
      ::grpc::Service::experimental().MarkMethodRawCallback(1,
        new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this](::grpc::ServerContext* context,
                 const ::grpc::ByteBuffer* request,
                 ::grpc::ByteBuffer* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->Check(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithRawCallbackMethod_Check() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Check(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::CheckRequest* request, ::google::api::expr::v1alpha1::CheckResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Check(::grpc::ServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Eval : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_Eval() {
      ::grpc::Service::experimental().MarkMethodRawCallback(2,
        new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this](::grpc::ServerContext* context,
                 const ::grpc::ByteBuffer* request,
                 ::grpc::ByteBuffer* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->Eval(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithRawCallbackMethod_Eval() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Eval(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::EvalRequest* request, ::google::api::expr::v1alpha1::EvalResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Eval(::grpc::ServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Parse : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_Parse() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::google::api::expr::v1alpha1::ParseRequest, ::google::api::expr::v1alpha1::ParseResponse>(std::bind(&WithStreamedUnaryMethod_Parse<BaseClass>::StreamedParse, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_Parse() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Parse(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::ParseRequest* request, ::google::api::expr::v1alpha1::ParseResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedParse(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::google::api::expr::v1alpha1::ParseRequest,::google::api::expr::v1alpha1::ParseResponse>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Check : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_Check() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler< ::google::api::expr::v1alpha1::CheckRequest, ::google::api::expr::v1alpha1::CheckResponse>(std::bind(&WithStreamedUnaryMethod_Check<BaseClass>::StreamedCheck, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_Check() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Check(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::CheckRequest* request, ::google::api::expr::v1alpha1::CheckResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedCheck(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::google::api::expr::v1alpha1::CheckRequest,::google::api::expr::v1alpha1::CheckResponse>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Eval : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_Eval() {
      ::grpc::Service::MarkMethodStreamed(2,
        new ::grpc::internal::StreamedUnaryHandler< ::google::api::expr::v1alpha1::EvalRequest, ::google::api::expr::v1alpha1::EvalResponse>(std::bind(&WithStreamedUnaryMethod_Eval<BaseClass>::StreamedEval, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_Eval() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Eval(::grpc::ServerContext* context, const ::google::api::expr::v1alpha1::EvalRequest* request, ::google::api::expr::v1alpha1::EvalResponse* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedEval(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::google::api::expr::v1alpha1::EvalRequest,::google::api::expr::v1alpha1::EvalResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_Parse<WithStreamedUnaryMethod_Check<WithStreamedUnaryMethod_Eval<Service > > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_Parse<WithStreamedUnaryMethod_Check<WithStreamedUnaryMethod_Eval<Service > > > StreamedService;
};

}  // namespace v1alpha1
}  // namespace expr
}  // namespace api
}  // namespace google


#endif  // GRPC_google_2fapi_2fexpr_2fv1alpha1_2fconformance_5fservice_2eproto__INCLUDED
