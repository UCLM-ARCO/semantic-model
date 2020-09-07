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

#include <SemanticModel.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
#include <IceUtil/Iterator.h>
#include <IceUtil/ScopedArray.h>

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

static const ::std::string __SemanticModel__EventMonitor__report_name = "report";

static const ::std::string __SemanticModel__Device__deviceName_name = "deviceName";

static const ::std::string __SemanticModel__Device__setProperties_name = "setProperties";

static const ::std::string __SemanticModel__Device__getProperties_name = "getProperties";

static const ::std::string __SemanticModel__Service__performAction_name = "performAction";

::Ice::Object* IceInternal::upCast(::SemanticModel::EventMonitor* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::SemanticModel::EventMonitor* p) { return p; }

::Ice::Object* IceInternal::upCast(::SemanticModel::Device* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::SemanticModel::Device* p) { return p; }

::Ice::Object* IceInternal::upCast(::SemanticModel::Service* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::SemanticModel::Service* p) { return p; }

void
SemanticModel::__read(::IceInternal::BasicStream* __is, ::SemanticModel::EventMonitorPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::SemanticModel::EventMonitor;
        v->__copyFrom(proxy);
    }
}

void
SemanticModel::__read(::IceInternal::BasicStream* __is, ::SemanticModel::DevicePrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::SemanticModel::Device;
        v->__copyFrom(proxy);
    }
}

void
SemanticModel::__read(::IceInternal::BasicStream* __is, ::SemanticModel::ServicePrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::SemanticModel::Service;
        v->__copyFrom(proxy);
    }
}

void
SemanticModel::__writeProperties(::IceInternal::BasicStream* __os, const ::SemanticModel::Properties& v)
{
    __os->writeSize(::Ice::Int(v.size()));
    ::SemanticModel::Properties::const_iterator p;
    for(p = v.begin(); p != v.end(); ++p)
    {
        __os->write(p->first);
        __os->write(p->second);
    }
}

void
SemanticModel::__readProperties(::IceInternal::BasicStream* __is, ::SemanticModel::Properties& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    while(sz--)
    {
        ::std::pair<const  ::std::string, ::Ice::ObjectPtr> pair;
        __is->read(const_cast< ::std::string&>(pair.first));
        ::SemanticModel::Properties::iterator __i = v.insert(v.end(), pair);
        __is->read(::Ice::__patch__ObjectPtr, &__i->second);
    }
}

bool
SemanticModel::Event::operator==(const Event& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(theProperties != __rhs.theProperties)
    {
        return false;
    }
    return true;
}

bool
SemanticModel::Event::operator<(const Event& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(theProperties < __rhs.theProperties)
    {
        return true;
    }
    else if(__rhs.theProperties < theProperties)
    {
        return false;
    }
    return false;
}

void
SemanticModel::Event::__write(::IceInternal::BasicStream* __os) const
{
    ::SemanticModel::__writeProperties(__os, theProperties);
}

void
SemanticModel::Event::__read(::IceInternal::BasicStream* __is)
{
    ::SemanticModel::__readProperties(__is, theProperties);
}

void
SemanticModel::__writeEventSeq(::IceInternal::BasicStream* __os, const ::SemanticModel::Event* begin, const ::SemanticModel::Event* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        begin[i].__write(__os);
    }
}

void
SemanticModel::__readEventSeq(::IceInternal::BasicStream* __is, ::SemanticModel::EventSeq& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 1);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        v[i].__read(__is);
        __is->checkSeq();
        __is->endElement();
    }
    __is->endSeq(sz);
}

void
IceProxy::SemanticModel::EventMonitor::report(const ::SemanticModel::Event& e, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __delBase = __getDelegate(false);
            ::IceDelegate::SemanticModel::EventMonitor* __del = dynamic_cast< ::IceDelegate::SemanticModel::EventMonitor*>(__delBase.get());
            __del->report(e, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

const ::std::string&
IceProxy::SemanticModel::EventMonitor::ice_staticId()
{
    return ::SemanticModel::EventMonitor::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::SemanticModel::EventMonitor::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::SemanticModel::EventMonitor);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::SemanticModel::EventMonitor::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::SemanticModel::EventMonitor);
}

::IceProxy::Ice::Object*
IceProxy::SemanticModel::EventMonitor::__newInstance() const
{
    return new EventMonitor;
}

void
IceProxy::SemanticModel::Device::deviceName(const ::std::string& name, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __delBase = __getDelegate(false);
            ::IceDelegate::SemanticModel::Device* __del = dynamic_cast< ::IceDelegate::SemanticModel::Device*>(__delBase.get());
            __del->deviceName(name, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::SemanticModel::Device::setProperties(const ::SemanticModel::Properties& spec, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __delBase = __getDelegate(false);
            ::IceDelegate::SemanticModel::Device* __del = dynamic_cast< ::IceDelegate::SemanticModel::Device*>(__delBase.get());
            __del->setProperties(spec, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::SemanticModel::Properties
IceProxy::SemanticModel::Device::getProperties(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __checkTwowayOnly(__SemanticModel__Device__getProperties_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::SemanticModel::Device* __del = dynamic_cast< ::IceDelegate::SemanticModel::Device*>(__delBase.get());
            return __del->getProperties(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

const ::std::string&
IceProxy::SemanticModel::Device::ice_staticId()
{
    return ::SemanticModel::Device::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::SemanticModel::Device::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::SemanticModel::Device);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::SemanticModel::Device::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::SemanticModel::Device);
}

::IceProxy::Ice::Object*
IceProxy::SemanticModel::Device::__newInstance() const
{
    return new Device;
}

::SemanticModel::EventSeq
IceProxy::SemanticModel::Service::performAction(const ::std::string& idAction, const ::Ice::ObjectPtr& thg, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
#if defined(__BCPLUSPLUS__) && (__BCPLUSPLUS__ >= 0x0600) // C++Builder 2009 compiler bug
            IceUtil::DummyBCC dummy;
#endif
            __checkTwowayOnly(__SemanticModel__Service__performAction_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::SemanticModel::Service* __del = dynamic_cast< ::IceDelegate::SemanticModel::Service*>(__delBase.get());
            return __del->performAction(idAction, thg, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

const ::std::string&
IceProxy::SemanticModel::Service::ice_staticId()
{
    return ::SemanticModel::Service::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::SemanticModel::Service::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::SemanticModel::Service);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::SemanticModel::Service::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::SemanticModel::Service);
}

::IceProxy::Ice::Object*
IceProxy::SemanticModel::Service::__newInstance() const
{
    return new Service;
}

void
IceDelegateM::SemanticModel::EventMonitor::report(const ::SemanticModel::Event& e, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __SemanticModel__EventMonitor__report_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        e.__write(__os);
        __os->writePendingObjects();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::SemanticModel::Device::deviceName(const ::std::string& name, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __SemanticModel__Device__deviceName_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(name);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::SemanticModel::Device::setProperties(const ::SemanticModel::Properties& spec, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __SemanticModel__Device__setProperties_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        ::SemanticModel::__writeProperties(__os, spec);
        __os->writePendingObjects();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

::SemanticModel::Properties
IceDelegateM::SemanticModel::Device::getProperties(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __SemanticModel__Device__getProperties_name, ::Ice::Normal, __context);
    bool __ok = __og.invoke();
    ::SemanticModel::Properties __ret;
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::SemanticModel::__readProperties(__is, __ret);
        __is->readPendingObjects();
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::SemanticModel::EventSeq
IceDelegateM::SemanticModel::Service::performAction(const ::std::string& idAction, const ::Ice::ObjectPtr& thg, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __SemanticModel__Service__performAction_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(idAction);
        __os->write(thg);
        __os->writePendingObjects();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    ::SemanticModel::EventSeq __ret;
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::SemanticModel::__readEventSeq(__is, __ret);
        __is->readPendingObjects();
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateD::SemanticModel::EventMonitor::report(const ::SemanticModel::Event& e, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::SemanticModel::Event& e, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_e(e)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::SemanticModel::EventMonitor* servant = dynamic_cast< ::SemanticModel::EventMonitor*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->report(_m_e, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::SemanticModel::Event& _m_e;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __SemanticModel__EventMonitor__report_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(e, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::SemanticModel::Device::deviceName(const ::std::string& name, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::std::string& name, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_name(name)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::SemanticModel::Device* servant = dynamic_cast< ::SemanticModel::Device*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->deviceName(_m_name, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::std::string& _m_name;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __SemanticModel__Device__deviceName_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(name, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::SemanticModel::Device::setProperties(const ::SemanticModel::Properties& spec, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::SemanticModel::Properties& spec, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_spec(spec)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::SemanticModel::Device* servant = dynamic_cast< ::SemanticModel::Device*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->setProperties(_m_spec, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::SemanticModel::Properties& _m_spec;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __SemanticModel__Device__setProperties_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(spec, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

::SemanticModel::Properties
IceDelegateD::SemanticModel::Device::getProperties(const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::SemanticModel::Properties& __result, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::SemanticModel::Device* servant = dynamic_cast< ::SemanticModel::Device*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->getProperties(_current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::SemanticModel::Properties& _result;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __SemanticModel__Device__getProperties_name, ::Ice::Normal, __context);
    ::SemanticModel::Properties __result;
    try
    {
        _DirectI __direct(__result, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::SemanticModel::EventSeq
IceDelegateD::SemanticModel::Service::performAction(const ::std::string& idAction, const ::Ice::ObjectPtr& thg, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::SemanticModel::EventSeq& __result, const ::std::string& idAction, const ::Ice::ObjectPtr& thg, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_idAction(idAction),
            _m_thg(thg)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::SemanticModel::Service* servant = dynamic_cast< ::SemanticModel::Service*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->performAction(_m_idAction, _m_thg, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::SemanticModel::EventSeq& _result;
        const ::std::string& _m_idAction;
        const ::Ice::ObjectPtr& _m_thg;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __SemanticModel__Service__performAction_name, ::Ice::Normal, __context);
    ::SemanticModel::EventSeq __result;
    try
    {
        _DirectI __direct(__result, idAction, thg, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::Ice::ObjectPtr
SemanticModel::EventMonitor::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __SemanticModel__EventMonitor_ids[2] =
{
    "::Ice::Object",
    "::SemanticModel::EventMonitor"
};

bool
SemanticModel::EventMonitor::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__SemanticModel__EventMonitor_ids, __SemanticModel__EventMonitor_ids + 2, _s);
}

::std::vector< ::std::string>
SemanticModel::EventMonitor::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__SemanticModel__EventMonitor_ids[0], &__SemanticModel__EventMonitor_ids[2]);
}

const ::std::string&
SemanticModel::EventMonitor::ice_id(const ::Ice::Current&) const
{
    return __SemanticModel__EventMonitor_ids[1];
}

const ::std::string&
SemanticModel::EventMonitor::ice_staticId()
{
    return __SemanticModel__EventMonitor_ids[1];
}

::Ice::DispatchStatus
SemanticModel::EventMonitor::___report(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::SemanticModel::Event e;
    e.__read(__is);
    __is->readPendingObjects();
    __is->endReadEncaps();
    report(e, __current);
    return ::Ice::DispatchOK;
}

static ::std::string __SemanticModel__EventMonitor_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "report"
};

::Ice::DispatchStatus
SemanticModel::EventMonitor::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__SemanticModel__EventMonitor_all, __SemanticModel__EventMonitor_all + 5, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __SemanticModel__EventMonitor_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___report(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
SemanticModel::EventMonitor::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
SemanticModel::EventMonitor::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
SemanticModel::EventMonitor::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type SemanticModel::EventMonitor was not generated with stream support";
    throw ex;
}

void
SemanticModel::EventMonitor::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type SemanticModel::EventMonitor was not generated with stream support";
    throw ex;
}

void 
SemanticModel::__patch__EventMonitorPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::SemanticModel::EventMonitorPtr* p = static_cast< ::SemanticModel::EventMonitorPtr*>(__addr);
    assert(p);
    *p = ::SemanticModel::EventMonitorPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::SemanticModel::EventMonitor::ice_staticId(), v->ice_id());
    }
}

bool
SemanticModel::operator==(const ::SemanticModel::EventMonitor& l, const ::SemanticModel::EventMonitor& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
SemanticModel::operator<(const ::SemanticModel::EventMonitor& l, const ::SemanticModel::EventMonitor& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
SemanticModel::Device::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __SemanticModel__Device_ids[2] =
{
    "::Ice::Object",
    "::SemanticModel::Device"
};

bool
SemanticModel::Device::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__SemanticModel__Device_ids, __SemanticModel__Device_ids + 2, _s);
}

::std::vector< ::std::string>
SemanticModel::Device::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__SemanticModel__Device_ids[0], &__SemanticModel__Device_ids[2]);
}

const ::std::string&
SemanticModel::Device::ice_id(const ::Ice::Current&) const
{
    return __SemanticModel__Device_ids[1];
}

const ::std::string&
SemanticModel::Device::ice_staticId()
{
    return __SemanticModel__Device_ids[1];
}

::Ice::DispatchStatus
SemanticModel::Device::___deviceName(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::std::string name;
    __is->read(name);
    __is->endReadEncaps();
    deviceName(name, __current);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
SemanticModel::Device::___setProperties(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::SemanticModel::Properties spec;
    ::SemanticModel::__readProperties(__is, spec);
    __is->readPendingObjects();
    __is->endReadEncaps();
    setProperties(spec, __current);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
SemanticModel::Device::___getProperties(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::SemanticModel::Properties __ret = getProperties(__current);
    ::SemanticModel::__writeProperties(__os, __ret);
    __os->writePendingObjects();
    return ::Ice::DispatchOK;
}

static ::std::string __SemanticModel__Device_all[] =
{
    "deviceName",
    "getProperties",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "setProperties"
};

::Ice::DispatchStatus
SemanticModel::Device::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__SemanticModel__Device_all, __SemanticModel__Device_all + 7, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __SemanticModel__Device_all)
    {
        case 0:
        {
            return ___deviceName(in, current);
        }
        case 1:
        {
            return ___getProperties(in, current);
        }
        case 2:
        {
            return ___ice_id(in, current);
        }
        case 3:
        {
            return ___ice_ids(in, current);
        }
        case 4:
        {
            return ___ice_isA(in, current);
        }
        case 5:
        {
            return ___ice_ping(in, current);
        }
        case 6:
        {
            return ___setProperties(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
SemanticModel::Device::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
SemanticModel::Device::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
SemanticModel::Device::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type SemanticModel::Device was not generated with stream support";
    throw ex;
}

void
SemanticModel::Device::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type SemanticModel::Device was not generated with stream support";
    throw ex;
}

void 
SemanticModel::__patch__DevicePtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::SemanticModel::DevicePtr* p = static_cast< ::SemanticModel::DevicePtr*>(__addr);
    assert(p);
    *p = ::SemanticModel::DevicePtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::SemanticModel::Device::ice_staticId(), v->ice_id());
    }
}

bool
SemanticModel::operator==(const ::SemanticModel::Device& l, const ::SemanticModel::Device& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
SemanticModel::operator<(const ::SemanticModel::Device& l, const ::SemanticModel::Device& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
SemanticModel::Service::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __SemanticModel__Service_ids[2] =
{
    "::Ice::Object",
    "::SemanticModel::Service"
};

bool
SemanticModel::Service::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__SemanticModel__Service_ids, __SemanticModel__Service_ids + 2, _s);
}

::std::vector< ::std::string>
SemanticModel::Service::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__SemanticModel__Service_ids[0], &__SemanticModel__Service_ids[2]);
}

const ::std::string&
SemanticModel::Service::ice_id(const ::Ice::Current&) const
{
    return __SemanticModel__Service_ids[1];
}

const ::std::string&
SemanticModel::Service::ice_staticId()
{
    return __SemanticModel__Service_ids[1];
}

::Ice::DispatchStatus
SemanticModel::Service::___performAction(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::std::string idAction;
    ::Ice::ObjectPtr thg;
    __is->read(idAction);
    __is->read(::Ice::__patch__ObjectPtr, &thg);
    __is->readPendingObjects();
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::SemanticModel::EventSeq __ret = performAction(idAction, thg, __current);
    if(__ret.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        ::SemanticModel::__writeEventSeq(__os, &__ret[0], &__ret[0] + __ret.size());
    }
    __os->writePendingObjects();
    return ::Ice::DispatchOK;
}

static ::std::string __SemanticModel__Service_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "performAction"
};

::Ice::DispatchStatus
SemanticModel::Service::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__SemanticModel__Service_all, __SemanticModel__Service_all + 5, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __SemanticModel__Service_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___performAction(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
SemanticModel::Service::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
SemanticModel::Service::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
SemanticModel::Service::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type SemanticModel::Service was not generated with stream support";
    throw ex;
}

void
SemanticModel::Service::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type SemanticModel::Service was not generated with stream support";
    throw ex;
}

void 
SemanticModel::__patch__ServicePtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::SemanticModel::ServicePtr* p = static_cast< ::SemanticModel::ServicePtr*>(__addr);
    assert(p);
    *p = ::SemanticModel::ServicePtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::SemanticModel::Service::ice_staticId(), v->ice_id());
    }
}

bool
SemanticModel::operator==(const ::SemanticModel::Service& l, const ::SemanticModel::Service& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
SemanticModel::operator<(const ::SemanticModel::Service& l, const ::SemanticModel::Service& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}
