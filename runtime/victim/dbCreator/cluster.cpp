#include "stdafx.h"
#include "dbCreator/cluster.hpp"

namespace dbCreator
{
	//////////////////////////////////////////////////////////////////////////
	std::string Cluster::escapeName(const std::string &name, bool escape)
	{
		if(escape)
		{
			return "\"" + name + "\"";
		}

		return name;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string Cluster::schemaName(dbMeta::SchemaCPtr s, bool escape, bool full)
	{
		std::string n = escapeName(_prefix + "_" + s->_name + "_" + _suffix, escape);
		if(full)
		{
			return n;
		}
		return n;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string Cluster::idGenName(dbMeta::SchemaCPtr s, bool escape, bool full)
	{
		std::string n = escapeName("idGen", escape);
		if(full)
		{
			return schemaName(s, escape, full)+"."+n;
		}
		return n;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string Cluster::tableName(dbMeta::CategoryCPtr c, bool escape, bool full)
	{
		std::string n = escapeName(c->_name, escape);
		if(full)
		{
			return schemaName(c->_schema, escape, full)+"."+n;
		}
		return n;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string Cluster::tableName(dbMeta::RelationCPtr r, bool escape, bool full)
	{
		std::string n = escapeName(r->_name, escape);
		if(full)
		{
			return schemaName(r->_schema, escape, full)+"."+n;
		}
		return n;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string Cluster::columnName(dbMeta::FieldCPtr f, bool escape, bool full)
	{
		std::string n = escapeName(f->_name, escape);
		if(full)
		{
			return tableName(f->_category, escape, full)+"."+n;
		}
		return n;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string Cluster::columnName(dbMeta::RelationEndCPtr re, bool escape, bool full)
	{
		std::string n = escapeName(re->_name, escape);
		if(full)
		{
			return tableName(re->_category, escape, full)+"."+n;
		}
		return n;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string Cluster::columnType(dbMeta::FieldCPtr f)
	{
		switch(f->_type)
		{
		case dbMeta::eftAudio:
			return "OID";
		case dbMeta::eftBinary:
			return "BYTEA";
		case dbMeta::eftBool:
			return "BOOLEAN";
		case dbMeta::eftDate:
			return "DATE";
		case dbMeta::eftDateTimeInterval:
			return "INTERVAL";
		case dbMeta::eftEnum:
			return "BYTEA";
		case dbMeta::eftFile:
			return "OID";
		case dbMeta::eftImage:
			return "OID";
		case dbMeta::eftInt16:
			return "SMALLINT";
		case dbMeta::eftInt32:
			return "INTEGER";
		case dbMeta::eftInt64:
			return "BIGINT";
		case dbMeta::eftInt8:
			return "SMALLINT";
		case dbMeta::eftMoney:
			return "MONEY";
		case dbMeta::eftReal32:
			return "REAL";
		case dbMeta::eftReal64:
			return "DOUBLE PRECISION";
		case dbMeta::eftSet:
			return "BYTEA";
		case dbMeta::eftString:
			return "VARCHAR";
		case dbMeta::eftTime:
			return "TIME WITH TIME ZONE";
		case dbMeta::eftTimestamp:
			return "TIMESTAMP WITH TIME ZONE";
		case dbMeta::eftVideo:
			return "OID";
		default:
			assert(!"unknown field type");
			throw "unknown field type";
		}
		return "";
	}

	
	//////////////////////////////////////////////////////////////////////////
	bool Cluster::sync_schemaExistence(TSyncLog &log, dbMeta::SchemaCPtr s, bool allowCreate)
	{
		pgc::Result pgr = _con
			.once("SELECT COUNT(*) FROM information_schema.schemata WHERE schema_name=$1")
			.exec(schemaName(s, false, false))
			.throwIfError();

		if(!pgr.fetchInt32(0,0))
		{
			log.push_back(SyncLogLine("schema absent", schemaName(s, false, false)));

			if(allowCreate)
			{
				_con.once("CREATE SCHEMA "+schemaName(s, true, true)).exec().throwIfError();
				log.push_back(SyncLogLine("schema created", schemaName(s, false, false)));
			}
			else
			{
				//без схемы куда?
				return false;
			}
		}

		//oid
		pgr = _con
			.once("SELECT oid FROM pg_catalog.pg_namespace WHERE nspname=$1")
			.exec(schemaName(s, false, false))
			.throwIfError();
		if(pgr.rows() != 1)
		{
			log.push_back(SyncLogLine("obtain schema oid failed", schemaName(s, false, false)));
			return false;
		}
		TOid oid = pgr.fetchUInt32(0, 0);
		_schema2oid[s] = oid;
		_oid2schema[oid] = s;

		//генератор идентификаторов объектов
		pgr = _con.once("SELECT COUNT(*) FROM information_schema.sequences WHERE sequence_schema=$1 AND sequence_name=$2").exec(schemaName(s, false, false), idGenName(s, false, false)).throwIfError();
		if(!pgr.fetchInt32(0, 0))
		{
			log.push_back(SyncLogLine("idGen absent", schemaName(s, false, false), idGenName(s, false, false)));

			if(allowCreate)
			{
				_con.once("CREATE SEQUENCE "+idGenName(s, true, true)).exec().throwIfError();
				log.push_back(SyncLogLine("idGen created", schemaName(s, false, false), idGenName(s, false, false)));
			}
			else
			{
				return false;
			}
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Cluster::sync_tableExistence(TSyncLog &log, dbMeta::CategoryCPtr c, bool allowCreate)
	{
		pgc::Result pgr = _con.once("SELECT * FROM information_schema.tables WHERE table_schema=$1 AND table_name=$2").exec(schemaName(c->_schema, false, false), tableName(c, false, false)).throwIfError();
		if(!pgr.rows())
		{
			log.push_back(SyncLogLine("table absent", schemaName(c->_schema, false, false), tableName(c, false, false)));
			if(allowCreate)
			{
				_con.once("CREATE TABLE "+tableName(c, true, true)+"(id BIGINT DEFAULT nextval('"+idGenName(c->_schema, true, true)+"'::regclass) PRIMARY KEY )").exec().throwIfError();
				log.push_back(SyncLogLine("table created", schemaName(c->_schema, false, false), tableName(c, false, false)));
			}
			else
			{
				return false;
			}
		}

		//oid
		pgr = _con
			.once("SELECT oid FROM pg_catalog.pg_class WHERE relname=$1 AND relnamespace=$2")
			.exec(tableName(c, false, false), _schema2oid[c->_schema])
			.throwIfError();
		if(pgr.rows() != 1)
		{
			log.push_back(SyncLogLine("obtain table oid failed", schemaName(c->_schema, false, false), tableName(c, false, false)));
			return false;
		}
		TOid oid = pgr.fetchUInt32(0, 0);
		_cat2oid[c] = oid;
		_oid2cat[oid] = c;

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Cluster::sync_columnExistence(TSyncLog &log, dbMeta::FieldCPtr f, bool allowCreate)
	{
		pgc::Result pgr = _con.once("SELECT * FROM information_schema.columns WHERE table_schema=$1 AND table_name=$2 AND column_name=$3").exec(schemaName(f->_category->_schema, false, false), tableName(f->_category, false, false), columnName(f, false, false)).throwIfError();
		if(!pgr.rows())
		{
			log.push_back(SyncLogLine("column absent", schemaName(f->_category->_schema, false, false), tableName(f->_category, false, false), columnName(f, false, false)));
			if(allowCreate)
			{
				_con.once("ALTER TABLE "+tableName(f->_category, true, true)+" ADD COLUMN "+columnName(f, true, false)+" "+columnType(f)).exec().throwIfError();
				log.push_back(SyncLogLine("column created", schemaName(f->_category->_schema, false, false), tableName(f->_category, false, false), columnName(f, false, false)));
			}
			else
			{
				return false;
			}
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Cluster::sync_columnExistence(TSyncLog &log, dbMeta::RelationEndCPtr re, bool allowCreate)
	{
		dbMeta::RelationEndCPtr are = re->_anotherEnd;

		bool makeFk = false;

		if(re->_mult == dbMeta::ermOne)
		{
			if(are->_mult == dbMeta::ermOne)
			{
				//one -> one
				//fk
				if(re->_isInput)
				{
					//делать внешний ключ на категорию другого края
					makeFk = true;
				}
				else
				{
					//ничего не делать, будет сделано с другого края
				}
			}
			else
			{
				//one -> many
				//alien fk
				//ничего не делать, будет сделано с другого края
			}
		}
		else
		{
			if(are->_mult == dbMeta::ermOne)
			{
				//many -> one
				//own fk
				{
					//делать внешний ключ на категорию другого края
					makeFk = true;
				}
			}
			else
			{
				//many -> many
				//cross

				//own fk
				//alien fk
				//делать кросс между этой категорией и категорией другого края
				makeFk = true;
			}
		}

		if(makeFk)
		{
			pgc::Result pgr = _con.once("SELECT * FROM information_schema.columns WHERE table_schema=$1 AND table_name=$2 AND column_name=$3").exec(schemaName(re->_category->_schema, false, false), tableName(re->_category, false, false), columnName(re, false, false)).throwIfError();
			if(!pgr.rows())
			{
				log.push_back(SyncLogLine("re column absent", schemaName(re->_category->_schema, false, false), tableName(re->_category, false, false), columnName(re, false, false)));
				if(allowCreate)
				{
					_con.once("ALTER TABLE "+tableName(re->_category, true, true)+" ADD COLUMN "+columnName(re, true, false)+" BIGINT").exec().throwIfError();
					log.push_back(SyncLogLine("re column created", schemaName(re->_category->_schema, false, false), tableName(re->_category, false, false), columnName(re, false, false)));
				}
				else
				{
					return false;
				}
			}
		}

		return true;
	}


	//////////////////////////////////////////////////////////////////////////
	bool Cluster::sync_tableInherits(TSyncLog &log, dbMeta::CategoryCPtr c, bool allowCreate)
	{
		pgc::Result pgr = _con
			.once("SELECT inhparent FROM pg_catalog.pg_inherits WHERE inhrelid=$1")
			.exec(_cat2oid[c])
			.throwIfError();

		std::set<TOid> baseOids;
		for(int i(0); i<pgr.rows(); i++)
		{
			baseOids.insert(pgr.fetchUInt32(i, 0));
		}


		BOOST_FOREACH(dbMeta::CategoryCPtr b, c->_bases)
		{
			if(baseOids.end() == baseOids.find(_cat2oid[b]))
			{
				log.push_back(SyncLogLine("inheritance absent", schemaName(c->_schema, false, false), tableName(c, false, false), tableName(b, false, false)));
				if(allowCreate)
				{
					_con.once("ALTER TABLE "+tableName(c, true, true)+" INHERIT "+tableName(b, true, true)).exec().throwIfError();
					baseOids.insert(_cat2oid[b]);
					log.push_back(SyncLogLine("inheritance created", schemaName(c->_schema, false, false), tableName(c, false, false), tableName(b, false, false)));
				}
				else
				{
					return false;
				}
			}
		}
		return true;
	}



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

		_oid2schema.clear();
		_schema2oid.clear();
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

		_oid2schema.clear();
		_schema2oid.clear();
		_oid2cat.clear();
		_cat2oid.clear();

		if(!_metaCluster->isInitialized())
		{
			log.push_back(SyncLogLine("meta cluster is not initialized"));
			return false;
		}

		bool res = true;

		//наличие схем
		BOOST_FOREACH(dbMeta::SchemaCPtr s, _metaCluster->getSchemas())
		{
			res &= sync_schemaExistence(log, s, allowCreate);
		}
		if(!res)
		{
			return res;
		}

		//наличие таблиц
		BOOST_FOREACH(dbMeta::SchemaCPtr s, _metaCluster->getSchemas())
		{
			BOOST_FOREACH(dbMeta::CategoryCPtr c, s->_categories)
			{
				res &= sync_tableExistence(log, c, allowCreate);
			}
		}
		if(!res)
		{
			return res;
		}

		//наличие полей
		BOOST_FOREACH(dbMeta::SchemaCPtr s, _metaCluster->getSchemas())
		{
			BOOST_FOREACH(dbMeta::CategoryCPtr c, s->_categories)
			{
				BOOST_FOREACH(dbMeta::FieldCPtr f, c->_fields)
				{
					res &= sync_columnExistence(log, f, allowCreate);
				}
				BOOST_FOREACH(dbMeta::RelationEndCPtr re, c->_relationEnds)
				{
					res &= sync_columnExistence(log, re, allowCreate);
				}
			}
		}
		if(!res)
		{
			return res;
		}

		//наследование
		BOOST_FOREACH(dbMeta::SchemaCPtr s, _metaCluster->getSchemas())
		{
			BOOST_FOREACH(dbMeta::CategoryCPtr c, s->_categories)
			{
				res &= sync_tableInherits(log, c, allowCreate);
			}
		}
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Cluster::drop(TSyncLog &log)
	{
		assert(0);
		return false;
	}

}
