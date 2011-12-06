#ifndef _PGC_IRESULT_HPP_
#define _PGC_IRESULT_HPP_

#include "utils/variant.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	enum EExecStatus
	{
		eesCommandOk,
		eesTuplesOk,
		eesError,
	};

	//////////////////////////////////////////////////////////////////////////
	struct IResult
	{
		virtual ~IResult(){}

		virtual EExecStatus status() = 0;
		virtual const char *errorMsg() = 0;
		virtual const char *errorCode() = 0;

		virtual size_t cmdRows() = 0;

		virtual size_t rows() =0;
		virtual size_t cols() =0;

		virtual size_t colIdx(const char *colName) =0;
		virtual const char *colName(size_t colIdx) =0;

		virtual bool isNull(size_t rowIdx, size_t colIdx) =0;
		virtual utils::Variant::EType type(size_t rowIdx, size_t colIdx) =0;

		virtual bool fetch(utils::Variant &v, size_t rowIdx, size_t colIdx) =0;

		//////////////////////////////////////////////////////////////////////////
		virtual bool fetchRowList(utils::Variant &v, size_t rowIdx=0) =0;
		virtual bool fetchRowMap(utils::Variant &v, size_t rowIdx=0) =0;

		virtual bool fetchRowsList(utils::Variant &v, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1) =0;
		virtual bool fetchRowsMap(utils::Variant &v, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1) =0;

		//////////////////////////////////////////////////////////////////////////
		virtual bool fetchRowList(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx=0) =0;
		virtual bool fetchRowMap(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx=0) =0;

		virtual bool fetchRowsList(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1) =0;
		virtual bool fetchRowsMap(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1) =0;

		virtual bool fetchColumn(utils::Variant &v, size_t colIdx, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1) =0;

		//////////////////////////////////////////////////////////////////////////
		virtual boost::int32_t fetchInt32(size_t rowIdx, size_t colIdx) =0;
		virtual boost::uint32_t fetchUInt32(size_t rowIdx, size_t colIdx) =0;
		virtual std::string fetchString(size_t rowIdx, size_t colIdx) =0;
	};
	typedef boost::shared_ptr<IResult> IResultPtr;
}
#endif
