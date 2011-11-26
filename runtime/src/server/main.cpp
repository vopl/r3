#include "pluma/pluma.hpp"
#include "async/iservice.hpp"
#include "net/iconnector.hpp"
#include "net/iserverSessionManager.hpp"
#include "net/iclientSession.hpp"

#include <conio.h>
#include <signal.h>
#include <boost/thread.hpp>
#include <iostream>


volatile bool bStop = false;
void onSignal(int /*sig*/)
{
	//printf("signal %d\n", sig);
	bStop = true;
}

int main(int argc, char* argv[])
{
	signal(SIGINT, onSignal);
	signal(SIGILL, onSignal);
	signal(SIGFPE, onSignal);
	signal(SIGSEGV, onSignal);
	signal(SIGTERM, onSignal);
	signal(SIGABRT, onSignal);
	signal(SIGBREAK, onSignal);

	try
	{

		pluma::Pluma plugins;
		// Tell plugins manager to accept providers of the type DeviceProvider
		plugins.acceptProviderType<async::IServiceProvider>();
		plugins.acceptProviderType<net::IConnectorProvider>();
		plugins.acceptProviderType<net::IServerSessionManagerProvider>();
 		plugins.acceptProviderType<net::IClientSessionProvider>();
		// Load library "standard_devices" from folder "plugins"
		plugins.loadFromFolder("../plug");

		std::vector<async::IServiceProvider *> providers;
		plugins.getProviders(providers);

		assert(!providers.empty());

		async::IServicePtr asrv(providers.front()->create());
		asrv->balance(4);
		do
		{

			if(_kbhit())
			{
				char ch=_getch();
				switch(ch)
				{
				case 'e':
					bStop = true;
					std::cout<<"exit"<<std::endl;
					break;
				default:
					std::cout<<"what?"<<std::endl;
					break;
				}
			}
			else
			{
				boost::thread::sleep(boost::get_system_time() + boost::posix_time::milliseconds(50));
			}
		} while(!bStop);

		asrv->stop();
		asrv.reset();
		//instance.reset();
	}
	catch(const std::exception &e)
	{
		std::cerr<<"std::exception: "<<e.what()<<std::endl;;
	}
	catch(...)
	{
		std::cerr<<"unknown exception";
	}

	return EXIT_SUCCESS;
}

