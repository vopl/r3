// victim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <boost/bind.hpp>

#include "net/asyncService.hpp"

#include "net/serverSessionManager.hpp"
#include "net/clientSession.hpp"

//////////////////////////////////////////////////////////////////////////
void onThreadStart()
{
	std::cout<<__FUNCTION__<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
void onThreadStop()
{
	std::cout<<__FUNCTION__<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
void onAcceptSendOk()
{
	std::cout<<__FUNCTION__<<std::endl;
}
void onAcceptSendFail(boost::system::error_code ec)
{
	std::cout<<__FUNCTION__<<ec<<std::endl;
}
//////////////////////////////////////////////////////////////////////////
void onAcceptReceiveOk(const net::SPacket &p)
{
	std::cout<<__FUNCTION__<<std::endl;
}
void onAcceptReceiveFail(boost::system::error_code ec)
{
	std::cout<<__FUNCTION__<<ec<<std::endl;
}
void onAccept(net::Channel &ch)
{
	net::SPacket p;
	p._size = 10;
	p._data = boost::shared_array<char>(new char[p._size]);
	ch.send(p, onAcceptSendOk, onAcceptSendFail);
	ch.receive(onAcceptReceiveOk, onAcceptReceiveFail);
	std::cout<<__FUNCTION__<<std::endl;
}

void onConnectSendOk()
{
	std::cout<<__FUNCTION__<<std::endl;
}
void onConnectSendFail(boost::system::error_code ec)
{
	std::cout<<__FUNCTION__<<ec<<std::endl;
}
//////////////////////////////////////////////////////////////////////////
void onConnectReceiveOk(const net::SPacket &p)
{
	std::cout<<__FUNCTION__<<std::endl;
}
void onConnectReceiveFail(boost::system::error_code ec)
{
	std::cout<<__FUNCTION__<<ec<<std::endl;
}
void onConnect(net::Channel &ch)
{
	net::SPacket p;
	p._size = 10;
	p._data = boost::shared_array<char>(new char[p._size]);
	ch.send(p, onConnectSendOk, onConnectSendFail);
	ch.receive(onConnectReceiveOk, onConnectReceiveFail);
	std::cout<<__FUNCTION__<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
void onAcceptError(boost::system::error_code ec)
{
	std::cout<<__FUNCTION__<<ec<<std::endl;
}
//////////////////////////////////////////////////////////////////////////
void onConnectError(boost::system::error_code ec)
{
	std::cout<<__FUNCTION__<<ec<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
void onServerSessionManagerReady(net::ServerSession ss)
{
	std::cout<<__FUNCTION__<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
void onServerSessionManagerError(boost::system::error_code ec)
{
	std::cout<<__FUNCTION__<<ec<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
void onClientSessionReady(net::ClientSession cs, size_t numChannels)
{
	std::cout<<__FUNCTION__<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
void onClientSessionError(size_t numChannels, boost::system::error_code ec)
{
	std::cout<<__FUNCTION__<<ec<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	net::AsyncService nas;

	nas.start(1, onThreadStart, onThreadStop);

	net::Connector c(nas);

	net::ServerSessionManager ssm(c, "localhost", "3000");
	ssm.start(
		onServerSessionManagerReady,
		onServerSessionManagerError);

	net::ClientSession cs(c, "localhost", "3000");
	cs.start(net::nullClientSid, 2,
		boost::bind(onClientSessionReady, cs, _1),
		onClientSessionError);

	char ch;
	std::cin>>ch;

	ssm.stop();
	cs.close();

	nas.stop();

	return 0;
}

