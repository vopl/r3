#ifndef _DBCREATOR_CLUSTER_HPP_
#define _DBCREATOR_CLUSTER_HPP_

#include "pgs/meta/cluster.hpp"
#include "pgc/connection.hpp"

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/cstdint.hpp>

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	struct SyncLogLine
	{
		std::string _msg;
		std::string _data1;
		std::string _data2;
		std::string _data3;

		SyncLogLine(std::string _msg, std::string _data1="", std::string _data2="", std::string _data3="")
			: _msg(_msg)
			, _data1(_data1)
			, _data2(_data2)
			, _data3(_data3)
		{
		}
	};
	typedef std::deque<SyncLogLine> TSyncLog;

	//////////////////////////////////////////////////////////////////////////
	namespace impl
	{
		class Cluster;
		typedef boost::shared_ptr<Cluster> Cluster_ptr;
	}


	//////////////////////////////////////////////////////////////////////////
	class Cluster
	{
		impl::Cluster_ptr	_impl;

	public:
		Cluster(boost::shared_ptr<pgs::meta::Cluster> metaCluster);

		void setUnicators(const std::string &prefix, const std::string &suffix);
		void setConnection(pgc::Connection con);

		bool sync(TSyncLog &log, bool allowCreate = false);
		bool drop(TSyncLog &log);

		// 	select
		// 	insert
		// 	update
		// 	delete
	};
}
#endif
