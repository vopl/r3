#ifndef _PGC_CONNECTION_HPP_
#define _PGC_CONNECTION_HPP_

#include "pgc/iconnection.hpp"
#include <boost/enable_shared_from_this.hpp>

namespace pgc
{
	using namespace boost;

	class Connection
		: public IConnection
		, public enable_shared_from_this<Connection>
	{
	public:
		Connection();
		~Connection();

		virtual void exec(IStatementPtr s,
			function<void (IResultPtr)> done);
	};
}

#endif

