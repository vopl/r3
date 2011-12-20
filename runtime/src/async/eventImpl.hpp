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
		volatile bool				_isSet;
		bool						_autoReset;
		std::deque<FiberImplPtr>	_waiters;
	public:
		EventImpl(bool autoReset);
		~EventImpl();

		void set();
		void reset();
		bool isSet();
		void wait();
	};
	typedef boost::shared_ptr<EventImpl> EventImplPtr;
}
#endif
