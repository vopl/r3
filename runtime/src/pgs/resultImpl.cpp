#include "pch.h"
#include "resultImpl.hpp"
#include "statementImpl.hpp"
#include "pgc/connectionHolder.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	ResultImpl::ResultImpl(	PGresult *pgres, 
		bool integerDatetime,
		ClusterImplPtr cluster,
		const TMName2idx &fetchName2idx)
		: pgc::ResultImpl(pgres, integerDatetime)
		, _cluster(cluster)
		, _fetchName2idx(fetchName2idx)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	bool ResultImpl::fldIndex(size_t &res, const std::string &name)
	{
		TMName2idx::iterator iter = _fetchName2idx.find(name);
		if(_fetchName2idx.end() == iter)
		{
			assert(!"bad name");
			throw "bad name";
			return false;
		}
		res = iter->second;
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool ResultImpl::fldIndex(size_t &res, const pgs::FieldImplPtr &fld)
	{
		std::string fldName;

		fldName += _cluster->escapeName(fld->srcAlias());
		fldName += ".";
		fldName += _cluster->escapeName(fld->meta()->_name);

		if(fld->alias().empty() && fld->alias() != fld->meta()->_name)
		{
			fldName += " AS ";
			fldName += _cluster->escapeName(fld->alias());
		}

		return fldIndex(res, fldName);
	}

	bool ResultImpl::fldIndices(std::deque<size_t> &res, const pgs::CategoryImplPtr &cat)
	{
		std::string categoryAlias = _cluster->escapeName(cat->alias());

		//tableoid
		std::string fldName = categoryAlias + ".tableoid";
		size_t idx;
		if(!fldIndex(idx, fldName))
		{
			return false;
		}
		res.push_back(idx);

		//перебрать все поля
		BOOST_FOREACH(meta::FieldCPtr mf, cat->meta()->_fields)
		{
			fldName = categoryAlias + "." + _cluster->escapeName(mf->_name);
			if(!fldIndex(idx, fldName))
			{
				return false;
			}
			res.push_back(idx);
		}

		return true;
	}

}