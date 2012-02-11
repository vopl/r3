#include "pch.hpp"
#include "pgs/cluster.hpp"
#include "clusterImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Cluster::Cluster(pgs::meta::Cluster metaCluster)
		: _impl(new ClusterImpl(metaCluster))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void Cluster::setUnicators(const std::string &prefix, const std::string &suffix)
	{
		return _impl->setUnicators(prefix, suffix);
	}

	//////////////////////////////////////////////////////////////////////////
	async::Future<bool> Cluster::sync(pgc::Connection con, bool allowCreate)
	{
		return _impl->sync(con, allowCreate);
	}

	//////////////////////////////////////////////////////////////////////////
	async::Future<bool> Cluster::drop(pgc::Connection con)
	{
		return _impl->drop(con);
	}
}
