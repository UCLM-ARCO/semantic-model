// **********************************************************************
//
// Copyright (c) 2003-2009 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.3.1
// Generated from file `SemanticModel.ice'

#ifndef __SemanticModel_h__
#define __SemanticModel_h__

#include <Ice/LocalObjectF.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/Outgoing.h>
#include <Ice/Incoming.h>
#include <Ice/Direct.h>
#include <Ice/StreamF.h>
#include <Ice/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 303
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

namespace IceProxy
{

namespace SemanticModel
{

class EventMonitor;

class Device;

class Service;

}

}

namespace SemanticModel
{

class EventMonitor;
bool operator==(const EventMonitor&, const EventMonitor&);
bool operator<(const EventMonitor&, const EventMonitor&);

class Device;
bool operator==(const Device&, const Device&);
bool operator<(const Device&, const Device&);

class Service;
bool operator==(const Service&, const Service&);
bool operator<(const Service&, const Service&);

}

namespace IceInternal
{

::Ice::Object* upCast(::SemanticModel::EventMonitor*);
::IceProxy::Ice::Object* upCast(::IceProxy::SemanticModel::EventMonitor*);

::Ice::Object* upCast(::SemanticModel::Device*);
::IceProxy::Ice::Object* upCast(::IceProxy::SemanticModel::Device*);

::Ice::Object* upCast(::SemanticModel::Service*);
::IceProxy::Ice::Object* upCast(::IceProxy::SemanticModel::Service*);

}

namespace SemanticModel
{

typedef ::IceInternal::Handle< ::SemanticModel::EventMonitor> EventMonitorPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::SemanticModel::EventMonitor> EventMonitorPrx;

void __read(::IceInternal::BasicStream*, EventMonitorPrx&);
void __patch__EventMonitorPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::SemanticModel::Device> DevicePtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::SemanticModel::Device> DevicePrx;

void __read(::IceInternal::BasicStream*, DevicePrx&);
void __patch__DevicePtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::SemanticModel::Service> ServicePtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::SemanticModel::Service> ServicePrx;

void __read(::IceInternal::BasicStream*, ServicePrx&);
void __patch__ServicePtr(void*, ::Ice::ObjectPtr&);

}

namespace SemanticModel
{

typedef ::std::map< ::std::string, ::Ice::ObjectPtr> Properties;
void __writeProperties(::IceInternal::BasicStream*, const Properties&);
void __readProperties(::IceInternal::BasicStream*, Properties&);

struct Event
{
    ::SemanticModel::Properties theProperties;

    bool operator==(const Event&) const;
    bool operator<(const Event&) const;
    bool operator!=(const Event& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const Event& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const Event& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const Event& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

typedef ::std::vector< ::SemanticModel::Event> EventSeq;
void __writeEventSeq(::IceInternal::BasicStream*, const ::SemanticModel::Event*, const ::SemanticModel::Event*);
void __readEventSeq(::IceInternal::BasicStream*, EventSeq&);

}

namespace IceProxy
{

namespace SemanticModel
{

class EventMonitor : virtual public ::IceProxy::Ice::Object
{
public:

    void report(const ::SemanticModel::Event& e)
    {
        report(e, 0);
    }
    void report(const ::SemanticModel::Event& e, const ::Ice::Context& __ctx)
    {
        report(e, &__ctx);
    }
    
private:

    void report(const ::SemanticModel::Event&, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<EventMonitor> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<EventMonitor*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<EventMonitor*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class Device : virtual public ::IceProxy::Ice::Object
{
public:

    void deviceName(const ::std::string& name)
    {
        deviceName(name, 0);
    }
    void deviceName(const ::std::string& name, const ::Ice::Context& __ctx)
    {
        deviceName(name, &__ctx);
    }
    
private:

    void deviceName(const ::std::string&, const ::Ice::Context*);
    
public:

    void setProperties(const ::SemanticModel::Properties& spec)
    {
        setProperties(spec, 0);
    }
    void setProperties(const ::SemanticModel::Properties& spec, const ::Ice::Context& __ctx)
    {
        setProperties(spec, &__ctx);
    }
    
private:

    void setProperties(const ::SemanticModel::Properties&, const ::Ice::Context*);
    
public:

    ::SemanticModel::Properties getProperties()
    {
        return getProperties(0);
    }
    ::SemanticModel::Properties getProperties(const ::Ice::Context& __ctx)
    {
        return getProperties(&__ctx);
    }
    
private:

    ::SemanticModel::Properties getProperties(const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<Device> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Device> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Device*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<Device*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class Service : virtual public ::IceProxy::Ice::Object
{
public:

    ::SemanticModel::EventSeq performAction(const ::std::string& idAction, const ::Ice::ObjectPtr& thg)
    {
        return performAction(idAction, thg, 0);
    }
    ::SemanticModel::EventSeq performAction(const ::std::string& idAction, const ::Ice::ObjectPtr& thg, const ::Ice::Context& __ctx)
    {
        return performAction(idAction, thg, &__ctx);
    }
    
private:

    ::SemanticModel::EventSeq performAction(const ::std::string&, const ::Ice::ObjectPtr&, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<Service> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Service> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Service*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<Service*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

}

}

namespace IceDelegate
{

namespace SemanticModel
{

class EventMonitor : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void report(const ::SemanticModel::Event&, const ::Ice::Context*) = 0;
};

class Device : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void deviceName(const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setProperties(const ::SemanticModel::Properties&, const ::Ice::Context*) = 0;

    virtual ::SemanticModel::Properties getProperties(const ::Ice::Context*) = 0;
};

class Service : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::SemanticModel::EventSeq performAction(const ::std::string&, const ::Ice::ObjectPtr&, const ::Ice::Context*) = 0;
};

}

}

namespace IceDelegateM
{

namespace SemanticModel
{

class EventMonitor : virtual public ::IceDelegate::SemanticModel::EventMonitor,
                     virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void report(const ::SemanticModel::Event&, const ::Ice::Context*);
};

class Device : virtual public ::IceDelegate::SemanticModel::Device,
               virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void deviceName(const ::std::string&, const ::Ice::Context*);

    virtual void setProperties(const ::SemanticModel::Properties&, const ::Ice::Context*);

    virtual ::SemanticModel::Properties getProperties(const ::Ice::Context*);
};

class Service : virtual public ::IceDelegate::SemanticModel::Service,
                virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::SemanticModel::EventSeq performAction(const ::std::string&, const ::Ice::ObjectPtr&, const ::Ice::Context*);
};

}

}

namespace IceDelegateD
{

namespace SemanticModel
{

class EventMonitor : virtual public ::IceDelegate::SemanticModel::EventMonitor,
                     virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void report(const ::SemanticModel::Event&, const ::Ice::Context*);
};

class Device : virtual public ::IceDelegate::SemanticModel::Device,
               virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void deviceName(const ::std::string&, const ::Ice::Context*);

    virtual void setProperties(const ::SemanticModel::Properties&, const ::Ice::Context*);

    virtual ::SemanticModel::Properties getProperties(const ::Ice::Context*);
};

class Service : virtual public ::IceDelegate::SemanticModel::Service,
                virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::SemanticModel::EventSeq performAction(const ::std::string&, const ::Ice::ObjectPtr&, const ::Ice::Context*);
};

}

}

namespace SemanticModel
{

class EventMonitor : virtual public ::Ice::Object
{
public:

    typedef EventMonitorPrx ProxyType;
    typedef EventMonitorPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void report(const ::SemanticModel::Event&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___report(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class Device : virtual public ::Ice::Object
{
public:

    typedef DevicePrx ProxyType;
    typedef DevicePtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void deviceName(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___deviceName(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setProperties(const ::SemanticModel::Properties&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setProperties(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::SemanticModel::Properties getProperties(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getProperties(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class Service : virtual public ::Ice::Object
{
public:

    typedef ServicePrx ProxyType;
    typedef ServicePtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::SemanticModel::EventSeq performAction(const ::std::string&, const ::Ice::ObjectPtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___performAction(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

}

#endif
