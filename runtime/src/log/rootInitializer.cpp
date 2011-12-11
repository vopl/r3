#include <log4cplus/logger.h>
#include <log4cplus/layout.h>
#include <log4cplus/helpers/pointer.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/configurator.h>

namespace
{

	class _static_root_log4cplus_initializer
	{
	public:
		_static_root_log4cplus_initializer()
		{
			std::string logformat = "[%t] %d{%H:%M:%S.%q} %p %c: %m%n";
			using namespace log4cplus;


			BasicConfigurator config;
			config.configure();

			SharedAppenderPtr conApp(new ConsoleAppender());
			conApp->setName("STDOUT");
			conApp->setLayout(std::auto_ptr<Layout>(new PatternLayout(logformat)));
			//conApp->setThreshold(NOT_SET_LOG_LEVEL);





			SharedAppenderPtr fileApp(new DailyRollingFileAppender("../log/root", DAILY, true, 150));
			fileApp->setName("file");
			fileApp->setLayout(std::auto_ptr<Layout>(new PatternLayout(logformat)));
			//fileApp->setThreshold(WARN_LOG_LEVEL);

			Logger::getRoot().removeAllAppenders();
			Logger::getRoot().addAppender(conApp);
			Logger::getRoot().addAppender(fileApp);
		}
	} static initializer;
}
