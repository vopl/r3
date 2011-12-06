#include "pch.h"
#include "connection.hpp"
#include "db.hpp"
#include "result.hpp"
#include "utils/ntoa.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	void Connection::prepare_(IStatementPtr s, BindDataPtr data, boost::function<void (IResultPtr)> done)
	{
		SPrepStatePtr state(new SPrepState);
		state->_eps = epsStart;
		state->_data = data;
		state->_done = done;
		state->_s = s;

		switch(PQtransactionStatus(*_con))
		{
		case PQTRANS_ACTIVE:
		case PQTRANS_INTRANS:
		case PQTRANS_INERROR:
			state->_inTrans = true;
			break;
		default:
			state->_inTrans = false;
			break;
		}

		prepareStep_(state);
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::prepareStep_(SPrepStatePtr state, IResultPtr lastRes)
	{
		switch(state->_eps)
		{
		case epsStart:
			{
				if(state->_inTrans)
				{
					state->_eps = epsSPMaked;
					execSimple(
						("SAVEPOINT pgcp"+_con->getPrid(state->_s)+";").c_str(),
						bind(&Connection::prepareStep_, shared_from_this(), state, _1));
					return;
				}
				else
				{
					state->_eps = epsSPMaked;
					prepareStep_(state);
					return;
				}
			}
			break;
		case epsSPMaked:
			{
				if(lastRes && eesCommandOk != lastRes->status())
				{
					std::cerr<<__FUNCTION__<<": "<<lastRes->errorMsg()<<std::endl;
					if(state->_done)
					{
						state->_done(lastRes);
					}
					return;
				}

				assert(!_inProcess);
				_inProcess = true;

				int nParams = state->_data?state->_data->typ.size():0;
				const Oid *paramTypes = nParams?&state->_data->typ[0]:NULL;
				if(!PQsendPrepare(
					*_con, 
					_con->getPrid(state->_s).c_str(),
					state->_s->getSql().c_str(),
					nParams,
					paramTypes))
				{
					std::cerr<<__FUNCTION__<<": "<<PQerrorMessage(*_con)<<std::endl;
					if(state->_done)
					{
						state->_done(IResultPtr());
					}
					_inProcess = false;
					return;
				}

				state->_eps = epsPrepMaked;

				assert(!_done);
				assert(_results.empty());
				_done = bind(&Connection::prepareStep_, shared_from_this(), state, _1);
				continueSend();
				return;
			}
			break;
		case epsPrepMaked:
			{
				if(eesCommandOk != lastRes->status())
				{
					const char *s4 = lastRes->errorCode();
					if(s4 && !strcmp(s4, "42P05"))//DUPLICATE PREPARED STATEMENT
					{
						std::string oldPrid = _con->getPrid(state->_s);
						state->_eps = epsStart;
						_con->genPrid(state->_s);
						if(state->_inTrans)
						{
							execSimple(
								("ROLLBACK TO SAVEPOINT pgcp"+oldPrid+";").c_str(),
								bind(&Connection::prepareStep_, shared_from_this(), state, IResultPtr()));
						}
						else
						{
							prepareStep_(state, IResultPtr());
						}
						return;
					}
					else
					{
						state->_eps = epsError;
						if(state->_inTrans)
						{
							execSimple(
								("ROLLBACK TO SAVEPOINT pgcp"+_con->getPrid(state->_s)+";").c_str(),
								bind(&Connection::prepareStep_, shared_from_this(), state, lastRes));
						}
						else
						{
							prepareStep_(state, lastRes);
						}
						return;
					}
				}
				else
				{
					state->_eps = epsPrepared;
					if(state->_inTrans)
					{
						execSimple(
							("RELEASE SAVEPOINT pgcp"+_con->getPrid(state->_s)+";").c_str(),
							bind(&Connection::prepareStep_, shared_from_this(), state, lastRes));
					}
					else
					{
						prepareStep_(state, lastRes);
					}
					return;
				}
			}
			break;
		case epsPrepared:
			//state->_s->setPreparedId(state->_uniq.c_str());
			_con->touchPrepared(state->_s);
			exec_(state->_s, state->_data, state->_done);
			break;
		case epsError:
			std::cerr<<__FUNCTION__<<": "<<lastRes->errorMsg()<<std::endl;
			if(state->_done)
			{
				state->_done(lastRes);
			}
			break;
		default:
			assert(0);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::execStep_(IStatementPtr s, BindDataPtr data, boost::function<void (IResultPtr)> done, IResultPtr lastRes)
	{
		assert(!_inProcess);

		if(eesError == lastRes->status())
		{
			const char *s4 = lastRes->errorCode();
			if(s4 && !strcmp(s4, "26000"))//INVALID SQL STATEMENT NAME
			{
				assert(!"такого не должно быть, препы внутри сессии, может клиент дернул EXEC");
// 				s->setPreparedId("");
// 				prepare_(s, data, done);
// 				return;
			}
		}

		if(done)
		{
			done(lastRes);
		}
	}

	
	//////////////////////////////////////////////////////////////////////////
	void Connection::exec_(IStatementPtr s, BindDataPtr data, boost::function<void (IResultPtr)> done)
	{
		int nParams = data?data->typ.size():0;
		const Oid *paramTypes = nParams?&data->typ[0]:NULL;
		const char * const *paramValues = nParams?&data->val[0]:NULL;
		const int *paramLengths = nParams?&data->len[0]:NULL;
		const int *paramFormats = nParams?&data->fmt[0]:NULL;

		if(!PQsendQueryPrepared(
			*_con, 
			_con->getPrid(s).c_str(),
			nParams,
			paramValues,
			paramLengths,
			paramFormats,
			1))
		{
			std::cerr<<__FUNCTION__<<": "<<PQerrorMessage(*_con)<<std::endl;
			if(done)
			{
				done(IResultPtr());
			}
			_inProcess = false;
			return;
		}

		assert(!_inProcess);
		_inProcess = true;
		assert(!_done);
		assert(_results.empty());
		_done = bind(&Connection::execStep_, shared_from_this(), s, data, done, _1);
		continueSend();
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::continueSend()
	{
		assert(_inProcess);

		if(PQflush(*_con))
		{
			_con->waitWrite(
				bind(&Connection::continueSend, shared_from_this()));
			return;

		}

		_con->waitRead(
			bind(&Connection::continueRecv, shared_from_this()));
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::continueRecv()
	{
		assert(_inProcess);

		if(!PQconsumeInput(*_con))
		{
			std::cerr<<__FUNCTION__<<": "<<PQerrorMessage(*_con)<<std::endl;
		}

		PGresult *pgr = PQgetResult(*_con);
		while(pgr)
		{
			_results.push_back(pgr);

			if(!PQconsumeInput(*_con))
			{
				std::cerr<<__FUNCTION__<<": "<<PQerrorMessage(*_con)<<std::endl;
			}
			if(PQisBusy(*_con))
			{
				_con->waitRead(
					bind(&Connection::continueRecv, shared_from_this()));

				return;
			}

			pgr = PQgetResult(*_con);
		}


		if(_done)
		{
			assert(_inProcess);
			_inProcess = false;

			std::deque<PGresult *> results;
			results.swap(_results);

			boost::function<void (IResultPtr)> done;
			done.swap(_done);

			BOOST_FOREACH(PGresult *pgr, results)
			{
				done(IResultPtr(new Result(pgr, _con)));
			}
		}
		else
		{
			BOOST_FOREACH(PGresult *pgr, _results)
			{
				PQclear(pgr);
			}
			_results.clear();
			assert(_inProcess);
			_inProcess = false;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::execSimple(const char *sql, boost::function<void (IResultPtr)> done)
	{
		assert(!_inProcess);
		_inProcess = true;

		assert(!_done);

		assert(_results.empty());
		_done = done;

		if(!PQsendQuery(*_con, sql))
		{
			std::cerr<<__FUNCTION__<<": "<<PQerrorMessage(*_con)<<std::endl;
			if(done)
			{
				done(IResultPtr());
			}
			_inProcess = false;
			return;
		}
		continueSend();
	}

	//////////////////////////////////////////////////////////////////////////
	Connection::Connection(DbPtr db, PGconnWrapperPtr con)
		: _db(db)
		, _con(con)
		, _inProcess(false)
	{
	}
	
	//////////////////////////////////////////////////////////////////////////
	Connection::~Connection()
	{
		assert(!_inProcess);
		_db->unwork(_con);
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::exec(const char *sql,
		boost::function<void (IResultPtr)> done)
	{
		assert(!_inProcess);
		if(_inProcess)
		{
			if(done)
			{
				done(IResultPtr());
			}
			return;
		}

		execSimple(sql, done);
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::exec(IStatementPtr s,
		function<void (IResultPtr)> done)
	{
		assert(!_inProcess);
		if(_inProcess)
		{
			if(done)
			{
				done(IResultPtr());
			}
			return;
		}

		BindDataPtr bindData;

		if(!_con->hasPrepared(s))
		{
			_con->touchPrepared(s);
			prepare_(s, bindData, done);
			return;
		}
		_con->touchPrepared(s);
		exec_(s, bindData, done);
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::exec(IStatementPtr s,
		const utils::Variant &data,
		boost::function<void (IResultPtr)> done)
	{
		assert(!_inProcess);
		if(_inProcess)
		{
			if(done)
			{
				done(IResultPtr());
			}
			return;
		}

		BindDataPtr bindData(new BindData(data, _con));

		if(!_con->hasPrepared(s))
		{
			_con->touchPrepared(s);
			prepare_(s, bindData, done);
			return;
		}
		_con->touchPrepared(s);
		exec_(s, bindData, done);
	}

}
