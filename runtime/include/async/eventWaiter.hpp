#ifndef _ASYNC_EVENTWAITER_HPP_
#define _ASYNC_EVENTWAITER_HPP_

#include "async/event.hpp"

//////////////////////////////////////////////////////////////////////////
namespace async
{
	class Operand;
	typedef boost::shared_ptr<Operand> OperandPtr;
	
	//////////////////////////////////////////////////////////////////////////
	/*!	\ingroup async
		\brief Групповое ожидание событий

		Это надстройка над \ref Event::waitAny, предоставляющая следующие возможности:
			-	удобное формирование набора событий к ожиданию\n
				можно до 10 штук сразу в конструктор передать или добавить любое количество событий 
				уже после создания объекта через EventWaiter::operator<<\n
				пример
				\code
					async::EventWaiter<Future<error_code> > myWaiter(
						service->send(),		// send возвращает Future<error_code>
						async::timeout(2000));

					myWaiter.wait();//либо send либо timeout
				\endcode
				еще пример
				\code
					//сформировать 'ожидатор'
					async::EventWaiter<Future<pgc::Result> > results;

					//запускать запросы в БД и складировать события о их окончании в ожидатор
					results << con.query(statement1);
					results << con.query(statement2);
					results << con.query(statement3);
					results << con.query(statement4);

					//все запросы в БД запущены

					results.wait();//ждать
					//тут как минимум один из четырех запросов исполнен
				\endcode

			-	циклический перебор ожидаемых событий с предоставлением текущего-сработавшего\n
				это может быть полезно например при таком сценарии: сделали N запросов в БД, 
				перебираем с ожиданием, на каждой итерации имеем один готовый исполненный 
				запрос, перерабатывем его тут же на месте\n
				пример
				\code
					//сформировать 'ожидатор'
					async::EventWaiter<Future<pgc::Result> > results;

					//запускать запросы в БД и складировать события о их окончании в ожидатор
					results << con.query(statement1);
					results << con.query(statement2);
					results << con.query(statement3);
					results << con.query(statement4);

					//все запросы в БД запущены

					while(results.wait())//ждать один любой
					{
						//очередной запрос исполнен, переработать результаты
						processResult(results.current());
					}
				\endcode
				или так
				\code
					while(results)//operator bool -> wait
					{
						processResult(results);//operator CustomEvent& -> current
					}
				\endcode

		\tparam CustomEvent тип ожидаемых событий. Это может быть сам \ref Event 
			или любые его производные (\ref Future, ...), главное чтобы они 
			приводились к Event
	*/
	template <class CustomEvent=Event>
	class EventWaiter
	{
	public:

		///	\name Конструирование нового объекта, ему сразу можно передать 0-10 событий
		//@{
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
		//@}

		/// Разрушение
		~EventWaiter();

		/*! \brief Добавление нового события в конец набора событий
			
			\param event добавляемое событие
			\return ссылку на себя, просто для удобства последовательного добавления\n
				\code
				myWaiter<<evt1<<evt2;
				\endcode
		*/
		EventWaiter &operator <<(const CustomEvent &event);

		/*!	\brief Ожидание очередного события из набора, заданного через конструктор и/или EventWaiter::operator<<

			\return true если произошло одно из событий\n
				false если набор событий пуст или уже переработаны все события

			после того как wait вернул истину - сработавшее событие помечается как "текущее"
			его можно получить через метод \ref current, а его индекс - через \ref currentIndex
		*/
		bool wait();

		/*! \brief Оператор приведения к bool, просто сахар, вызывает \ref wait
			\copydoc wait
			
			пример использования
			\code
				...
				if(myWaiter)//operator bool
				...
				while(myWaiter)//operator bool
				...
			\endcode
		*/
		operator bool();
		
		/*! \brief Доступ к экземпляру текущего события
			
			текущее событие - это то, которое произошло на момент последнего wait
			существует только если wait вернул истину

			если wait вернул ложь или вообще не вызывался - будет выброшено исключение 
			\ref async::exception

			\return экземпляр события
		*/
		CustomEvent &current();

		/*! \brief Оператор приведения к пользовательскому событию, просто сахар, вызывает \ref current
			\copydoc current
			
			пример использования
			\code
				...
				while(myWaiter)//operator bool
				{
					processResult(myWaiter);//operator CustomEvent &
				}
				...
			\endcode
		*/
		operator CustomEvent &();

		/*! \brief Индекс текущего события
			
			работает аналогично \ref current, но возвращает не само событие а его индекс

			индекс отсчитывается от 0 и наращивается на 1 при каждом добавлении нового события
			например, тут индексы как в именах
			\code
				EventWaiter myWaiter(evt0, evt1, evt3);
				myWaiter<<evt4<<evt5;
				myWaiter<<evt6;
			\endcode

			этот метод удобно использовать для идентификации события которое произошло 
			при \ref wait

			пример
			\code
				async::EventWaiter<Future<error_code> > myWaiter(
					service->send(),		// send возвращает Future<error_code>
					async::timeout(2000));

				myWaiter.wait();//либо send либо timeout

				if(myWaiter.currentIndex() == 0)
				{
					//сработал send
				}
				else
				{
					//сработал timeout
				}
			\endcode

			если перед вызовом этого метода wait вернул ложь или вообще не вызывался - 
			будет выброшено исключение \ref async::exception

			\return индекс текущего события

		*/
		size_t currentIndex();

	private:
		struct CustomEventHolder
		{
			CustomEvent	_event;
			size_t		_originalIndex;

			CustomEventHolder(const CustomEvent &event, size_t originalIndex)
				: _event(event)
				, _originalIndex(originalIndex)
			{}
		};
		std::deque<CustomEventHolder>	_customs;
		std::vector<Event>				_events;
		size_t							_current;
		static const size_t				_wrongIndex = (size_t)-1;
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
		(*this)<<event1;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2)
		: _current(_wrongIndex)
	{
		(*this)<<event1<<event2;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2, const CustomEvent &event3)
		: _current(_wrongIndex)
	{
		(*this)<<event1<<event2<<event3;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2, const CustomEvent &event3, const CustomEvent &event4)
		: _current(_wrongIndex)
	{
		(*this)<<event1<<event2<<event3<<event4;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2, const CustomEvent &event3, const CustomEvent &event4, const CustomEvent &event5)
		: _current(_wrongIndex)
	{
		(*this)<<event1<<event2<<event3<<event4<<event5;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2, const CustomEvent &event3, const CustomEvent &event4, const CustomEvent &event5, const CustomEvent &event6)
		: _current(_wrongIndex)
	{
		(*this)<<event1<<event2<<event3<<event4<<event5<<event6;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2, const CustomEvent &event3, const CustomEvent &event4, const CustomEvent &event5, const CustomEvent &event6, const CustomEvent &event7)
		: _current(_wrongIndex)
	{
		(*this)<<event1<<event2<<event3<<event4<<event5<<event6<<event7;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2, const CustomEvent &event3, const CustomEvent &event4, const CustomEvent &event5, const CustomEvent &event6, const CustomEvent &event7, const CustomEvent &event8)
		: _current(_wrongIndex)
	{
		(*this)<<event1<<event2<<event3<<event4<<event5<<event6<<event7<<event8;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2, const CustomEvent &event3, const CustomEvent &event4, const CustomEvent &event5, const CustomEvent &event6, const CustomEvent &event7, const CustomEvent &event8, const CustomEvent &event9)
		: _current(_wrongIndex)
	{
		(*this)<<event1<<event2<<event3<<event4<<event5<<event6<<event7<<event8<<event9;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::EventWaiter(const CustomEvent &event1, const CustomEvent &event2, const CustomEvent &event3, const CustomEvent &event4, const CustomEvent &event5, const CustomEvent &event6, const CustomEvent &event7, const CustomEvent &event8, const CustomEvent &event9, const CustomEvent &event10)
		: _current(_wrongIndex)
	{
		(*this)<<event1<<event2<<event3<<event4<<event5<<event6<<event7<<event8<<event9<<event10;
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
		_customs.push_back(CustomEventHolder(event, _customs.size()));
		_events.push_back((const Event&)event);
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

		return _customs[_current]._event;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	EventWaiter<CustomEvent>::operator CustomEvent&()
	{
		return current();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CustomEvent>
	size_t EventWaiter<CustomEvent>::currentIndex()
	{
		if(_wrongIndex==_current)
		{
			assert("need call 'wait' first");
			throw exception("need call 'wait' first");
			return _wrongIndex;
		}
		if(_current > _events.size() || _wrongIndex==_current)
		{
			assert("no more event in waiter");
			throw exception("no more event in waiter");
			return _wrongIndex;
		}

		return _customs[_current]._originalIndex;
	}

}

#endif
