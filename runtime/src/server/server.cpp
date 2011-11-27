#include "pch.h"
#include "server.hpp"
#ifdef WIN32
#	include <conio.h>
#else
#	include <poll.h>
#endif
#include <signal.h>

#include "async/iservice.hpp"
#include "net/iserverSessionManager.hpp"
#include <boost/thread.hpp>
#include <iostream>



namespace server
{


	volatile bool bStop = false;
	void onSignal(int /*sig*/)
	{
		//printf("signal %d\n", sig);
		bStop = true;
	}




	//////////////////////////////////////////////////////////////////////////
	Server::Server()
		: _plugs(NULL)
	{

	}
	
	//////////////////////////////////////////////////////////////////////////
	Server::~Server()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void Server::run(pluma::Pluma *plugs, const char *host, const char *service)
	{
		assert(!_plugs);
		_plugs = plugs;

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

		try
		{
			//////////////////////////////////////////////////////////////////////////
			//поднять асинхронный двиг
			_async = _plugs->create<async::IServiceProvider>();
			assert(_async);
			_async->balance(4);



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

			_async->stop();
			_async.reset();
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

		_plugs = NULL;
	}

	//////////////////////////////////////////////////////////////////////////
	pluma::Pluma *Server::getPlugs()
	{
		return _plugs;
	}

	//////////////////////////////////////////////////////////////////////////
	async::IServicePtr Server::getAsync()
	{
		return _async;
	}

}
