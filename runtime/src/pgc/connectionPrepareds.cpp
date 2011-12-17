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
		random::random_device pridGenRng;
		random::uniform_int_distribution<> pridGenIndexDist(0, sizeof(pridGenChars)-2);
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
	void ConnectionPrepareds::cleanPrepareds(posix_time::ptime boundATime, TDone done, IResultPtrs result)
	{
		assert(result.size()<2);

		if(!result.empty() && ersCommandOk != result[0]->status())
		{
			ELOG(__FUNCTION__<<", "<<result[0]->errorMsg()<<"("<<result[0]->errorCode()<<")");
			const char * errCode = result[0]->errorCode();
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

		//терминатор
		done(IResultPtrs());
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
		TDone done,
		IResultPtrs result,
		bool inTrans)
	{
		assert(result.size()<2);
		if(!result.empty() && ersCommandOk != result[0]->status())
		{
			const char *s4 = result[0]->errorCode();
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
				ELOG(__FUNCTION__<<", "<<result[0]->errorMsg()<<"("<<result[0]->errorCode()<<")");
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

		runQueryPrepared(getPrid(s), data, bind(&ConnectionPrepareds::onQueryPrepared, shared_from_this(), s, data, done, _1));
	}

	void ConnectionPrepareds::onSavepoint(IStatementPtr s,
		BindDataPtr data,
		TDone done,
		IResultPtrs result)
	{
		assert(result.size()<2);
		if(!result.empty() && ersCommandOk != result[0]->status())
		{
			ELOG(__FUNCTION__<<", "<<result[0]->errorMsg()<<"("<<result[0]->errorCode()<<")");
			done(IResultPtrs());
			return;
		}

		runPrepare(getPrid(s), s->getSql(), data, 
			bind(&ConnectionPrepareds::onPrepare, shared_from_this(), s, data, done, _1, true));
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::onRollbackSavepoint(IStatementPtr s,
		BindDataPtr data,
		TDone done,
		IResultPtrs result)
	{
		assert(result.size()<2);
		if(!result.empty() && ersCommandOk != result[0]->status())
		{
			ELOG(__FUNCTION__<<", "<<result[0]->errorMsg()<<"("<<result[0]->errorCode()<<")");
			done(IResultPtrs());
			return;
		}

		runQuery(
			"SAVEPOINT pgcp"+getPrid(s),
			bind(&ConnectionPrepareds::onSavepoint, shared_from_this(), s, data, done, _1));
	}


	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::onReleaseSavepoint(IStatementPtr s,
		BindDataPtr data,
		TDone done,
		IResultPtrs result)
	{
		assert(result.size()<2);
		if(!result.empty() && ersCommandOk != result[0]->status())
		{
			ELOG(__FUNCTION__<<", "<<result[0]->errorMsg()<<"("<<result[0]->errorCode()<<")");
			done(IResultPtrs());
			return;
		}

		runQueryPrepared(getPrid(s), data, bind(&ConnectionPrepareds::onQueryPrepared, shared_from_this(), s, data, done, _1));
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::onQueryPrepared(IStatementPtr s,
		BindDataPtr data,
		TDone done,
		IResultPtrs result)
	{
		if(!result.empty() && ersError == result[0]->status())
		{
			const char * errCode = result[0]->errorCode();
			if(errCode && !strcmp("26000", errCode))
			{
				//ERROR:  prepared statement "XXX" does not exist
				delPrepared(s);
				_requests.push_back(SRequestPtr(new SQueryWithPrepare(s, data, done)));

				runNextRequest();
			}
			else
			{
				//другая ошибка - транслировать клиенту
			}
		}
		done(result);
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::queueEmpty()
	{
		runNextRequest();
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::runNextRequest()
	{
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
				ELOG("connection lost or closed");

				_inProcess = false;

				IResultPtrs nullResult;
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

		if(_inProcess)
		{
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
						bind(&ConnectionPrepareds::onQueryPrepared, shared_from_this(), q->_s, q->_data, q->_done, _1));
					return;
				}
				//этот запрос еще не подготовлен

				bool inTrans = false;
				PGTransactionStatusType tstatus = PQtransactionStatus(pgcon());
				//assert(PQTRANS_ACTIVE != tstatus);
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
				cleanPrepareds(boundATime, q->_done, IResultPtrs());
			}
			break;
		default:
			assert(!"unknown request type");
			return;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::requestTerminator(TDone done, IResultPtrs result)
	{
		_inProcess = false;
		runNextRequest();
		if(done)
		{
			done(result);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionPrepareds::ConnectionPrepareds(PGconn *pgcon, async::IServicePtr asrv)
		: ConnectionProcessor(pgcon, asrv)
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
	void ConnectionPrepareds::endWork(TDone done)
	{
		_requests.push_back(SRequestPtr(new SCleanPrepareds(
			bind(&ConnectionPrepareds::requestTerminator, shared_from_this(), done, _1))));

		runNextRequest();
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::runQueryWithPrepare(IStatementPtr s,
		BindDataPtr data,
		TDone done)
	{
		_requests.push_back(SRequestPtr(new SQueryWithPrepare(s, data, 
			bind(&ConnectionPrepareds::requestTerminator, shared_from_this(), done, _1))));

		runNextRequest();
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::close()
	{
		assert(_requests.empty());

		_inProcess = false;
		_prepareds.clear();

		ConnectionProcessor::close();
	}

}
