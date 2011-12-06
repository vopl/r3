#include "pch.h"
#include "connection.hpp"
#include "db.hpp"
#include "result.hpp"
#include <boost/uuid/uuid_io.hpp>

namespace pgc
{
	namespace
	{
		inline char to_char(int i)
		{
			if (i <= 9)
			{
				return static_cast<char>('0' + i);
			}
			else
			{
				return static_cast<char>('a' + (i-10));
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	boost::uuids::random_generator Connection::_uuidGen;
	std::string Connection::preparedIdGen()
	{
		std::string result;
		result.reserve(33);
		result += '_';
		const uuids::uuid &u = _uuidGen();

		std::size_t i=0;
		for (uuids::uuid::const_iterator it_data = u.begin(); it_data!=u.end(); ++it_data, ++i)
		{
			const int hi = ((*it_data) >> 4) & 0x0F;
			result += to_char(hi);

			const int lo = (*it_data) & 0x0F;
			result += to_char(lo);
		}

		return result;
	}

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
				state->_uniq = preparedIdGen();
				if(state->_inTrans)
				{
					state->_eps = epsSPMaked;
					execSimple(
						("SAVEPOINT pgc_prepare_"+state->_uniq+";").c_str(),
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
				int nParams = state->_data?state->_data->typ.size():0;
				const Oid *paramTypes = nParams?&state->_data->typ[0]:NULL;
				if(!PQsendPrepare(
					*_con, 
					state->_uniq.c_str(),
					state->_s->getSql().c_str(),
					nParams,
					paramTypes))
				{
					std::cerr<<__FUNCTION__<<": "<<PQerrorMessage(*_con)<<std::endl;
					if(state->_done)
					{
						state->_done(IResultPtr());
					}
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
						state->_eps = epsStart;
						if(state->_inTrans)
						{
							execSimple(
								("ROLLBACK TO SAVEPOINT pgc_prepare_"+state->_uniq+";").c_str(),
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
								("ROLLBACK TO SAVEPOINT pgc_prepare_"+state->_uniq+";").c_str(),
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
							("RELEASE SAVEPOINT pgc_prepare_"+state->_uniq+";").c_str(),
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
			state->_s->setPreparedId(state->_uniq.c_str());
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
		if(eesError == lastRes->status())
		{
			const char *s4 = lastRes->errorCode();
			if(s4 && !strcmp(s4, "26000"))//INVALID SQL STATEMENT NAME
			{
				s->setPreparedId("");
				prepare_(s, data, done);
				return;
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
			s->getPreparedId().c_str(),
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
			return;
		}

		assert(!_done);
		assert(_results.empty());
		_done = bind(&Connection::execStep_, shared_from_this(), s, data, done, _1);
		continueSend();
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::continueSend()
	{
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
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::execSimple(const char *sql, boost::function<void (IResultPtr)> done)
	{
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
			return;
		}
		continueSend();
	}

	//////////////////////////////////////////////////////////////////////////
	Connection::Connection(DbPtr db, PGconnWrapperPtr con)
		: _db(db)
		, _con(con)
	{
	}
	
	//////////////////////////////////////////////////////////////////////////
	Connection::~Connection()
	{
		_db->unwork(_con);
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::exec(const char *sql,
		boost::function<void (IResultPtr)> done)
	{
		execSimple(sql, done);
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::exec(IStatementPtr s,
		function<void (IResultPtr)> done)
	{
		BindDataPtr bindData;

		if(s->getPreparedId().empty())
		{
			prepare_(s, bindData, done);
			return;
		}
		exec_(s, bindData, done);
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::exec(IStatementPtr s,
		const utils::Variant &data,
		boost::function<void (IResultPtr)> done)
	{
		BindDataPtr bindData(new BindData(data));

		if(s->getPreparedId().empty())
		{
			prepare_(s, bindData, bind(&Connection::exec_, shared_from_this(), s, bindData, done));
			return;
		}
		exec_(s, bindData, done);
	}

}
