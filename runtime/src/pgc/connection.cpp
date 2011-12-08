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
					_con->execSimple(
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

				state->_eps = epsPrepMaked;
				assert(!_con->_inProcess);
				_con->execPrepare(
					state->_s, 
					state->_data, 
					bind(&Connection::prepareStep_, shared_from_this(), state, _1));

				return;
			}
			break;
		case epsPrepMaked:
			{
				if(!lastRes)
				{
					return;
				}
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
							_con->execSimple(
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
							_con->execSimple(
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
						_con->execSimple(
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
	void Connection::exec_(IStatementPtr s, BindDataPtr data, boost::function<void (IResultPtr)> done)
	{
		assert(!_con->_inProcess);
		_con->execPrepared(s, data, bind(&Connection::keeper, shared_from_this(), done, _1));
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::keeper(boost::function<void (IResultPtr)> done, IResultPtr res)
	{
		if(done)
		{
			done(res);
		}
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
		assert(!_con->_inProcess);
		_db->unwork(_con);
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::exec(const std::string &sql,
		boost::function<void (IResultPtr)> done)
	{
		assert(!_con->_inProcess);
		if(_con->_inProcess)
		{
			if(done)
			{
				done(IResultPtr());
			}
			return;
		}

		_con->execSimple(sql.c_str(), bind(&Connection::keeper, shared_from_this(), done, _1));
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::exec(IStatementPtr s,
		function<void (IResultPtr)> done)
	{
		assert(!_con->_inProcess);
		if(_con->_inProcess)
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
		assert(!_con->_inProcess);
		if(_con->_inProcess)
		{
			if(done)
			{
				done(IResultPtr());
			}
			return;
		}

		assert(!"устарело");
		BindDataPtr bindData;//(new BindData(data, _con));

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
	void Connection::close()
	{
		assert(!_con->_inProcess);
		_con->close();
	}


}
