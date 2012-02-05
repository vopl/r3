#ifndef _PGC_CONNECTION_HPP_
#define _PGC_CONNECTION_HPP_

#include "pgc/statement.hpp"
#include "pgc/result.hpp"
#include "utils/variant.hpp"
#include "async/future.hpp"

namespace pgc
{
	enum EConnectionStatus
	{
		ecsNull,
		ecsLost,
		ecsOk,
	};


	//////////////////////////////////////////////////////////////////////////
	class ConnectionImpl;
	typedef boost::shared_ptr<ConnectionImpl> ConnectionImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class PG_API Connection
	{
	protected:
		typedef ConnectionImplPtr ImplPtr;
		ImplPtr	_impl;

	public:
		Connection();
		~Connection();

		operator bool() const;
		bool operator!() const;

		async::Future<Result> query(const char *sql);
		async::Future<Result> query(const char *, const utils::Variant &data);
		async::Future<Result> query(const std::string &sql);
		async::Future<Result> query(const std::string &sql, const utils::Variant &data);
		async::Future<Result> query(Statement s, bool withPrepare=true);
		async::Future<Result> query(Statement s, const utils::Variant &data, bool withPrepare=true);

		EConnectionStatus status();
	};
}
#endif
