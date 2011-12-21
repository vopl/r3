#ifndef _PGC_CONNECTIONHOLDER_HPP_
#define _PGC_CONNECTIONHOLDER_HPP_

#include "pgc/iconnection.hpp"
#include <boost/enable_shared_from_this.hpp>
#include "connectionImpl.hpp"
#include "bindData.hpp"

namespace pgc
{
	using namespace boost;


	class Db;
	typedef shared_ptr<Db> DbPtr;

	//////////////////////////////////////////////////////////////////////////
	class ConnectionHolder
		: public IConnection
		, public enable_shared_from_this<ConnectionHolder>
	{
		DbPtr _db;
		ConnectionImplPtr _impl;

	public:
		ConnectionHolder(DbPtr db, ConnectionImplPtr impl);
		~ConnectionHolder();

		virtual async::Result<IResultPtrs> query(const std::string &sql);
		virtual async::Result<IResultPtrs> query(IStatementPtr s);
		virtual async::Result<IResultPtrs> query(IStatementPtr s, const utils::Variant &data);

		virtual EConnectionStatus status();
	};
	typedef shared_ptr<ConnectionHolder> ConnectionHolderPtr;
}

#endif

