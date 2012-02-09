﻿#ifndef _ASYNC_EVENT_HPP_
#define _ASYNC_EVENT_HPP_

#include "async/api.h"
#include <boost/shared_ptr.hpp>
#include <deque>

//////////////////////////////////////////////////////////////////////////
namespace async
{
	class EventImpl;
	typedef boost::shared_ptr<EventImpl> EventImplPtr;

	//////////////////////////////////////////////////////////////////////////
	/*!	\ingroup async
		\brief Примитив синхронизации - событие

		Имеет состояние "сигнальное"/"не-сигнальное", 
		позволяет устанавливать состояние и 
		ожидать сигнальное состояние.

		Может работать в режиме автоматического сброса сигнального состояния. 
		В этом режиме при установлении сигнального состояния (async::Event::set) будет 
		активирован только один ожидающий фибер (async::Event::wait) и состояние события 
		будет переведено в не-сигнальное.

		В обычном режиме при установлении сигнального состояния будут 
		активированы все ожидающие фиберы и состояние события 
		останется сигнальным - что то типа broadcast.

		Предоставляет метод для ожидания некольких событий одновременно (ака win.WaitForMultipleObjects)
	*/
	class ASYNC_API Event
	{
		friend class EventImpl;
		EventImplPtr	_impl;

	public:
		/*!	\brief Конструирование нового объекта

			Вновь созданный объект находится в не-сигнальном состоянии

			\param autoReset режим автоматического сброса, по умолчанию выключен
		*/
		Event(bool autoReset = false);

		/*!	\brief Установка состояния в сигнальное
			
			Если состояние уже было сигнальное - ничего не делает.

			Если состояние было не-сигнальное и никто не ожидает (async::Event::wait) это событие - то состояние переводится в сигнальное.

			Если состояние было не-сигнальное и есть ожидающие - то, в зависимости от режима автосброса:
				-	автосброс установлен\n
					будет активирован первый (который раньше всех вызвал async::Event::wait) из ожидающих фиберов, состояние переключится в не-сигнальное. Чтобы активировать следующий фибер - надо снова вызвать async::Event::set
				-	автосброс не установлен\n
					будут активированы все ожидающие фиберы, состояние останется сигнальным
		*/
		void set();

		/*!	\brief Установка состояния в не-сигнальное
	
			Если состояние уже было не-сигнальное - ничего не делает.

			Этот метод удобно использовать вне режима автосброса, для организации нового ожидания
		*/
		void reset();

		/*!	\brief проверка сигнального состояния
			\return признак сигнального состояния
		*/
		bool isSet();

		/*!	\brief Блокирование текущего фибера до наступления сигнального состояния
			
			Если текущее состояние уже является сигнальным - то, в зависимости от режима автосброса
				-	автосброс установлен\n
					состояние переключится в не-сигнальное, фибер продолжит исполнение без ожидания
				-	автосброс не установлен\n
					состояние останется сигнальным, фибер продолжит исполнение без ожидания

			Если текущее состояние является не-сигнальным - то фибер будет приостановлен и запомнен во внутренней очереди ожидающих. Фибер будет активирован после вызова async::Event::set
		*/
		void wait();

	public:

		/*!	\brief Демультиплексор для ожидания любого события из набора

			принимает массив событий в виде двух указателей

			\param begin указатель на начало массива событий
			\param end указатель на конец (элемент за последним, как для итераторов) массива событий

			\return указатель на событие, которое перешло в сигнальное состояние раньше других
		*/
		static Event *waitAny(Event *begin, Event *end);
	};
}

#endif
