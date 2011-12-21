#ifndef _ASYNC_EVENT_HPP_
#define _ASYNC_EVENT_HPP_

#include "async/api.h"
#include <boost/shared_ptr.hpp>
#include <deque>

//////////////////////////////////////////////////////////////////////////
namespace async
{
	class EventImpl;
	typedef boost::shared_ptr<EventImpl> EventImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class ASYNC_API Event
	{
		EventImplPtr	_impl;

	public:
		Event(bool autoReset = false);

		void set();
		void reset();
		bool isSet();
		void wait();

	public:
		typedef std::deque<Event *> Deque;
		static Deque::iterator waitAny(Deque::iterator begin, Deque::iterator end);
	};
}

#endif
