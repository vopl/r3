#include "pch.h"
#include "async/event.hpp"

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	Event::Event()
		: _ready(new bool(false))
	{
	}


	//////////////////////////////////////////////////////////////////////////
	void Event::ready()
	{
		assert(!*_ready);
		if(!*_ready)
		{
			*_ready = true;
			assert(_fiber);
			_fiber->ready();
			_fiber.reset();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	bool Event::isReady()
	{
		return *_ready;
	}

	//////////////////////////////////////////////////////////////////////////
	void Event::wait()
	{
		assert(!_fiber);
		_fiber = Fiber::current();
		assert(_fiber);
		while(!*_ready)
		{
			Fiber::yield();
		}
	}
}

