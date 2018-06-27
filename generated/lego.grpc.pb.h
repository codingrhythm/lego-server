// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: lego.proto
#ifndef GRPC_lego_2eproto__INCLUDED
#define GRPC_lego_2eproto__INCLUDED

#include "lego.pb.h"

#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
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

namespace lego {

class Lego final {
 public:
  static constexpr char const* service_full_name() {
    return "lego.Lego";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status SendRecord(::grpc::ClientContext* context, const ::lego::LegoRecord& request, ::lego::LegoResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::lego::LegoResponse>> AsyncSendRecord(::grpc::ClientContext* context, const ::lego::LegoRecord& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::lego::LegoResponse>>(AsyncSendRecordRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::lego::LegoResponse>> PrepareAsyncSendRecord(::grpc::ClientContext* context, const ::lego::LegoRecord& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::lego::LegoResponse>>(PrepareAsyncSendRecordRaw(context, request, cq));
    }
    virtual ::grpc::Status GetData(::grpc::ClientContext* context, const ::lego::GetRequest& request, ::lego::Template* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::lego::Template>> AsyncGetData(::grpc::ClientContext* context, const ::lego::GetRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::lego::Template>>(AsyncGetDataRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::lego::Template>> PrepareAsyncGetData(::grpc::ClientContext* context, const ::lego::GetRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::lego::Template>>(PrepareAsyncGetDataRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::lego::LegoResponse>* AsyncSendRecordRaw(::grpc::ClientContext* context, const ::lego::LegoRecord& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::lego::LegoResponse>* PrepareAsyncSendRecordRaw(::grpc::ClientContext* context, const ::lego::LegoRecord& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::lego::Template>* AsyncGetDataRaw(::grpc::ClientContext* context, const ::lego::GetRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::lego::Template>* PrepareAsyncGetDataRaw(::grpc::ClientContext* context, const ::lego::GetRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status SendRecord(::grpc::ClientContext* context, const ::lego::LegoRecord& request, ::lego::LegoResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::lego::LegoResponse>> AsyncSendRecord(::grpc::ClientContext* context, const ::lego::LegoRecord& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::lego::LegoResponse>>(AsyncSendRecordRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::lego::LegoResponse>> PrepareAsyncSendRecord(::grpc::ClientContext* context, const ::lego::LegoRecord& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::lego::LegoResponse>>(PrepareAsyncSendRecordRaw(context, request, cq));
    }
    ::grpc::Status GetData(::grpc::ClientContext* context, const ::lego::GetRequest& request, ::lego::Template* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::lego::Template>> AsyncGetData(::grpc::ClientContext* context, const ::lego::GetRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::lego::Template>>(AsyncGetDataRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::lego::Template>> PrepareAsyncGetData(::grpc::ClientContext* context, const ::lego::GetRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::lego::Template>>(PrepareAsyncGetDataRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< ::lego::LegoResponse>* AsyncSendRecordRaw(::grpc::ClientContext* context, const ::lego::LegoRecord& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::lego::LegoResponse>* PrepareAsyncSendRecordRaw(::grpc::ClientContext* context, const ::lego::LegoRecord& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::lego::Template>* AsyncGetDataRaw(::grpc::ClientContext* context, const ::lego::GetRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::lego::Template>* PrepareAsyncGetDataRaw(::grpc::ClientContext* context, const ::lego::GetRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_SendRecord_;
    const ::grpc::internal::RpcMethod rpcmethod_GetData_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status SendRecord(::grpc::ServerContext* context, const ::lego::LegoRecord* request, ::lego::LegoResponse* response);
    virtual ::grpc::Status GetData(::grpc::ServerContext* context, const ::lego::GetRequest* request, ::lego::Template* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_SendRecord : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_SendRecord() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_SendRecord() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendRecord(::grpc::ServerContext* context, const ::lego::LegoRecord* request, ::lego::LegoResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendRecord(::grpc::ServerContext* context, ::lego::LegoRecord* request, ::grpc::ServerAsyncResponseWriter< ::lego::LegoResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_GetData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_GetData() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_GetData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetData(::grpc::ServerContext* context, const ::lego::GetRequest* request, ::lego::Template* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetData(::grpc::ServerContext* context, ::lego::GetRequest* request, ::grpc::ServerAsyncResponseWriter< ::lego::Template>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_SendRecord<WithAsyncMethod_GetData<Service > > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_SendRecord : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_SendRecord() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_SendRecord() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendRecord(::grpc::ServerContext* context, const ::lego::LegoRecord* request, ::lego::LegoResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_GetData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_GetData() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_GetData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetData(::grpc::ServerContext* context, const ::lego::GetRequest* request, ::lego::Template* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_SendRecord : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_SendRecord() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::lego::LegoRecord, ::lego::LegoResponse>(std::bind(&WithStreamedUnaryMethod_SendRecord<BaseClass>::StreamedSendRecord, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_SendRecord() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status SendRecord(::grpc::ServerContext* context, const ::lego::LegoRecord* request, ::lego::LegoResponse* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSendRecord(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::lego::LegoRecord,::lego::LegoResponse>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_GetData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_GetData() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler< ::lego::GetRequest, ::lego::Template>(std::bind(&WithStreamedUnaryMethod_GetData<BaseClass>::StreamedGetData, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_GetData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status GetData(::grpc::ServerContext* context, const ::lego::GetRequest* request, ::lego::Template* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedGetData(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::lego::GetRequest,::lego::Template>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_SendRecord<WithStreamedUnaryMethod_GetData<Service > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_SendRecord<WithStreamedUnaryMethod_GetData<Service > > StreamedService;
};

}  // namespace lego


#endif  // GRPC_lego_2eproto__INCLUDED
