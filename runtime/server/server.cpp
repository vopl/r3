// server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <signal.h>
#include "r3/server/instance.hpp"

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

// 		instance.setDBInfo("dbname=test user=postgres password=postgres port=5432")

		net::AsyncService asrv;
		asrv.balance(4);
		r3::server::Instance instance(asrv);

		instance.setAddress("localhost", "29431");
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
		instance.setAddress("", "");

		asrv.stop();
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

