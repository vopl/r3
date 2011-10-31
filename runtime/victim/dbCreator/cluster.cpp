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

// 	//////////////////////////////////////////////////////////////////////////
// 	std::string Cluster::columnName(dbMeta::RelationEndCPtr re, bool escape, bool full)
// 	{
// 		std::string n = escapeName(re->_name, escape);
// 		if(full)
// 		{
// 			return tableName(re->_category, escape, full)+"."+n;
// 		}
// 		return n;
// 	}

	//////////////////////////////////////////////////////////////////////////
	std::string Cluster::indexName	(dbMeta::IndexCPtr i,			bool escape,	bool full)
	{
		std::string n = escapeName(i->_category->_name+"_"+i->_name, escape);
		if(full)
		{
			return schemaName(i->_category->_schema, escape, full)+"."+n;
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
	std::string Cluster::triggerFuncName	(dbMeta::CategoryCPtr c, const std::string &suffix)
	{
		return schemaName(c->_schema, true, true)+"."+escapeName(c->_name+"_"+suffix, true);
	}
	
	//////////////////////////////////////////////////////////////////////////
	std::string Cluster::triggerFuncName	(dbMeta::RelationCPtr r, const std::string &suffix)
	{
		return schemaName(r->_schema, true, true)+"."+escapeName(r->_name+"_"+suffix, true);
	}

	//////////////////////////////////////////////////////////////////////////
	std::string Cluster::triggerName	(dbMeta::CategoryCPtr c, const std::string &suffix)
	{
		return escapeName(c->_name+"_"+suffix, true);
	}
	
	//////////////////////////////////////////////////////////////////////////
	std::string Cluster::triggerName	(dbMeta::RelationCPtr r, const std::string &suffix)
	{
		return escapeName(r->_name+"_"+suffix, true);
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
	bool Cluster::sync_indexExistence(TSyncLog &log, dbMeta::IndexCPtr i, bool allowCreate)
	{
		if(i->_fields.empty())
		{
			return true;
		}

		pgc::Result pgr = _con.once("SELECT * FROM pg_catalog.pg_indexes WHERE schemaname=$1 AND tablename=$2 AND indexname=$3").exec(schemaName(i->_category->_schema, false, false), tableName(i->_category, false, false), indexName(i, false, false)).throwIfError();
		if(!pgr.rows())
		{
			log.push_back(SyncLogLine("index absent", schemaName(i->_category->_schema, false, false), indexName(i, false, false)));
			if(allowCreate)
			{
				std::string sql = "CREATE INDEX "+indexName(i, true, false)+" ON "+tableName(i->_category, true, true)+" USING ";
				switch(i->_type)
				{
				default:
					assert(!"unknown index type");
				case dbMeta::eitTree:
					sql += "btree";
					break;
				case dbMeta::eitHash:
					sql += "hash";
					break;
				}

				sql += "(";
				bool isFirst = true;
				BOOST_FOREACH(dbMeta::FieldCPtr f, i->_fields)
				{
					if(isFirst)
					{
						isFirst = false;
					}
					else
					{
						sql += ",";
					}
					sql += columnName(f, true, false);
				}
				sql += ")";
				_con.once(sql).exec().throwIfError();
				log.push_back(SyncLogLine("index created", schemaName(i->_category->_schema, false, false), indexName(i, false, false)));
			}
			else
			{
				return false;
			}
		}

		return true;
	}


	//////////////////////////////////////////////////////////////////////////
	bool Cluster::sync_crossExistence(TSyncLog &log, dbMeta::RelationCPtr r, bool allowCreate)
	{
		pgc::Result pgr = _con.once("SELECT * FROM information_schema.tables WHERE table_schema=$1 AND table_name=$2").exec(schemaName(r->_schema, false, false), tableName(r, false, false)).throwIfError();
		if(!pgr.rows())
		{
			log.push_back(SyncLogLine("cross table absent", schemaName(r->_schema, false, false), tableName(r, false, false)));
			if(allowCreate)
			{
				_con.once("CREATE TABLE "+tableName(r, true, true)+"("
					" id BIGINT DEFAULT nextval('"+idGenName(r->_schema, true, true)+"'::regclass) PRIMARY KEY "
					", input_id BIGINT"
					", output_id BIGINT)").exec().throwIfError();
				log.push_back(SyncLogLine("cross table created", schemaName(r->_schema, false, false), tableName(r, false, false)));

				//тригер на добавление в кросс
				_con.once(
					"CREATE OR REPLACE FUNCTION "+triggerFuncName(r, "ins_upd")+"()\n"
					"	RETURNS trigger AS\n"
					"	$BODY$\n"
					"	BEGIN\n"
					"		IF NOT EXISTS (SELECT id FROM "+tableName(r->_inputEnd->_category, true, true)+" WHERE id=NEW.input_id) THEN\n"
					"			RAISE EXCEPTION 'unable to insert/update cross record %, input record % absent', NEW.id, NEW.input_id;\n"
					"		END IF;\n"
					"		IF NOT EXISTS (SELECT id FROM "+tableName(r->_outputEnd->_category, true, true)+" WHERE id=NEW.output_id) THEN\n"
					"			RAISE EXCEPTION 'unable to insert/update cross record %, output record % absent', NEW.id, NEW.output_id;\n"
					"		END IF;\n"
					"		RETURN NEW;\n"
					"	END\n"
					"	$BODY$\n"
					"	LANGUAGE plpgsql;\n"
					).exec().throwIfError();

				_con.once(
					"CREATE TRIGGER "+triggerName(r, "ins_upd")+"\n"
					"	BEFORE INSERT OR UPDATE\n"
					"	ON "+tableName(r, true, true)+"\n"
					"	FOR EACH ROW\n"
					"	EXECUTE PROCEDURE "+triggerFuncName(r, "ins_upd")+"();\n"
					).exec().throwIfError();


				BOOST_FOREACH(dbMeta::CategoryCPtr c, r->_inputEnd->_categories)
				{
					dbMeta::RelationEndCPtr re = c->_relationEnds[r->_inputEnd->_name];
					if(!createTable2CrossTrigger(log, re, "in"))
					{
						log.push_back(SyncLogLine("table triggers creation failed", schemaName(r->_schema, false, false), tableName(c, false, false)));
						return false;
					}
				}
				BOOST_FOREACH(dbMeta::CategoryCPtr c, r->_outputEnd->_categories)
				{
					dbMeta::RelationEndCPtr re = c->_relationEnds[r->_outputEnd->_name];
					if(!createTable2CrossTrigger(log, re, "out"))
					{
						log.push_back(SyncLogLine("table triggers creation failed", schemaName(r->_schema, false, false), tableName(c, false, false)));
						return false;
					}
				}
			}
			else
			{
				return false;
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
	bool Cluster::createTable2CrossTrigger(TSyncLog &log, dbMeta::RelationEndCPtr re, const std::string &who)
	{
		//////////////////////////////////////////////////////////////////////////
		//тригер на удаление
		_con.once(
			"CREATE OR REPLACE FUNCTION "+triggerFuncName(re->_category, re->_name+"_del")+"()\n"
			"	RETURNS trigger AS\n"
			"	$BODY$\n"
			"	BEGIN\n"
			"		IF EXISTS (SELECT id FROM "+tableName(re->_relation, true, true)+" WHERE "+who+"put_id=OLD.id) THEN\n"
			"			RAISE EXCEPTION 'unable to delete "+who+"put record %, cross record present', OLD.id;\n"
			"		END IF;\n"
			"		RETURN OLD;\n"
			"	END\n"
			"	$BODY$\n"
			"	LANGUAGE plpgsql;\n"
			).exec().throwIfError();
		_con.once(
			"CREATE TRIGGER "+triggerName(re->_category, re->_name+"_del")+"\n"
			"	BEFORE DELETE\n"
			"	ON "+tableName(re->_category, true, true)+"\n"
			"	FOR EACH ROW\n"
			"	EXECUTE PROCEDURE "+triggerFuncName(re->_category, re->_name+"_del")+"();\n"
			).exec().throwIfError();

		//////////////////////////////////////////////////////////////////////////
		//на обновление
		_con.once(
			"CREATE OR REPLACE FUNCTION "+triggerFuncName(re->_category, re->_name+"_upd")+"()\n"
			"	RETURNS trigger AS\n"
			"	$BODY$\n"
			"	BEGIN\n"
			"		IF OLD.id != NEW.id AND EXISTS (SELECT id FROM "+tableName(re->_relation, true, true)+" WHERE "+who+"put_id=OLD.id) THEN\n"
			"			RAISE EXCEPTION 'unable to update "+who+"put record %, cross record present', OLD.id;\n"
			"		END IF;\n"
			"		RETURN NEW;\n"
			"	END\n"
			"	$BODY$\n"
			"	LANGUAGE plpgsql;\n"
			).exec().throwIfError();
		_con.once(
			"CREATE TRIGGER "+triggerName(re->_category, re->_name+"_upd")+"\n"
			"	BEFORE UPDATE\n"
			"	ON "+tableName(re->_category, true, true)+"\n"
			"	FOR EACH ROW\n"
			"	EXECUTE PROCEDURE "+triggerFuncName(re->_category, re->_name+"_upd")+"();\n"
			).exec().throwIfError();

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Cluster::drop_schemaExistence(TSyncLog &log, dbMeta::SchemaCPtr s)
	{
		pgc::Result pgr = _con
			.once("SELECT COUNT(*) FROM information_schema.schemata WHERE schema_name=$1")
			.exec(schemaName(s, false, false))
			.throwIfError();

		if(pgr.fetchInt32(0,0))
		{
			log.push_back(SyncLogLine("schema present", schemaName(s, false, false)));

			_con.once("DROP SCHEMA "+schemaName(s, true, true)+" CASCADE").exec().throwIfError();
			log.push_back(SyncLogLine("schema droppped", schemaName(s, false, false)));
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
			}
		}
		if(!res)
		{
			return res;
		}

		//наличие индексов
		BOOST_FOREACH(dbMeta::SchemaCPtr s, _metaCluster->getSchemas())
		{
			BOOST_FOREACH(dbMeta::CategoryCPtr c, s->_categories)
			{
				BOOST_FOREACH(dbMeta::IndexCPtr i, c->_indices)
				{
					res &= sync_indexExistence(log, i, allowCreate);
				}
			}
		}
		if(!res)
		{
			return res;
		}

		//наличие таблиц связей
		BOOST_FOREACH(dbMeta::SchemaCPtr s, _metaCluster->getSchemas())
		{
			BOOST_FOREACH(dbMeta::RelationCPtr r, s->_relations)
			{
				res &= sync_crossExistence(log, r, allowCreate);
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
		if(!res)
		{
			return res;
		}

		_isSynced = true;
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Cluster::drop(TSyncLog &log)
	{
		if(!_metaCluster->isInitialized())
		{
			log.push_back(SyncLogLine("meta cluster is not initialized"));
			return false;
		}

		bool res = true;

		//схемы
		BOOST_FOREACH(dbMeta::SchemaCPtr s, _metaCluster->getSchemas())
		{
			res &= drop_schemaExistence(log, s);
		}
		if(!res)
		{
			return res;
		}

		_isSynced = false;

		_oid2schema.clear();
		_schema2oid.clear();
		_oid2cat.clear();
		_cat2oid.clear();

		return true;
	}

}
