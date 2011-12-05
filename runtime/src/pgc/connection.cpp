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
		result.reserve(32);
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

		PQclear(PQexec(*_con, "BEGIN"));

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
		PQclear(PQexec(*_con, "END"));



// 		boost::uint64_t sapox;
// 		char sapo[256];
// 		char id[64];
// 		for(;;)
// 		{
// 			if(inTrans)
// 			{
// 				sapox = rand()*rand();
// 				sprintf(sapo, "SAVEPOINT pgc_prepare_%08x", sapox);
// 				PQclear(PQexec(*_con, sapo));
// 			}
// 
// 			sprintf(id, "pgc_ps_%08x", rand()*rand());
// 			PGresult *res;
// 
// 			if(data && data->typ.size())
// 			{
// 				res = PQprepare(*_con, id, s->getSql().c_str(), (int)data->typ.size(), &data->typ[0]);
// 			}
// 			else
// 			{
// 				res = PQprepare(*_con, id, s->getSql().c_str(), 0, NULL);
// 			}
// 			ExecStatusType est = PQresultStatus(res);
// 			if(PGRES_FATAL_ERROR == est)
// 			{
// 				if(inTrans)
// 				{
// 					sprintf(sapo, "ROLLBACK TO SAVEPOINT pgc_prepare_%08x", sapox);
// 					PQclear(PQexec(*_con, sapo));
// 				}
// 				char *s4 = PQresultErrorField(res, PG_DIAG_SQLSTATE);
// 				if(s4 && !strcmp(s4, "42P05"))//DUPLICATE PREPARED STATEMENT
// 				{
// 					PQclear(res);
// 					continue;
// 				}
// 			}
// 			if(inTrans)
// 			{
// 				sprintf(sapo, "RELEASE SAVEPOINT pgc_prepare_%08x", sapox);
// 				PQclear(PQexec(*_con, sapo));
// 			}
// 			if(PGRES_COMMAND_OK != est)
// 			{
// 				IResultPtr rp(new Result(res));
// 				done(rp);
// 				return;
// 			}
// 
// 			//ok
// 			PQclear(res);
// 			break;
// 		};
// 
// 		s->setPreparedId(id);
// 		exec_(s, data, done);
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::prepareStep_(SPrepStatePtr state)
	{
		switch(state->_eps)
		{
		case epsStart:
			{
				state->_uniq = preparedIdGen();
				if(state->_inTrans)
				{
					if(!PQsendQuery(*_con, ("SAVEPOINT pgc_prepare_"+state->_uniq).c_str()))
					{
						std::cerr<<__FUNCTION__<<": "<<PQerrorMessage(*_con)<<std::endl;
						state->_done(IResultPtr());
						return;
					}
					state->_eps = epsSPMaked;
					_con->waitRead(
						bind(&Connection::prepareStep_, shared_from_this(), state));
					return;
				}
				else
				{
					state->_eps = epsSPMaked;
					prepareStep_(state);
				}
			}
			break;
		case epsSPMaked:
			{
				PQconsumeInput(*_con);
				PGresult *res;
				res = PQgetResult(*_con);
				if(res)
				{
					state->_done(IResultPtr(new Result(res)));
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
					state->_done(IResultPtr());
					return;
				}
				state->_eps = epsPrepMaked;
				_con->waitRead(
					bind(&Connection::prepareStep_, shared_from_this(), state));
				return;
			}
			break;
		case epsPrepMaked:
// 			{
// 				PGresult *res;
// 				res = PQgetResult(*_con);
// 				if(res)
// 				{
// 					ExecStatusType est = PQresultStatus(res);
// 					if(PGRES_FATAL_ERROR == est)
// 					{
// 						char *s4 = PQresultErrorField(res, PG_DIAG_SQLSTATE);
// 						if(s4 && !strcmp(s4, "42P05"))//DUPLICATE PREPARED STATEMENT
// 						{
// 							PQclear(res);
// 							state->_eps = epsStart;
// 						}
// 						if(inTrans)
// 						{
// 							sprintf(sapo, "ROLLBACK TO SAVEPOINT pgc_prepare_%08x", sapox);
// 							PQclear(PQexec(*_con, sapo));
// 						}
// 
// 					}
// 				}
// 			}
			break;
		case epsSPReverted:
			break;
		case epsSPReleased:
			break;
		default:
			assert(0);
		}
	}

	
	//////////////////////////////////////////////////////////////////////////
	void Connection::exec_(IStatementPtr s, BindDataPtr data, boost::function<void (IResultPtr)> done)
	{
		assert(0);
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
