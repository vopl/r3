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
	};
	typedef boost::shared_ptr<IStatement> IStatementPtr;

	PLUMA_PROVIDER_HEADER(IStatement, 1, 1);
}
#endif
