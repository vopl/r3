#ifndef _PGC_CONNECTION_HPP_
#define _PGC_CONNECTION_HPP_

#include "pgc/statement.hpp"
#include "pgc/data.hpp"
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

		async::Future<Datas> query(const char *sql);
		async::Future<Datas> query(const char *, const utils::Variant &data);
		async::Future<Datas> query(const std::string &sql);
		async::Future<Datas> query(const std::string &sql, const utils::Variant &data);
		async::Future<Datas> query(Statement s, bool withPrepare=true);
		async::Future<Datas> query(Statement s, const utils::Variant &data, bool withPrepare=true);

		EConnectionStatus status();
	};
}
#endif
