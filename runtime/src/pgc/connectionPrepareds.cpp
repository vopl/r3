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
	bool ConnectionPrepareds::hasPrepared(IStatementWtr p)
	{
		TPrepareds::nth_index<0>::type &ptrIndex = _prepareds.get<0>();
		TPrepareds::nth_index<0>::type::iterator iter = ptrIndex.find(p);
		return ptrIndex.end() != iter;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string ConnectionPrepareds::getPrid(IStatementWtr p)
	{
		struct ChangeAccessTime
		{
			ChangeAccessTime(const posix_time::ptime& accessTime):_accessTime(accessTime){}

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
			ptrIndex.modify(iter, ChangeAccessTime(_now));
			return iter->_prid;
		}

		StatementPrepareState sps = 
		{
			pridGenerator(),
			p, 
			_now
		};
		_prepareds.insert(sps);
		return sps._prid;
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::cleanPrepareds(posix_time::ptime boundATime, TDone done, IResultPtr result)
	{
		assert(_max > 0);

		if(result && ersCommandOk != result->status())
		{
			std::cerr<<__FUNCTION__<<": "<<result->errorMsg()<<std::endl;
			const char * errCode = result->errorCode();
			if(errCode && !strcmp("26000", errCode))
			{
				//ERROR:  prepared statement "XXX" does not exist
			}
			else
			{
				//другая ошибка - фатально
				_prepareds.clear();
			}

		}

		TPrepareds::nth_index<1>::type &timedIndex = _prepareds.get<1>();
		if(timedIndex.size() > _max)
		{
			std::string prid = timedIndex.begin()->_prid;
			timedIndex.erase(timedIndex.begin());
			runQuery(
				"DEALLOCATE "+prid, 
				bind(&ConnectionPrepareds::cleanPrepareds, shared_from_this(), boundATime, done, _1));
			return;
		}

		if(!timedIndex.empty() && boundATime > timedIndex.begin()->_accessTime)
		{
			std::string prid = timedIndex.begin()->_prid;
			timedIndex.erase(timedIndex.begin());
			runQuery(
				"DEALLOCATE "+prid,
				bind(&ConnectionPrepareds::cleanPrepareds, shared_from_this(), boundATime, done, _1));
			return;
		}

		done(result);
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

		StatementPrepareState sps = 
		{
			pridGenerator(),
			p, 
			_now
		};
		_prepareds.insert(sps);
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::delPrepared(IStatementWtr p)
	{
		TPrepareds::nth_index<0>::type &ptrIndex = _prepareds.get<0>();
		TPrepareds::nth_index<0>::type::iterator iter = ptrIndex.find(p);
		if(ptrIndex.end() != iter)
		{
			ptrIndex.erase(iter);
			return;
		}

		assert(!"unknown statement for delete");
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
		if(!result)
		{
			std::cerr<<__FUNCTION__<<": null result"<<std::endl;
			done(result);
			return;
		}
		if(ersCommandOk != result->status())
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

				runPrepare(getPrid(s), s->getSql(), data, 
					bind(&ConnectionPrepareds::onPrepare, shared_from_this(), s, data, done, _1, false));
				return;
			}
			else
			{
				std::cerr<<__FUNCTION__<<": "<<result->errorMsg()<<std::endl;
				delPrepared(s);
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
		if(!result)
		{
			std::cerr<<__FUNCTION__<<": null result"<<std::endl;
			done(result);
			return;
		}
		if(ersCommandOk != result->status())
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
		if(!result)
		{
			std::cerr<<__FUNCTION__<<": null result"<<std::endl;
			done(result);
			return;
		}
		if(ersCommandOk != result->status())
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
		if(!result)
		{
			std::cerr<<__FUNCTION__<<": null result"<<std::endl;
			done(result);
			return;
		}
		if(ersCommandOk != result->status())
		{
			std::cerr<<__FUNCTION__<<": "<<result->errorMsg()<<std::endl;
			done(IResultPtr());
			return;
		}

		runQueryPrepared(getPrid(s), data, done);
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::queueEmpty()
	{
		runNextRequest();
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::runNextRequest()
	{
		if(inProcess())
		{
			//когда нижний уровень закончит - он позовет queueEmpty()
			return;
		}

		if(_inProcess)
		{
			//свой процесс исполняется
			return;
		}

		if(_requests.empty())
		{
			//нечего исполнять
			return;
		}

		switch(status())
		{
		case ecsNull:
		case ecsLost:
			//соединение утеряно или закрыто
			{
				std::cerr<<__FUNCTION__<<": connection lost or closed"<<std::endl;
				IResultPtr nullResult;
				TRequests requests;
				requests.swap(_requests);
				BOOST_FOREACH(SRequestPtr &r, requests)
				{
					r->_done(nullResult);
					r.reset();
				}
			}
			return;
		}

		SRequestPtr r = _requests.front();
		_requests.pop_front();
		_inProcess = true;

		switch(r->_ert)
		{
		case ertQueryWithPrepare:
			{
				SQueryWithPrepare * q = static_cast<SQueryWithPrepare *>(r.get());
				if(hasPrepared(q->_s))
				{
					runQueryPrepared(
						getPrid(q->_s), 
						q->_data, 
						q->_done);
					return;
				}
				//этот запрос еще не подготовлен

				bool inTrans = false;
				PGTransactionStatusType tstatus = PQtransactionStatus(pgcon());
				assert(PQTRANS_ACTIVE != tstatus);
				switch(tstatus)
				{
// 				case PQTRANS_ACTIVE:
				case PQTRANS_INTRANS:
				case PQTRANS_INERROR:
					inTrans = true;
					break;
				}

				if(inTrans)
				{
					runQuery(
						"SAVEPOINT pgcp"+getPrid(q->_s),
						bind(&ConnectionPrepareds::onSavepoint, shared_from_this(), q->_s, q->_data, q->_done, _1));
				}
				else
				{
					runPrepare(
						getPrid(q->_s), 
						q->_s->getSql(), 
						q->_data, 
						bind(&ConnectionPrepareds::onPrepare, shared_from_this(), q->_s, q->_data, q->_done, _1, false));
				}
			}
			break;
		case ertCleanPrepareds:
			{
				SCleanPrepareds * q = static_cast<SCleanPrepareds *>(r.get());

				posix_time::ptime boundATime = _now - posix_time::milliseconds(_timeout);
				cleanPrepareds(boundATime, q->_done, IResultPtr());
			}
			break;
		default:
			assert(!"unknown request type");
			return;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::requestTerminator(TDone done, IResultPtr result)
	{
		_inProcess = false;
		runNextRequest();
		if(done)
		{
			done(result);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionPrepareds::ConnectionPrepareds(PGconn *pgcon, asio::io_service &io_service)
		: ConnectionProcessor(pgcon, io_service)
		, _inProcess(false)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionPrepareds::~ConnectionPrepareds()
	{
		assert(_requests.empty());
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::beginWork()
	{
		_now = posix_time::microsec_clock::local_time();
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::endWork(function<void(IResultPtr)> done)
	{
		_requests.push_back(SRequestPtr(new SCleanPrepareds(
			bind(&ConnectionPrepareds::requestTerminator, shared_from_this(), done, _1))));

		runNextRequest();
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::runQueryWithPrepare(IStatementPtr s,
		BindDataPtr data,
		boost::function<void (IResultPtr)> done)
	{
		_requests.push_back(SRequestPtr(new SQueryWithPrepare(s, data, 
			bind(&ConnectionPrepareds::requestTerminator, shared_from_this(), done, _1))));

		runNextRequest();
	}

}
