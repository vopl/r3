#include "pch.hpp"
#include "statementImpl.hpp"
#include "utils/implAccess.hpp"

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
	StatementImpl::StatementImpl(	const std::string &sql,
									pgs::ClusterImplPtr cluster, 
									const TMName2idx &bindName2idx)
 		: pgc::StatementImpl(sql)
		, _bindName2idx(bindName2idx)
 		, _cluster(cluster)
	{
		//assert(0);
	}

// 	//////////////////////////////////////////////////////////////////////////
// 	bool StatementImpl::bind(int typCpp, void const *valCpp, const char *name)
// 	{
// 		return pgc::StatementPrepImpl::bind(typCpp, valCpp, bindName2idx(name));
// 	}
// 
// 	//////////////////////////////////////////////////////////////////////////
// 	void StatementImpl::unbind(const char *name)
// 	{
// 		pgc::StatementPrepImpl::unbind(bindName2idx(name));
// 	}
}
