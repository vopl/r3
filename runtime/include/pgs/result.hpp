#ifndef _PGS_RESULT_HPP_
#define _PGS_RESULT_HPP_

#include <boost/shared_ptr.hpp>
#include "pgc/connection.hpp"
#include "pgs/category.hpp"
#include "pgs/field.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class ResultImpl;
	typedef boost::shared_ptr<ResultImpl> ResultImpl_ptr;

	//////////////////////////////////////////////////////////////////////////
	class Result
		: public pgc::Result
	{
	protected:
		typedef ResultImpl_ptr Impl_ptr;

		friend class Statement;
		Result(Impl_ptr impl);

	protected:
		bool fldIndex(size_t &res, const Field &fld);
		bool fldIndices(std::deque<size_t> &res, const Category &cat);

	public:

		using pgc::Result::fetch;
		using pgc::Result::fetchRowList;
		using pgc::Result::fetchRowMap;
		using pgc::Result::fetchRowsList;
		using pgc::Result::fetchRowsMap;
		using pgc::Result::fetchColumn;

		template <class SequenceVariant>
		bool fetchRowList(SequenceVariant &v, const pgs::Category &cat, size_t rowIdx=0);

		bool fetchRowMap(utils::Variant::MapStringVariant &v, const pgs::Category &cat, size_t rowIdx=0);

		template <class SequenceVariant>
		bool fetchRowsList(SequenceVariant &v, const pgs::Category &cat, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		template <class SequenceVariant>
		bool fetchRowsMap(SequenceVariant &v, const pgs::Category &cat, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);




		bool fetch(utils::Variant &v, const pgs::Field &fld, size_t rowIdx=0);

		template <class SequenceVariant>
		bool fetchColumn(SequenceVariant &v, const pgs::Field &fld, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);
	};


	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchRowList(SequenceVariant &v, const pgs::Category &cat, size_t rowIdx)
	{
		std::deque<size_t> indices;
		if(!fldIndices(indices, cat))
		{
			throw std::invalid_argument("for Result::fetchRowList");
			return false;
		}

		return fetchRowList(v, indices, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchRowsList(SequenceVariant &v, const pgs::Category &cat, size_t rowBeginIdx, size_t rowEndIdx)
	{
		std::deque<size_t> indices;
		if(!fldIndices(indices, cat))
		{
			throw std::invalid_argument("for Result::fetchRowsList");
			return false;
		}

		return fetchRowsList(v, indices, rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchRowsMap(SequenceVariant &v, const pgs::Category &cat, size_t rowBeginIdx, size_t rowEndIdx)
	{
		std::deque<size_t> indices;
		if(!fldIndices(indices, cat))
		{
			throw std::invalid_argument("for Result::fetchRowsMap");
			return false;
		}

		return fetchRowsMap(v, indices, rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchColumn(SequenceVariant &v, const pgs::Field &fld, size_t rowBeginIdx, size_t rowEndIdx)
	{
		size_t index;
		if(!fldIndex(index, fld))
		{
			throw std::invalid_argument("for Result::fetchColumn");
			return false;
		}

		return fetchColumn(v, index, rowBeginIdx, rowEndIdx);
	}

}
#endif
