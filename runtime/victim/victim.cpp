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
void onServerSendOk(net::ServerSession ss)
{
	std::cout<<__FUNCTION__<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
void onServerSendFail(boost::system::error_code ec)
{
	std::cout<<__FUNCTION__<<ec<<std::endl;
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
	std::cout<<__FUNCTION__<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
void onServerSessionManagerError(boost::system::error_code ec)
{
	std::cout<<__FUNCTION__<<ec<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
void onClientSendOk(net::ClientSession cs)
{
	std::cout<<__FUNCTION__<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
void onClientSendFail(boost::system::error_code ec)
{
	std::cout<<__FUNCTION__<<ec<<std::endl;
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
	std::cout<<__FUNCTION__<<", "<<k++<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
void onClientSessionError(size_t numChannels, boost::system::error_code ec)
{
	std::cout<<__FUNCTION__<<ec<<std::endl;
}

//////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
	net::AsyncService nas;

	nas.start(1, onThreadStart, onThreadStop);

	net::Connector c1(nas);
	net::ServerSessionManager ssm(c1, "localhost", "3000");
	ssm.start(
		onServerSessionManagerReady,
		onServerSessionManagerError);

	net::Connector c2(nas);
	net::ClientSession cs(c2, "localhost", "3000");
	cs.start(net::nullClientSid, 2,
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

