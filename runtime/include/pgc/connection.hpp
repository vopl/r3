#ifndef _PGC_CONNECTION_HPP_
#define _PGC_CONNECTION_HPP_

#include "pgc/statement.hpp"
#include "pgc/data.hpp"
#include "utils/variant.hpp"
#include "async/result.hpp"

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
	class PGC_API Connection
	{
	protected:
		typedef ConnectionImplPtr ImplPtr;
		ImplPtr	_impl;

	public:
		Connection();
		~Connection();

		operator bool() const;
		bool operator!() const;

		async::Result<Datas> query(const std::string &sql);
		async::Result<Datas> query(const std::string &sql, const utils::Variant &data);
		async::Result<Datas> query(Statement s, bool withPrepare=true);
		async::Result<Datas> query(Statement s, const utils::Variant &data, bool withPrepare=true);

		EConnectionStatus status();
	};
}
#endif
