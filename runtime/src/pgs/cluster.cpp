#include "stdafx.h"
#include "pgs/cluster.hpp"
#include "impl/cluster.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Cluster::Cluster(pgs::meta::Cluster metaCluster)
		: _impl(new impl::Cluster(metaCluster))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void Cluster::setUnicators(const std::string &prefix, const std::string &suffix)
	{
		return _impl->setUnicators(prefix, suffix);
	}

	//////////////////////////////////////////////////////////////////////////
	pgc::Connection Cluster::con(pgc::Connection con)
	{
		return _impl->con(con);
	}

	//////////////////////////////////////////////////////////////////////////
	pgc::Connection Cluster::con()
	{
		return _impl->con();
	}

	//////////////////////////////////////////////////////////////////////////
	bool Cluster::sync(TSyncLog &log, bool allowCreate)
	{
		return _impl->sync(log, allowCreate);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Cluster::drop(TSyncLog &log)
	{
		return _impl->drop(log);
	}
}
