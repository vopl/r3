#ifndef _ASYNC_SERVICE_HPP_
#define _ASYNC_SERVICE_HPP_

#include "async/api.h"
#include "async/exception.hpp"
#include "async/event.hpp"
#include "async/future.hpp"

#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/asio/io_service.hpp>

namespace async
{
	class ServiceImpl;
	typedef boost::shared_ptr<ServiceImpl> ServiceImplPtr;

	//////////////////////////////////////////////////////////////////////////
	/*!	\ingroup async
		\brief Головная служба

		Предназначена для управления подсистемой асинхронности
			- запуск/останов
			- балансировка количества рабочих потоков
			- предоставление экземпляра boost::asio службы
			- различные вспомогательные функции (запуск функтора на фибере, таймауты, ...)

		примерный сценарий использования:
		\code
			//создать экземпляр службы
			async::Service asrv(false);

			//запустить службу c 4 рабочими потоками
			asrv.start(4);

			//запустить полезный код
			asrv.spawn(bind(&myCode, myParam));

			//тормозить текущий поток по логике работы кода
			sleep(500);

			//остановить
			asrv.stop();
		\endcode

		\code
			//этот код будет вызван в контексте фибера
			void myCode(int myParam)
			{
				//работать асинхронно, использовать async
				//async::spawn(myCode2);
				//async::timeout(220).wait();
				//async::yield();
			}
		\endcode

		Объект может быть пустым (не инициализирован), это удобно использовать когда необходимо 
		наличие объекта но не нужен его функционал. Например, в классе "сервер" сделать 
		поле 
		\code
			async::Service _asrv
		\endcode
		и если вдруг сервер запускается с целью, например, "проверка конфигурации" - 
		то служба не будет сконструирована.

		Пустая служба не потребляет никаких ресурсов.
		Пустую службу можно переинициализировать в рабочую через оператор присваивания или 
		конструктор копирования.

		Этот класс (впрочем, как и все остальные в этом модуле) реализован через pimpl, 
		один и тот же impl может одновременно использоваться из нескольких Service.
	*/
	class ASYNC_API Service
	{
		ServiceImplPtr _impl;

	public:
		/*! \brief Конструирование нового объекта службы

			\param isNull признак пустой службы.

			Пустую службу можно переинициализировать в рабочую через оператор присваивания или 
			конструктор копирования.
			\code
				async::Service mySrv(true); //mySrv - пустая
				mySrv = async::Service();	//а теперь уже нет
			\endcode

		*/
		Service(bool isNull=true);

		/*! \brief Конструктор копирования

			Вновь созданный объект будет использовать тот же самый impl что и у исходного
		*/
		Service(const Service &from);

		/*!	\brief Разрушение
			\pre если impl уникален - то он будет разрушатся тоже, тогда служба должна быть остановлена заранее
		*/
		~Service();

		//! Проверка на пустую службу
		operator bool() const;

		//! Проверка на пустую службу
		bool operator!() const;

		//! сброс службы в пустую
		void reset();

		/*!	\brief Запуск
			
			\param numThreads количество рабочих потоков, лучше делать поменьше (для клиента - 1, для сервера - по числу аппаратных потоков)
			\param onThreadStart пользовательский функтор, будет вызван из рабочего потока при его запуске
			\param onThreadStop пользовательский функтор, будет вызван из рабочего потока при его останове
		*/
		void start(
			size_t numThreads,
			const boost::function<void ()> &onThreadStart = boost::function<void ()>(),
			const boost::function<void ()> &onThreadStop = boost::function<void ()>());

		void balance(size_t numThreads);
		void stop();

		void spawn(const boost::function<void ()> &code);

		Future<boost::system::error_code> timeout(size_t millisec);
		void cancelAllTimeouts();

		boost::asio::io_service &io();
		bool setAsGlobal(bool force);
	};


	/// выполнить кусок кода асинхронно
	ASYNC_API void spawn(const boost::function<void ()> &code);

	/// приостановка фибера на заданное время
	ASYNC_API Future<boost::system::error_code> timeout(size_t millisec);

	/// выполнить кусок кода синхронно
	ASYNC_API void exec(const boost::function<void ()> &code);

	/// прервать текущий фибер в пользу других, исполнение будет продолжено по очереди шедулера
	ASYNC_API void yield();

	/// текущий экземпляр проактора
	ASYNC_API boost::asio::io_service &io();

	/// признак наличия службы для текущего потока
	ASYNC_API bool serviceExists();

	/// текущий экземпляр службы
	ASYNC_API Service service();
}

#include "async/asioBridge.hpp"

//////////////////////////////////////////////////////////////////////////
//для asio мост в фиберы
namespace async
{
	/// TODO add comments
    template <class Handler>
    AsioBridge<Handler> bridge(const Handler &handler)
    {
		return AsioBridge<Handler>(handler);
    }
}
#endif
