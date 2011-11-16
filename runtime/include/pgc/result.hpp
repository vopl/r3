#ifndef _PGC_RESULT_HPP_
#define _PGC_RESULT_HPP_

#include "pgc/common.h"
#include "pgc/cppDataType.hpp"

namespace pgc
{
	class ResultImpl;
	typedef boost::shared_ptr<ResultImpl> ResultImplPtr;

	enum EExecStatus
	{
		ees_commandOk,
		ees_tuplesOk,
		ees_error,
	};

	//////////////////////////////////////////////////////////////////////////
	class Result
	{
	protected:
		ResultImplPtr _impl;

	protected:
		friend class Statement;
		Result(ResultImplPtr impl);

	public:
		bool fetchNative(int typCpp, void *valCpp, size_t colIdx, size_t rowIdx);
		bool fetchNative(int typCpp, void *valCpp, const char *colName, size_t rowIdx);

	public:
		~Result();

		EExecStatus status();
		const char *errorMsg();
		const char *errorCode();
		Result &throwIfError();

		int bestType(size_t colIdx) const;
		int bestType(const char *colName) const;
		const char *name(size_t colIdx) const;

		size_t cmdRows();
		size_t rows();
		size_t columns();

		template <class T> bool fetch(T &v, int colIdx=0, size_t rowIdx=0);
		template <class T> bool fetch(T &v, const char *colName, size_t rowIdx=0);

		bool fetch(utils::Variant &v, int colIdx=0, size_t rowIdx=0);
		bool fetch(utils::Variant &v, const char *colName, size_t rowIdx=0);

		
		//////////////////////////////////////////////////////////////////////////
		template <class SequenceVariant>
		bool fetchRowList(SequenceVariant &v, size_t rowIdx=0);

		bool fetchRowMap(utils::Variant::MapStringVariant &v, size_t rowIdx=0);

		template <class SequenceVariant>
		bool fetchRowsList(SequenceVariant &v, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		template <class SequenceVariant>
		bool fetchRowsMap(SequenceVariant &v, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		//////////////////////////////////////////////////////////////////////////
		template <class SequenceVariant>
		bool fetchRowList(SequenceVariant &v, const std::deque<size_t> &colIndices, size_t rowIdx=0);

		bool fetchRowMap(utils::Variant::MapStringVariant &v, const std::deque<size_t> &colIndices, size_t rowIdx=0);

		template <class SequenceVariant>
		bool fetchRowsList(SequenceVariant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		template <class SequenceVariant>
		bool fetchRowsMap(SequenceVariant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		template <class SequenceVariant>
		bool fetchColumn(SequenceVariant &v, size_t colIdx, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);


		//////////////////////////////////////////////////////////////////////////
		boost::int32_t fetchInt32(int colIdx=0, size_t rowIdx=0);
		boost::int32_t fetchInt32(const char *colName, size_t rowIdx=0);

		boost::uint32_t fetchUInt32(int colIdx=0, size_t rowIdx=0);
		boost::uint32_t fetchUInt32(const char *colName, size_t rowIdx=0);

		std::string fetchString(int colIdx=0, size_t rowIdx=0);
		std::string fetchString(const char *colName, size_t rowIdx=0);

		bool isNull(int colIdx=0, size_t rowIdx=0);
		bool isNull(const char *colName, size_t rowIdx);
	};
	typedef boost::shared_ptr<Result> ResultPtr;

	//////////////////////////////////////////////////////////////////////////
	template <class T> bool Result::fetch(T &v, int colIdx, size_t rowIdx)
	{
		return fetchNative(CppDataType<T>::cdt_index, &v, colIdx, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class T> bool Result::fetch(T &v, const char *colName, size_t rowIdx)
	{
		return fetchNative(CppDataType<T>::cdt_index, &v, colName, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchRowList(SequenceVariant &v, size_t rowIdx)
	{
		size_t columns = this->columns();
		v.resize(columns);

		SequenceVariant::iterator iter = v.begin();
		for(size_t colIdx(0); colIdx<columns; colIdx++)
		{
			utils::Variant &rv = *iter;
			if(isNull(colIdx, rowIdx))
			{
				rv.clear();
			}
			else
			{
				if(!fetch(rv, colIdx, rowIdx))
				{
					return false;
				}
			}
			iter++;
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchRowsList(SequenceVariant &v, size_t rowBeginIdx, size_t rowEndIdx)
	{
		size_t rows = this->rows();
		if(rowEndIdx > rows) 
		{
			rowEndIdx = rows;
		}

		if(rowBeginIdx>=rowEndIdx)
		{
			v.clear();
			return true;
		}

		v.resize(rowEndIdx - rowBeginIdx);
		SequenceVariant::iterator iter = v.begin();
		for(size_t rowIdx(rowBeginIdx); rowIdx<rowEndIdx; rowIdx++)
		{
			utils::Variant &rv = *iter;
			if(!fetchRowList(rv.as<SequenceVariant>(true), rowIdx))
			{
				return false;
			}
			iter++;
		}
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchRowsMap(SequenceVariant &v, size_t rowBeginIdx, size_t rowEndIdx)
	{
		size_t rows = this->rows();
		if(rowEndIdx > rows)
		{
			rowEndIdx = rows;
		}

		if(rowBeginIdx>=rowEndIdx)
		{
			v.clear();
			return true;
		}

		v.resize(rowEndIdx - rowBeginIdx);
		SequenceVariant::const_iterator iter = v.begin();
		for(size_t rowIdx(rowBeginIdx); rowIdx<rowEndIdx; rowIdx++)
		{
			utils::Variant &rv = v[rowIdx];
			if(!fetchRowMap(rv.as<utils::Variant::MapStringVariant>(true), rowIdx))
			{
				return false;
			}
			iter++;
		}
		return true;
	}












	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchRowList(SequenceVariant &v, const std::deque<size_t> &colIndices, size_t rowIdx)
	{
		size_t columns = colIndices.size();
		v.resize(columns);

		SequenceVariant::iterator iter = v.begin();
		for(size_t colIdx(0); colIdx<columns; colIdx++)
		{
			assert(colIndices[colIdx] < Result::columns());
			utils::Variant &rv = *iter;
			if(isNull(colIndices[colIdx], rowIdx))
			{
				rv.clear();
			}
			else
			{
				if(!fetch(rv, colIndices[colIdx], rowIdx))
				{
					return false;
				}
			}
			iter++;
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchRowsList(SequenceVariant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx, size_t rowEndIdx)
	{
		size_t rows = this->rows();
		if(rowEndIdx > rows) 
		{
			rowEndIdx = rows;
		}

		if(rowBeginIdx>=rowEndIdx)
		{
			v.clear();
			return true;
		}

		v.resize(rowEndIdx - rowBeginIdx);
		SequenceVariant::iterator iter = v.begin();
		for(size_t rowIdx(rowBeginIdx); rowIdx<rowEndIdx; rowIdx++)
		{
			utils::Variant &rv = *iter;
			if(!fetchRowList(rv.as<SequenceVariant>(true), colIndices, rowIdx))
			{
				return false;
			}
			iter++;
		}
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchRowsMap(SequenceVariant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx, size_t rowEndIdx)
	{
		size_t rows = this->rows();
		if(rowEndIdx > rows)
		{
			rowEndIdx = rows;
		}

		if(rowBeginIdx>=rowEndIdx)
		{
			v.clear();
			return true;
		}

		v.resize(rowEndIdx - rowBeginIdx);
		SequenceVariant::const_iterator iter = v.begin();
		for(size_t rowIdx(rowBeginIdx); rowIdx<rowEndIdx; rowIdx++)
		{
			utils::Variant &rv = v[rowIdx];
			if(!fetchRowMap(rv.as<utils::Variant::MapStringVariant>(true), colIndices, rowIdx))
			{
				return false;
			}
			iter++;
		}
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchColumn(SequenceVariant &v, size_t colIdx, size_t rowBeginIdx, size_t rowEndIdx)
	{
		size_t rows = this->rows();
		if(rowEndIdx > rows)
		{
			rowEndIdx = rows;
		}

		if(rowBeginIdx>=rowEndIdx)
		{
			v.clear();
			return true;
		}

		v.resize(rowEndIdx - rowBeginIdx);
		SequenceVariant::const_iterator iter = v.begin();
		for(size_t rowIdx(rowBeginIdx); rowIdx<rowEndIdx; rowIdx++)
		{
			utils::Variant &rv = v[rowIdx];
			if(!fetch(rv, colIdx, rowIdx))
			{
				return false;
			}
			iter++;
		}
		return true;
	}

}
#endif
