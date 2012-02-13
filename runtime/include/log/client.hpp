#include "log/api.h"
#include <log4cplus/logger.h>
#include <log4cplus/layout.h>
#include <log4cplus/helpers/pointer.h>
#include <log4cplus/fileappender.h>



/*!	\ingroup log
	\file
	\brief Заголовочный файл для инициализации экземпляра лога
	
	В этом заголовке определены конструкции для инициализации экземпляра лога и
	логирующие макросы.

	Перед подключением этого заголовка необходимо определит имя лога в макрос LOG_NAME
*/


//////////////////////////////////////////////////////////////////////////
/*!	\ingroup log
	\brief Головное пространство имен модуля log

	Наименование по идее должно бы быть "log", но это имя уже занято под логарифм
	из стандартной библиотеки, поэтому имя "log_".

	Для пользователя это пространство имен не очень то и нужно, он использует макросы
	в основном.


*/
namespace log_
{
	/*! \ingroup log
		\brief Фиктивный экспорт, без него не генерируется архив импорта, не подгружается библиотека
	*/
	LOG_API void instanceInitialized(log4cplus::Logger &instance);
}


//////////////////////////////////////////////////////////////////////////
/*!	\ingroup log
	\def LOG_NAME
	\brief Имя экземпляра лога

	Перед использованием возможностей логирования пользователь должен объявить экземпляр лога.
	Это делается так:
	\code
		#define LOG_NAME myLog
		#include "log/client.hpp"
	\endcode

	После такого кода будет сформирован лог с именем myLog. При запуске программы будет 
	создан файл log/myLog, все логируемые сообщения будут попадать в него. Кроме файла - 
	сообщения будут продублированы в родительские логи рекурсивно. На самом верхнем уровне
	находится лог с именем root, он выводит сообщения не только в файл но и на консоль.

	Примеры:
	\code
		#define LOG_NAME myLog
		#include "log/client.hpp"
	\endcode
	- логируемые сообщения попадут в файл 'log/myLog', в файл 'log/root' и на консоль

	\code
		#define LOG_NAME myLog_subLog
		#include "log/client.hpp"
	\endcode
	- логируемые сообщения попадут в файл 'log/myLog.subLog', в файл 'log/myLog', в файл 'log/root' и на консоль

	Значение макроса LOG_NAME должно сохранятся до тех пор пока используются логирующие 
	макросы (WLOG, ...).
*/
#ifndef LOG_NAME
#define LOG_NAME main
#endif

#ifndef LOG_TOSTRING2
#	define LOG_TOSTRING2(x) #x
#endif
#ifndef LOG_TOSTRING
#	define LOG_TOSTRING(x) LOG_TOSTRING2(x)
#endif


#ifndef LOG_CONCAT2
#	define LOG_CONCAT2(x,y) x ## y
#endif
#ifndef LOG_CONCAT
#	define LOG_CONCAT(x,y) LOG_CONCAT2(x,y)
#endif

namespace log_
{
	//////////////////////////////////////////////////////////////////////////
	template <bool b>
	struct LOG_CONCAT(StaticLoggerHolder, LOG_NAME)
	{
		static log4cplus::Logger _instance;

		//////////////////////////////////////////////////////////////////////////
		static log4cplus::Logger initializer(std::string name)
		{
			bool hasDot = false;
			{
				std::string::size_type pos = 0;
				while((pos = name.find('_', pos)) != std::string::npos)
				{
					name.replace(pos, 1, 1, '.');
					hasDot = true;
					pos++;
				}
			}

			std::string logformat = "[%t] %d{%H:%M:%S.%q} %p %c: %m%n";
			using namespace log4cplus;


			Logger result = Logger::getInstance(name);

			SharedAppenderPtr fileApp(new DailyRollingFileAppender("../../log/"+name, DAILY, true, 150));
			fileApp->setName("file");
			fileApp->setLayout(std::auto_ptr<Layout>(new PatternLayout(logformat)));
			result.addAppender(fileApp);

			//result.setLogLevel(TRACE_LOG_LEVEL);

			log_::instanceInitialized(result);
			return result;
		}

	};

	template <bool b> log4cplus::Logger LOG_CONCAT(StaticLoggerHolder, LOG_NAME)<b>::_instance = LOG_CONCAT(StaticLoggerHolder, LOG_NAME)<b>::initializer( LOG_TOSTRING(LOG_NAME) );
}


#define FLOG(msg)	LOG4CPLUS_FATAL(log_::LOG_CONCAT(StaticLoggerHolder, LOG_NAME)<true>::_instance, msg)
#define ELOG(msg)	LOG4CPLUS_ERROR(log_::LOG_CONCAT(StaticLoggerHolder, LOG_NAME)<true>::_instance, msg)
#define WLOG(msg)	LOG4CPLUS_WARN(log_::LOG_CONCAT(StaticLoggerHolder, LOG_NAME)<true>::_instance, msg)
#define ILOG(msg)	LOG4CPLUS_INFO(log_::LOG_CONCAT(StaticLoggerHolder, LOG_NAME)<true>::_instance, msg)
#define DLOG(msg)	LOG4CPLUS_DEBUG(log_::LOG_CONCAT(StaticLoggerHolder, LOG_NAME)<true>::_instance, msg)
#define TLOG(msg)	LOG4CPLUS_TRACE(log_::LOG_CONCAT(StaticLoggerHolder, LOG_NAME)<true>::_instance, msg)



//////////////////////////////////////////////////////////////////////////
/*!	\ingroup log
	\def FLOG(msg)
	\brief Логирование фатальной ошибки

	Уровень сообщения \b FATAL

	Может быть отключено во время компиляции объявлением 
		- LOG4CPLUS_DISABLE_FATAL

	\param msg выражение сообщения.
*/

/*!	\ingroup log
	\def ELOG(msg)
	\brief Логирование ошибки

	Уровень сообщения \b ERROR

	Может быть отключено во время компиляции объявлением
		- LOG4CPLUS_DISABLE_FATAL
		- LOG4CPLUS_DISABLE_ERROR

	\param msg выражение сообщения.
*/

/*!	\ingroup log
	\def WLOG(msg)
	\brief Логирование ошибки

	Уровень сообщения \b WARN

	Может быть отключено во время компиляции объявлением
		- LOG4CPLUS_DISABLE_FATAL
		- LOG4CPLUS_DISABLE_ERROR
		- LOG4CPLUS_DISABLE_WARN

	\param msg выражение сообщения.
*/

/*!	\ingroup log
	\def ILOG(msg)
	\brief Логирование информационного сообщения

	Уровень сообщения \b INFO

	Может быть отключено во время компиляции объявлением
		- LOG4CPLUS_DISABLE_FATAL
		- LOG4CPLUS_DISABLE_ERROR
		- LOG4CPLUS_DISABLE_WARN
		- LOG4CPLUS_DISABLE_INFO

	\param msg выражение сообщения.
*/

/*!	\ingroup log
	\def DLOG(msg)
	\brief Логирование отладочного сообщения

	Уровень сообщения \b DEBUG

	Может быть отключено во время компиляции объявлением
		- LOG4CPLUS_DISABLE_FATAL
		- LOG4CPLUS_DISABLE_ERROR
		- LOG4CPLUS_DISABLE_WARN
		- LOG4CPLUS_DISABLE_INFO
		- LOG4CPLUS_DISABLE_DEBUG

	\param msg выражение сообщения.
*/

/*!	\ingroup log
	\def TLOG(msg)
	\brief Логирование сообщения трассировки

	Уровень сообщения \b TRACE

	Может быть отключено во время компиляции объявлением
		- LOG4CPLUS_DISABLE_FATAL
		- LOG4CPLUS_DISABLE_ERROR
		- LOG4CPLUS_DISABLE_WARN
		- LOG4CPLUS_DISABLE_INFO
		- LOG4CPLUS_DISABLE_DEBUG
		- LOG4CPLUS_DISABLE_TRACE

	\param msg выражение сообщения.
*/
