#ifndef _ASYNC_EVENTIMPL_HPP_
#define _ASYNC_EVENTIMPL_HPP_

#include "async/event.hpp"
#include <deque>
#include "fiberImpl.hpp"

namespace async
{
	class EventImpl
	{
		mutex						_mtx;
		volatile bool				_isSet;
		bool						_autoReset;
		std::deque<FiberImplPtr>	_waiters;

		struct MultiNotifier
		{
			mutex						_mtx;
			FiberImplPtr				_initiator;
			EventImpl *					_ready;

			bool notifyReady(EventImpl *who);
		};
		typedef boost::shared_ptr<MultiNotifier> MultiNotifierPtr;
		std::deque<MultiNotifierPtr>	_pmnWaiters;
	public:
		EventImpl(bool autoReset);
		~EventImpl();

		void set();
		void reset();
		bool isSet();
		void wait();

	public:
		static Event *waitAny(Event *begin, Event *end);
		bool mnWait(MultiNotifierPtr pmn);
		void mnCancel(MultiNotifierPtr pmn);

	};
	typedef shared_ptr<EventImpl> EventImplPtr;
}
#endif
