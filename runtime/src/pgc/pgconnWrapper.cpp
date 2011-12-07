#include "pch.h"
#include "pgconnWrapper.hpp"
#include "result.hpp"
#include "bindData.hpp"
#include <boost/random/random_device.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#ifdef _WIN32
#	include <Winsock2.h>
#else
#	include <sys/socket.h>
#endif

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::cleanPrepareds(function<void()> ready)
	{
		assert(_maxPreparedStatements > 0);

		TPrepareds::nth_index<1>::type &timedIndex = _prepareds.get<1>();
		if(timedIndex.size() > _maxPreparedStatements)
		{
			std::string prid = timedIndex.begin()->_prid;
			timedIndex.erase(timedIndex.begin());
			execSimple(("DEALLOCATE "+prid).c_str(), bind(&PGconnWrapper::cleanPrepareds, shared_from_this(), ready));
			return;
		}

		if(_now > timedIndex.begin()->_timeout)
		{
			std::string prid = timedIndex.begin()->_prid;
			timedIndex.erase(timedIndex.begin());
			execSimple(("DEALLOCATE "+prid).c_str(), bind(&PGconnWrapper::cleanPrepareds, shared_from_this(), ready));
			return;
		}

		ready();
	}

	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::onWaitRead(
		function<void()> ready, 
		const boost::system::error_code& error, 
		std::size_t bytes_transferre)
	{
		assert(!bytes_transferre);
		if(ready)
		{
			ready();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::onWaitWrite(
		function<void()> ready, 
		const boost::system::error_code& error, 
		std::size_t bytes_transferre)
	{
		assert(!bytes_transferre);
		if(ready)
		{
			ready();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	int PGconnWrapper::sockFamily(int sock)
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
			std::cerr<<__FUNCTION__<<": getsockname failed"<<std::endl;
		}
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	int PGconnWrapper::sockType(int sock)
	{
		int type;
		int length = sizeof(type);
		if(!getsockopt(sock, SOL_SOCKET, SO_TYPE, (char *)&type, &length))
		{
			return type;
		}
		else
		{
			std::cerr<<__FUNCTION__<<": getsockopt failed"<<std::endl;
		}
		return 0;
	}


	//////////////////////////////////////////////////////////////////////////
	PGconnWrapper::PGconnWrapper(PGconn *lowConn, boost::asio::io_service &io_service)
		: _lowConn(lowConn)
		, _sock(io_service, SockProtocol(sockFamily(PQsocket(_lowConn)), sockType(PQsocket(_lowConn)), IPPROTO_RAW), PQsocket(_lowConn))
		, _sockReadStrand(io_service)
		, _integerDatetimes(false)
		, _inProcess(false)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	PGconnWrapper::~PGconnWrapper()
	{
		close();
	}

	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::onOpen()
	{
		const char *csz = PQparameterStatus(_lowConn, "integer_datetimes");

		if(csz)
		{
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

		PQsetnonblocking(_lowConn, 1);
		PQsetClientEncoding(_lowConn, "UTF-8");
	}

	//////////////////////////////////////////////////////////////////////////
	bool PGconnWrapper::isOpened()
	{
		if(!_lowConn)
		{
			return false;
		}
		ConnStatusType status = PQstatus(_lowConn);
		return CONNECTION_BAD != status;
	}


	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::close()
	{
		assert(!_inProcess);
		if(_lowConn)
		{
			PQfinish(_lowConn);
			_lowConn = NULL;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::beginWork(function<void()> ready)
	{
		_now = posix_time::microsec_clock::local_time();
		ready();
	}
	
	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::endWork(function<void()> ready)
	{
		cleanPrepareds(ready);
	}

	//////////////////////////////////////////////////////////////////////////
	bool PGconnWrapper::integerDatetimes()
	{
		return _integerDatetimes;
	}


	//////////////////////////////////////////////////////////////////////////
	PGconnWrapper::operator PGconn *() const
	{
		return _lowConn;
	}

	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::waitRead(function<void()> ready)
	{
		_sock.async_receive(
			asio::null_buffers(), 
			_sockReadStrand.wrap(
				bind(&PGconnWrapper::onWaitRead, shared_from_this(),
					ready, 
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred)));
	}

	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::waitWrite(function<void()> ready)
	{
		_sock.async_send(
			asio::null_buffers(), 
			bind(&PGconnWrapper::onWaitWrite, shared_from_this(),
				ready, 
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
	}

	//////////////////////////////////////////////////////////////////////////
	namespace 
	{
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
	void PGconnWrapper::touchPrepared(IStatementWtr p)
	{
		struct changeTimeout
		{
			changeTimeout(const posix_time::ptime& newTimeout):newTimeout(newTimeout){}

			void operator()(StatementPrepareState& e)
			{
				e._timeout = newTimeout;
			}

		private:
			posix_time::ptime newTimeout;
		};

		posix_time::ptime timeout = _now + posix_time::milliseconds(_timeoutPreparedStatements);

		TPrepareds::nth_index<0>::type &ptrIndex = _prepareds.get<0>();
		TPrepareds::nth_index<0>::type::iterator iter = ptrIndex.find(p);
		if(ptrIndex.end() != iter)
		{
			ptrIndex.modify(iter, changeTimeout(timeout));
			return;
		}

		StatementPrepareState sps = 
		{
			pridGenerator(),
			p, 
			timeout
		};
		_prepareds.insert(sps);
	}

	//////////////////////////////////////////////////////////////////////////
	bool PGconnWrapper::hasPrepared(IStatementWtr p)
	{
		TPrepareds::nth_index<0>::type &ptrIndex = _prepareds.get<0>();
		TPrepareds::nth_index<0>::type::iterator iter = ptrIndex.find(p);
		return ptrIndex.end() != iter;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string PGconnWrapper::getPrid(IStatementWtr p)
	{
		TPrepareds::nth_index<0>::type &ptrIndex = _prepareds.get<0>();
		TPrepareds::nth_index<0>::type::iterator iter = ptrIndex.find(p);
		if(ptrIndex.end() != iter)
		{
			return iter->_prid;
		}
		assert(0);
		return "unknown";
	}

	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::genPrid(IStatementWtr p)
	{
		struct changePrid
		{
			changePrid(const std::string& newPrid):newPrid(newPrid){}

			void operator()(StatementPrepareState& e)
			{
				e._prid = newPrid;
			}

		private:
			std::string newPrid;
		};

		TPrepareds::nth_index<0>::type &ptrIndex = _prepareds.get<0>();
		TPrepareds::nth_index<0>::type::iterator iter = ptrIndex.find(p);
		if(ptrIndex.end() != iter)
		{
			ptrIndex.modify(iter, changePrid(pridGenerator()));
			return;
		}
		assert(!"statement absent!");
	}










	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::continueSend()
	{
		assert(_inProcess);

		if(PQflush(_lowConn))
		{
			waitWrite(
				bind(&PGconnWrapper::continueSend, shared_from_this()));
			return;

		}

		waitRead(
				bind(&PGconnWrapper::continueRecv, shared_from_this()));
	}

	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::continueRecv()
	{
		assert(_inProcess);

		if(_lowConn)
		{
			if(!PQconsumeInput(_lowConn))
			{
				std::cerr<<__FUNCTION__<<": "<<PQerrorMessage(_lowConn)<<std::endl;
			}

			PGresult *pgr = PQgetResult(_lowConn);
			while(pgr)
			{
				_results.push_back(pgr);

				if(!PQconsumeInput(_lowConn))
				{
					std::cerr<<__FUNCTION__<<": "<<PQerrorMessage(_lowConn)<<std::endl;
				}
				if(PQisBusy(_lowConn))
				{
					waitRead(
							bind(&PGconnWrapper::continueRecv, shared_from_this()));

					return;
				}

				pgr = PQgetResult(_lowConn);
			}
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
				done(IResultPtr(new Result(pgr, shared_from_this())));
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
	void PGconnWrapper::execSimple(const char *sql, boost::function<void (IResultPtr)> done)
	{
		assert(!_inProcess);
		assert(!_done);
		assert(_results.empty());

		_inProcess = true;

		if(!PQsendQuery(_lowConn, sql))
		{
			std::cerr<<__FUNCTION__<<": "<<PQerrorMessage(_lowConn)<<std::endl;
			_inProcess = false;
			if(done)
			{
				done(IResultPtr());
			}
			return;
		}

		_done = done;
		continueSend();
	}

	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::execPrepare(IStatementPtr s, BindDataPtr data, boost::function<void (IResultPtr)> done)
	{
		assert(!_inProcess);
		assert(!_done);
		assert(_results.empty());

		_inProcess = true;

		int nParams = data?data->typ.size():0;
		const Oid *paramTypes = nParams?&data->typ[0]:NULL;
		if(!PQsendPrepare(
			_lowConn, 
			getPrid(s).c_str(),
			s->getSql().c_str(),
			nParams,
			paramTypes))
		{
			std::cerr<<__FUNCTION__<<": "<<PQerrorMessage(_lowConn)<<std::endl;
			_inProcess = false;
			if(done)
			{
				done(IResultPtr());
			}
			return;
		}

		_done = done;
		continueSend();
	}
	
	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::execPrepared(IStatementPtr s, BindDataPtr data, boost::function<void (IResultPtr)> done)
	{
		assert(!_inProcess);
		assert(!_done);
		assert(_results.empty());

		_inProcess = true;

		int nParams = data?data->typ.size():0;
		const Oid *paramTypes = nParams?&data->typ[0]:NULL;
		const char * const *paramValues = nParams?&data->val[0]:NULL;
		const int *paramLengths = nParams?&data->len[0]:NULL;
		const int *paramFormats = nParams?&data->fmt[0]:NULL;

		if(!PQsendQueryPrepared(
			_lowConn, 
			getPrid(s).c_str(),
			nParams,
			paramValues,
			paramLengths,
			paramFormats,
			1))
		{
			std::cerr<<__FUNCTION__<<": "<<PQerrorMessage(_lowConn)<<std::endl;
			_inProcess = false;
			if(done)
			{
				done(IResultPtr());
			}
			return;
		}

		_done = done;
		continueSend();
	}



}
