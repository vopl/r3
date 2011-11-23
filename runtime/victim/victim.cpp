// victim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <boost/bind.hpp>

#include "net/asyncService.hpp"

#include "net/serverSessionManager.hpp"
#include "net/clientSession.hpp"

//#define LF std::cout<<__FUNCTION__<<std::endl;
#define LF 

//////////////////////////////////////////////////////////////////////////
void onThreadStart()
{
	LF;
}

//////////////////////////////////////////////////////////////////////////
void onThreadStop()
{
	LF;
}











void onServerSendOk(net::ServerSession ss);
void onServerSendFail(boost::system::error_code ec);

//////////////////////////////////////////////////////////////////////////
void onServerReceiveOk(net::ServerSession ss)
{
	net::SPacket p;
	p._size = 10;
	p._data = boost::shared_array<char>(new char[p._size]);
	ss.send(p, 
		boost::bind(onServerSendOk, ss),
		onServerSendFail);

	LF;
}

//////////////////////////////////////////////////////////////////////////
void onServerReceiveFail(boost::system::error_code ec)
{
	LF;
}

//////////////////////////////////////////////////////////////////////////
void onServerSendOk(net::ServerSession ss)
{
	ss.receive( 
		boost::bind(onServerReceiveOk, ss),
		onServerReceiveFail);
	LF;
}

//////////////////////////////////////////////////////////////////////////
void onServerSendFail(boost::system::error_code ec)
{
	LF;
}

//////////////////////////////////////////////////////////////////////////
void onServerSessionManagerReady(net::ServerSession ss)
{
	net::SPacket p;
	p._size = 10;
	p._data = boost::shared_array<char>(new char[p._size]);
	ss.send(p, 
		boost::bind(onServerSendOk, ss),
		onServerSendFail);
	LF;
}

//////////////////////////////////////////////////////////////////////////
void onServerSessionManagerError(boost::system::error_code ec)
{
	LF;
}





void onClientSendOk(net::ClientSession cs);
void onClientSendFail(boost::system::error_code ec);

//////////////////////////////////////////////////////////////////////////
void onClientReceiveOk(net::ClientSession cs)
{
	net::SPacket p;
	p._size = 10;
	p._data = boost::shared_array<char>(new char[p._size]);
	cs.send(p, 
		boost::bind(onClientSendOk, cs),
		onClientSendFail);

	LF;
}

//////////////////////////////////////////////////////////////////////////
void onClientReceiveFail(boost::system::error_code ec)
{
	LF;
}

//////////////////////////////////////////////////////////////////////////
void onClientSendOk(net::ClientSession cs)
{
	cs.receive( 
		boost::bind(onClientReceiveOk, cs),
		onClientReceiveFail);
	LF;
}

//////////////////////////////////////////////////////////////////////////
void onClientSendFail(boost::system::error_code ec)
{
	LF;
}


//////////////////////////////////////////////////////////////////////////
void onClientSessionReady(net::ClientSession cs, size_t numChannels)
{
	net::SPacket p;
	p._size = 10;
	p._data = boost::shared_array<char>(new char[p._size]);
	cs.send(p, 
		boost::bind(onClientSendOk, cs),
		onClientSendFail);

	static int k(0);
	std::cout<<__FUNCTION__ ": "<<k++<<std::endl;
	LF;
}

//////////////////////////////////////////////////////////////////////////
void onClientSessionError(size_t numChannels, boost::system::error_code ec)
{
	LF;
}

//////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
	net::AsyncService nas;

	nas.start(10, onThreadStart, onThreadStop);

	net::Connector c1(nas);
	net::ServerSessionManager ssm(c1, "localhost", "3000");
	ssm.start(
		onServerSessionManagerReady,
		onServerSessionManagerError);

	net::Connector c2(nas);
	net::ClientSession cs(c2, "localhost", "3000");
	cs.start(net::nullClientSid, 200,
		boost::bind(onClientSessionReady, cs, _1),
		onClientSessionError);

	char ch;
	std::cin>>ch;

	ssm.stop();
	cs.close();

	nas.stop();

	std::cout<<"\n\nall stopped"<<std::endl;
	std::cin>>ch;

	return 0;
}

