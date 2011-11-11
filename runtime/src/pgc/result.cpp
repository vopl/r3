#include "pgc/result.hpp"
#include "pgc/exception.hpp"
#include "resultImpl.hpp"

namespace pgc
{
	Result::Result(ResultImplPtr impl)
		: _impl(impl)
	{
	}

	bool Result::fetchNative(int typCpp, void *valCpp, size_t rowIdx, size_t colIdx)
	{
		return _impl->fetch(typCpp, valCpp, rowIdx, colIdx);
	}
	
	bool Result::fetchNative(int typCpp, void *valCpp, size_t rowIdx, const char *colName)
	{
		return _impl->fetch(typCpp, valCpp, rowIdx, colName);
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

	size_t Result::rows()
	{
		return _impl->rows();
	}

	boost::int32_t Result::fetchInt32(size_t rowIdx, size_t colIdx)
	{
		boost::int32_t res;
		if(!fetch(res, rowIdx, colIdx))
		{
			throw std::runtime_error("fetchInt failed");
			return res;
		}
		return res;
	}

	boost::int32_t Result::fetchInt32(size_t rowIdx, const char *colName)
	{
		boost::int32_t res;
		if(!fetch(res, rowIdx, colName))
		{
			throw std::runtime_error("fetchInt failed");
			return res;
		}
		return res;
	}

	boost::uint32_t Result::fetchUInt32(size_t rowIdx, size_t colIdx)
	{
		boost::uint32_t res;
		if(!fetch(res, rowIdx, colIdx))
		{
			throw std::runtime_error("fetchInt failed");
			return res;
		}
		return res;
	}

	boost::uint32_t Result::fetchUInt32(size_t rowIdx, const char *colName)
	{
		boost::uint32_t res;
		if(!fetch(res, rowIdx, colName))
		{
			throw std::runtime_error("fetchInt failed");
			return res;
		}
		return res;
	}

	std::string Result::fetchString(size_t rowIdx, size_t colIdx)
	{
		std::string res;
		if(!fetch(res, rowIdx, colIdx))
		{
			throw std::runtime_error("fetchString failed");
			return res;
		}
		return res;
	}

	std::string Result::fetchString(size_t rowIdx, const char *colName)
	{
		std::string res;
		if(!fetch(res, rowIdx, colName))
		{
			throw std::runtime_error("fetchString failed");
			return res;
		}
		return res;
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