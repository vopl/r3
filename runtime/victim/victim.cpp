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

#define PACKETSIZE 1024*64

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






net::SPacket randomPacket(size_t size)
{
	net::SPacket p;
	p._size = size;
	p._data = boost::shared_array<char>(new char[p._size]);
	for(size_t i(0); i<p._size; i++)
	{
		p._data[i] = (char)rand();
	}
	return p;
}




void onServerSendOk(net::ServerSession ss);
void onServerSendFail(boost::system::error_code ec);

//////////////////////////////////////////////////////////////////////////
void onServerReceiveOk(net::ServerSession ss)
{
	ss.send(randomPacket(PACKETSIZE), 
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
	ss.send(randomPacket(PACKETSIZE), 
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
	cs.send(randomPacket(PACKETSIZE), 
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
	cs.send(randomPacket(PACKETSIZE), 
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

	nas.start(20, onThreadStart, onThreadStop);

	net::Connector c1(nas);
	net::ServerSessionManager ssm(c1, "localhost", "3000");
	ssm.start(
		onServerSessionManagerReady,
		onServerSessionManagerError);

	//net::Connector c2(nas);
	net::ClientSession cs(c1, "localhost", "3000");
	cs.start(net::nullClientSid, 10,
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

