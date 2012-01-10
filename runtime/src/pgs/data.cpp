#include "pch.h"
#include "pgs/data.hpp"
#include "dataImpl.hpp"
#include "utils/implAccess.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	bool Data::fldIndex(size_t &res, const Field &fld)
	{
		return boost::static_pointer_cast<DataImpl>(_impl)->fldIndex(res, utils::ImplAccess<Field>(fld).impl());
	}

	//////////////////////////////////////////////////////////////////////////
	bool Data::fldIndices(std::deque<size_t> &res, const pgs::Category &cat)
	{
		return boost::static_pointer_cast<DataImpl>(_impl)->fldIndices(res, utils::ImplAccess<Category>(cat).impl());
	}

	//////////////////////////////////////////////////////////////////////////
	Data::Data(ImplPtr impl)
	//	: pgc::Data(impl)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Data::fetchRowList(utils::Variant &v, const pgs::Category &cat, size_t rowIdx)
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
	bool Data::fetchRowMap(utils::Variant &v, const pgs::Category &cat, size_t rowIdx)
	{
		std::deque<size_t> indices;
		if(!fldIndices(indices, cat))
		{
			throw std::invalid_argument("for Data::fetchRowMap");
			return false;
		}

		return fetchRowMap(v, indices, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Data::fetchRowsList(utils::Variant &v, const pgs::Category &cat, size_t rowBeginIdx, size_t rowEndIdx)
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
	bool Data::fetchRowsMap(utils::Variant &v, const pgs::Category &cat, size_t rowBeginIdx, size_t rowEndIdx)
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
	bool Data::fetch(utils::Variant &v, const pgs::Field &fld, size_t rowIdx)
	{
		size_t index;
		if(!fldIndex(index, fld))
		{
			throw std::invalid_argument("for Data::fetch");
			return false;
		}

		return fetch(v, index, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Data::fetchColumn(utils::Variant &v, const pgs::Field &fld, size_t rowBeginIdx, size_t rowEndIdx)
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