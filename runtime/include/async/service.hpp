#ifndef _ASYNC_SERVICE_HPP_
#define _ASYNC_SERVICE_HPP_

#include "async/api.h"
#include "async/event.hpp"
#include "async/result.hpp"

#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/asio/io_service.hpp>

namespace async
{
	class ASYNC_API Service
	{
	protected:
		Service();
		Service(const Service&);

	public:
		virtual ~Service();

		void start(
			size_t numThreads,
			const boost::function<void ()> &onThreadStart = boost::function<void ()>(),
			const boost::function<void ()> &onThreadStop = boost::function<void ()>());

		void balance(size_t numThreads);
		void stop();

		void spawn(const boost::function<void ()> &code);
		boost::asio::io_service &io();
	};
	typedef boost::shared_ptr<Service> ServicePtr;


	//////////////////////////////////////////////////////////////////////////
	ASYNC_API ServicePtr createService();

	//��������� ����� ���� ����������
	ASYNC_API void spawn(const boost::function<void ()> &code);

	//��������� ����� ���� ���������
	ASYNC_API void exec(const boost::function<void ()> &code);

	//������� ��������� ���������
	ASYNC_API boost::asio::io_service &io();

	//������� ��������� ������
	ASYNC_API ServicePtr service();
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
