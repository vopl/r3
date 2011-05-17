#ifndef _PGC_RESULTIMPL_HPP_
#define _PGC_RESULTIMPL_HPP_

#include <boost/enable_shared_from_this.hpp>
#include <libpq-fe.h>
#include "pgc/result.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	class ResultImpl
		: public boost::enable_shared_from_this<ResultImpl>
	{
		PGresult *_pgres;
	public:
		ResultImpl(PGresult *pgres);
		~ResultImpl();

		EExecStatus status();
		const char *errorMsg();

		size_t cmdRows();

		int rows();
		bool fetch(int rowIdx, int colIdx, int typIdx, void *data);
		bool fetch(int rowIdx, const char *colName, int typIdx, void *data);

		bool isNull(int rowIdx, int colIdx);
		bool isNull(int rowIdx, const char *colName);

	};

	typedef boost::shared_ptr<ResultImpl> ResultImplPtr;
}
#endif
