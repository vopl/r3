#include "pch.h"
#include "pgconnWrapper.hpp"
#include <Winsock2.h>

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::onWait(
		function<void()> ready, 
		const boost::system::error_code& error, 
		std::size_t bytes_transferre)
	{
		assert(!bytes_transferre);
		if(ready)
		{
			ready();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	PGconnWrapper::PGconnWrapper(PGconn *lowConn, boost::asio::io_service &io_service)
		: _lowConn(lowConn)
		, _sock(io_service)
	{

		int rawSock = PQsocket(lowConn);
		sockaddr name;
		socklen_t name_len = sizeof(name);
		if(!getsockname(
			rawSock, 
			&name,
			&name_len))
		{
			int type;
			int length = sizeof(type);
			if(!getsockopt(rawSock, SOL_SOCKET, SO_TYPE, (char *)&type, &length))
			{

				SockProtocol protocol;
				protocol._family = name.sa_family;
				protocol._type = type;
				protocol._protocol = IPPROTO_TCP;

				_sock.assign(protocol, rawSock);
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	PGconnWrapper::~PGconnWrapper()
	{
		close();
	}

	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::close()
	{
		PQfinish(_lowConn);
		_lowConn = NULL;
	}

	//////////////////////////////////////////////////////////////////////////
	PGconnWrapper::operator PGconn *() const
	{
		return _lowConn;
	}

	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::waitRead(function<void()> ready)
	{
		_sock.async_receive(
			asio::null_buffers(), 
			bind(&PGconnWrapper::onWait, 
				ready, 
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
	}

	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::waitWrite(function<void()> ready)
	{
		_sock.async_send(
			asio::null_buffers(), 
			bind(&PGconnWrapper::onWait, 
			ready, 
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
	}

}
