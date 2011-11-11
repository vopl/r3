#include "stdafx.h"
#include "pgs/result.hpp"
#include "impl/result.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchNative(size_t rowIdx, size_t colIdx, int typCpp, void *valCpp)
	{
		return _impl->fetch(rowIdx, colIdx, typCpp, valCpp);
	}
	
	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchNative(size_t rowIdx, const std::string &colName, int typCpp, void *valCpp)
	{
		return _impl->fetch(rowIdx, colName, typCpp, valCpp);
	}

	//////////////////////////////////////////////////////////////////////////
	Result::Result(const Impl_ptr &impl)
		: _impl(impl)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	pgc::EExecStatus Result::status()
	{
		return _impl->status();
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
	bool Result::isNull(size_t rowIdx, size_t colIdx)
	{
		return _impl->isNull(rowIdx, colIdx);
	}

	bool Result::isNull(size_t rowIdx, const std::string &colName)
	{
		return _impl->isNull(rowIdx, colName);
	}

}