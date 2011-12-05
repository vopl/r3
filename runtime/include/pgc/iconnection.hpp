#ifndef _PGC_ICONNECTION_HPP_
#define _PGC_ICONNECTION_HPP_

#include "pgc/istatement.hpp"
#include "pgc/iresult.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	struct IConnection
	{
		virtual ~IConnection(){}

		virtual void exec(IStatementPtr s,
			boost::function<void (IResultPtr)> done) =0;
	};
	typedef boost::shared_ptr<IConnection> IConnectionPtr;
}
#endif