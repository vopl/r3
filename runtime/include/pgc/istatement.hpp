#ifndef _PGC_ISTATEMENT_HPP_
#define _PGC_ISTATEMENT_HPP_

#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include "pluma/pluma.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	struct IStatement
	{
		virtual ~IStatement(){}

		virtual void setSql(const char *csz) =0;
		virtual void setSql(const std::string &sql) =0;
		virtual const std::string &getSql() =0;

// 		virtual const std::string &getPreparedId() =0;
// 		virtual void setPreparedId(const char *csz) =0;
	};
	typedef boost::shared_ptr<IStatement> IStatementPtr;
	typedef boost::weak_ptr<IStatement> IStatementWtr;

	PLUMA_PROVIDER_HEADER(IStatement, 1, 1);
}
#endif
