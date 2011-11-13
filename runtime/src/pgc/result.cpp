#include "pgc/result.hpp"
#include "pgc/exception.hpp"
#include "resultImpl.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	Result::Result(ResultImplPtr impl)
		: _impl(impl)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchNative(int typCpp, void *valCpp, size_t colIdx, size_t rowIdx)
	{
		return _impl->fetch(typCpp, valCpp, colIdx, rowIdx);
	}
	
	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchNative(int typCpp, void *valCpp, const char *colName, size_t rowIdx)
	{
		return _impl->fetch(typCpp, valCpp, colName, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	Result::~Result()
	{
		_impl.reset();
	}

	//////////////////////////////////////////////////////////////////////////
	EExecStatus Result::status()
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
	Result &Result::throwIfError()
	{
		if(_impl->status() == ees_error)
		{
			throw Exception(_impl);
		}
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	int Result::bestType(size_t colIdx) const
	{
		return _impl->bestType((int)colIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	int Result::bestType(const char *colName) const
	{
		return _impl->bestType(colName);
	}

	//////////////////////////////////////////////////////////////////////////
	const char *Result::name(size_t colIdx) const
	{
		return _impl->name(colIdx);
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
	size_t Result::columns()
	{
		return _impl->columns();
	}


	//////////////////////////////////////////////////////////////////////////
	bool Result::fetch(utils::Variant &v, int colIdx, size_t rowIdx)
	{
		int bestType = this->bestType(colIdx);
		switch(bestType)
		{
		case CppDataType<Blob>::cdt_index:
			bestType = CppDataType<boost::uint32_t>::cdt_index;
			break;
		case CppDataType<Money>::cdt_index:
			bestType = CppDataType<boost::int64_t>::cdt_index;
			break;
		}
		v.forceType((utils::Variant::EType)bestType);
		return fetchNative(v.type(), v.data(), colIdx, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetch(utils::Variant &v, const char *colName, size_t rowIdx)
	{
		int bestType = this->bestType(colName);
		switch(bestType)
		{
		case CppDataType<Blob>::cdt_index:
			bestType = CppDataType<boost::uint32_t>::cdt_index;
			break;
		case CppDataType<Money>::cdt_index:
			bestType = CppDataType<boost::int64_t>::cdt_index;
			break;
		}
		v.forceType((utils::Variant::EType)bestType);
		return fetchNative(v.type(), v.data(), colName, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchArray(utils::Variant::VectorVariant &v, size_t rowIdx)
	{
		size_t columns = this->columns();
		v.resize(columns);

		for(size_t colIdx(0); colIdx<columns; colIdx++)
		{
			if(isNull(colIdx, rowIdx))
			{
				v[colIdx].clear();
			}
			else
			{
				if(!fetch(v[colIdx], colIdx, rowIdx))
				{
					return false;
				}
			}
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchMap(utils::Variant::MapStringVariant &v, size_t rowIdx)
	{
		size_t columns = this->columns();
		v.clear();

		for(size_t colIdx(0); colIdx<columns; colIdx++)
		{
			if(isNull(colIdx, rowIdx))
			{
				v[name(colIdx)];
			}
			else
			{
				if(!fetch(v[name(colIdx)], colIdx, rowIdx))
				{
					return false;
				}
			}
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchArrays(utils::Variant::VectorVariant &v, size_t rowBeginIdx, size_t rowEndIdx)
	{
		size_t columns = this->columns();
		if(rowEndIdx > columns) 
		{
			rowEndIdx = columns;
		}

		if(rowBeginIdx>=rowEndIdx)
		{
			v.clear();
			return true;
		}

		v.resize(rowEndIdx - rowBeginIdx);
		for(size_t rowIdx(rowBeginIdx); rowIdx<rowEndIdx; rowIdx++)
		{
			utils::Variant &rv = v[rowIdx];
			rv.forceType(utils::Variant::etVectorVariant);
			if(!fetchArray(rv.as<utils::Variant::VectorVariant>(), rowIdx))
			{
				return false;
			}
		}
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchMaps(utils::Variant::VectorVariant &v, size_t rowBeginIdx, size_t rowEndIdx)
	{
		size_t columns = this->columns();
		if(rowEndIdx > columns) 
		{
			rowEndIdx = columns;
		}

		if(rowBeginIdx>=rowEndIdx)
		{
			v.clear();
			return true;
		}

		v.resize(rowEndIdx - rowBeginIdx);
		for(size_t rowIdx(rowBeginIdx); rowIdx<rowEndIdx; rowIdx++)
		{
			utils::Variant &rv = v[rowIdx];
			rv.forceType(utils::Variant::etMapStringVariant);
			if(!fetchMap(rv.as<utils::Variant::MapStringVariant>(), rowIdx))
			{
				return false;
			}
		}
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
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

	//////////////////////////////////////////////////////////////////////////
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

	//////////////////////////////////////////////////////////////////////////
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

	//////////////////////////////////////////////////////////////////////////
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

	//////////////////////////////////////////////////////////////////////////
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

	//////////////////////////////////////////////////////////////////////////
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

	//////////////////////////////////////////////////////////////////////////
	bool Result::isNull(int colIdx, size_t rowIdx)
	{
		return _impl->isNull(colIdx, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::isNull(const char *colName, size_t rowIdx)
	{
		return _impl->isNull(colName, rowIdx);
	}



}