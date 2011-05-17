#include "pgc/result.hpp"
#include "pgc/exception.hpp"
#include "resultImpl.hpp"

namespace pgc
{
	Result::Result(ResultImplPtr impl)
		: _impl(impl)
	{
	}

	bool Result::fetchHelper(int rowIdx, int colIdx, int typIdx, void *data)
	{
		return _impl->fetch(rowIdx, colIdx, typIdx, data);
	}
	
	bool Result::fetchHelper(int rowIdx, const char *colName, int typIdx, void *data)
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

	int Result::rows()
	{
		return _impl->rows();
	}

	bool Result::isNull(int rowIdx, int colIdx)
	{
		return _impl->isNull(rowIdx, colIdx);
	}

	bool Result::isNull(int rowIdx, const char *colName)
	{
		return _impl->isNull(rowIdx, colName);
	}



}