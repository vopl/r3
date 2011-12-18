#include "pch.h"
#include "async/event.hpp"

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	Event::Event()
		: _state(new State())
	{
	}


	//////////////////////////////////////////////////////////////////////////
	void Event::ready()
	{
		assert(!_state->_ready);
		if(!_state->_ready)
		{
			_state->_ready = true;
			if(_state->_fiber)
			{
				_state->_fiber->ready();
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	bool Event::isReady()
	{
		return _state->_ready;
	}

	//////////////////////////////////////////////////////////////////////////
	void Event::wait()
	{
		assert(!_state->_fiber);

		if(!_state->_ready)
		{
			_state->_fiber = Fiber::current();
			assert(_state->_fiber);
			while(!_state->_ready)
			{
				Fiber::yield();
			}
			_state->_fiber.reset();
		}
	}
}

