#ifndef _PGC_DB_HPP_
#define _PGC_DB_HPP_

#include "pgc/idb.hpp"
#include <boost/enable_shared_from_this.hpp>
#include <boost/thread/mutex.hpp>
#include <set>
#include <deque>
#include "pgconnWrapper.hpp"

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
		std::set<PGconnWrapperPtr>						_startConnections;
		std::set<PGconnWrapperPtr>						_readyConnections;
		std::set<PGconnWrapperPtr>						_workConnections;
		std::deque<function<void (IConnectionPtr)> >	_waiters;

	private:
		void balanceConnections();
		void makeConnection_poll(PGconnWrapperPtr pcw);

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

