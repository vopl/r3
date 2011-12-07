#ifndef _PGC_ICONNECTION_HPP_
#define _PGC_ICONNECTION_HPP_

#include "pgc/istatement.hpp"
#include "pgc/iresult.hpp"
#include "utils/variant.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	struct IConnection
	{
		virtual ~IConnection(){}

		virtual void exec(const char *sql,
			boost::function<void (IResultPtr)> done) =0;

		virtual void exec(IStatementPtr s,
			boost::function<void (IResultPtr)> done) =0;

		virtual void exec(IStatementPtr s,
			const utils::Variant &data,
			boost::function<void (IResultPtr)> done) =0;

		virtual void close() =0;
	};
	typedef boost::shared_ptr<IConnection> IConnectionPtr;
}
#endif
