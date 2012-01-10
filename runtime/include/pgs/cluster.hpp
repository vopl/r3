#ifndef _PGS_CLUSTER_HPP_
#define _PGS_CLUSTER_HPP_

#include "pgs/meta/cluster.hpp"
#include "pgc/connection.hpp"

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/cstdint.hpp>

#include <deque>

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class ClusterImpl;
	typedef boost::shared_ptr<ClusterImpl> ClusterImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class PG_API Cluster
	{
	protected:
		typedef ClusterImplPtr ImplPtr;
		ImplPtr	_impl;

	public:
		Cluster(pgs::meta::Cluster metaCluster);

		void setUnicators(const std::string &prefix, const std::string &suffix);
		pgc::Connection con(pgc::Connection con);
		pgc::Connection con();

		bool sync(pgc::Connection con, bool allowCreate = false);
		bool drop(pgc::Connection con);

		// 	select
		// 	insert
		// 	update
		// 	delete
	};
}
#endif
