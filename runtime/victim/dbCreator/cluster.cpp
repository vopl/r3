#include "stdafx.h"
#include "dbCreator/cluster.hpp"

namespace dbCreator
{

	//////////////////////////////////////////////////////////////////////////
	Cluster::Cluster(boost::shared_ptr<dbMeta::Cluster> metaCluster)
		: _metaCluster(metaCluster)
		, _prefix()
		, _suffix()
		, _isSynced(false)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void Cluster::setUnicators(const std::string &prefix, const std::string &suffix)
	{
		_isSynced = false;
		_oid2cat.clear();
		_cat2oid.clear();

		_prefix = prefix;
		_suffix = suffix;
	}

	//////////////////////////////////////////////////////////////////////////
	void Cluster::setConnection(pgc::Connection con)
	{
		_con = con;
	}


	//////////////////////////////////////////////////////////////////////////
	bool Cluster::sync(TSyncLog &log, bool allowCreate)
	{
		_isSynced = false;
		_oid2cat.clear();
		_cat2oid.clear();

		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Cluster::drop(TSyncLog &log)
	{
		assert(0);
		return false;
	}

}
