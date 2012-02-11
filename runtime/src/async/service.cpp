#include "pch.hpp"
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
	Service::Service(const Service &from)
		: _impl(from._impl)
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
	Future<boost::system::error_code> Service::timeout(size_t millisec)
	{
		return _impl->timeout(millisec);
	}

	//////////////////////////////////////////////////////////////////////////
	void Service::cancelAllTimeouts()
	{
		return _impl->cancelAllTimeouts();
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
			ELOG("call spawn with empty service");
			throw exception("call spawn with empty service");
			return;
		}

		return service->spawn(code);
	}

	//////////////////////////////////////////////////////////////////////////
	ASYNC_API Future<boost::system::error_code> timeout(size_t millisec)
	{
		ServiceImpl *service = ServiceImpl::current();
		if(!service)
		{
			assert(0);
			ELOG("call timeout with empty service");
			throw exception("call timeout with empty service");

			Future<boost::system::error_code> stub;
			return stub;
		}

		return service->timeout(millisec);
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
	ASYNC_API void yield()
	{
		WorkerImpl *worker = WorkerImpl::current();
		if(!worker)
		{
			assert(0);
			ELOG("yield request with no current worker");
			throw exception("yield request with no current worker");
			return;
		}

		return worker->yield();
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

