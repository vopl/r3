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
	private:
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
		Data &dataNoWait()
		{
			return _state->_data;
		}

	public:
		typedef void result_type;

		void operator()(const Data &data)
		{
			_state->_data = data;
			ready();
		}
	};

	//////////////////////////////////////////////////////////////////////////
	template <class Data1, class Data2>
	class Result2
		: public Event
	{
	private:
		struct State
		{
			Data1	_data1;
			Data2	_data2;
		};
		boost::shared_ptr<State> _state;

	public:
		Result2()
			: _state(new State)
		{
		}

		Data1 &data1()
		{
			wait();
			return _state->_data1;
		}
		Data1 &data1NoWait()
		{
			return _state->_data1;
		}

		Data2 &data2()
		{
			wait();
			return _state->_data2;
		}
		Data2 &data2NoWait()
		{
			return _state->_data2;
		}

	public:
		typedef void result_type;

		void operator()(const Data1 &data1, const Data2 &data2)
		{
			_state->_data1 = data1;
			_state->_data2 = data2;
			ready();
		}

	};
}

#endif
