#ifndef _ASYNC_RESULT_HPP_
#define _ASYNC_RESULT_HPP_

#include "async/event.hpp"

//////////////////////////////////////////////////////////////////////////
namespace async
{
	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	class Result
		: public Event
	{
	public:
		struct State
		{
			Data	_data;
		};
		boost::shared_ptr<State> _state;
	public:
		Result()
			: _state(new State)
		{
		}
		Data &data()
		{
			wait();
			return _state->_data;
		}
	};
}

#endif
