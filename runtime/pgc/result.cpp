#include "stdafx.h"
#include "result.hpp"
#include "resultImpl.hpp"
#include "exception.hpp"

namespace pgc
{
	Result::Result(ResultImplPtr impl)
		: _impl(impl)
	{
	}

	bool Result::fetchHelper(size_t rowIdx, size_t colIdx, int typIdx, void *data)
	{
		return _impl->fetch(rowIdx, colIdx, typIdx, data);
	}
	
	bool Result::fetchHelper(size_t rowIdx, const char *colName, int typIdx, void *data)
	{
		return _impl->fetch(rowIdx, colName, typIdx, data);
	}

	Result::~Result()
	{
		_impl.reset();
	}

	EExecStatus Result::status()
	{
		return _impl->status();
	}

	Result &Result::throwIfError()
	{
		if(_impl->status() == ees_error)
		{
			throw Exception(_impl);
		}
		return *this;
	}

	size_t Result::rows()
	{
		return _impl->rows();
	}

	bool Result::isNull(size_t rowIdx, size_t colIdx)
	{
		return _impl->isNull(rowIdx, colIdx);
	}

	bool Result::isNull(size_t rowIdx, const char *colName)
	{
		return _impl->isNull(rowIdx, colName);
	}



}