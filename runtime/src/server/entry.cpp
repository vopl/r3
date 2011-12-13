#include "pluma/pluma.hpp"
#include "server/iserver.hpp"

#define LOG_NAME entry
#include "log/client.hpp"

#include <boost/thread.hpp>
#include <iostream>

#ifdef WIN32
#	include <conio.h>
#else
#	include <poll.h>
#endif
#include <signal.h>

#include "utils/variant.hpp"

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

	utils::Variant v;
	std::string errors;
	bool b = v.load("P:\\projects\\r3\\repo\\runtime\\server\\test.js", &errors);

	std::cout<<(b?"success":"failure")<<std::endl;
	if(!b)
	{
		std::cout<<errors<<std::endl;
	}

	std::cout<<v<<std::endl;

	return EXIT_SUCCESS;
	ILOG("startup");


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
	ILOG("load plugins");
	g_plugins->loadFromFolder("../plug");

	ILOG("create server");
	server::IServerPtr srv(g_plugins->create<server::IServerProvider>());
	assert(srv);
	if(!srv)
	{
		FLOG("unable to create server");
		return EXIT_FAILURE;
	}

	if(!srv->start(g_plugins, "localhost", "29431"))
	{
		FLOG("unable to start server");
		return EXIT_FAILURE;
	}

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
				ILOG("exit request");
				break;
			default:
				ILOG("?");
				break;
			}
		}
		else
		{
			//std::cout<<"sleep"<<std::endl;
			boost::thread::sleep(boost::get_system_time() + boost::posix_time::milliseconds(50));
		}
	} while(!bStop);


	ILOG("stopping server");
	srv->stop();
	srv.reset();

	ILOG("shutdown");
	return EXIT_SUCCESS;
}

