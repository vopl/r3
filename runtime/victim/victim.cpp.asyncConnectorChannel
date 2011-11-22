// victim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include "net/asyncService.hpp"
#include "net/connector.hpp"

//////////////////////////////////////////////////////////////////////////
void onThreadStart()
{
	std::cout<<"onThreadStart()"<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
void onThreadStop()
{
	std::cout<<"onThreadStop()"<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
void onAcceptSendOk()
{
	std::cout<<"void onAcceptSendOk()"<<std::endl;
}
void onAcceptSendFail(boost::system::error_code ec)
{
	std::cout<<"void onAcceptSendFail(boost::system::error_code ec)"<<ec<<std::endl;
}
//////////////////////////////////////////////////////////////////////////
void onAcceptReceiveOk(const net::SPacket &p)
{
	std::cout<<"void onAcceptReceiveOk(const net::SPacket &p)"<<std::endl;
}
void onAcceptReceiveFail(boost::system::error_code ec)
{
	std::cout<<"void onAcceptReceiveFail(boost::system::error_code ec)"<<ec<<std::endl;
}
void onAccept(net::Channel &ch)
{
	net::SPacket p;
	p._size = 10;
	p._data = boost::shared_array<char>(new char[p._size]);
	ch.send(p, onAcceptSendOk, onAcceptSendFail);
	ch.receive(onAcceptReceiveOk, onAcceptReceiveFail);
	std::cout<<"void onAccept(net::Channel &ch)"<<std::endl;
}

void onConnectSendOk()
{
	std::cout<<"void onConnectSendOk()"<<std::endl;
}
void onConnectSendFail(boost::system::error_code ec)
{
	std::cout<<"void onConnectSendFail(boost::system::error_code ec)"<<ec<<std::endl;
}
//////////////////////////////////////////////////////////////////////////
void onConnectReceiveOk(const net::SPacket &p)
{
	std::cout<<"void onConnectReceiveOk(const net::SPacket &p)"<<std::endl;
}
void onConnectReceiveFail(boost::system::error_code ec)
{
	std::cout<<"void onConnectReceiveFail(boost::system::error_code ec)"<<ec<<std::endl;
}
void onConnect(net::Channel &ch)
{
	net::SPacket p;
	p._size = 10;
	p._data = boost::shared_array<char>(new char[p._size]);
	ch.send(p, onConnectSendOk, onConnectSendFail);
	ch.receive(onConnectReceiveOk, onConnectReceiveFail);
	std::cout<<"void onConnect(net::Channel &ch)"<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
void onAcceptError(boost::system::error_code ec)
{
	std::cout<<"void onAcceptError(boost::system::error_code ec)"<<ec<<std::endl;
}
//////////////////////////////////////////////////////////////////////////
void onConnectError(boost::system::error_code ec)
{
	std::cout<<"void onConnectError(boost::system::error_code ec)"<<ec<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	net::AsyncService nas;

	nas.start(1, onThreadStart, onThreadStop);


	net::Connector nc(nas);
	nc.listen("localhost", "3000", 
		onAccept,
		onAcceptError);

	nc.connect("localhost", "3000",
		onConnect,
		onConnectError);

	char c;
	std::cin>>c;

	nc.unlisten("localhost", "3000");

	nas.stop();

	return 0;
}

