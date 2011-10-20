#include "pgc/result.hpp"
#include "pgc/exception.hpp"
#include "resultImpl.hpp"

namespace pgc
{
	Result::Result(ResultImplPtr impl)
		: _impl(impl)
	{
	}

	bool Result::fetchHelper(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		return _impl->fetch(rowIdx, colIdx, typCpp, valCpp);
	}
	
	bool Result::fetchHelper(int rowIdx, const char *colName, int typCpp, void *valCpp)
	{
		return _impl->fetch(rowIdx, colName, typCpp, valCpp);
	}

	Result::Result()
	{

	}

	Result::~Result()
	{
		_impl.reset();
	}

	EExecStatus Result::status()
	{
		return _impl->status();
	}
	const char *Result::errorMsg()
	{
		return _impl->errorMsg();
	}
	const char *Result::errorCode()
	{
		return _impl->errorCode();
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

	int Result::fetchInt(int rowIdx, int colIdx)
	{
		int res;
		if(!fetch(rowIdx, colIdx, res))
		{
			throw std::runtime_error("fetchInt failed");
			return res;
		}
		return res;
	}

	int Result::fetchInt(int rowIdx, const char *colName)
	{
		int res;
		if(!fetch(rowIdx, colName, res))
		{
			throw std::runtime_error("fetchInt failed");
			return res;
		}
		return res;
	}

	std::string Result::fetchString(int rowIdx, int colIdx)
	{
		std::string res;
		if(!fetch(rowIdx, colIdx, res))
		{
			throw std::runtime_error("fetchString failed");
			return res;
		}
		return res;
	}

	std::string Result::fetchString(int rowIdx, const char *colName)
	{
		std::string res;
		if(!fetch(rowIdx, colName, res))
		{
			throw std::runtime_error("fetchString failed");
			return res;
		}
		return res;
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