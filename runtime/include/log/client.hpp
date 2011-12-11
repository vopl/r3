#ifndef _LOG_CLIENT_HPP_
#define _LOG_CLIENT_HPP_

#include <log4cplus/logger.h>
#include <log4cplus/layout.h>
#include <log4cplus/helpers/pointer.h>
#include <log4cplus/fileappender.h>

namespace log_
{
	//////////////////////////////////////////////////////////////////////////
	template <bool b>
	struct StaticLoggerHolder
	{
		static log4cplus::Logger _instance;

		//////////////////////////////////////////////////////////////////////////
		static log4cplus::Logger initializer(const std::string name)
		{
			std::string logformat="%d{%H:%M:%S} %-5p [%t]:%m%n";
			using namespace log4cplus;


			Logger result = Logger::getInstance(name);

			SharedAppenderPtr fileApp(new RollingFileAppender("../log/"+name));
			fileApp->setName("file");
			fileApp->setLayout(std::auto_ptr<Layout>(new PatternLayout(logformat)));
			result.addAppender(fileApp);

			result.setLogLevel(TRACE_LOG_LEVEL);

			return result;
		}

	};

#ifndef LOG_NAME
#define LOG_NAME "main"
#endif

	template <bool b>
	log4cplus::Logger StaticLoggerHolder<b>::_instance = StaticLoggerHolder<b>::initializer(LOG_NAME);



#define LOGF(...)	LOG4CPLUS_FATAL(log_::StaticLoggerHolder<true>::_instance, __VA_ARGS__)
#define LOGE(...)	LOG4CPLUS_ERROR(log_::StaticLoggerHolder<true>::_instance, __VA_ARGS__)
#define LOGW(...)	LOG4CPLUS_WARN(log_::StaticLoggerHolder<true>::_instance, __VA_ARGS__)
#define LOGI(...)	LOG4CPLUS_INFO(log_::StaticLoggerHolder<true>::_instance, __VA_ARGS__)
#define LOGD(...)	LOG4CPLUS_DEBUG(log_::StaticLoggerHolder<true>::_instance, __VA_ARGS__)
#define LOGT(...)	LOG4CPLUS_TRACE(log_::StaticLoggerHolder<true>::_instance, __VA_ARGS__)
}

#endif
