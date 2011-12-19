#ifndef _ASYNC_EVENT_HPP_
#define _ASYNC_EVENT_HPP_

#include "async/api.h"
#include "async/fiber.hpp"


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
		Event();

		void ready();
		bool isReady();
		void wait();
	};
}

#endif
