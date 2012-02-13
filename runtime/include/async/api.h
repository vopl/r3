/*!	\defgroup async Асинхронность (async)
	
	Поддержка
		- многопоточности, для утилизации всех аппаратных потоков машины
		- асинхронности, для утилизации разряженного по времени потока действий

	Головная служба реализована с использованием boost::asio, на базе которой можно 
	реализовать эффективный сетевой ввод-вывод.

	Количество потоков исполнения предлагается выставлять по количеству аппаратных 
	потоков. Можно менять прямо в рантайме.

	Асинхронность реализуется на базе fiber(windows)/ucontext(posix).
	
	Для синхронизации асинхронности предлагаются несколько прмитивов, такие как событие, 
	мутекс.
	
	Устройство исполняющей системы примерно следующее:
	
	Есть несколько (по числу аппаратных потоков) рабочих потоков, на которых исполняются 
	циклы проактора asio, эти циклы выгребают готовые события asio (completition handlers),
	и запускают фиберный шедулер, который создает фиберы и исполняет в них код из 
	completition handlers.

	Есть несколько фиберов для исполнения пользовательского кода. Сompletition handlers 
	исполняются в контексте какого то фибера. Пока эти Сompletition handlers исполняются 
	на фибере - они могут:
		- инициировать новые асинхронные исполнения (создать функтор и передать его на 
			исполнение в async), 
		- синхронизироваться друг с другом за счет объектов синхронизации (event, mutex, 
			future) и
		- могут завершатся, тогда исполняющий фибер будет готов для нового кода
*/

/*!	\ingroup async
	\def ASYNC_API
	\brief Поддержка экспорта/импорта интерфейсным символов модуля async
	
	Актуален только для windows, при сборке модуля выставляется в экспорт, при сборках 
	пользовательского кода - в импорт
*/

#if defined OS_WINDOWS
#   ifdef libasync_EXPORTS
#	    define ASYNC_API __declspec(dllexport)
#   else
#	    define ASYNC_API __declspec(dllimport)
#   endif
#else
#	    define ASYNC_API
#endif

//////////////////////////////////////////////////////////////////////////
/*!	\ingroup async
	\namespace async
	\brief Головное пространство имен модуля async
*/