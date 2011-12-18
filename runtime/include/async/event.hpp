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
		struct State
		{
			FiberPtr	_fiber;
			bool		_ready;

			State():_ready(false){}
		};
		boost::shared_ptr<State> _state;

	public:
		Event();

		void ready();
		bool isReady();
		void wait();
	};
}

#endif
