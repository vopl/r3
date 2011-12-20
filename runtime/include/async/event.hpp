#ifndef _ASYNC_EVENT_HPP_
#define _ASYNC_EVENT_HPP_

#include "async/api.h"
#include <boost/shared_ptr.hpp>


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
	};
}

#endif
