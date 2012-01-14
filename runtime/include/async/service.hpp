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

		//����������� ����������� � �������� ������������ ����������

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
		boost::asio::io_service &io();
		bool setAsGlobal(bool force);
	};


	//��������� ����� ���� ����������
	ASYNC_API void spawn(const boost::function<void ()> &code);

	//��������� ����� ���� ���������
	ASYNC_API void exec(const boost::function<void ()> &code);

	//������� ��������� ���������
	ASYNC_API boost::asio::io_service &io();

	//������� ��������� ������
	ASYNC_API bool serviceExists();
	ASYNC_API Service service();
}


//////////////////////////////////////////////////////////////////////////
//��� asio ���� � ������
namespace boost
{
	namespace asio
	{
		template <typename Function, typename Any>
		inline void asio_handler_invoke(Function &code, Any stub)
		{
			async::exec(code);
		}
	}
}
#endif
