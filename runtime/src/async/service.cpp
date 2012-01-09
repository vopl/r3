#include "pch.h"
#include "async/service.hpp"
#include "serviceImpl.hpp"
#include "async/exception.hpp"

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	Service::Service(bool isNull)
	{
		if(!isNull)
		{
			_impl.reset(new ServiceImpl);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	Service::Service(ServiceImplPtr impl)
		: _impl(impl)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	Service::~Service()
	{
		_impl.reset();
	}

	//////////////////////////////////////////////////////////////////////////
	Service::operator bool() const
	{
		return _impl?true:false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Service::operator!() const
	{
		return _impl?false:true;
	}

	//////////////////////////////////////////////////////////////////////////
	void Service::reset()
	{
		_impl.reset();
	}


	//////////////////////////////////////////////////////////////////////////
	void Service::start(
		size_t numThreads,
		const function<void ()> &onThreadStart,
		const function<void ()> &onThreadStop)
	{
		return _impl->start(numThreads, onThreadStart, onThreadStop);
	}

	//////////////////////////////////////////////////////////////////////////
	void Service::balance(size_t numThreads)
	{
		return _impl->balance(numThreads);
	}

	//////////////////////////////////////////////////////////////////////////
	void Service::stop()
	{
		return _impl->stop();
	}

	//////////////////////////////////////////////////////////////////////////
	void Service::spawn(const boost::function<void ()> &code)
	{
		return _impl->spawn(code);
	}

	//////////////////////////////////////////////////////////////////////////
	boost::asio::io_service &Service::io()
	{
		return _impl->io();
	}

	//////////////////////////////////////////////////////////////////////////
	bool Service::setAsGlobal(bool force)
	{
		return _impl->setAsGlobal(force);
	}






	//////////////////////////////////////////////////////////////////////////
	ASYNC_API void spawn(const function<void ()> &code)
	{
		ServiceImpl *service = ServiceImpl::current();
		if(!service)
		{
			assert(0);
			ELOG("spawn with empty service");
			throw exception("spawn with empty service");
			return;
		}

		return service->spawn(code);
	}

	//////////////////////////////////////////////////////////////////////////
	ASYNC_API void exec(const function<void ()> &code)
	{
		WorkerImpl *worker = WorkerImpl::current();
		if(!worker)
		{
			assert(0);
			ELOG("exec request with no current worker");
			throw exception("exec request with no current worker");
			return;
		}

		return worker->exec(code);
	}

	//////////////////////////////////////////////////////////////////////////
	ASYNC_API asio::io_service &io()
	{
		ServiceImpl *service = ServiceImpl::current();
		if(!service)
		{
			assert(0);
			ELOG("io request with no current service");
			throw exception("io request with no current service");
			static asio::io_service stub;
			return stub;
		}

		return service->io();
	}

	//////////////////////////////////////////////////////////////////////////
	ASYNC_API bool serviceExists()
	{
		return ServiceImpl::current()?true:false;
	}

	//////////////////////////////////////////////////////////////////////////
	ASYNC_API Service service()
	{
		ServiceImpl *service = ServiceImpl::current();
		if(!service)
		{
			ELOG("service request with no current service");
			throw exception("service request with no current service");
			return Service();
		}

		return Service(service->shared_from_this());
	}

}

