
#include <log4cplus/logger.h>
#include <log4cplus/layout.h>
#include <log4cplus/helpers/pointer.h>
#include <log4cplus/fileappender.h>

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

			SharedAppenderPtr fileApp(new DailyRollingFileAppender("../log/"+name, DAILY, true, 150));
			fileApp->setName("file");
			fileApp->setLayout(std::auto_ptr<Layout>(new PatternLayout(logformat)));
			result.addAppender(fileApp);

			//result.setLogLevel(TRACE_LOG_LEVEL);
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

