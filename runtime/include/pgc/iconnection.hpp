#ifndef _PGC_ICONNECTION_HPP_
#define _PGC_ICONNECTION_HPP_

#include "pgc/istatement.hpp"
#include "pgc/iresult.hpp"
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
	struct IConnection
	{
		virtual ~IConnection(){}

		virtual async::Result<IResultPtrs> query(const std::string &sql) =0;
		virtual async::Result<IResultPtrs> query(IStatementPtr s) =0;
		virtual async::Result<IResultPtrs> query(IStatementPtr s, const utils::Variant &data) =0;

		virtual EConnectionStatus status() =0;
	};
	typedef boost::shared_ptr<IConnection> IConnectionPtr;
}
#endif
