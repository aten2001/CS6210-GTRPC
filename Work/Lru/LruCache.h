/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef LruCache_H
#define LruCache_H

#include <thrift/TDispatchProcessor.h>
#include "lru_types.h"

namespace Lru {

class LruCacheIf {
 public:
  virtual ~LruCacheIf() {}
  virtual void getURL(std::string& _return, const std::string& url) = 0;
};

class LruCacheIfFactory {
 public:
  typedef LruCacheIf Handler;

  virtual ~LruCacheIfFactory() {}

  virtual LruCacheIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(LruCacheIf* /* handler */) = 0;
};

class LruCacheIfSingletonFactory : virtual public LruCacheIfFactory {
 public:
  LruCacheIfSingletonFactory(const boost::shared_ptr<LruCacheIf>& iface) : iface_(iface) {}
  virtual ~LruCacheIfSingletonFactory() {}

  virtual LruCacheIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(LruCacheIf* /* handler */) {}

 protected:
  boost::shared_ptr<LruCacheIf> iface_;
};

class LruCacheNull : virtual public LruCacheIf {
 public:
  virtual ~LruCacheNull() {}
  void getURL(std::string& /* _return */, const std::string& /* url */) {
    return;
  }
};

typedef struct _LruCache_getURL_args__isset {
  _LruCache_getURL_args__isset() : url(false) {}
  bool url;
} _LruCache_getURL_args__isset;

class LruCache_getURL_args {
 public:

  LruCache_getURL_args() : url() {
  }

  virtual ~LruCache_getURL_args() throw() {}

  std::string url;

  _LruCache_getURL_args__isset __isset;

  void __set_url(const std::string& val) {
    url = val;
  }

  bool operator == (const LruCache_getURL_args & rhs) const
  {
    if (!(url == rhs.url))
      return false;
    return true;
  }
  bool operator != (const LruCache_getURL_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LruCache_getURL_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LruCache_getURL_pargs {
 public:


  virtual ~LruCache_getURL_pargs() throw() {}

  const std::string* url;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LruCache_getURL_result__isset {
  _LruCache_getURL_result__isset() : success(false) {}
  bool success;
} _LruCache_getURL_result__isset;

class LruCache_getURL_result {
 public:

  LruCache_getURL_result() : success() {
  }

  virtual ~LruCache_getURL_result() throw() {}

  std::string success;

  _LruCache_getURL_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const LruCache_getURL_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const LruCache_getURL_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LruCache_getURL_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LruCache_getURL_presult__isset {
  _LruCache_getURL_presult__isset() : success(false) {}
  bool success;
} _LruCache_getURL_presult__isset;

class LruCache_getURL_presult {
 public:


  virtual ~LruCache_getURL_presult() throw() {}

  std::string* success;

  _LruCache_getURL_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class LruCacheClient : virtual public LruCacheIf {
 public:
  LruCacheClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  LruCacheClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getURL(std::string& _return, const std::string& url);
  void send_getURL(const std::string& url);
  void recv_getURL(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class LruCacheProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<LruCacheIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (LruCacheProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getURL(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  LruCacheProcessor(boost::shared_ptr<LruCacheIf> iface) :
    iface_(iface) {
    processMap_["getURL"] = &LruCacheProcessor::process_getURL;
  }

  virtual ~LruCacheProcessor() {}
};

class LruCacheProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  LruCacheProcessorFactory(const ::boost::shared_ptr< LruCacheIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< LruCacheIfFactory > handlerFactory_;
};

class LruCacheMultiface : virtual public LruCacheIf {
 public:
  LruCacheMultiface(std::vector<boost::shared_ptr<LruCacheIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~LruCacheMultiface() {}
 protected:
  std::vector<boost::shared_ptr<LruCacheIf> > ifaces_;
  LruCacheMultiface() {}
  void add(boost::shared_ptr<LruCacheIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void getURL(std::string& _return, const std::string& url) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getURL(_return, url);
    }
    ifaces_[i]->getURL(_return, url);
    return;
  }

};

} // namespace

#endif
