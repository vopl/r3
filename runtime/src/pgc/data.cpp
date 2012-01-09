#include "pch.h"
#include "pgc/data.hpp"
#include "dataImpl.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	Data::Data()
	{
	}


	//////////////////////////////////////////////////////////////////////////
	EDataStatus Data::status()
	{
		return _impl->status();
	}

	//////////////////////////////////////////////////////////////////////////
	const char *Data::errorMsg()
	{
		return _impl->errorMsg();
	}

	//////////////////////////////////////////////////////////////////////////
	const char *Data::errorCode()
	{
		return _impl->errorCode();
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Data::cmdRows()
	{
		return _impl->cmdRows();
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Data::rows()
	{
		return _impl->rows();
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Data::cols()
	{
		return _impl->cols();
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Data::colIdx(const char *colName)
	{
		return _impl->colIdx(colName);
	}

	//////////////////////////////////////////////////////////////////////////
	const char *Data::colName(size_t colIdx)
	{
		return _impl->colName(colIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	utils::Variant::EType Data::colType(size_t colIdx)
	{
		return _impl->colType(colIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Data::isNull(size_t colIdx, size_t rowIdx)
	{
		return _impl->isNull(colIdx, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Data::fetch(utils::Variant &v, size_t colIdx, size_t rowIdx)
	{
		return _impl->fetch(v, colIdx, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Data::fetchRowList(utils::Variant &v, size_t rowIdx)
	{
		return _impl->fetchRowList(v, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Data::fetchRowMap(utils::Variant &v, size_t rowIdx)
	{
		return _impl->fetchRowMap(v, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Data::fetchRowsList(utils::Variant &v, size_t rowBeginIdx, size_t rowEndIdx)
	{
		return _impl->fetchRowsList(v, rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Data::fetchRowsMap(utils::Variant &v, size_t rowBeginIdx, size_t rowEndIdx)
	{
		return _impl->fetchRowsMap(v, rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Data::fetchRowList(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx)
	{
		return _impl->fetchRowList(v, colIndices, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Data::fetchRowMap(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx)
	{
		return _impl->fetchRowMap(v, colIndices, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Data::fetchRowsList(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx, size_t rowEndIdx)
	{
		return _impl->fetchRowsList(v, colIndices, rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Data::fetchRowsMap(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx, size_t rowEndIdx)
	{
		return _impl->fetchRowsMap(v, colIndices, rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Data::fetchColumn(utils::Variant &v, size_t colIdx, size_t rowBeginIdx, size_t rowEndIdx)
	{
		return _impl->fetchColumn(v, colIdx, rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	boost::int32_t Data::fetchInt32(size_t colIdx, size_t rowIdx)
	{
		return _impl->fetchInt32(colIdx, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	boost::uint32_t Data::fetchUInt32(size_t colIdx, size_t rowIdx)
	{
		return _impl->fetchUInt32(colIdx, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	std::string Data::fetchString(size_t colIdx, size_t rowIdx)
	{
		return _impl->fetchString(colIdx, rowIdx);
	}
}