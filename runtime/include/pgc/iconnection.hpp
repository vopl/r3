#ifndef _PGC_ICONNECTION_HPP_
#define _PGC_ICONNECTION_HPP_

#include "pgc/istatement.hpp"
#include "pgc/iresult.hpp"
#include "utils/variant.hpp"

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

		virtual void exec(const std::string &sql,
			boost::function<void (IResultPtrs)> done) =0;

		virtual void exec(IStatementPtr s,
			boost::function<void (IResultPtrs)> done) =0;

		virtual void exec(IStatementPtr s,
			const utils::Variant &data,
			boost::function<void (IResultPtrs)> done) =0;

		virtual EConnectionStatus status() =0;
	};
	typedef boost::shared_ptr<IConnection> IConnectionPtr;
}
#endif
