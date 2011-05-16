#ifndef _PGC_RESULTIMPL_HPP_
#define _PGC_RESULTIMPL_HPP_

#include <libpq-fe.h>
#include "result.hpp"

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

		size_t rows();
		bool fetch(size_t rowIdx, size_t colIdx, int typIdx, void *data);
		bool fetch(size_t rowIdx, const char *colName, int typIdx, void *data);
	};

	typedef boost::shared_ptr<ResultImpl> ResultImplPtr;
}
#endif
