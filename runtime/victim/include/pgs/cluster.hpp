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
	class Cluster
		: public boost::enable_shared_from_this<Cluster>
	{
		//мета данные этого экземпл€ра
		boost::shared_ptr<pgs::meta::Cluster> _metaCluster;

		//уникаторы
		std::string _prefix;
		std::string _suffix;

		typedef boost::uint32_t TOid;

		//соответстви€ мета и схем базы
		//schema oid -> schema
		typedef std::map<TOid, pgs::meta::SchemaCPtr> TMOid2Schema;
		TMOid2Schema _oid2schema;

		//schema -> schema oid
		typedef std::map<pgs::meta::SchemaCPtr, TOid> TMSchema2Oid;
		TMSchema2Oid _schema2oid;

		//соответстви€ мета и таблиц базы
		//table oid -> category
		typedef std::map<TOid, pgs::meta::CategoryCPtr> TMOid2Cat;
		TMOid2Cat _oid2cat;

		//category -> table oid
		typedef std::map<pgs::meta::CategoryCPtr, TOid> TMCat2Oid;
		TMCat2Oid _cat2oid;


		//признак инициализированности
		bool _isSynced;

		//соединение с базой 
		pgc::Connection _con;

	private:
		std::string escapeName	(const std::string &name, bool escape);

		std::string schemaName	(pgs::meta::SchemaCPtr s,			bool escape,	bool full);
		std::string idGenName	(pgs::meta::SchemaCPtr s,			bool escape,	bool full);
		std::string tableName	(pgs::meta::CategoryCPtr c,		bool escape,	bool full);
		std::string tableName	(pgs::meta::RelationCPtr r,		bool escape,	bool full);
		std::string columnName	(pgs::meta::FieldCPtr f,			bool escape,	bool full);
		std::string indexName	(pgs::meta::IndexCPtr i,			bool escape,	bool full);

		std::string columnType	(pgs::meta::FieldCPtr f);

		std::string triggerFuncName	(pgs::meta::CategoryCPtr c, const std::string &suffix);
		std::string triggerFuncName	(pgs::meta::RelationCPtr r, const std::string &suffix);

		std::string triggerName	(pgs::meta::CategoryCPtr c, const std::string &suffix);
		std::string triggerName	(pgs::meta::RelationCPtr r, const std::string &suffix);

	private:
		bool sync_schemaExistence(TSyncLog &log, pgs::meta::SchemaCPtr s, bool allowCreate);
		bool sync_tableExistence(TSyncLog &log, pgs::meta::CategoryCPtr c, bool allowCreate);
		bool sync_columnExistence(TSyncLog &log, pgs::meta::FieldCPtr f, bool allowCreate);
		bool sync_indexExistence(TSyncLog &log, pgs::meta::IndexCPtr i, bool allowCreate);
		bool sync_crossExistence(TSyncLog &log, pgs::meta::RelationCPtr r, bool allowCreate);
		bool sync_tableInherits(TSyncLog &log, pgs::meta::CategoryCPtr c, bool allowCreate);

		bool createTable2CrossTrigger(TSyncLog &log, pgs::meta::RelationEndCPtr re, const std::string &who);

	private:
		bool drop_schemaExistence(TSyncLog &log, pgs::meta::SchemaCPtr s);

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
