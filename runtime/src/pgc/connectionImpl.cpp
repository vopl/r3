#include "pch.h"
#include "connectionImpl.hpp"
#include "async/service.hpp"
#include "async/result.hpp"

#include "result.hpp"
#include "bindData.hpp"

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
	bool ConnectionImpl::hasPrepared(IStatementWtr p)
	{
		TPrepareds::nth_index<0>::type &ptrIndex = _prepareds.get<0>();
		TPrepareds::nth_index<0>::type::iterator iter = ptrIndex.find(p);
		return ptrIndex.end() != iter;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string ConnectionImpl::getPrid(IStatementWtr p)
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
	void ConnectionImpl::genPrid(IStatementWtr p)
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
	void ConnectionImpl::delPrepared(IStatementWtr p)
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
	void ConnectionImpl::processRequest()
	{
		assert(_mtxProcess.isLocked());
		assert(!_requestInProcess);
		assert(!_requests.empty());

		if(_requestInProcess || _requests.empty())
		{
			_mtxProcess.unlock();
			return;
		}

		_requestInProcess = true;
		async::Result<IResultPtrs> result;
		SRequestPtr request;

		for(;;)
		{
			request = _requests.front();
			_requests.erase(_requests.begin());

			switch(request->_ert)
			{
			case ertQuery:
				{
					SRequestQuery *rd = static_cast<SRequestQuery *>(request.get());
					runQuery_f(result, rd->_sql);
				}
				break;
			case ertQueryWithPrepare:
				{
					SRequestQueryWithPrepare *rd = static_cast<SRequestQueryWithPrepare *>(request.get());
					runQueryWithPrepare_f(result, rd->_s, rd->_data);
				}
				break;
			case ertQueryEndWork:
				{
					SRequestEndWork *rd = static_cast<SRequestEndWork *>(request.get());
					runEndWork_f(result);
				}
				break;
			default:
				_requestInProcess = false;
				_mtxProcess.unlock();

				assert(!"unknown ert");
				throw("unknown ert");
				return;
			}
			result.wait();
			if(_requests.empty())
			{
				//последний ответ отдать после разблокировки
				break;
			}
			else
			{
				request->_res(result.data());
			}
			result = async::Result<IResultPtrs>();
		}

		assert(_requestInProcess);
		assert(_mtxProcess.isLocked());
		_requestInProcess = false;
		_mtxProcess.unlock();
		request->_res(result.data());
	}


	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::processSingle(async::Result<IResultPtrs> res)
	{
		assert(_mtxProcess.isLocked());
		assert(!_now.is_not_a_date_time());
		assert(_requestInProcess);

		//слать
		while(PQflush(_pgcon))
		{
			system::error_code ec = send0();
			if(ec)
			{
				ELOG(__FUNCTION__<<", send, "<<ec<<", "<<PQerrorMessage(_pgcon));
				res.set();
				return;
			}
		}

		//принимать
		for(;;)
		{
			if(PQisBusy(_pgcon))
			{
				system::error_code ec = recv0();
				if(ec)
				{
					ELOG(__FUNCTION__<<", recv, "<<ec<<", "<<PQerrorMessage(_pgcon));
					res.set();
					return;
				}
			}

			if(!PQconsumeInput(_pgcon))
			{
				ELOG(__FUNCTION__<<", "<<PQerrorMessage(_pgcon));
				res.set();
				return;
			}

			PGresult *pgr = PQgetResult(_pgcon);
			if(!pgr)
			{
				res.set();
				return;
			}

			res.dataNoWait().push_back(IResultPtr(new Result(pgr, shared_from_this())));
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::processQueryWithPrepare(async::Result<IResultPtrs> res, IStatementPtr s, BindDataPtr data)
	{
		assert(_mtxProcess.isLocked());
		assert(!_now.is_not_a_date_time());
		assert(_requestInProcess);

		bool inTrans = false;
		PGTransactionStatusType tstatus = PQtransactionStatus(pgcon());
		assert(PQTRANS_ACTIVE != tstatus);
		switch(tstatus)
		{
// 		case PQTRANS_ACTIVE:
		case PQTRANS_INTRANS:
		case PQTRANS_INERROR:
			inTrans = true;
			break;
		}

		for(;;)
		{
			if(inTrans)
			{
				async::Result<IResultPtrs> r1;
				runQuery_f(r1, "SAVEPOINT pgcp"+getPrid(s));
				if(r1.data().size() != 1 || ersCommandOk != r1.data()[0]->status())
				{
					ELOG(__FUNCTION__<<", "<<PQerrorMessage(_pgcon));
					res(IResultPtrs());
					return;
				}
			}

			async::Result<IResultPtrs> r2;
			runPrepare_f(
				r2,
				getPrid(s), 
				s->getSql(), 
				data);
			if(r2.data().size() != 1 || ersCommandOk != r2.data()[0]->status())
			{
				const char *s4 = r2.data()[0]->errorCode();

				if(s4 && !strcmp(s4, "42P05"))//DUPLICATE PREPARED STATEMENT
				{
					if(inTrans)
					{
						std::string oldPrid = getPrid(s);
						genPrid(s);

						async::Result<IResultPtrs> r3;
						runQuery_f(r3, "ROLLBACK TO SAVEPOINT pgcp"+oldPrid);
						if(r3.data().size() != 1 || ersCommandOk != r3.data()[0]->status())
						{
							ELOG(__FUNCTION__<<", "<<PQerrorMessage(_pgcon));
							res(IResultPtrs());
							return;
						}
					}
					continue;
				}
				else
				{
					ELOG(__FUNCTION__<<", "<<PQerrorMessage(_pgcon));
					delPrepared(s);
					res(IResultPtrs());
					return;
				}
			}
			break;
		}

		if(inTrans)
		{
			async::Result<IResultPtrs> r4;
			runQuery_f(r4, "RELEASE SAVEPOINT pgcp"+getPrid(s));
			if(r4.data().size() != 1 || ersCommandOk != r4.data()[0]->status())
			{
				ELOG(__FUNCTION__<<", "<<PQerrorMessage(_pgcon));
				res(IResultPtrs());
				return;
			}
		}


		runQueryPrepared_f(res, getPrid(s), data);
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::runQuery_f(async::Result<IResultPtrs> res, const std::string &sql)
	{
		assert(_mtxProcess.isLocked());
		assert(!_now.is_not_a_date_time());
		assert(_requestInProcess);

		if(!PQsendQueryParams (
			_pgcon, 
			sql.c_str(), 
			0, 
			NULL, 
			NULL, 
			NULL, 
			NULL, 
			1))
		{
			ELOG(__FUNCTION__<<", "<<PQerrorMessage(_pgcon));
			res(IResultPtrs());
			return;
		};

		processSingle(res);
	}
	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::runPrepare_f(
		async::Result<IResultPtrs> res, 
		const std::string &prid, 
		const std::string &sql, 
		BindDataPtr data)
	{
		assert(_mtxProcess.isLocked());
		assert(!_now.is_not_a_date_time());
		assert(_requestInProcess);

		int nParams = data?data->typ.size():0;
		const Oid *paramTypes = nParams?&data->typ[0]:NULL;
		if(!PQsendPrepare(
			_pgcon, 
			prid.c_str(), 
			sql.c_str(),
			nParams,
			paramTypes))
		{
			ELOG(__FUNCTION__<<", "<<PQerrorMessage(_pgcon));
			res(IResultPtrs());
			return;
		};

		processSingle(res);
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::runQueryPrepared_f(
		async::Result<IResultPtrs> res, 
		const std::string &prid, 
		BindDataPtr data)
	{
		assert(_mtxProcess.isLocked());
		assert(!_now.is_not_a_date_time());
		assert(_requestInProcess);

		int nParams = data?data->typ.size():0;
		const Oid *paramTypes = nParams?&data->typ[0]:NULL;
		const char * const *paramValues = nParams?&data->val[0]:NULL;
		const int *paramLengths = nParams?&data->len[0]:NULL;
		const int *paramFormats = nParams?&data->fmt[0]:NULL;
		if(!PQsendQueryPrepared(
			_pgcon, 
			prid.c_str(),
			nParams,
			paramValues,
			paramLengths,
			paramFormats,
			1))
		{
			ELOG(__FUNCTION__<<", "<<PQerrorMessage(_pgcon));
			res(IResultPtrs());
			return;
		};

		processSingle(res);
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::runQueryWithPrepare_f(async::Result<IResultPtrs> res, IStatementPtr s, BindDataPtr data)
	{
		assert(_mtxProcess.isLocked());
		assert(!_now.is_not_a_date_time());
		assert(_requestInProcess);

		if(hasPrepared(s))
		{
			runQueryPrepared_f(res, getPrid(s), data);
			return;
		}

		processQueryWithPrepare(res, s, data);
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::runEndWork_f(async::Result<IResultPtrs> res)
	{
		assert(_mtxProcess.isLocked());
		assert(!_now.is_not_a_date_time());
		assert(_requestInProcess);

		posix_time::ptime boundATime = _now - posix_time::milliseconds(_timeout);

		TPrepareds::nth_index<1>::type &timedIndex = _prepareds.get<1>();
		while(
			!timedIndex.empty() &&
			(
				timedIndex.size() > _max ||
				boundATime > timedIndex.begin()->_accessTime)		)
		{
			std::string prid = timedIndex.begin()->_prid;
			timedIndex.erase(timedIndex.begin());

			async::Result<IResultPtrs> r;
			runQuery_f(r, "DEALLOCATE "+prid);
			if(r.data().size()!=1 || ersCommandOk != r.data()[0]->status())
			{
				const char * errCode = r.data()[0]->errorCode();
				if(errCode && !strcmp("26000", errCode))
				{
					//ERROR:  prepared statement "XXX" does not exist
				}
				else
				{
					//другая ошибка - фатально
					ELOG(__FUNCTION__<<", "<<PQerrorMessage(_pgcon));
					_prepareds.clear();
					res.set();
					return;
				}
			}
		}

		_now = posix_time::ptime();
		assert(_mtxProcess.isLocked());
		assert(_requestInProcess);
		assert(_pgcon);
		res.set();
	}


	//////////////////////////////////////////////////////////////////////////
	async::Result<system::error_code> ConnectionImpl::send0()
	{
		async::Result<system::error_code> h;
		_sock.async_send(asio::null_buffers(), bind(h, _1));
		return h;
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<system::error_code> ConnectionImpl::recv0()
	{
		async::Result<system::error_code> h;
		_sock.async_receive(asio::null_buffers(), bind(h, _1));
		return h;
	}


	//////////////////////////////////////////////////////////////////////////
	ConnectionImpl::ConnectionImpl(PGconn *pgcon)
		: _pgcon(pgcon)
		, _sock(async::io(), PGSockProtocol(sockFamily(PQsocket(_pgcon)), sockType(PQsocket(_pgcon)), IPPROTO_TCP), PQsocket(_pgcon))
		, _integerDatetimes(false)
		, _requestInProcess(false)
	{
		assert(_pgcon);
		PQsetnonblocking(_pgcon, 0);
	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionImpl::~ConnectionImpl()
	{
		assert(!_mtxProcess.isLocked());
		assert(_now.is_not_a_date_time());
		assert(!_requestInProcess);

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
			assert(!_mtxProcess.isLocked());
			assert(_now.is_not_a_date_time());
			assert(!_requestInProcess);
			assert(_requests.empty());

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
	void ConnectionImpl::runQuery(async::Result<IResultPtrs> res, const std::string &sql)
	{
		_mtxProcess.lock();
		assert(_pgcon);

		SRequestPtr r(new SRequestQuery(res, sql));
		_requests.push_back(r);

		async::spawn(bind(&ConnectionImpl::processRequest, shared_from_this()));
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::runQueryWithPrepare(async::Result<IResultPtrs> res, IStatementPtr s, BindDataPtr data)
	{
		_mtxProcess.lock();
		assert(_pgcon);

		SRequestPtr r(new SRequestQueryWithPrepare(res, s, data));
		_requests.push_back(r);

		async::spawn(bind(&ConnectionImpl::processRequest, shared_from_this()));
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::beginWork()
	{
		assert(_pgcon);
		assert(!_mtxProcess.isLocked());
		assert(_now.is_not_a_date_time());
		assert(!_requestInProcess);
		_now = posix_time::microsec_clock::local_time();
	}
	
	//////////////////////////////////////////////////////////////////////////
	void ConnectionImpl::runEndWork(async::Result<IResultPtrs> res)
	{
		_mtxProcess.lock();
		assert(_pgcon);

		SRequestPtr r(new SRequestEndWork(res));
		_requests.push_back(r);

		async::spawn(bind(&ConnectionImpl::processRequest, shared_from_this()));
	}
}
