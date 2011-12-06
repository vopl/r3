#include "pch.h"
#include "pgconnWrapper.hpp"
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
	void PGconnWrapper::cleanPrepareds()
	{
		assert(_maxPreparedStatements > 0);
		TPrepareds::nth_index<1>::type &timedIndex = _prepareds.get<1>();
		while(timedIndex.size() > _maxPreparedStatements)
		{
			timedIndex.erase(timedIndex.end()--);
		}
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
		, _integerDatetimes(false)
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
	void PGconnWrapper::close()
	{
		PQfinish(_lowConn);
		_lowConn = NULL;
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
			bind(&PGconnWrapper::onWaitRead, 
				ready, 
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
	}

	//////////////////////////////////////////////////////////////////////////
	void PGconnWrapper::waitWrite(function<void()> ready)
	{
		_sock.async_send(
			asio::null_buffers(), 
			bind(&PGconnWrapper::onWaitWrite, 
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

		posix_time::ptime timeout = posix_time::microsec_clock::local_time() + posix_time::microseconds(_timeoutPreparedStatements);

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



}
