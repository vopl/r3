#include "connectionImpl.hpp"
#include "statementImpl.hpp"
#include "statementPrepImpl.hpp"
#include <iostream>

namespace pgc
{
	ConnectionImpl::ConnectionImpl()
		: _pgcon(NULL)
		, _log(NULL)
		, _logFlags(lf_notice)
		, _integerDatetimes(false)
	{
	}
	ConnectionImpl::~ConnectionImpl()
	{
		close();
	}

	PGconn *ConnectionImpl::pgcon()
	{
		return _pgcon;
	}

	bool ConnectionImpl::integerDatetimes()
	{
		return _integerDatetimes;
	}

	void ConnectionImpl::log(std::ostream &out, int flags)
	{
		_log = &out;
		_logFlags = flags;
		updateLog();
	}

	EConnectionStatus ConnectionImpl::open(const char *conninfo)
	{
		close();

		_pgcon = PQconnectdb(conninfo);
		if(_pgcon == NULL)
		{
			return ecs_null;
		}
		updateLog();

		EConnectionStatus s = status();

		if(ecs_ok == s)
		{
			PQsetClientEncoding(_pgcon, "UTF-8");

			const char *csz = PQparameterStatus(_pgcon, "integer_datetimes");

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

		return s;
	}

	EConnectionStatus ConnectionImpl::ping(bool forceReset)
	{
		if(_pgcon)
		{
			if(ecs_ok != status() && forceReset)
			{
				PQreset(_pgcon);
			}

			EConnectionStatus s = status();

			if(ecs_ok == s)
			{
				PQsetClientEncoding(_pgcon, "UTF-8");
			}
			return s;
		}


		return status();
	}

	void ConnectionImpl::close()
	{
		if(_pgcon)
		{
			PQfinish(_pgcon);
			_pgcon = NULL;
		}
	}
	EConnectionStatus ConnectionImpl::status()
	{
		if(!_pgcon)
		{
			return ecs_null;
		}
		return CONNECTION_OK == PQstatus(_pgcon)? ecs_ok : ecs_lost;
	}

	StatementImplPtr ConnectionImpl::once()
	{
		return StatementImplPtr(new StatementImpl(shared_from_this()));
	}
	StatementImplPtr ConnectionImpl::prep()
	{
		return StatementImplPtr(new StatementPrepImpl(shared_from_this()));
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::doLogExec(const std::string &stmt)
	{
		if(_log && _logFlags&lf_exec)
		{
			(*_log)<<stmt<<std::endl;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::doLogError(const std::string &stmt, PGresult *res)
	{
		ExecStatusType est = PQresultStatus(res);
		if(est!=PGRES_COMMAND_OK && est!=PGRES_TUPLES_OK)
		{

			if(_log)
			{
				if(!(lf_exec & _logFlags))
				{
					(*_log)<<stmt<<std::endl;
				}
				(*_log)<<PQresultErrorMessage(res)<<std::endl;
			}
			else
			{
				std::cerr<<PQresultErrorMessage(res)<<std::endl;
			}
		}
	}


	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::noticeReceiver(void *arg, const PGresult *res)
	{
		ConnectionImpl *self = (ConnectionImpl *)arg;

		if(self->_log && self->_logFlags&lf_notice)
		{
			(*self->_log)<<PQresultErrorMessage(res);
			self->_log->flush();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::updateLog()
	{
		PQsetNoticeReceiver(_pgcon, noticeReceiver, this);
	}



}