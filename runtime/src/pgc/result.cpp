#include "pgc/result.hpp"
#include "pgc/exception.hpp"
#include "resultImpl.hpp"

namespace pgc
{
	Result::Result(ResultImplPtr impl)
		: _impl(impl)
	{
	}

	bool Result::fetchNative(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		return _impl->fetch(rowIdx, colIdx, typCpp, valCpp);
	}
	
	bool Result::fetchNative(int rowIdx, const char *colName, int typCpp, void *valCpp)
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

	size_t Result::cmdRows()
	{
		return _impl->cmdRows();
	}

	int Result::rows()
	{
		return _impl->rows();
	}

	boost::int32_t Result::fetchInt32(int rowIdx, int colIdx)
	{
		boost::int32_t res;
		if(!fetch(rowIdx, colIdx, res))
		{
			throw std::runtime_error("fetchInt failed");
			return res;
		}
		return res;
	}

	boost::int32_t Result::fetchInt32(int rowIdx, const char *colName)
	{
		boost::int32_t res;
		if(!fetch(rowIdx, colName, res))
		{
			throw std::runtime_error("fetchInt failed");
			return res;
		}
		return res;
	}

	boost::uint32_t Result::fetchUInt32(int rowIdx, int colIdx)
	{
		boost::uint32_t res;
		if(!fetch(rowIdx, colIdx, res))
		{
			throw std::runtime_error("fetchInt failed");
			return res;
		}
		return res;
	}

	boost::uint32_t Result::fetchUInt32(int rowIdx, const char *colName)
	{
		boost::uint32_t res;
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