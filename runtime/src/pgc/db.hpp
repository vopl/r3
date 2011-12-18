#ifndef _PGC_DB_HPP_
#define _PGC_DB_HPP_

#include "pgc/idb.hpp"
#include <boost/enable_shared_from_this.hpp>
#include <boost/thread/mutex.hpp>
#include <set>
#include <deque>
#include "connectionHolder.hpp"

namespace pgc
{
	using namespace boost;

	class Db
		: public IDb
		, public enable_shared_from_this<Db>
	{
		mutex					_mtx;
		async::IServicePtr		_asrv;
		std::string				_conninfo;
		size_t					_maxConnections;
		function<void (size_t)> _onConnectionMade;
		function<void (size_t)> _onConnectionLost;

	private:
		typedef std::set<ConnectionPreparedsPtr> TSConnectins;
		TSConnectins									_startConnections;
		TSConnectins									_readyConnections;
		TSConnectins									_workConnections;
		std::deque<function<void (IConnectionPtr)> >	_waiters;

		typedef asio::deadline_timer Timeout;
		typedef boost::shared_ptr<Timeout> TimeoutPtr;
		TimeoutPtr	_timeout;

	private:
		void balanceConnections();
		void makeConnection_poll(ConnectionPreparedsPtr pcw, system::error_code ec);

	private:
		void onReconnectTimer();

	public:
		void unwork(ConnectionPreparedsPtr pcw);

	private:
		void allocConnection_f(function<void (IConnectionPtr)> ready);

	public:
		Db();
		~Db();

		virtual void initialize(
			async::IServicePtr asrv,
			const char *conninfo,
			size_t maxConnections,
			function<void (size_t)> connectionMade,
			function<void (size_t)> connectionLost);

		virtual void allocConnection(function<void (IConnectionPtr)> ready);

		virtual void deinitialize();
	};

	PLUMA_INHERIT_PROVIDER(Db, IDb);
}

#endif

