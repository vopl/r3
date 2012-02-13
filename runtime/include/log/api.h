/*!	\defgroup log Логирование (log)

	Поддержка логирования

	Низкоуровневый функционал логирования реализован за счет библиотеки log4cplus
	http://log4cplus.sourceforge.net/. Данный модуль является тонкой надстройкой 
	над этой библиотекой и предоставляет следующие функции:
		- короткие удобные имена логирующих макросов (WLOG vs LOG4CPLUS_WARN)
		- удобную инициализацию логов

	Сценарий использования примерно следующий:

		-# объявить лог
		\code
			#define LOG_NAME async
			#include "log/client.hpp"
		\endcode
		-# производить логирование
		\code
			WLOG("my log message: "<<220<<'c');
		\endcode

	Иерархия логов следующая
		- root (на консоль и в файл 'log/root')
			- myLog1 (в файл 'log/myLog1')
			- myLog2 (в файл 'log/myLog2')
				- myLog2_subLog (в файл 'log/myLog2.subLog'))

	Формат строки лога для файла
	\verbatim
		[%t] %d{%H:%M:%S.%q} %p %c: %m%n
	\endverbatim
		- [%t]\n
			ид потока
		- %d{%H:%M:%S.%q}\n
			дата время
		- %p\n
			маркер уровня сообщения (FATAL ERROR WARN INFO DEBUG TRACE)
		- %c\n
			имя лога
		- %m\n
			сообщение
		- %n\n
			конец строки
	
	пример выводимой строки:
	\verbatim
		[7976] 10:00:38.703 INFO async: start
	\endverbatim

	Формат строки лога для консоли примерно такой же, но немного выровнены ид потока и маркер уровня сообщения
	\verbatim
		[%-5t] %d{%H:%M:%S.%q} %-5p %c: %m%n
	\endverbatim

	Ограничивать уровень сообщений в compile time можно средствами самого log4cplus, 
	определив макросы LOG4CPLUS_DISABLE_XXX
*/

/*!	\ingroup log
	\def LOG_API
	\brief Поддержка экспорта/импорта интерфейсным символов модуля логирования
	
	Актуален только для windows, при сборке модуля выставляется в экспорт, при сборках 
	пользовательского кода - в импорт
*/

#if defined OS_WINDOWS
#   ifdef liblog_EXPORTS
#	    define LOG_API __declspec(dllexport)
#   else
#	    define LOG_API __declspec(dllimport)
#   endif
#else
#   define LOG_API
#endif
