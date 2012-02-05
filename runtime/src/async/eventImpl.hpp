#ifndef _ASYNC_EVENTIMPL_HPP_
#define _ASYNC_EVENTIMPL_HPP_

#include "async/event.hpp"
#include <vector>
#include "fiberImpl.hpp"

namespace async
{
	class EventImpl
	{
		mutex						_mtx;
		volatile bool				_isSet;
		bool						_autoReset;
		std::vector<FiberImplPtr>	_waiters;

		struct MultiNotifier
		{
			mutex						_mtx;
			FiberImplPtr				_initiator;
			void *						_readyKey;

			bool notifyReady(void *key);
		};
		typedef boost::shared_ptr<MultiNotifier> MultiNotifierPtr;

		struct MultiNotifierMarked
		{
			MultiNotifierPtr _pmn;
			void *_key;

			MultiNotifierMarked(const MultiNotifierPtr &pmn, void *key);
		};
		std::vector<MultiNotifierMarked>	_mnWaiters;
	public:
		EventImpl(bool autoReset);
		~EventImpl();

		void set();
		void reset();
		bool isSet();
		void wait();

	public:
		static Event *waitAny(Event *begin, Event *end);

	private:
		bool mnWait(const MultiNotifierMarked &mn);
		void mnCancel(const MultiNotifierPtr &pmn);

	};
	typedef shared_ptr<EventImpl> EventImplPtr;
}
#endif
