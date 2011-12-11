#include "pluma/pluma.hpp"
#include "server/iserver.hpp"
#define LOG_NAME "server"
#include "log/client.hpp"
#include <boost/thread.hpp>
#include <iostream>

#ifdef WIN32
#	include <conio.h>
#else
#	include <poll.h>
#endif
#include <signal.h>



volatile bool bStop = false;
void onSignal(int /*sig*/)
{
	//printf("signal %d\n", sig);
	bStop = true;
}

//удалено не будет
static pluma::Pluma *g_plugins = new pluma::Pluma;


int main(int argc, char* argv[])
{
	LOGI("startup");


	signal(SIGINT, onSignal);
	signal(SIGILL, onSignal);
	signal(SIGFPE, onSignal);
	signal(SIGSEGV, onSignal);
	signal(SIGTERM, onSignal);
	signal(SIGABRT, onSignal);
#ifdef WIN32
	signal(SIGBREAK, onSignal);
#else
	signal(SIGKILL, onSignal);
#endif



	//////////////////////////////////////////////////////////////////////////
	LOGI("load plugins");
	g_plugins->loadFromFolder("../plug");

	LOGI("create server");
	server::IServerPtr srv(g_plugins->create<server::IServerProvider>());
	assert(srv);
	if(!srv)
	{
		LOGF("unable to create server plugin");
		return EXIT_FAILURE;
	}

	srv->start(g_plugins, "localhost", "29431");

	//////////////////////////////////////////////////////////////////////////
#ifdef WIN32
#else
	pollfd stdin_pfd[1]={0, POLLIN|POLLRDNORM|POLLRDBAND|POLLPRI,0};
#endif
	do
	{
		char ch;
#ifdef WIN32
		if(_kbhit())
		{
			ch = (char)_getch();
#else
		if(0<poll(stdin_pfd,1,0))
		{
			if(1 > read(0, &ch, 1))
			{
				break;
			}
#endif
			switch(ch)
			{
			case 'e':
				bStop = true;
				LOGI("exit request");
				std::cout<<"exit"<<std::endl;
				break;
			default:
				std::cout<<"what?"<<std::endl;
				break;
			}
		}
		else
		{
			//std::cout<<"sleep"<<std::endl;
			boost::thread::sleep(boost::get_system_time() + boost::posix_time::milliseconds(50));
		}
	} while(!bStop);


	LOGI("stopping server");
	srv->stop();
	srv.reset();

	LOGI("exiting");
	return EXIT_SUCCESS;
}

