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
			\pre если impl уникален - то он будет разрушатся тоже, тогда служба должна 
				быть остановлена заранее вызовом async::Service::stop
		*/
		~Service();

		/*! \brief Проверка на пустую службу

			\retval true если службы не пустая
			\retval false если службы пустая
		*/
		operator bool() const;

		/*! \brief Проверка на пустую службу

			\retval true если службы пустая
			\retval false если службы не пустая
		*/
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

		/*! \brief Балансировка количества рабочих потоков
			
			\param numThreads новое количество рабочих потоков
		*/
		void balance(size_t numThreads);

		/*! \brief Останов запущенной службы

			\pre на момент вызова служба должна быть запущена
		*/
		void stop();

		/*!	\brief Запуск пользовательского функтора в контексте фибера

			\param code пользовательский функтор к исполнению

			\pre вызов должен производится в рабочем потоке этого экземпляром службы
		*/
		void spawn(const boost::function<void ()> &code);

		/*!	\brief Таймаут

			\param millisec количество времени в миллисекундах
			
			\retval Future с кодом ошибки, он сработает по истечении времени 
				millisec (error_code будет OK) или при вызове 
				async::Service::cancelAllTimeouts (error_code будет не OK)

			\pre вызов должен производится в рабочем потоке этого экземпляром службы
			\pre ожидание Future должно производится в рабочем потоке этого экземпляром службы
		*/
		Future<boost::system::error_code> timeout(size_t millisec);

		/*!	\brief Отмена всех таймаутов

			Эту функцию удобно вызывать перед остановом службы
		*/
		void cancelAllTimeouts();

		/*! Доступ к внутреннему экземпляру службы asio
			
			\retval экземпляр службы asio
		*/
		boost::asio::io_service &io();

		/*!	\brief Установка данного экземпляра службы как "глобального"
			
			Это может быть полезно если служба всего одна на приложение и 
			необходимо иметь доступ к ней из любого потока.

			При вызове service() из потока, который не принадлежит asio - будет 
			возвращен глобальный экземпляр.

			\param force если ранее глобальный экземпляр уже был установлен - то вызов 
			async::Service::setAsGlobal(false) ничего не сделает, вернет false и глобальным останется старый
			экземпляр. Вызов async::Service::setAsGlobal(true) переустановит глобальный экземпляр на данный.

			\retval true если глобальный экземпляр успешно установлен
			\retval false если глобальный экземпляр не установлен, такое может быть если 
				ранее уже был зарегистрирован глобальный экземпляр и производится 
				вызов async::Service::setAsGlobal(false)
		*/
		bool setAsGlobal(bool force);
	};


	/*! \ingroup async
		\brief Запуск пользовательского функтора в контексте фибера

		Получает экземпляр службы для текущего потока аналогично async::service и вызывает 
		на нем async::Service::spawn

		\copydetails async::Service::spawn
	*/
	ASYNC_API void spawn(const boost::function<void ()> &code);

	/*! \ingroup async
		\brief Таймаут

		Получает экземпляр службы для текущего потока аналогично async::service и вызывает 
		на нем async::Service::timeout

		\copydetails async::Service::timeout
	*/
	ASYNC_API Future<boost::system::error_code> timeout(size_t millisec);

	/*!	\ingroup async
		\brief Выполнить кусок кода синхронно

		\param code пользовательский функтор к исполнению

		Функтор code будет выполнен в контексте фибера.

		\pre вызов должен производится в рабочем потоке службы async::Service или 
		в контексте фибера

		Если вызов производится в контексте фибера - то функтор будет просто вызван 
		без всяких дополнительных действий.

		Если вызов производится вне контекста фибера - то будет организован фибер и код
		будет выполнен в нем.

		Этот способ навязан особенностями asio, используется при проведении вызовов 
		completition handlers в контекст фибера, смотри async::bridge, async::AsioBridge
	*/
	ASYNC_API void exec(const boost::function<void ()> &code);

	/*!	\ingroup async
		\brief Приостановить текущий фибер в пользу других
		
		Исполнение приостановленного фибера будет продолжено по очереди шедулера

		\pre вызов должен производится в контексте фибера
	*/
	ASYNC_API void yield();

	/*! \ingroup async
		\brief Доступ к экземпляру службы asio

		\retval экземпляр службы asio, используемый в службе async

		Экземпляр службы, из которого будет предоставлено asio получается 
		аналогично async::service.
	*/
	ASYNC_API boost::asio::io_service &io();

	/*!	\ingroup async
		\brief Признак наличия службы для текущего потока

		\retval true если текущий поток находится под управлением службы asio или 
			зарегистрирован глобальный экземпляр (async::Service::setAsGlobal)
		\retval false если текущий поток не находится под управлением службы asio и
			не зарегистрирован глобальный экземпляр (async::Service::setAsGlobal)
	*/
	ASYNC_API bool serviceExists();

	/*!	\ingroup async
		\brief Доступ к текущему экземпляру службы

		\retval экземпляр службы, если текущий поток находится под управлением службы asio или 
			зарегистрирован глобальный экземпляр (async::Service::setAsGlobal)

		Если текущий поток не находится под управлением службы asio и не зарегистрирован 
		глобальный экземпляр (async::Service::setAsGlobal) - будет выброшено исключение
		async::exception.
	*/
	ASYNC_API Service service();
}

#include "async/asioBridge.hpp"

//////////////////////////////////////////////////////////////////////////
//для asio мост в фиберы
namespace async
{
	/*!	\ingroup async
		\brief Обертка для вызова пользовательского функутора в контексте фибера

		\param handler пользовательский функтор, который будет обернут

		\return обернутый функтор, при его вызове будет произведен вызов клиентского 
			функтора через async::exec

		Эту обертку необходимо использовать при формировании completition handlers для asio
	*/
    template <class Handler>
	async::AsioBridge<Handler> bridge(const Handler &handler)
    {
		return AsioBridge<Handler>(handler);
    }
}
#endif
