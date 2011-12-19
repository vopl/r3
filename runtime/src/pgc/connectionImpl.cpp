#include "pch.h"
#include "connectionImpl.hpp"
#include "async/result.hpp"

#include "result.hpp"
#include "bindData.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	int ConnectionImpl::sockFamily(int sock)
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
			ELOG(__FUNCTION__<<", getsockname failed");
		}
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	int ConnectionImpl::sockType(int sock)
	{
		int type;
		int length = sizeof(type);
		if(!getsockopt(sock, SOL_SOCKET, SO_TYPE, (char *)&type, &length))
		{
			return type;
		}
		else
		{
			ELOG(__FUNCTION__<<", getsockopt failed");
		}
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<system::error_code> ConnectionImpl::send0()
	{
		async::Result<system::error_code> h;
		_sock.async_send(asio::null_buffers(), _strand.wrap(bind(h, _1)));
		return h;
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<system::error_code> ConnectionImpl::recv0()
	{
		async::Result<system::error_code> h;
		_sock.async_receive(asio::null_buffers(), _strand.wrap(bind(h, _1)));
		return h;
	}


	//////////////////////////////////////////////////////////////////////////
	ConnectionImpl::ConnectionImpl(PGconn *pgcon, async::IServicePtr asrv)
		: _pgcon(pgcon)
		, _asrv(asrv)
		, _sock(asrv->get_io_service(), PGSockProtocol(sockFamily(PQsocket(_pgcon)), sockType(PQsocket(_pgcon)), IPPROTO_TCP), PQsocket(_pgcon))
		, _strand(asrv->get_io_service())
		, _integerDatetimes(false)
	{
		PQsetnonblocking(_pgcon, 0);
	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionImpl::~ConnectionImpl()
	{
		assert(ecsOk != status());
		close();
	}

	//////////////////////////////////////////////////////////////////////////
	PGconn *ConnectionImpl::pgcon()
	{
		return _pgcon;
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::onOpen()
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

		PQsetClientEncoding(_pgcon, "UTF-8");
		PQsetnonblocking(_pgcon, 0);
	}

	//////////////////////////////////////////////////////////////////////////
	EConnectionStatus ConnectionImpl::status()
	{
		if(!_pgcon)
		{
			return ecsNull;
		}
		ConnStatusType status = PQstatus(_pgcon);
		return CONNECTION_BAD == status ? ecsLost : ecsOk;
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::close()
	{
		if(_pgcon)
		{
			PQfinish(_pgcon);
			_pgcon = NULL;
			system::error_code ec;
// 			_sock.close(ec);
// 			if(ec)
// 			{
// 				std::cerr<<ec.message()<<std::endl;
// 			}
			_integerDatetimes = false;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	bool ConnectionImpl::integerDatetimes()
	{
		return _integerDatetimes;
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::dispatch(function<void()> action)
	{
		_strand.get_io_service().post(
			_strand.wrap(action));
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<IResultPtrs> ConnectionImpl::runQuery(const std::string &sql)
	{
		async::Result<IResultPtrs> res;
		if(!PQsendQueryParams (_pgcon, sql.c_str(), 0, NULL, NULL, NULL, NULL, 1))
		{
			ELOG(__FUNCTION__<<", "<<PQerrorMessage(_pgcon));
			res(IResultPtrs());
			return res;
		};

		dispatch(bind(&ConnectionImpl::processTransmission, shared_from_this(), res));
		
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::processTransmission(async::Result<IResultPtrs> res)
	{
		//слать
		while(PQflush(_pgcon))
		{
			system::error_code ec = send0().data();
			if(ec)
			{
				ELOG(__FUNCTION__<<", send, "<<ec<<", "<<PQerrorMessage(_pgcon));
				res.ready();
				return;
			}
		}

		//принимать
		for(;;)
		{
			if(PQisBusy(_pgcon))
			{
				system::error_code ec = recv0().data();
				if(ec)
				{
					ELOG(__FUNCTION__<<", recv, "<<ec<<", "<<PQerrorMessage(_pgcon));
					res.ready();
					return;
				}
			}

			if(!PQconsumeInput(_pgcon))
			{
				ELOG(__FUNCTION__<<", "<<PQerrorMessage(_pgcon));
				res.ready();
				return;
			}

			PGresult *pgr = PQgetResult(_pgcon);
			if(!pgr)
			{
				res.ready();
				return;
			}

			res.dataNoWait().push_back(IResultPtr(new Result(pgr, shared_from_this())));
		}
	}


}
