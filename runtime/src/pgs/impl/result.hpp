#ifndef _PGS_IMPL_RESULT_HPP_
#define _PGS_IMPL_RESULT_HPP_

#include "pgc/result.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		class Result
		{
			pgc::Result _pg;
		public:
			Result(pgc::Result pg);

			pgc::EExecStatus status();

			size_t cmdRows();
			size_t rows();

			bool fetch(size_t rowIdx, size_t colIdx, int typCpp, void *valCpp);
			bool fetch(size_t rowIdx, const std::string &colName, int typCpp, void *valCpp);

			bool isNull(size_t rowIdx, size_t colIdx);
			bool isNull(size_t rowIdx, const std::string &colName);


		};
		typedef boost::shared_ptr<Result> Result_ptr;
	}
}

#endif
