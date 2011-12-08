#include "pch.h"
#include "connectionPrepareds.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	//различные помогаторы
	namespace 
	{
		//////////////////////////////////////////////////////////////////////////
		char pridGenChars[] = "abcdefghijklmnopqrstuvwxyz01234567890";
		boost::random::random_device pridGenRng;
		boost::random::uniform_int_distribution<> pridGenIndexDist(0, sizeof(pridGenChars)-2);
		std::string pridGenerator()
		{
			std::string res;
			res.resize(24);
			res[0] = '_';
			for(int i = 1; i < 24; ++i)
			{
				res[i] = pridGenChars[pridGenIndexDist(pridGenRng)];
			}
			return res;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::touchPrepared(IStatementWtr p)
	{
		struct changeAccessTime
		{
			changeAccessTime(const posix_time::ptime& accessTime):_accessTime(accessTime){}

			void operator()(StatementPrepareState& e)
			{
				e._accessTime = _accessTime;
			}

		private:
			posix_time::ptime _accessTime;
		};

		TPrepareds::nth_index<0>::type &ptrIndex = _prepareds.get<0>();
		TPrepareds::nth_index<0>::type::iterator iter = ptrIndex.find(p);
		if(ptrIndex.end() != iter)
		{
			ptrIndex.modify(iter, changeAccessTime(_now));
			return;
		}

		StatementPrepareState sps = 
		{
			pridGenerator(),
			p, 
			_now
		};
		_prepareds.insert(sps);
	}

	//////////////////////////////////////////////////////////////////////////
	bool ConnectionPrepareds::hasPrepared(IStatementWtr p)
	{
		TPrepareds::nth_index<0>::type &ptrIndex = _prepareds.get<0>();
		TPrepareds::nth_index<0>::type::iterator iter = ptrIndex.find(p);
		return ptrIndex.end() != iter;
	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &ConnectionPrepareds::getPrid(IStatementWtr p)
	{
		touchPrepared(p);

		TPrepareds::nth_index<0>::type &ptrIndex = _prepareds.get<0>();
		TPrepareds::nth_index<0>::type::iterator iter = ptrIndex.find(p);
		if(ptrIndex.end() != iter)
		{
			return iter->_prid;
		}
		assert(0);
		static std::string stub = "unknown";
		return stub;
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::genPrid(IStatementWtr p)
	{
		struct ChangePrid
		{
			ChangePrid(const std::string& prid):_prid(prid){}

			void operator()(StatementPrepareState& e)
			{
				e._prid = _prid;
			}

		private:
			std::string _prid;
		};

		TPrepareds::nth_index<0>::type &ptrIndex = _prepareds.get<0>();
		TPrepareds::nth_index<0>::type::iterator iter = ptrIndex.find(p);
		if(ptrIndex.end() != iter)
		{
			ptrIndex.modify(iter, ChangePrid(pridGenerator()));
			return;
		}
		assert(!"statement absent!");
	}


	//////////////////////////////////////////////////////////////////////////
	ConnectionPreparedsPtr ConnectionPrepareds::shared_from_this()
	{
		return static_pointer_cast<ConnectionPrepareds>(ConnectionLow::shared_from_this());
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::onPrepare(IStatementPtr s,
		BindDataPtr data,
		boost::function<void (IResultPtr)> done,
		IResultPtr result,
		bool inTrans)
	{
		if(eesCommandOk != result->status())
		{
			const char *s4 = result->errorCode();
			if(s4 && !strcmp(s4, "42P05"))//DUPLICATE PREPARED STATEMENT
			{
				if(inTrans)
				{
					std::string oldPrid = getPrid(s);
					genPrid(s);
					runQuery(
						"ROLLBACK TO SAVEPOINT pgcp"+oldPrid,
						bind(&ConnectionPrepareds::onRollbackSavepoint, shared_from_this(), s, data, done, _1));
					return;
				}

				genPrid(s);
				runPrepare(getPrid(s), s->getSql(), data, 
					bind(&ConnectionPrepareds::onPrepare, shared_from_this(), s, data, done, _1, false));
				return;
			}
			else
			{
				done(result);
				return;
			}
		}

		if(inTrans)
		{
			runQuery(
				"RELEASE SAVEPOINT pgcp"+getPrid(s),
				bind(&ConnectionPrepareds::onReleaseSavepoint, shared_from_this(), s, data, done, _1));
			return;
		}

		runQueryPrepared(getPrid(s), data, done);
	}

	void ConnectionPrepareds::onSavepoint(IStatementPtr s,
		BindDataPtr data,
		boost::function<void (IResultPtr)> done,
		IResultPtr result)
	{
		if(eesCommandOk != result->status())
		{
			std::cerr<<__FUNCTION__<<": "<<result->errorMsg()<<std::endl;
			done(IResultPtr());
			return;
		}

		runPrepare(getPrid(s), s->getSql(), data, 
			bind(&ConnectionPrepareds::onPrepare, shared_from_this(), s, data, done, _1, true));
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::onRollbackSavepoint(IStatementPtr s,
		BindDataPtr data,
		boost::function<void (IResultPtr)> done,
		IResultPtr result)
	{
		if(eesCommandOk != result->status())
		{
			std::cerr<<__FUNCTION__<<": "<<result->errorMsg()<<std::endl;
			done(IResultPtr());
			return;
		}

		runQuery(
			"SAVEPOINT pgcp"+getPrid(s),
			bind(&ConnectionPrepareds::onSavepoint, shared_from_this(), s, data, done, _1));
	}


	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::onReleaseSavepoint(IStatementPtr s,
		BindDataPtr data,
		boost::function<void (IResultPtr)> done,
		IResultPtr result)
	{
		if(eesCommandOk != result->status())
		{
			std::cerr<<__FUNCTION__<<": "<<result->errorMsg()<<std::endl;
			done(IResultPtr());
			return;
		}

		runQueryPrepared(getPrid(s), data, done);
	}

	void ConnectionPrepareds::runNextRequest()
	{
		if(_requests.empty())
		{
			return;
		}
		SRequestPtr r = _requests.front();
		_requests.pop_front();

		if(hasPrepared(r->_s))
		{
			runQueryPrepared(
				getPrid(r->_s), 
				r->_data, 
				r->_done);
			return;
		}
		//этот запрос еще не подготовлен

		bool inTrans = false;
		switch(PQtransactionStatus(pgcon()))
		{
		case PQTRANS_ACTIVE:
		case PQTRANS_INTRANS:
		case PQTRANS_INERROR:
			inTrans = true;
			break;
		}

		if(inTrans)
		{
			runQuery(
				"SAVEPOINT pgcp"+getPrid(r->_s),
				bind(&ConnectionPrepareds::onSavepoint, shared_from_this(), r->_s, r->_data, r->_done, _1));
		}
		else
		{
			runPrepare(getPrid(r->_s), r->_s->getSql(), r->_data, 
				bind(&ConnectionPrepareds::onPrepare, shared_from_this(), r->_s, r->_data, r->_done, _1, false));
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::terminator(TDone done, IResultPtr result)
	{
		runNextRequest();
		if(done)
		{
			done(result);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionPrepareds::ConnectionPrepareds(PGconn *pgcon, asio::io_service &io_service)
		: ConnectionProcessor(pgcon, io_service)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionPrepareds::~ConnectionPrepareds()
	{
		assert(_requests.empty());
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::runQueryWithPrepare(IStatementPtr s,
		BindDataPtr data,
		boost::function<void (IResultPtr)> done)
	{
		_requests.push_back(SRequestPtr(new SRequest(s, data, 
			bind(&ConnectionPrepareds::terminator, shared_from_this(), done, _1))));

		runNextRequest();
	}

}
