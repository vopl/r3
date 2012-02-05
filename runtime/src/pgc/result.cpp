#include "pch.h"
#include "pgc/result.hpp"
#include "resultImpl.hpp"

namespace pgc
{
// 	//////////////////////////////////////////////////////////////////////////
// 	Result::Result()
// 	{
// 	}


	//////////////////////////////////////////////////////////////////////////
	EResultStatus Result::status()
	{
		return _impl->status();
	}

	//////////////////////////////////////////////////////////////////////////
	const char *Result::errorMsg()
	{
		return _impl->errorMsg();
	}

	//////////////////////////////////////////////////////////////////////////
	const char *Result::errorCode()
	{
		return _impl->errorCode();
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Result::cmdRows()
	{
		return _impl->cmdRows();
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Result::rows()
	{
		return _impl->rows();
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Result::cols()
	{
		return _impl->cols();
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Result::colIdx(const char *colName)
	{
		return _impl->colIdx(colName);
	}

	//////////////////////////////////////////////////////////////////////////
	const char *Result::colName(size_t colIdx)
	{
		return _impl->colName(colIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	utils::Variant::EType Result::colType(size_t colIdx)
	{
		return _impl->colType(colIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::isNull(size_t colIdx, size_t rowIdx)
	{
		return _impl->isNull(colIdx, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetch(utils::Variant &v, size_t colIdx, size_t rowIdx)
	{
		return _impl->fetch(v, colIdx, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowList(utils::Variant &v, size_t rowIdx)
	{
		return _impl->fetchRowList(v, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowMap(utils::Variant &v, size_t rowIdx)
	{
		return _impl->fetchRowMap(v, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowsList(utils::Variant &v, size_t rowBeginIdx, size_t rowEndIdx)
	{
		return _impl->fetchRowsList(v, rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowsMap(utils::Variant &v, size_t rowBeginIdx, size_t rowEndIdx)
	{
		return _impl->fetchRowsMap(v, rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowList(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx)
	{
		return _impl->fetchRowList(v, colIndices, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowMap(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx)
	{
		return _impl->fetchRowMap(v, colIndices, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowsList(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx, size_t rowEndIdx)
	{
		return _impl->fetchRowsList(v, colIndices, rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowsMap(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx, size_t rowEndIdx)
	{
		return _impl->fetchRowsMap(v, colIndices, rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchColumn(utils::Variant &v, size_t colIdx, size_t rowBeginIdx, size_t rowEndIdx)
	{
		return _impl->fetchColumn(v, colIdx, rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	boost::int32_t Result::fetchInt32(size_t colIdx, size_t rowIdx)
	{
		return _impl->fetchInt32(colIdx, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	boost::uint32_t Result::fetchUInt32(size_t colIdx, size_t rowIdx)
	{
		return _impl->fetchUInt32(colIdx, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	std::string Result::fetchString(size_t colIdx, size_t rowIdx)
	{
		return _impl->fetchString(colIdx, rowIdx);
	}
}