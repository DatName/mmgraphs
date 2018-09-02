// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messages_config.proto

#ifndef PROTOBUF_INCLUDED_messages_5fconfig_2eproto
#define PROTOBUF_INCLUDED_messages_5fconfig_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "messages_generic.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_messages_5fconfig_2eproto 

namespace protobuf_messages_5fconfig_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[3];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_messages_5fconfig_2eproto
namespace models {
class ConfigRequest;
class ConfigRequestDefaultTypeInternal;
extern ConfigRequestDefaultTypeInternal _ConfigRequest_default_instance_;
class ConfigRequest_ConfigRequestBody;
class ConfigRequest_ConfigRequestBodyDefaultTypeInternal;
extern ConfigRequest_ConfigRequestBodyDefaultTypeInternal _ConfigRequest_ConfigRequestBody_default_instance_;
class ConfigResponse;
class ConfigResponseDefaultTypeInternal;
extern ConfigResponseDefaultTypeInternal _ConfigResponse_default_instance_;
}  // namespace models
namespace google {
namespace protobuf {
template<> ::models::ConfigRequest* Arena::CreateMaybeMessage<::models::ConfigRequest>(Arena*);
template<> ::models::ConfigRequest_ConfigRequestBody* Arena::CreateMaybeMessage<::models::ConfigRequest_ConfigRequestBody>(Arena*);
template<> ::models::ConfigResponse* Arena::CreateMaybeMessage<::models::ConfigResponse>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace models {

// ===================================================================

class ConfigRequest_ConfigRequestBody : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:models.ConfigRequest.ConfigRequestBody) */ {
 public:
  ConfigRequest_ConfigRequestBody();
  virtual ~ConfigRequest_ConfigRequestBody();

  ConfigRequest_ConfigRequestBody(const ConfigRequest_ConfigRequestBody& from);

  inline ConfigRequest_ConfigRequestBody& operator=(const ConfigRequest_ConfigRequestBody& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ConfigRequest_ConfigRequestBody(ConfigRequest_ConfigRequestBody&& from) noexcept
    : ConfigRequest_ConfigRequestBody() {
    *this = ::std::move(from);
  }

  inline ConfigRequest_ConfigRequestBody& operator=(ConfigRequest_ConfigRequestBody&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ConfigRequest_ConfigRequestBody& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ConfigRequest_ConfigRequestBody* internal_default_instance() {
    return reinterpret_cast<const ConfigRequest_ConfigRequestBody*>(
               &_ConfigRequest_ConfigRequestBody_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(ConfigRequest_ConfigRequestBody* other);
  friend void swap(ConfigRequest_ConfigRequestBody& a, ConfigRequest_ConfigRequestBody& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ConfigRequest_ConfigRequestBody* New() const final {
    return CreateMaybeMessage<ConfigRequest_ConfigRequestBody>(NULL);
  }

  ConfigRequest_ConfigRequestBody* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ConfigRequest_ConfigRequestBody>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ConfigRequest_ConfigRequestBody& from);
  void MergeFrom(const ConfigRequest_ConfigRequestBody& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ConfigRequest_ConfigRequestBody* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string Name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // @@protoc_insertion_point(class_scope:models.ConfigRequest.ConfigRequestBody)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_messages_5fconfig_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class ConfigRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:models.ConfigRequest) */ {
 public:
  ConfigRequest();
  virtual ~ConfigRequest();

  ConfigRequest(const ConfigRequest& from);

  inline ConfigRequest& operator=(const ConfigRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ConfigRequest(ConfigRequest&& from) noexcept
    : ConfigRequest() {
    *this = ::std::move(from);
  }

  inline ConfigRequest& operator=(ConfigRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ConfigRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ConfigRequest* internal_default_instance() {
    return reinterpret_cast<const ConfigRequest*>(
               &_ConfigRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(ConfigRequest* other);
  friend void swap(ConfigRequest& a, ConfigRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ConfigRequest* New() const final {
    return CreateMaybeMessage<ConfigRequest>(NULL);
  }

  ConfigRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ConfigRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ConfigRequest& from);
  void MergeFrom(const ConfigRequest& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ConfigRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef ConfigRequest_ConfigRequestBody ConfigRequestBody;

  // accessors -------------------------------------------------------

  // .models.MessageHeader Header = 1;
  bool has_header() const;
  void clear_header();
  static const int kHeaderFieldNumber = 1;
  private:
  const ::models::MessageHeader& _internal_header() const;
  public:
  const ::models::MessageHeader& header() const;
  ::models::MessageHeader* release_header();
  ::models::MessageHeader* mutable_header();
  void set_allocated_header(::models::MessageHeader* header);

  // .models.ConfigRequest.ConfigRequestBody Body = 2;
  bool has_body() const;
  void clear_body();
  static const int kBodyFieldNumber = 2;
  private:
  const ::models::ConfigRequest_ConfigRequestBody& _internal_body() const;
  public:
  const ::models::ConfigRequest_ConfigRequestBody& body() const;
  ::models::ConfigRequest_ConfigRequestBody* release_body();
  ::models::ConfigRequest_ConfigRequestBody* mutable_body();
  void set_allocated_body(::models::ConfigRequest_ConfigRequestBody* body);

  // @@protoc_insertion_point(class_scope:models.ConfigRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::models::MessageHeader* header_;
  ::models::ConfigRequest_ConfigRequestBody* body_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_messages_5fconfig_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class ConfigResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:models.ConfigResponse) */ {
 public:
  ConfigResponse();
  virtual ~ConfigResponse();

  ConfigResponse(const ConfigResponse& from);

  inline ConfigResponse& operator=(const ConfigResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ConfigResponse(ConfigResponse&& from) noexcept
    : ConfigResponse() {
    *this = ::std::move(from);
  }

  inline ConfigResponse& operator=(ConfigResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ConfigResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ConfigResponse* internal_default_instance() {
    return reinterpret_cast<const ConfigResponse*>(
               &_ConfigResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(ConfigResponse* other);
  friend void swap(ConfigResponse& a, ConfigResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ConfigResponse* New() const final {
    return CreateMaybeMessage<ConfigResponse>(NULL);
  }

  ConfigResponse* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ConfigResponse>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ConfigResponse& from);
  void MergeFrom(const ConfigResponse& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ConfigResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string Body = 2;
  void clear_body();
  static const int kBodyFieldNumber = 2;
  const ::std::string& body() const;
  void set_body(const ::std::string& value);
  #if LANG_CXX11
  void set_body(::std::string&& value);
  #endif
  void set_body(const char* value);
  void set_body(const char* value, size_t size);
  ::std::string* mutable_body();
  ::std::string* release_body();
  void set_allocated_body(::std::string* body);

  // .models.MessageHeader Header = 1;
  bool has_header() const;
  void clear_header();
  static const int kHeaderFieldNumber = 1;
  private:
  const ::models::MessageHeader& _internal_header() const;
  public:
  const ::models::MessageHeader& header() const;
  ::models::MessageHeader* release_header();
  ::models::MessageHeader* mutable_header();
  void set_allocated_header(::models::MessageHeader* header);

  // @@protoc_insertion_point(class_scope:models.ConfigResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr body_;
  ::models::MessageHeader* header_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_messages_5fconfig_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ConfigRequest_ConfigRequestBody

// string Name = 1;
inline void ConfigRequest_ConfigRequestBody::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ConfigRequest_ConfigRequestBody::name() const {
  // @@protoc_insertion_point(field_get:models.ConfigRequest.ConfigRequestBody.Name)
  return name_.GetNoArena();
}
inline void ConfigRequest_ConfigRequestBody::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:models.ConfigRequest.ConfigRequestBody.Name)
}
#if LANG_CXX11
inline void ConfigRequest_ConfigRequestBody::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:models.ConfigRequest.ConfigRequestBody.Name)
}
#endif
inline void ConfigRequest_ConfigRequestBody::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:models.ConfigRequest.ConfigRequestBody.Name)
}
inline void ConfigRequest_ConfigRequestBody::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:models.ConfigRequest.ConfigRequestBody.Name)
}
inline ::std::string* ConfigRequest_ConfigRequestBody::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:models.ConfigRequest.ConfigRequestBody.Name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ConfigRequest_ConfigRequestBody::release_name() {
  // @@protoc_insertion_point(field_release:models.ConfigRequest.ConfigRequestBody.Name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ConfigRequest_ConfigRequestBody::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:models.ConfigRequest.ConfigRequestBody.Name)
}

// -------------------------------------------------------------------

// ConfigRequest

// .models.MessageHeader Header = 1;
inline bool ConfigRequest::has_header() const {
  return this != internal_default_instance() && header_ != NULL;
}
inline const ::models::MessageHeader& ConfigRequest::_internal_header() const {
  return *header_;
}
inline const ::models::MessageHeader& ConfigRequest::header() const {
  const ::models::MessageHeader* p = header_;
  // @@protoc_insertion_point(field_get:models.ConfigRequest.Header)
  return p != NULL ? *p : *reinterpret_cast<const ::models::MessageHeader*>(
      &::models::_MessageHeader_default_instance_);
}
inline ::models::MessageHeader* ConfigRequest::release_header() {
  // @@protoc_insertion_point(field_release:models.ConfigRequest.Header)
  
  ::models::MessageHeader* temp = header_;
  header_ = NULL;
  return temp;
}
inline ::models::MessageHeader* ConfigRequest::mutable_header() {
  
  if (header_ == NULL) {
    auto* p = CreateMaybeMessage<::models::MessageHeader>(GetArenaNoVirtual());
    header_ = p;
  }
  // @@protoc_insertion_point(field_mutable:models.ConfigRequest.Header)
  return header_;
}
inline void ConfigRequest::set_allocated_header(::models::MessageHeader* header) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(header_);
  }
  if (header) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      header = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, header, submessage_arena);
    }
    
  } else {
    
  }
  header_ = header;
  // @@protoc_insertion_point(field_set_allocated:models.ConfigRequest.Header)
}

// .models.ConfigRequest.ConfigRequestBody Body = 2;
inline bool ConfigRequest::has_body() const {
  return this != internal_default_instance() && body_ != NULL;
}
inline void ConfigRequest::clear_body() {
  if (GetArenaNoVirtual() == NULL && body_ != NULL) {
    delete body_;
  }
  body_ = NULL;
}
inline const ::models::ConfigRequest_ConfigRequestBody& ConfigRequest::_internal_body() const {
  return *body_;
}
inline const ::models::ConfigRequest_ConfigRequestBody& ConfigRequest::body() const {
  const ::models::ConfigRequest_ConfigRequestBody* p = body_;
  // @@protoc_insertion_point(field_get:models.ConfigRequest.Body)
  return p != NULL ? *p : *reinterpret_cast<const ::models::ConfigRequest_ConfigRequestBody*>(
      &::models::_ConfigRequest_ConfigRequestBody_default_instance_);
}
inline ::models::ConfigRequest_ConfigRequestBody* ConfigRequest::release_body() {
  // @@protoc_insertion_point(field_release:models.ConfigRequest.Body)
  
  ::models::ConfigRequest_ConfigRequestBody* temp = body_;
  body_ = NULL;
  return temp;
}
inline ::models::ConfigRequest_ConfigRequestBody* ConfigRequest::mutable_body() {
  
  if (body_ == NULL) {
    auto* p = CreateMaybeMessage<::models::ConfigRequest_ConfigRequestBody>(GetArenaNoVirtual());
    body_ = p;
  }
  // @@protoc_insertion_point(field_mutable:models.ConfigRequest.Body)
  return body_;
}
inline void ConfigRequest::set_allocated_body(::models::ConfigRequest_ConfigRequestBody* body) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete body_;
  }
  if (body) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      body = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, body, submessage_arena);
    }
    
  } else {
    
  }
  body_ = body;
  // @@protoc_insertion_point(field_set_allocated:models.ConfigRequest.Body)
}

// -------------------------------------------------------------------

// ConfigResponse

// .models.MessageHeader Header = 1;
inline bool ConfigResponse::has_header() const {
  return this != internal_default_instance() && header_ != NULL;
}
inline const ::models::MessageHeader& ConfigResponse::_internal_header() const {
  return *header_;
}
inline const ::models::MessageHeader& ConfigResponse::header() const {
  const ::models::MessageHeader* p = header_;
  // @@protoc_insertion_point(field_get:models.ConfigResponse.Header)
  return p != NULL ? *p : *reinterpret_cast<const ::models::MessageHeader*>(
      &::models::_MessageHeader_default_instance_);
}
inline ::models::MessageHeader* ConfigResponse::release_header() {
  // @@protoc_insertion_point(field_release:models.ConfigResponse.Header)
  
  ::models::MessageHeader* temp = header_;
  header_ = NULL;
  return temp;
}
inline ::models::MessageHeader* ConfigResponse::mutable_header() {
  
  if (header_ == NULL) {
    auto* p = CreateMaybeMessage<::models::MessageHeader>(GetArenaNoVirtual());
    header_ = p;
  }
  // @@protoc_insertion_point(field_mutable:models.ConfigResponse.Header)
  return header_;
}
inline void ConfigResponse::set_allocated_header(::models::MessageHeader* header) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(header_);
  }
  if (header) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      header = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, header, submessage_arena);
    }
    
  } else {
    
  }
  header_ = header;
  // @@protoc_insertion_point(field_set_allocated:models.ConfigResponse.Header)
}

// string Body = 2;
inline void ConfigResponse::clear_body() {
  body_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ConfigResponse::body() const {
  // @@protoc_insertion_point(field_get:models.ConfigResponse.Body)
  return body_.GetNoArena();
}
inline void ConfigResponse::set_body(const ::std::string& value) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:models.ConfigResponse.Body)
}
#if LANG_CXX11
inline void ConfigResponse::set_body(::std::string&& value) {
  
  body_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:models.ConfigResponse.Body)
}
#endif
inline void ConfigResponse::set_body(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:models.ConfigResponse.Body)
}
inline void ConfigResponse::set_body(const char* value, size_t size) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:models.ConfigResponse.Body)
}
inline ::std::string* ConfigResponse::mutable_body() {
  
  // @@protoc_insertion_point(field_mutable:models.ConfigResponse.Body)
  return body_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ConfigResponse::release_body() {
  // @@protoc_insertion_point(field_release:models.ConfigResponse.Body)
  
  return body_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ConfigResponse::set_allocated_body(::std::string* body) {
  if (body != NULL) {
    
  } else {
    
  }
  body_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), body);
  // @@protoc_insertion_point(field_set_allocated:models.ConfigResponse.Body)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace models

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_messages_5fconfig_2eproto
