#ifndef _ASYNC_FUTURE_HPP_
#define _ASYNC_FUTURE_HPP_

#include "async/event.hpp"

//////////////////////////////////////////////////////////////////////////
namespace async
{
	//////////////////////////////////////////////////////////////////////////
	/*! \ingroup async
		\brief Событие с данными

		Используется для передачи результата работы от асинхронного сервиса, 
		исполняющего длительную задачу (сеть, БД, подобное) к клиенту, использующему 
		этот сервис

		Фактически, это реализация паттерна future/promise, но и future и promise
		слеплены в одно целое.

		примерный сценарий клиента
		\code
			...
			// клиент использует некий сервис асинхронно
			Future<error_code> result = someService->someOperation();
			// сервис запустил задачу и исполняет ее асинхронно
			
			// тут клиент делает другую работу
			...
			// теперь нужен результат работы того сервиса
			result.wait(); // текущий фибер блокируется пока сервис не переведет result в сигнальное состояние (и положит туда данные)

			// result с данными готов к использованию, получить данные
			error_code ec = result.data();

			// работать с результатом
			if(ec)...
		\endcode


		примерный сценарий сервиса
		\code
			//метод, который будет вызывать клиент
			Future<error_code> someOperation()
			{
				//создаем новый Future, его отдадим клиенту и воркеру
				Future<error_code> result;

				//запускаем асинхронного воркера, чтобы не блокировать клиента
				//и передаем ему Future, по готовности воркер положит туда данные для клиента
				async::spawn(bind(someOperationWorker, result));

				//отдаем клиенту Future
				return result;
			}

			// исполнение операции будет происходить в другом фибере
			void someOperationWorker(Future<error_code> result)
			{
				//делать длительную операцию (запрос в сеть, команда в БД, ...)
				error_code ec = ...

				//зарядить данные и сигнализировать о готовности, заблокированный клиент будет активирован
				result(ec);
			}
		\endcode

		Данный класс не является потоко-безопасным.

		\tparam Data тип пользовательских данных
	*/
	template <class Data>
	class Future
		: public Event
	{
	private:
		struct State
		{
			Data	_data;
			//bool	_ready;

			State()
				//: _ready(false)
			{
			}
		};
		boost::shared_ptr<State> _state;

	public:
		/*! \brief Конструирование нового объекта

			пользовательский объект будет построен конструктором по умолчанию или не будет 
			построен вообще если конструктора нет (POD?)

			состояние события не-сигнальное
		*/
		Future()
			: _state(new State)
			, Event(false)
		{
		}

		/*!	\brief Сброс события и данных

			Подготовка объекта к повторному использованию - сброс события в не-сигнальное 
			состояние и сброс пользовательского объекта в значение, конструируемое по 
			умолчанию
		*/
		void reset()
		{
			Event::reset();
			//_state->_ready = false;
			_state->_data = Data();
		}
		
		/*!	\brief Явное ожидание готовности
		*/
		void wait()
		{
			//if(!_state->_ready)
			{
				Event::wait();
				//_state->_ready = true;
			}
		}

		/*!	\brief Ожидание готовности и предоставление данных
		*/
		Data &data()
		{
			wait();
			return _state->_data;
		}

		/*!	\brief Ожидание готовности и предоставление данных
		*/
		operator Data &()
		{
			wait();
			return _state->_data;
		}

		/*!	\brief Предоставление данных без ожидания
		*/
		Data &dataNoWait()
		{
			return _state->_data;
		}

	public:

		/*!	\brief тип возващаемого значения при вызове объекта этого класса как функтора, необходимо для  boost::bind
			
			Как функтор, данный класс можно использовать, например вместе с asio, как completition handler, очень удобно
		*/
		typedef void result_type;

		/*!	\brief Установка пользовательских данных и установка состояния в сигнальное
		*/
		void operator()(const Data &data)
		{
			_state->_data = data;
			set();
		}
	};

	//////////////////////////////////////////////////////////////////////////
	/*! \ingroup async
		\brief Событие с данными, две штуки
		\copydoc Future

		Работает аналогично async::Future, только пользовательские данные представлены 
		двумя объектами а не одним
	*/
	template <class Data1, class Data2>
	class Future2
		: public Event
	{
	private:
		struct State
		{
			Data1	_data1;
			Data2	_data2;
			//bool	_ready;

			State()
			//	: _ready(false)
			{
			}
		};
		boost::shared_ptr<State> _state;

	public:
		Future2()
			: _state(new State)
			, Event(false)
		{
		}

		void reset()
		{
			Event::reset();
			//_state->_ready = false;
			_state->_data1 = Data1();
			_state->_data2 = Data2();
		}

		void wait()
		{
			//if(!_state->_ready)
			{
				Event::wait();
				//_state->_ready = true;
			}
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
			set();
		}

	};

	//////////////////////////////////////////////////////////////////////////
	/*! \ingroup async
		\brief Событие с данными, три штуки

		Работает аналогично async::Future, только пользовательские данные представлены 
		тремя объектами а не одним
	*/
	template <class Data1, class Data2, class Data3>
	class Future3
		: public Event
	{
	private:
		struct State
		{
			Data1	_data1;
			Data2	_data2;
			Data3	_data3;
			//bool	_ready;

			State()
				//: _ready(false)
			{
			}
		};
		boost::shared_ptr<State> _state;

	public:
		Future3()
			: _state(new State)
			, Event(false)
		{
		}

		void reset()
		{
			Event::reset();
			//_state->_ready = false;
			_state->_data1 = Data1();
			_state->_data2 = Data2();
			_state->_data3 = Data3();
		}

		void wait()
		{
			//if(!_state->_ready)
			{
				Event::wait();
				//_state->_ready = true;
			}
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

		Data3 &data3()
		{
			wait();
			return _state->_data3;
		}
		Data2 &data3NoWait()
		{
			return _state->_data3;
		}
	public:
		typedef void result_type;

		void operator()(const Data1 &data1, const Data2 &data2, const Data3 &data3)
		{
			_state->_data1 = data1;
			_state->_data2 = data2;
			_state->_data3 = data3;
			set();
		}

	};
}

#endif
