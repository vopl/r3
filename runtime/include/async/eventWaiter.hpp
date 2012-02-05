#ifndef _ASYNC_EVENTWAITER_HPP_
#define _ASYNC_EVENTWAITER_HPP_

#include "async/event.hpp"

//////////////////////////////////////////////////////////////////////////
namespace async
{
	class Operand;
	typedef boost::shared_ptr<Operand> OperandPtr;
	
	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	class EventWaiter
	{
	public:
		EventWaiter();
		EventWaiter(const CustomEvent &);
		EventWaiter(const CustomEvent &, const CustomEvent &);
		EventWaiter(const CustomEvent &, const CustomEvent &, const CustomEvent &);
		EventWaiter(const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &);
		EventWaiter(const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &);
		EventWaiter(const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &);
		EventWaiter(const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &);
		EventWaiter(const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &);
		EventWaiter(const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &);
		EventWaiter(const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &, const CustomEvent &);
		~EventWaiter();

		//добавить
		EventWaiter &operator <<(const CustomEvent &event);

		//ждать
		bool wait();
		operator bool();
		
		//после успешного ожидания доступен один готовый элемент
		CustomEvent &current();
		operator CustomEvent &();

	private:
		std::deque<CustomEvent>		_customs;
		std::vector<Event>			_events;
		size_t						_current;
		static const size_t			_wrongIndex = (size_t)-1;
	};

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter()
		: _current(_wrongIndex)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1)
		: _current(_wrongIndex)
	{
		_customs.push_back(event1);
		_events.push_back(event1);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2)
		: _current(_wrongIndex)
	{
		_customs.push_back(event1);
		_events.push_back(event1);

		_customs.push_back(event2);
		_events.push_back(event2);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2, const CustomEvent &event3)
		: _current(_wrongIndex)
	{
		_customs.push_back(event1);
		_events.push_back(event1);

		_customs.push_back(event2);
		_events.push_back(event2);

		_customs.push_back(event3);
		_events.push_back(event3);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2, const CustomEvent &event3, const CustomEvent &event4)
		: _current(_wrongIndex)
	{
		_customs.push_back(event1);
		_events.push_back(event1);

		_customs.push_back(event2);
		_events.push_back(event2);

		_customs.push_back(event3);
		_events.push_back(event3);

		_customs.push_back(event4);
		_events.push_back(event4);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2, const CustomEvent &event3, const CustomEvent &event4, const CustomEvent &event5)
		: _current(_wrongIndex)
	{
		_customs.push_back(event1);
		_events.push_back(event1);

		_customs.push_back(event2);
		_events.push_back(event2);

		_customs.push_back(event3);
		_events.push_back(event3);

		_customs.push_back(event4);
		_events.push_back(event4);

		_customs.push_back(event5);
		_events.push_back(event5);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2, const CustomEvent &event3, const CustomEvent &event4, const CustomEvent &event5, const CustomEvent &event6)
		: _current(_wrongIndex)
	{
		_customs.push_back(event1);
		_events.push_back(event1);

		_customs.push_back(event2);
		_events.push_back(event2);

		_customs.push_back(event3);
		_events.push_back(event3);

		_customs.push_back(event4);
		_events.push_back(event4);

		_customs.push_back(event5);
		_events.push_back(event5);

		_customs.push_back(event6);
		_events.push_back(event6);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2, const CustomEvent &event3, const CustomEvent &event4, const CustomEvent &event5, const CustomEvent &event6, const CustomEvent &event7)
		: _current(_wrongIndex)
	{
		_customs.push_back(event1);
		_events.push_back(event1);

		_customs.push_back(event2);
		_events.push_back(event2);

		_customs.push_back(event3);
		_events.push_back(event3);

		_customs.push_back(event4);
		_events.push_back(event4);

		_customs.push_back(event5);
		_events.push_back(event5);

		_customs.push_back(event6);
		_events.push_back(event6);

		_customs.push_back(event7);
		_events.push_back(event7);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2, const CustomEvent &event3, const CustomEvent &event4, const CustomEvent &event5, const CustomEvent &event6, const CustomEvent &event7, const CustomEvent &event8)
		: _current(_wrongIndex)
	{
		_customs.push_back(event1);
		_events.push_back(event1);

		_customs.push_back(event2);
		_events.push_back(event2);

		_customs.push_back(event3);
		_events.push_back(event3);

		_customs.push_back(event4);
		_events.push_back(event4);

		_customs.push_back(event5);
		_events.push_back(event5);

		_customs.push_back(event6);
		_events.push_back(event6);

		_customs.push_back(event7);
		_events.push_back(event7);

		_customs.push_back(event8);
		_events.push_back(event8);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2, const CustomEvent &event3, const CustomEvent &event4, const CustomEvent &event5, const CustomEvent &event6, const CustomEvent &event7, const CustomEvent &event8, const CustomEvent &event9)
		: _current(_wrongIndex)
	{
		_customs.push_back(event1);
		_events.push_back(event1);

		_customs.push_back(event2);
		_events.push_back(event2);

		_customs.push_back(event3);
		_events.push_back(event3);

		_customs.push_back(event4);
		_events.push_back(event4);

		_customs.push_back(event5);
		_events.push_back(event5);

		_customs.push_back(event6);
		_events.push_back(event6);

		_customs.push_back(event7);
		_events.push_back(event7);

		_customs.push_back(event8);
		_events.push_back(event8);

		_customs.push_back(event9);
		_events.push_back(event9);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2, const CustomEvent &event3, const CustomEvent &event4, const CustomEvent &event5, const CustomEvent &event6, const CustomEvent &event7, const CustomEvent &event8, const CustomEvent &event9, const CustomEvent &event10)
		: _current(_wrongIndex)
	{
		_customs.push_back(event1);
		_events.push_back(event1);

		_customs.push_back(event2);
		_events.push_back(event2);

		_customs.push_back(event3);
		_events.push_back(event3);

		_customs.push_back(event4);
		_events.push_back(event4);

		_customs.push_back(event5);
		_events.push_back(event5);

		_customs.push_back(event6);
		_events.push_back(event6);

		_customs.push_back(event7);
		_events.push_back(event7);

		_customs.push_back(event8);
		_events.push_back(event8);

		_customs.push_back(event9);
		_events.push_back(event9);

		_customs.push_back(event10);
		_events.push_back(event10);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::~EventWaiter()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent> &EventWaiter<CustomEvent>::operator <<(const CustomEvent &event)
	{
		_customs.push_back(event);
		_events.push_back(event);
		return *this;
	}


	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	bool EventWaiter<CustomEvent>::wait()
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

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::operator bool()
	{
		return wait();
	}


	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	CustomEvent &EventWaiter<CustomEvent>::current()
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

		return _customs[_current];
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::operator CustomEvent&()
	{
		return current();
	}

}

#endif
