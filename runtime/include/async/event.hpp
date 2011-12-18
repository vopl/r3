#ifndef _ASYNC_EVENT_HPP_
#define _ASYNC_EVENT_HPP_

#include "async/api.h"
#include "async/fiber.hpp"


//////////////////////////////////////////////////////////////////////////
namespace async
{
	//////////////////////////////////////////////////////////////////////////
	class ASYNC_API Event
	{
		FiberPtr	_fiber;
		boost::shared_ptr<bool>	_ready;

	public:
		Event();

		void ready();
		bool isReady();
		void wait();
	};
}

#endif
