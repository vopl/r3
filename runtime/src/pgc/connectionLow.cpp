#include "pch.h"
#include "connectionLow.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	int ConnectionLow::sockFamily(int sock)
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
	int ConnectionLow::sockType(int sock)
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
	void ConnectionLow::waitSend(function<void(const system::error_code &)> ready)
	{
		_sock.async_send(asio::null_buffers(), _strand.wrap(bind(ready, _1)));
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionLow::waitRecv(function<void(const system::error_code &)> ready)
	{
		_sock.async_receive(asio::null_buffers(), _strand.wrap(bind(ready, _1)));
		//_sock.async_read(asio::null_buffers(), _strand.wrap(bind(ready, _1)));
	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionLow::ConnectionLow(PGconn *pgcon, asio::io_service &io_service)
		: _pgcon(pgcon)
		, _sock(io_service, PGSockProtocol(sockFamily(PQsocket(_pgcon)), sockType(PQsocket(_pgcon)), IPPROTO_TCP), PQsocket(_pgcon))
		, _strand(io_service)
		, _integerDatetimes(false)
	{
		PQsetnonblocking(_pgcon, 0);
	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionLow::~ConnectionLow()
	{
		assert(ecsOk != status());
		close();
	}

	//////////////////////////////////////////////////////////////////////////
	PGconn *ConnectionLow::pgcon()
	{
		return _pgcon;
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionLow::onOpen()
	{
		const char *csz = PQparameterStatus(_pgcon, "integer_datetimes");

		if(csz && !strcmp("on", csz))
		{
			_integerDatetimes = true;
		}
		else
		{
			_integerDatetimes = false;
		}

		//PQsetnonblocking(_pgcon, 0);
		PQsetClientEncoding(_pgcon, "UTF-8");
	}

	//////////////////////////////////////////////////////////////////////////
	EConnectionStatus ConnectionLow::status()
	{
		if(!_pgcon)
		{
			return ecsNull;
		}
		ConnStatusType status = PQstatus(_pgcon);
		return CONNECTION_BAD == status ? ecsLost : ecsOk;
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionLow::close()
	{
		if(_pgcon)
		{
			PQfinish(_pgcon);
			_pgcon = NULL;
			//_sock.assign(PGSockProtocol(0,0,0), -1);
			_integerDatetimes = false;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	bool ConnectionLow::integerDatetimes()
	{
		return _integerDatetimes;
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionLow::dispatch(function<void()> action)
	{
		_strand.dispatch(action);
	}


}