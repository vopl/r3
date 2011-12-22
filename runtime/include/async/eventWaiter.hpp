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
		EventWaiter(const EventWaiter &);
		EventWaiter(const CustomEvent &);
		~EventWaiter();


		EventWaiter &operator =(const EventWaiter &);
		EventWaiter &operator =(const CustomEvent &);


		//добавить
		EventWaiter operator |(const EventWaiter &waiter);
		EventWaiter &operator |=(const EventWaiter &waiter);
		EventWaiter operator |(const CustomEvent &evt);
		EventWaiter &operator |=(const CustomEvent &evt);

		EventWaiter operator &(const EventWaiter &waiter);
		EventWaiter &operator &=(const EventWaiter &waiter);
		EventWaiter operator &(const CustomEvent &evt);
		EventWaiter &operator &=(const CustomEvent &evt);

		EventWaiter operator !();

		//ждать
		bool wait();
		
		//после успешного ожидания доступен один готовый элемент
		CustomEvent &current();

	private:
// 		std::deque<CustomEvent>		_customs;
// 		std::vector<Event>			_events;
// 		size_t						_current;
// 		static const size_t			_wrongIndex = (size_t)-1;

	private:
		enum EOperation
		{
			eoNull,
			eoOr,
			eoAnd,
		};
		EOperation	_operation;
		bool		_negation;

		std::deque<OperandPtr>	_operands;
	};

	class Operand
	{
	public:
	};






	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter()
		: _operation(eoNull)
		, _negation(false)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const EventWaiter &waiter)
		: _operation(waiter._operation)
		, _negation(waiter._negation)
		, _operands(waiter._operands)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event)
		: _operation(eoNull)
		, _negation(false)
		, _operands(event)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::~EventWaiter()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent> &EventWaiter<CustomEvent>::operator =(const EventWaiter<CustomEvent> &waiter)
	{
		_operation = waiter._operation;
		_negation = waiter._negation;
		_operands = waiter._operands;
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent> &EventWaiter<CustomEvent>::operator =(const CustomEvent &)
	{
		_operation = eoNull;
		_negation = false;
		_operands.clear();
		_operands.push_back(event);
		return *this;
	}


	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent> EventWaiter<CustomEvent>::operator |(const EventWaiter &evt)
	{
		assert(0);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent> &EventWaiter<CustomEvent>::operator |=(const EventWaiter<CustomEvent> &waiter)
	{
		assert(0);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent> EventWaiter<CustomEvent>::operator |(const CustomEvent &evt)
	{
		assert(0);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent> &EventWaiter<CustomEvent>::operator |=(const CustomEvent &evt)
	{
		assert(0);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent> EventWaiter<CustomEvent>::operator &(const EventWaiter &evt)
	{
		assert(0);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent> &EventWaiter<CustomEvent>::operator &=(const EventWaiter<CustomEvent> &waiter)
	{
		assert(0);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent> EventWaiter<CustomEvent>::operator &(const CustomEvent &evt)
	{
		assert(0);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent> &EventWaiter<CustomEvent>::operator &=(const CustomEvent &evt)
	{
		assert(0);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent> EventWaiter<CustomEvent>::operator !()
	{
		assert(0);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	bool EventWaiter<CustomEvent>::wait()
	{
		assert(0);
		return false;

// 		if(_wrongIndex == _current)
// 		{
// 			_current = 0;
// 		}
// 		else
// 		{
// 			_current++;
// 		}
// 
// 		if(_current >= _events.size())
// 		{
// 			return false;
// 		}
// 
// 		Event *begin = &_events[0]+_current;
// 		Event *ready =
// 			Event::waitAny(begin, &_events.back()+1);
// 
// 		if(begin != ready)
// 		{
// 			size_t readyIdx = ready - begin + _current;
// 			std::swap(*begin, *ready);
// 			std::swap(_customs[_current], _customs[readyIdx]);
// 		}
// 		return true;
// 	}
// 
// 	//////////////////////////////////////////////////////////////////////////
// 	template <class CustomEvent>
// 	CustomEvent &EventWaiter<CustomEvent>::current()
// 	{
// 		if(_wrongIndex==_current)
// 		{
// 			assert("need call 'wait' first");
// 			throw exception("need call 'wait' first");
// 			static CustomEvent stub;
// 			return stub;
// 		}
// 		if(_current > _events.size() || _wrongIndex==_current)
// 		{
// 			assert("no more event in waiter");
// 			throw exception("no more event in waiter");
// 			static CustomEvent stub;
// 			return stub;
// 		}
// 		//неправильно, в деке могут быть перемещения
// 		return _customs[_current];
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	CustomEvent &EventWaiter<CustomEvent>::current()
	{
		assert(0);
		static CustomEvent stub;
		return stub;
	}

}

#endif
