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

		typedef boost::uint32_t TOid;

		//соответстви€ мета и схем базы
		//schema oid -> schema
		typedef std::map<TOid, dbMeta::SchemaCPtr> TMOid2Schema;
		TMOid2Schema _oid2schema;

		//schema -> schema oid
		typedef std::map<dbMeta::SchemaCPtr, TOid> TMSchema2Oid;
		TMSchema2Oid _schema2oid;

		//соответстви€ мета и таблиц базы
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

	private:
		std::string escapeName	(const std::string &name, bool escape);

		std::string schemaName	(dbMeta::SchemaCPtr s,			bool escape,	bool full);
		std::string idGenName	(dbMeta::SchemaCPtr s,			bool escape,	bool full);
		std::string tableName	(dbMeta::CategoryCPtr c,		bool escape,	bool full);
		std::string tableName	(dbMeta::RelationCPtr r,		bool escape,	bool full);
		std::string columnName	(dbMeta::FieldCPtr f,			bool escape,	bool full);
		std::string columnName	(dbMeta::RelationEndCPtr re,	bool escape,	bool full);

		std::string columnType	(dbMeta::FieldCPtr f);

		std::string triggerFuncName	(dbMeta::CategoryCPtr c, const std::string &suffix);
		std::string triggerFuncName	(dbMeta::RelationCPtr r, const std::string &suffix);

		std::string triggerName	(dbMeta::CategoryCPtr c, const std::string &suffix);
		std::string triggerName	(dbMeta::RelationCPtr r, const std::string &suffix);

	private:
		bool sync_schemaExistence(TSyncLog &log, dbMeta::SchemaCPtr s, bool allowCreate);
		bool sync_tableExistence(TSyncLog &log, dbMeta::CategoryCPtr c, bool allowCreate);
		bool sync_columnExistence(TSyncLog &log, dbMeta::FieldCPtr f, bool allowCreate);
		bool sync_crossExistence(TSyncLog &log, dbMeta::RelationCPtr r, bool allowCreate);
		bool sync_tableInherits(TSyncLog &log, dbMeta::CategoryCPtr c, bool allowCreate);

		bool createTable2CrossTrigger(TSyncLog &log, dbMeta::RelationEndCPtr re, const std::string &who);

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
