#include "pgc/result.hpp"
#include "pgc/exception.hpp"
#include "resultImpl.hpp"

namespace pgc
{
	Result::Result(ResultImplPtr impl)
		: _impl(impl)
	{
	}

	bool Result::fetchNative(int typCpp, void *valCpp, size_t colIdx, size_t rowIdx)
	{
		return _impl->fetch(typCpp, valCpp, colIdx, rowIdx);
	}
	
	bool Result::fetchNative(int typCpp, void *valCpp, const char *colName, size_t rowIdx)
	{
		return _impl->fetch(typCpp, valCpp, colName, rowIdx);
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

	boost::int32_t Result::fetchInt32(int colIdx, size_t rowIdx)
	{
		boost::int32_t res;
		if(!fetch(res, colIdx, rowIdx))
		{
			throw std::runtime_error("fetchInt32 failed");
			return res;
		}
		return res;
	}

	boost::int32_t Result::fetchInt32(const char *colName, size_t rowIdx)
	{
		boost::int32_t res;
		if(!fetch(res, colName, rowIdx))
		{
			throw std::runtime_error("fetchInt32 failed");
			return res;
		}
		return res;
	}

	boost::uint32_t Result::fetchUInt32(int colIdx, size_t rowIdx)
	{
		boost::uint32_t res;
		if(!fetch(res, colIdx, rowIdx))
		{
			throw std::runtime_error("fetchUInt32 failed");
			return res;
		}
		return res;
	}

	boost::uint32_t Result::fetchUInt32(const char *colName, size_t rowIdx)
	{
		boost::uint32_t res;
		if(!fetch(res, colName, rowIdx))
		{
			throw std::runtime_error("fetchUInt32 failed");
			return res;
		}
		return res;
	}

	std::string Result::fetchString(int colIdx, size_t rowIdx)
	{
		std::string res;
		if(!fetch(res, colIdx, rowIdx))
		{
			throw std::runtime_error("fetchString failed");
			return res;
		}
		return res;
	}

	std::string Result::fetchString(const char *colName, size_t rowIdx)
	{
		std::string res;
		if(!fetch(res, colName, rowIdx))
		{
			throw std::runtime_error("fetchString failed");
			return res;
		}
		return res;
	}

	bool Result::isNull(int colIdx, size_t rowIdx)
	{
		return _impl->isNull(colIdx, rowIdx);
	}

	bool Result::isNull(const char *colName, size_t rowIdx)
	{
		return _impl->isNull(colName, rowIdx);
	}



}