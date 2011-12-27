#include "pch.h"
#include "async/service.hpp"
#include "serviceImpl.hpp"
#include "async/exception.hpp"

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	Service::Service()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	Service::Service(const Service&)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	Service::~Service()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void Service::start(
		size_t numThreads,
		const function<void ()> &onThreadStart,
		const function<void ()> &onThreadStop)
	{
		return static_cast<ServiceImpl *>(this)->start(numThreads, onThreadStart, onThreadStop);
	}

	//////////////////////////////////////////////////////////////////////////
	void Service::balance(size_t numThreads)
	{
		return static_cast<ServiceImpl *>(this)->balance(numThreads);
	}

	//////////////////////////////////////////////////////////////////////////
	void Service::stop()
	{
		return static_cast<ServiceImpl *>(this)->stop();
	}

	//////////////////////////////////////////////////////////////////////////
	void Service::spawn(const boost::function<void ()> &code)
	{
		return static_cast<ServiceImpl *>(this)->spawn(code);
	}

	//////////////////////////////////////////////////////////////////////////
	boost::asio::io_service &Service::io()
	{
		return static_cast<ServiceImpl *>(this)->io();
	}






	//////////////////////////////////////////////////////////////////////////
	ASYNC_API ServicePtr createService()
	{
		return ServicePtr(new ServiceImpl);
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
	ASYNC_API ServicePtr service()
	{
		ServiceImpl *service = ServiceImpl::current();
		if(!service)
		{
			ELOG("service request with no current service");
			return ServicePtr();
		}

		return service->shared_from_this();
	}

}

