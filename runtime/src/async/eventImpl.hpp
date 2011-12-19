#ifndef _ASYNC_EVENTIMPL_HPP_
#define _ASYNC_EVENTIMPL_HPP_

#include "async/event.hpp"
#include <deque>
#include "fiberImpl.hpp"

namespace async
{
	class EventImpl
	{
		boost::mutex				_mtx;
		bool						_ready;
		std::deque<FiberImplPtr>	_waiters;
	public:
		EventImpl();
		~EventImpl();

		void ready();
		bool isReady();
		void wait();
	};
	typedef boost::shared_ptr<EventImpl> EventImplPtr;
}
#endif
