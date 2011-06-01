#include "statementPrepImpl.hpp"
#include "connectionImpl.hpp"
#include "pgDataType.h"
#include "pgc/exception.hpp"
#include <cstring>

namespace pgc
{
	StatementPrepImpl::StatementPrepImpl(ConnectionImplPtr con)
		: StatementImpl(con)
	{

	}
	StatementPrepImpl::~StatementPrepImpl()
	{
		unprepare();
	}

	void StatementPrepImpl::bind(int typCpp, void const *valCpp, size_t idx)
	{
		if(_id.empty())
		{
			return StatementImpl::bind(typCpp, valCpp, idx);
		}
		else
		{
			if(!idx)
			{
				idx = _bindTyp.size();
			}
			idx--;
			if(idx >= _bindTyp.size())
			{
				throw std::range_error("bind index out of range");
				return;
			}

			if(_bindOwn[idx])
			{
				delete [] _bindVal[idx];
				_bindVal[idx] = NULL;
				_bindOwn[idx] = false;
			}

			Oid	bindTyp = InvalidOid;
			char *bindVal = NULL;
			int bindLen = 0;
			int bindFmt = 0;
			bool bindOwn = 0;

			bool bf = bindFiller(
				typCpp, valCpp,
				bindTyp,
				bindVal,
				bindLen,
				bindFmt,
				bindOwn);

			if(bf)
			{
				if(bindTyp != _bindTyp[idx])
				{
					throw std::invalid_argument("bind type is differ");
					return;
				}

				_bindVal[idx] = bindVal;
				_bindLen[idx] = bindLen;
				_bindFmt[idx] = bindFmt;
				_bindOwn[idx] = bindOwn;
			}
			return;
		}

		//throw std::exception("unable bind to compiled statement");
	}

	void StatementPrepImpl::unbind(size_t idx)
	{
		assert(
			_bindTyp.size() == _bindVal.size() &&
			_bindTyp.size() == _bindVal.size() &&
			_bindTyp.size() == _bindLen.size() &&
			_bindTyp.size() == _bindFmt.size() &&
			_bindTyp.size() == _bindOwn.size());

		if(idx)
		{
			idx--;

			if(idx < _bindTyp.size())
			{
				if(_bindOwn[idx])
				{
					delete [] _bindVal[idx];
				}

				_bindVal[idx] = NULL;
				_bindLen[idx] = 0;//ignored for text
				_bindFmt[idx] = 0;//text
				_bindOwn[idx] = false;//alien _bindVal[idx]
			}

		}
		else
		{
			//all
			if(!_bindTyp.empty())
			{
				for(size_t i(0); i<_bindTyp.size(); i++)
				{
					if(_bindOwn[idx])
					{
						delete [] _bindVal[idx];
					}
					_bindVal[i] = NULL;
					_bindLen[i] = 0;//ignored for text
					_bindFmt[i] = 0;//text
					_bindOwn[i] = false;//alien _bindVal[idx]
				}
			}
		}
	}
	ResultImplPtr StatementPrepImpl::exec()
	{
		_con->doLogExec(_sql);

		ResultImplPtr res;
		if(_id.empty())
		{
			res = prepare();
			if(res)
			{
				_con->doLogError(_sql, res);
				return res;
			}
		}

		if(_bindTyp.size())
		{
			res.reset(new ResultImpl(_con, PQexecPrepared(
				_con->pgcon(),
				_id.c_str(),
				_bindVal.size(),
				&_bindVal[0],
				&_bindLen[0],
				&_bindFmt[0],
				1)));
		}
		else
		{
			res.reset(new ResultImpl(_con, PQexecPrepared(
				_con->pgcon(),
				_id.c_str(),
				0,
				NULL,
				NULL,
				NULL,
				1)));
		}

		if(ees_error == res->status())
		{
			if(!strcmp(res->errorCode(), "26000"))//26000 INVALID SQL STATEMENT NAME
			{
				_id.clear();
				return exec();
			}
		}
		_con->doLogError(_sql, res);
		unbind(0);
		return res;
	}

	ResultImplPtr StatementPrepImpl::prepare()
	{
		bool inTrans = false;
		PGconn *_conn = _con->pgcon();
		switch(PQtransactionStatus(_conn))
		{
		case PQTRANS_ACTIVE:
		case PQTRANS_INTRANS:
		case PQTRANS_INERROR:
			inTrans = true;
		}

		boost::uint64_t sapox;
		char sapo[256];
		char id[64];
		for(;;)
		{
			if(inTrans)
			{
				sapox = rand()*rand();
				sprintf(sapo, "SAVEPOINT pgc_prepare_%08x", sapox);
				PQclear(PQexec(_conn, sapo));
			}

			sprintf(id, "pgc_ps_%08x", rand()*rand());
			PGresult *res;

			if(_bindTyp.size())
			{
				res = PQprepare(_conn, id, _sql.data(), _bindTyp.size(), &_bindTyp[0]);
			}
			else
			{
				res = PQprepare(_conn, id, _sql.data(), 0, NULL);
			}
			ExecStatusType est = PQresultStatus(res);
			if(PGRES_FATAL_ERROR == est)
			{
				if(inTrans)
				{
					sprintf(sapo, "ROLLBACK TO SAVEPOINT pgc_prepare_%08x", sapox);
					PQclear(PQexec(_conn, sapo));
				}
				char *s4 = PQresultErrorField(res, PG_DIAG_SQLSTATE);
				if(s4 && !strcmp(s4, "42P05"))//DUPLICATE PREPARED STATEMENT
				{
					PQclear(res);
					continue;
				}
			}
			if(inTrans)
			{
				sprintf(sapo, "RELEASE SAVEPOINT pgc_prepare_%08x", sapox);
				PQclear(PQexec(_conn, sapo));
			}
			if(PGRES_COMMAND_OK != est)
			{
				return ResultImplPtr(new ResultImpl(_con, res));
			}

			//ok
			PQclear(res);
			break;
		};

		_id = id;
		return ResultImplPtr();
	}

	void StatementPrepImpl::unprepare()
	{
		if(!_id.empty())
		{
			PQclear(PQexec(_con->pgcon(), ("DEALLOCATE "+_id).c_str()));
			_id.clear();
		}
	}

}
