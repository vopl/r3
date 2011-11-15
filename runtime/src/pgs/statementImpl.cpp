#include "stdafx.h"
#include "statementImpl.hpp"
#include "implAccess.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	size_t StatementImpl::bindName2idx(const char *name)
	{
		TMName2idx::iterator iter = _bindName2idx.find(name);
		if(_bindName2idx.end() == iter)
		{
			assert(!"bad name");
			throw "bad name";
			return (size_t)-1;
		}
		return iter->second;
	}

	//////////////////////////////////////////////////////////////////////////
	bool StatementImpl::fldIndex(size_t &res, const std::string &name)
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
	bool StatementImpl::fldIndex(size_t &res, const FieldImpl_ptr &fld)
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

	//////////////////////////////////////////////////////////////////////////
	bool StatementImpl::fldIndices(std::deque<size_t> &res, const CategoryImpl_ptr &cat)
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

	//////////////////////////////////////////////////////////////////////////
	StatementImpl::StatementImpl(
									pgs::ClusterImpl_ptr cluster, 
									const TMName2idx &bindName2idx,
									const TMName2idx &fetchName2idx)
		: pgc::StatementPrepImpl(ImplAccess<pgc::Connection>(cluster->con()).impl())
		, _bindName2idx(bindName2idx)
		, _fetchName2idx(fetchName2idx)
		, _cluster(cluster)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	bool StatementImpl::bind(int typCpp, void const *valCpp, const char *name)
	{
		return pgc::StatementPrepImpl::bind(typCpp, valCpp, bindName2idx(name));
	}

	//////////////////////////////////////////////////////////////////////////
	void StatementImpl::unbind(const char *name)
	{
		pgc::StatementPrepImpl::unbind(bindName2idx(name));
	}
}