#ifndef _PGC_RESULT_HPP_
#define _PGC_RESULT_HPP_

#include "pgc/iresult.hpp"
#include <boost/enable_shared_from_this.hpp>

namespace pgc
{
	using namespace boost;

	class Result
		: public IResult
		, public enable_shared_from_this<Result>
	{
		PGresult *_pgr;
	public:
		Result(PGresult *pgr);
		~Result();

		virtual EExecStatus status();
		virtual const char *errorMsg();
		virtual const char *errorCode();

		virtual size_t cmdRows();

		virtual size_t rows();
		virtual size_t cols();

		virtual size_t colIdx(const char *colName);
		virtual const char *colName(size_t colIdx);

		virtual bool isNull(size_t rowIdx, size_t colIdx);
		virtual utils::Variant::EType type(size_t rowIdx, size_t colIdx);

		virtual bool fetch(utils::Variant &v, size_t rowIdx, size_t colIdx);

		//////////////////////////////////////////////////////////////////////////
		virtual bool fetchRowList(utils::Variant &v, size_t rowIdx=0);
		virtual bool fetchRowMap(utils::Variant &v, size_t rowIdx=0);

		virtual bool fetchRowsList(utils::Variant &v, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);
		virtual bool fetchRowsMap(utils::Variant &v, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		//////////////////////////////////////////////////////////////////////////
		virtual bool fetchRowList(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx=0);
		virtual bool fetchRowMap(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx=0);

		virtual bool fetchRowsList(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);
		virtual bool fetchRowsMap(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		virtual bool fetchColumn(utils::Variant &v, size_t colIdx, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		//////////////////////////////////////////////////////////////////////////
		virtual boost::int32_t fetchInt32(size_t rowIdx, size_t colIdx);
		virtual boost::uint32_t fetchUInt32(size_t rowIdx, size_t colIdx);
		virtual std::string fetchString(size_t rowIdx, size_t colIdx);

	};
}

#endif

