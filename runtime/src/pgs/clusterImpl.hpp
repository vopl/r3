#ifndef _PGS_CLUSTER_IMPL_HPP_
#define _PGS_CLUSTER_IMPL_HPP_

#include "pgs/meta/cluster.hpp"
#include "pgs/cluster.hpp"
//#include "pgc/connection.hpp"

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/cstdint.hpp>

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class ClusterImpl
		: public boost::enable_shared_from_this<ClusterImpl>
	{
		//���� ������ ����� ����������
		pgs::meta::Cluster _metaCluster;

		//���������
		std::string _prefix;
		std::string _suffix;

		typedef boost::uint32_t TOid;

		//������������ ���� � ���� ����
		//schema oid -> schema
		typedef std::map<TOid, pgs::meta::SchemaCPtr> TMOid2Schema;
		TMOid2Schema _oid2schema;

		//schema -> schema oid
		typedef std::map<pgs::meta::SchemaCPtr, TOid> TMSchema2Oid;
		TMSchema2Oid _schema2oid;

		//������������ ���� � ������ ����
		//table oid -> category
		typedef std::map<TOid, pgs::meta::CategoryCPtr> TMOid2Cat;
		TMOid2Cat _oid2cat;

		//category -> table oid
		typedef std::map<pgs::meta::CategoryCPtr, TOid> TMCat2Oid;
		TMCat2Oid _cat2oid;


		//������� ��������������������
		bool _isSynced;

		//���������� � ����� 
		pgc::Connection _con;

	public:
		std::string escapeName	(const std::string &name, bool escape=true);

		std::string schemaName	(pgs::meta::SchemaCPtr s,		bool escape=true,	bool full=true);
		std::string idGenName	(pgs::meta::SchemaCPtr s,		bool escape=true,	bool full=true);
		std::string tableName	(pgs::meta::CategoryCPtr c,		bool escape=true,	bool full=true);
		std::string tableName	(pgs::meta::RelationCPtr r,		bool escape=true,	bool full=true);
		std::string columnName	(pgs::meta::FieldCPtr f,		bool escape=true,	bool full=true);
		std::string indexName	(pgs::meta::IndexCPtr i,		bool escape=true,	bool full=true);

		std::string columnType	(pgs::meta::FieldCPtr f);

		std::string triggerFuncName	(pgs::meta::CategoryCPtr c, const std::string &suffix);
		std::string triggerFuncName	(pgs::meta::RelationCPtr r, const std::string &suffix);

		std::string triggerName	(pgs::meta::CategoryCPtr c, const std::string &suffix);
		std::string triggerName	(pgs::meta::RelationCPtr r, const std::string &suffix);

	private:
		bool sync_schemaExistence(pgc::Connection con, pgs::meta::SchemaCPtr s, bool allowCreate);
		bool sync_tableExistence(pgc::Connection con, pgs::meta::CategoryCPtr c, bool allowCreate);
		bool sync_columnExistence(pgc::Connection con, pgs::meta::FieldCPtr f, bool allowCreate);
		bool sync_indexExistence(pgc::Connection con, pgs::meta::IndexCPtr i, bool allowCreate);
		bool sync_crossExistence(pgc::Connection con, pgs::meta::RelationCPtr r, bool allowCreate);
		bool sync_tableInherits(pgc::Connection con, pgs::meta::CategoryCPtr c, bool allowCreate);

		bool createTable2CrossTrigger(pgc::Connection con, pgs::meta::RelationEndCPtr re, const std::string &who);

	private:
		bool drop_schemaExistence(pgc::Connection con, pgs::meta::SchemaCPtr s);

	public:
		ClusterImpl(pgs::meta::Cluster metaCluster);

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
	typedef boost::shared_ptr<ClusterImpl> ClusterImplPtr;
}
#endif
