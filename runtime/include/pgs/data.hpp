#ifndef _PGS_DATA_HPP_
#define _PGS_DATA_HPP_

#include <boost/shared_ptr.hpp>
#include "pgs/category.hpp"
#include "pgs/field.hpp"
#include "pgc/data.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class DataImpl;
	typedef boost::shared_ptr<DataImpl> DataImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class Data
		: public pgc::Data
	{
	protected:
		typedef DataImplPtr ImplPtr;

		friend class Statement;
		Data(ImplPtr impl);

	protected:
		bool fldIndex(size_t &res, const Field &fld);
		bool fldIndices(std::deque<size_t> &res, const Category &cat);

	public:

		using pgc::Data::fetch;
		using pgc::Data::fetchRowList;
		using pgc::Data::fetchRowMap;
		using pgc::Data::fetchRowsList;
		using pgc::Data::fetchRowsMap;
		using pgc::Data::fetchColumn;

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
	bool Data::fetchRowList(SequenceVariant &v, const pgs::Category &cat, size_t rowIdx)
	{
		std::deque<size_t> indices;
		if(!fldIndices(indices, cat))
		{
			throw std::invalid_argument("for Data::fetchRowList");
			return false;
		}

		return fetchRowList(v, indices, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Data::fetchRowsList(SequenceVariant &v, const pgs::Category &cat, size_t rowBeginIdx, size_t rowEndIdx)
	{
		std::deque<size_t> indices;
		if(!fldIndices(indices, cat))
		{
			throw std::invalid_argument("for Data::fetchRowsList");
			return false;
		}

		return fetchRowsList(v, indices, rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Data::fetchRowsMap(SequenceVariant &v, const pgs::Category &cat, size_t rowBeginIdx, size_t rowEndIdx)
	{
		std::deque<size_t> indices;
		if(!fldIndices(indices, cat))
		{
			throw std::invalid_argument("for Data::fetchRowsMap");
			return false;
		}

		return fetchRowsMap(v, indices, rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Data::fetchColumn(SequenceVariant &v, const pgs::Field &fld, size_t rowBeginIdx, size_t rowEndIdx)
	{
		size_t index;
		if(!fldIndex(index, fld))
		{
			throw std::invalid_argument("for Data::fetchColumn");
			return false;
		}

		return fetchColumn(v, index, rowBeginIdx, rowEndIdx);
	}

}
#endif
