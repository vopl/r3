#ifndef _PGC_CONNECTIONPREPAREDS_HPP_
#define _PGC_CONNECTIONPREPAREDS_HPP_

#include "connectionRunner.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	class ConnectionPrepareds;
	typedef shared_ptr<ConnectionPrepareds> ConnectionPreparedsPtr;
	class ConnectionPrepareds
		: public ConnectionRunner
	{
	private:
		ConnectionPreparedsPtr shared_from_this();

	public:
		ConnectionPrepareds(PGconn *pgcon, asio::io_service &io_service);
		~ConnectionPrepareds();

		void exec(IStatementPtr s,
			boost::function<void (IResultPtr)> done);

		void exec(IStatementPtr s,
			BindDataPtr data,
			boost::function<void (IResultPtr)> done);
	};
}
#endif
