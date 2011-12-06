#include "pch.h"
#include "pgconnWrapper.hpp"

#ifdef _WIN32
#	include <Winsock2.h>
#else
#	include <sys/socket.h>
#endif

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::onWaitRead(
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
	void PGconnWrapper::onWaitWrite(
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
	int PGconnWrapper::sockFamily(int sock)
	{
		sockaddr name;
		socklen_t name_len = sizeof(name);
		if(!getsockname(
			sock, 
			&name,
			&name_len))
		{
			return name.sa_family;
		}
		else
		{
			std::cerr<<__FUNCTION__<<": getsockname failed"<<std::endl;
		}
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	int PGconnWrapper::sockType(int sock)
	{
		int type;
		int length = sizeof(type);
		if(!getsockopt(sock, SOL_SOCKET, SO_TYPE, (char *)&type, &length))
		{
			return type;
		}
		else
		{
			std::cerr<<__FUNCTION__<<": getsockopt failed"<<std::endl;
		}
		return 0;
	}


	//////////////////////////////////////////////////////////////////////////
	PGconnWrapper::PGconnWrapper(PGconn *lowConn, boost::asio::io_service &io_service)
		: _lowConn(lowConn)
		, _sock(io_service, SockProtocol(sockFamily(PQsocket(_lowConn)), sockType(PQsocket(_lowConn)), IPPROTO_TCP), PQsocket(_lowConn))
		, _integerDatetimes(false)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	PGconnWrapper::~PGconnWrapper()
	{
		close();
	}

	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::onOpen()
	{
		const char *csz = PQparameterStatus(_lowConn, "integer_datetimes");

		if(csz)
		{
			if(!strcmp("on", csz))
			{
				_integerDatetimes = true;
			}
			else if(!strcmp("off", csz))
			{
				_integerDatetimes = false;
			}
			else
			{
				assert(0);
				_integerDatetimes = false;
			}
		}

		PQsetnonblocking(_lowConn, 1);
		PQsetClientEncoding(_lowConn, "UTF-8");
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
			bind(&PGconnWrapper::onWaitRead, 
				ready, 
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
	}

	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::waitWrite(function<void()> ready)
	{
		_sock.async_send(
			asio::null_buffers(), 
			bind(&PGconnWrapper::onWaitWrite, 
				ready, 
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
	}

}
