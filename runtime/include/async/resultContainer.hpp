#ifndef _ASYNC_RESULTCONTAINER_HPP_
#define _ASYNC_RESULTCONTAINER_HPP_

#include "async/result.hpp"

//////////////////////////////////////////////////////////////////////////
namespace async
{
	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	class EventWaiter
	{
	private:
		std::deque<CustomEvent>		_customs;
		std::vector<Event>			_events;
		size_t						_current;
		static const size_t			_wrongIndex = (size_t)-1;

	public:
		EventWaiter()
			: _current(_wrongIndex)
		{
		}

		~EventWaiter()
		{

		}

		//добавить
		EventWaiter &operator |=(const CustomEvent &evt)
		{
			_customs.push_back(evt);
			_events.push_back(evt);
			return *this;
		}

		//ждать
		bool wait()
		{
			if(_wrongIndex == _current)
			{
				_current = 0;
			}
			else
			{
				_current++;
			}

			if(_current >= _events.size())
			{
				return false;
			}

			Event *begin = &_events[0]+_current;
			Event *ready =
				Event::waitAny(begin, &_events.back()+1);

			if(begin != ready)
			{
				size_t readyIdx = ready - begin + _current;
				std::swap(*begin, *ready);
				std::swap(_customs[_current], _customs[readyIdx]);
			}
			return true;
		}
		
		CustomEvent &current()
		{
			if(_wrongIndex==_current)
			{
				assert("need call 'wait' first");
				throw exception("need call 'wait' first");
				static CustomEvent stub;
				return stub;
			}
			if(_current > _events.size() || _wrongIndex==_current)
			{
				assert("no more event in waiter");
				throw exception("no more event in waiter");
				static CustomEvent stub;
				return stub;
			}
			//неправильно, в деке могут быть перемещения
			return _customs[_current];
		}
	};

	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	class ResultWaiter
		: public EventWaiter<Result<Data> >
	{
	public:
	};
}

#endif
