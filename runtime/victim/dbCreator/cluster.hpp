#ifndef _DBCREATOR_CLUSTER_HPP_
#define _DBCREATOR_CLUSTER_HPP_

#include "dbMeta/cluster.hpp"
#include "pgc/connection.hpp"

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/cstdint.hpp>

namespace dbCreator
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
	class Cluster
		: public boost::enable_shared_from_this<Cluster>
	{
		//мета данные этого экземпл€ра
		boost::shared_ptr<dbMeta::Cluster> _metaCluster;

		//уникаторы
		std::string _prefix;
		std::string _suffix;

		//соответстви€ мета и таблиц базы
		typedef boost::uint32_t TOid;
		//table oid -> category
		typedef std::map<TOid, dbMeta::CategoryCPtr> TMOid2Cat;
		TMOid2Cat _oid2cat;

		//category -> table oid
		typedef std::map<dbMeta::CategoryCPtr, TOid> TMCat2Oid;
		TMCat2Oid _cat2oid;

		//признак инициализированности
		bool _isSynced;

		//соединение с базой 
		pgc::Connection _con;

	public:
		Cluster(boost::shared_ptr<dbMeta::Cluster> metaCluster);
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
