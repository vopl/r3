#include "stdafx.h"
#include "pgs/result.hpp"
#include "resultImpl.hpp"
#include "implAccess.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	bool Result::fldIndex(size_t &res, const Field &fld)
	{
		return boost::static_pointer_cast<ResultImpl>(_impl)->fldIndex(res, ImplAccess<Field>(fld).impl());
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fldIndices(std::deque<size_t> &res, const pgs::Category &cat)
	{
		return boost::static_pointer_cast<ResultImpl>(_impl)->fldIndices(res, ImplAccess<Category>(cat).impl());
	}

	//////////////////////////////////////////////////////////////////////////
	Result::Result(Impl_ptr impl)
		: pgc::Result(impl)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowMap(utils::Variant::MapStringVariant &v, const pgs::Category &cat, size_t rowIdx)
	{
		std::deque<size_t> indices;
		if(!fldIndices(indices, cat))
		{
			throw std::invalid_argument("for Result::fetchRowMap");
			return false;
		}

		return fetchRowMap(v, indices, rowIdx);
	}

	bool Result::fetch(utils::Variant &v, const pgs::Field &fld, size_t rowIdx)
	{
		size_t index;
		if(!fldIndex(index, fld))
		{
			throw std::invalid_argument("for Result::fetch");
			return false;
		}

		return fetch(v, index, rowIdx);
	}

}