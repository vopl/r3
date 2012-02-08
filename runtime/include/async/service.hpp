#ifndef _ASYNC_SERVICE_HPP_
#define _ASYNC_SERVICE_HPP_

#include "async/api.h"
#include "async/exception.hpp"
#include "async/event.hpp"
#include "async/future.hpp"

#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/asio/io_service.hpp>

namespace async
{
	class ServiceImpl;
	typedef boost::shared_ptr<ServiceImpl> ServiceImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class ASYNC_API Service
	{
		ServiceImplPtr _impl;
	public:
		Service(bool isNull=true);
		Service(ServiceImplPtr impl);
		~Service();

		//конструктор копирования и оператор присваивания встроенные

		operator bool() const;
		bool operator!() const;
		void reset();

		void start(
			size_t numThreads,
			const boost::function<void ()> &onThreadStart = boost::function<void ()>(),
			const boost::function<void ()> &onThreadStop = boost::function<void ()>());

		void balance(size_t numThreads);
		void stop();

		void spawn(const boost::function<void ()> &code);

		Future<boost::system::error_code> timeout(size_t millisec);
		void cancelAllTimeouts();

		boost::asio::io_service &io();
		bool setAsGlobal(bool force);
	};


	/// выполнить кусок кода асинхронно
	ASYNC_API void spawn(const boost::function<void ()> &code);

	/// приостановка фибера на заданное время
	ASYNC_API Future<boost::system::error_code> timeout(size_t millisec);

	/// выполнить кусок кода синхронно
	ASYNC_API void exec(const boost::function<void ()> &code);

	/// прервать текущий фибер в пользу других, исполнение будет продолжено по очереди шедулера
	ASYNC_API void yield();

	/// текущий экземпляр проактора
	ASYNC_API boost::asio::io_service &io();

	/// признак наличия службы для текущего потока
	ASYNC_API bool serviceExists();

	/// текущий экземпляр службы
	ASYNC_API Service service();
}

#include "async/asioBridge.hpp"

//////////////////////////////////////////////////////////////////////////
//для asio мост в фиберы
namespace async
{
	/// TODO add comments
    template <class Handler>
    AsioBridge<Handler> bridge(const Handler &handler)
    {
		return AsioBridge<Handler>(handler);
    }
}
#endif
