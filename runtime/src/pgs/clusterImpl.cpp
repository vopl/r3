#include "pch.h"
#include "pgs/cluster.hpp"
#include "clusterImpl.hpp"
#include <set>

namespace pgs
{
	using namespace utils;

	//////////////////////////////////////////////////////////////////////////
	std::string ClusterImpl::escapeName(const std::string &name, bool escape)
	{
		if(escape)
		{
			return "\"" + name + "\"";
		}

		return name;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string ClusterImpl::schemaName(pgs::meta::SchemaCPtr s, bool escape, bool full)
	{
		std::string n = escapeName(_prefix + "_" + s->_name + "_" + _suffix, escape);
		if(full)
		{
			return n;
		}
		return n;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string ClusterImpl::idGenName(pgs::meta::SchemaCPtr s, bool escape, bool full)
	{
		std::string n = escapeName("idGen", escape);
		if(full)
		{
			return schemaName(s, escape, full)+"."+n;
		}
		return n;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string ClusterImpl::tableName(pgs::meta::CategoryCPtr c, bool escape, bool full)
	{
		std::string n = escapeName(c->_name, escape);
		if(full)
		{
			return schemaName(c->_schema, escape, full)+"."+n;
		}
		return n;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string ClusterImpl::tableName(pgs::meta::RelationCPtr r, bool escape, bool full)
	{
		std::string n = escapeName(r->_name, escape);
		if(full)
		{
			return schemaName(r->_schema, escape, full)+"."+n;
		}
		return n;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string ClusterImpl::columnName(pgs::meta::FieldCPtr f, bool escape, bool full)
	{
		std::string n = escapeName(f->_name, escape);
		if(full)
		{
			return tableName(f->_category, escape, full)+"."+n;
		}
		return n;
	}

	// 	//////////////////////////////////////////////////////////////////////////
	// 	std::string ClusterImpl::columnName(pgs::meta::RelationEndCPtr re, bool escape, bool full)
	// 	{
	// 		std::string n = escapeName(re->_name, escape);
	// 		if(full)
	// 		{
	// 			return tableName(re->_category, escape, full)+"."+n;
	// 		}
	// 		return n;
	// 	}

	//////////////////////////////////////////////////////////////////////////
	std::string ClusterImpl::indexName	(pgs::meta::IndexCPtr i,			bool escape,	bool full)
	{
		std::string n = escapeName(i->_category->_name+"_"+i->_name, escape);
		if(full)
		{
			return schemaName(i->_category->_schema, escape, full)+"."+n;
		}
		return n;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string ClusterImpl::columnType(pgs::meta::FieldCPtr f)
	{
		std::string res;
		switch(f->_type)
		{
		case pgs::meta::eftBinary:
			res = "BYTEA";
		case pgs::meta::eftBool:
			res =  "BOOLEAN";
			break;
		case pgs::meta::eftDate:
			res =  "DATE";
			break;
		case pgs::meta::eftDateTimeInterval:
			res =  "INTERVAL";
			break;
		case pgs::meta::eftEnum:
			res =  "SMALLINT";
			break;
		case pgs::meta::eftFile:
			res =  "OID";
			break;
		case pgs::meta::eftId:
			res =  "BIGINT";
			break;
		case pgs::meta::eftInt16:
			res =  "SMALLINT";
			break;
		case pgs::meta::eftInt32:
			res =  "INTEGER";
			break;
		case pgs::meta::eftInt64:
			res =  "BIGINT";
			break;
		case pgs::meta::eftInt8:
			res =  "SMALLINT";
			break;
		case pgs::meta::eftMoney:
			res =  "MONEY";
			break;
		case pgs::meta::eftReal32:
			res =  "REAL";
			break;
		case pgs::meta::eftReal64:
			res =  "DOUBLE PRECISION";
			break;
		case pgs::meta::eftSet:
			assert(!"������");
			res =  "BITS(8)";
			break;
		case pgs::meta::eftString:
			res =  "VARCHAR";
			break;
		case pgs::meta::eftTime:
			res =  "TIME WITHOUT TIME ZONE";
			break;
		case pgs::meta::eftTimestamp:
			res =  "TIMESTAMP WITHOUT TIME ZONE";
			break;
		case pgs::meta::eftUuid:
			res =  "UUID";
			break;
		case pgs::meta::eftVariant:
			res =  "BYTEA";
			break;
		case pgs::meta::eftBitset8:
			res =  "BIT(8)";
			break;
		case pgs::meta::eftBitset16:
			res =  "BIT(16)";
			break;
		case pgs::meta::eftBitset32:
			res =  "BIT(32)";
			break;
		case pgs::meta::eftBitset64:
			res =  "BIT(64)";
			break;
		case pgs::meta::eftBitset128:
			res =  "BIT(128)";
			break;
		case pgs::meta::eftBitset256:
			res =  "BIT(256)";
			break;
		case pgs::meta::eftBitset512:
			res =  "BIT(512)";
			break;
		default:
			assert(!"unknown field type");
			throw "unknown field type";
		}

		if(f->_allowNull)
		{
			res += " NULL";
		}
		else
		{
			res += " NOT NULL";
		}

		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string ClusterImpl::triggerFuncName	(pgs::meta::CategoryCPtr c, const std::string &suffix)
	{
		return schemaName(c->_schema, true, true)+"."+escapeName(c->_name+"_"+suffix, true);
	}

	//////////////////////////////////////////////////////////////////////////
	std::string ClusterImpl::triggerFuncName	(pgs::meta::RelationCPtr r, const std::string &suffix)
	{
		return schemaName(r->_schema, true, true)+"."+escapeName(r->_name+"_"+suffix, true);
	}

	//////////////////////////////////////////////////////////////////////////
	std::string ClusterImpl::triggerName	(pgs::meta::CategoryCPtr c, const std::string &suffix)
	{
		return escapeName(c->_name+"_"+suffix, true);
	}

	//////////////////////////////////////////////////////////////////////////
	std::string ClusterImpl::triggerName	(pgs::meta::RelationCPtr r, const std::string &suffix)
	{
		return escapeName(r->_name+"_"+suffix, true);
	}


	//////////////////////////////////////////////////////////////////////////
	bool ClusterImpl::sync_schemaExistence(pgc::Connection con, pgs::meta::SchemaCPtr s, bool allowCreate)
	{
		pgc::Data pgr = con.query(
			"SELECT COUNT(*) FROM information_schema.schemata WHERE schema_name=$1",
			schemaName(s, false, false)).data()[0];

		if(pgc::ersTuplesOk != pgr.status() || !pgr.fetchInt32(0,0))
		{
			//log.push_back(SyncLogLine("schema absent", schemaName(s, false, false)));
			WLOG("schema absent: "<<schemaName(s, false, false));

			if(allowCreate)
			{
				pgr = con.query("CREATE SCHEMA "+schemaName(s, true, true)).data()[0];
				if(pgc::ersCommandOk != pgr.status())
				{
					return false;
				}
				//log.push_back(SyncLogLine("schema created", schemaName(s, false, false)));
				ILOG("schema created: "<<schemaName(s, false, false));

			}
			else
			{
				//��� ����� ����?
				return false;
			}
		}

		//oid
		pgr = con.query(
			"SELECT oid FROM pg_catalog.pg_namespace WHERE nspname=$1",
			schemaName(s, false, false)).data()[0];
		if(pgc::ersTuplesOk != pgr.status() || 1 != pgr.rows())
		{
			//log.push_back(SyncLogLine("obtain schema oid failed", schemaName(s, false, false)));
			WLOG("obtain schema oid failed: "<<schemaName(s, false, false));
			return false;
		}
		TOid oid = pgr.fetchUInt32(0,0);
		_schema2oid[s] = oid;
		_oid2schema[oid] = s;

		//��������� ��������������� ��������
		pgr = con.query(
			"SELECT COUNT(*) FROM information_schema.sequences WHERE sequence_schema=$1 AND sequence_name=$2",
			MVA(schemaName(s, false, false), idGenName(s, false, false))).data()[0];
		if(pgc::ersTuplesOk != pgr.status() || !pgr.fetchInt32(0,0))
		{
			//log.push_back(SyncLogLine("idGen absent", schemaName(s, false, false), idGenName(s, false, false)));
			WLOG("idGen absent: "<<schemaName(s, false, false)<<", "<<idGenName(s, false, false));

			if(allowCreate)
			{
				pgr = con.query("CREATE SEQUENCE "+idGenName(s, true, true)).data()[0];
				if(pgc::ersCommandOk != pgr.status())
				{
					return false;
				}
				//log.push_back(SyncLogLine("idGen created", schemaName(s, false, false), idGenName(s, false, false)));
				ILOG("idGen created: "<<schemaName(s, false, false)<<", "<<idGenName(s, false, false));
			}
			else
			{
				return false;
			}
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool ClusterImpl::sync_tableExistence(pgc::Connection con, pgs::meta::CategoryCPtr c, bool allowCreate)
	{
		pgc::Data pgr = con.query(
			"SELECT * FROM information_schema.tables WHERE table_schema=$1 AND table_name=$2",
			MVA(schemaName(c->_schema, false, false), tableName(c, false, false))).data()[0];

		if(pgc::ersTuplesOk != pgr.status() || !pgr.rows())
		{
			//log.push_back(SyncLogLine("table absent", schemaName(c->_schema, false, false), tableName(c, false, false)));
			WLOG("table absent: "<<schemaName(c->_schema, false, false)<<", "<<tableName(c, false, false));
			if(allowCreate)
			{
				pgr = con.query("CREATE TABLE "+tableName(c, true, true)+"()").data()[0];
				if(pgc::ersCommandOk != pgr.status())
				{
					return false;
				}
				//log.push_back(SyncLogLine("table created", schemaName(c->_schema, false, false), tableName(c, false, false)));
				ILOG("table created: "<<schemaName(c->_schema, false, false)<<", "<<tableName(c, false, false));
			}
			else
			{
				return false;
			}
		}

		//oid
		pgr = con.query(
			"SELECT oid FROM pg_catalog.pg_class WHERE relname=$1 AND relnamespace=$2",
			MVA(tableName(c, false, false), _schema2oid[c->_schema])).data()[0];
		if(pgc::ersTuplesOk != pgr.status() || pgr.rows() != 1)
		{
			//log.push_back(SyncLogLine("obtain table oid failed", schemaName(c->_schema, false, false), tableName(c, false, false)));
			WLOG("obtain table oid failed: "<<schemaName(c->_schema, false, false)<<", "<<tableName(c, false, false));
			return false;
		}
		TOid oid = pgr.fetchUInt32(0,0);
		_cat2oid[c] = oid;
		_oid2cat[oid] = c;

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool ClusterImpl::sync_columnExistence(pgc::Connection con, pgs::meta::FieldCPtr f, bool allowCreate)
	{
		pgc::Data pgr = con.query(
			"SELECT * FROM information_schema.columns WHERE table_schema=$1 AND table_name=$2 AND column_name=$3",
			MVA(schemaName(f->_category->_schema, false, false), tableName(f->_category, false, false), columnName(f, false, false))).data()[0];
		if(pgc::ersTuplesOk != pgr.status() || !pgr.rows())
		{
			//log.push_back(SyncLogLine("column absent", schemaName(f->_category->_schema, false, false), tableName(f->_category, false, false), columnName(f, false, false)));
			WLOG("column absent: "<<schemaName(f->_category->_schema, false, false)<<", "<<tableName(f->_category, false, false)<<", "<<columnName(f, false, false));
			if(allowCreate)
			{
				std::string sql = "ALTER TABLE "+tableName(f->_category, true, true)+" ADD COLUMN "+columnName(f, true, false)+" "+columnType(f);
				if(meta::eftId == f->_type)
				{
					sql += " DEFAULT nextval('"+idGenName(f->_category->_schema, true, true)+"'::regclass) PRIMARY KEY";
				}

				pgr = con.query(sql).data()[0];
				if(pgc::ersCommandOk != pgr.status())
				{
					return false;
				}
				//log.push_back(SyncLogLine("column created", schemaName(f->_category->_schema, false, false), tableName(f->_category, false, false), columnName(f, false, false)));
				ILOG("column created: "<<schemaName(f->_category->_schema, false, false)<<", "<<tableName(f->_category, false, false)<<", "<<columnName(f, false, false));
			}
			else
			{
				return false;
			}
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool ClusterImpl::sync_indexExistence(pgc::Connection con, pgs::meta::IndexCPtr i, bool allowCreate)
	{
		if(i->_fields.empty())
		{
			return true;
		}

		pgc::Data pgr = con.query(
			"SELECT * FROM pg_catalog.pg_indexes WHERE schemaname=$1 AND tablename=$2 AND indexname=$3",
			MVA(
				schemaName(i->_category->_schema, false, false), 
				tableName(i->_category, false, false), 
				indexName(i, false, false))).data()[0];
		if(pgc::ersTuplesOk != pgr.status() || !pgr.rows())
		{
			//log.push_back(SyncLogLine("index absent", schemaName(i->_category->_schema, false, false), indexName(i, false, false)));
			WLOG("index absent: "<<schemaName(i->_category->_schema, false, false)<<", "<<indexName(i, false, false));
			if(allowCreate)
			{
				std::string sql = "CREATE INDEX "+indexName(i, true, false)+" ON "+tableName(i->_category, true, true)+" USING ";
				switch(i->_type)
				{
				default:
					assert(!"unknown index type");
				case pgs::meta::eitTree:
					sql += "btree";
					break;
				case pgs::meta::eitHash:
					sql += "hash";
					break;
				}

				sql += "(";
				bool isFirst = true;
				BOOST_FOREACH(pgs::meta::FieldCPtr f, i->_fields)
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
				pgr = con.query(sql).data()[0];
				if(pgc::ersCommandOk != pgr.status())
				{
					return false;
				}
				//log.push_back(SyncLogLine("index created", schemaName(i->_category->_schema, false, false), indexName(i, false, false)));
				ILOG("index created: "<<schemaName(i->_category->_schema, false, false)<<", "<<indexName(i, false, false));
			}
			else
			{
				return false;
			}
		}

		return true;
	}


	//////////////////////////////////////////////////////////////////////////
	bool ClusterImpl::sync_crossExistence(pgc::Connection con, pgs::meta::RelationCPtr r, bool allowCreate)
	{
		pgc::Data pgr = con.query(
			"SELECT * FROM information_schema.tables WHERE table_schema=$1 AND table_name=$2",
			MVA(schemaName(r->_schema, false, false), tableName(r, false, false))).data()[0];
		if(pgc::ersTuplesOk != pgr.status() || !pgr.rows())
		{
			//log.push_back(SyncLogLine("cross table absent", schemaName(r->_schema, false, false), tableName(r, false, false)));
			WLOG("cross table absent: "<<schemaName(r->_schema, false, false)<<", "<<tableName(r, false, false));
			if(allowCreate)
			{
				pgr = con.query("CREATE TABLE "+tableName(r, true, true)+"("
					" id BIGINT DEFAULT nextval('"+idGenName(r->_schema, true, true)+"'::regclass) PRIMARY KEY "
					", input_id BIGINT"
					", output_id BIGINT)").data()[0];
				if(pgc::ersCommandOk != pgr.status())
				{
					return false;
				}
				//log.push_back(SyncLogLine("cross table created", schemaName(r->_schema, false, false), tableName(r, false, false)));
				ILOG("cross table created: "<<schemaName(r->_schema, false, false)<<", "<<tableName(r, false, false));

				//������ �� ���������� � �����
				pgr = con.query(
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
					).data()[0];
				if(pgc::ersCommandOk != pgr.status())
				{
					return false;
				}

				pgr = con.query(
					"CREATE TRIGGER "+triggerName(r, "ins_upd")+"\n"
					"	BEFORE INSERT OR UPDATE\n"
					"	ON "+tableName(r, true, true)+"\n"
					"	FOR EACH ROW\n"
					"	EXECUTE PROCEDURE "+triggerFuncName(r, "ins_upd")+"();\n"
					).data()[0];
				if(pgc::ersCommandOk != pgr.status())
				{
					return false;
				}


				BOOST_FOREACH(pgs::meta::CategoryCPtr c, r->_inputEnd->_categories)
				{
					pgs::meta::RelationEndCPtr re = c->_relationEnds[r->_inputEnd->_name];
					if(!createTable2CrossTrigger(con, re, "in"))
					{
						//log.push_back(SyncLogLine("table triggers creation failed", schemaName(r->_schema, false, false), tableName(c, false, false)));
						WLOG("table triggers creation failed: "<<schemaName(r->_schema, false, false)<<", "<<tableName(c, false, false));
						return false;
					}
				}
				BOOST_FOREACH(pgs::meta::CategoryCPtr c, r->_outputEnd->_categories)
				{
					pgs::meta::RelationEndCPtr re = c->_relationEnds[r->_outputEnd->_name];
					if(!createTable2CrossTrigger(con, re, "out"))
					{
						//log.push_back(SyncLogLine("table triggers creation failed", schemaName(r->_schema, false, false), tableName(c, false, false)));
						WLOG("table triggers creation failed: "<<schemaName(r->_schema, false, false)<<", "<<tableName(c, false, false));
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
	bool ClusterImpl::sync_tableInherits(pgc::Connection con, pgs::meta::CategoryCPtr c, bool allowCreate)
	{
		//todo: withPrepare �������
		pgc::Data pgr = con.query(
			"SELECT inhparent FROM pg_catalog.pg_inherits WHERE inhrelid=$1",
			Variant(_cat2oid[c])).data()[0];

		if(pgc::ersTuplesOk != pgr.status())
		{
			return false;
		}

		std::set<TOid> baseOids;
		for(size_t i(0); i<pgr.rows(); i++)
		{
			baseOids.insert(pgr.fetchUInt32(0, i));
		}


		BOOST_FOREACH(pgs::meta::CategoryCPtr b, c->_bases)
		{
			if(baseOids.end() == baseOids.find(_cat2oid[b]))
			{
				//log.push_back(SyncLogLine("inheritance absent", schemaName(c->_schema, false, false), tableName(c, false, false), tableName(b, false, false)));
				WLOG("inheritance absent: "<<schemaName(c->_schema, false, false)<<", "<<tableName(c, false, false)<<", "<<tableName(b, false, false));
				if(allowCreate)
				{
					pgr = con.query("ALTER TABLE "+tableName(c, true, true)+" INHERIT "+tableName(b, true, true)).data()[0];
					if(pgc::ersCommandOk != pgr.status())
					{
						return false;
					}
					baseOids.insert(_cat2oid[b]);
					//log.push_back(SyncLogLine("inheritance created", schemaName(c->_schema, false, false), tableName(c, false, false), tableName(b, false, false)));
					ILOG("inheritance created: "<<schemaName(c->_schema, false, false)<<", "<<tableName(c, false, false)<<", "<<tableName(b, false, false));
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
	bool ClusterImpl::createTable2CrossTrigger(pgc::Connection con, pgs::meta::RelationEndCPtr re, const std::string &who)
	{
		//////////////////////////////////////////////////////////////////////////
		//������ �� ��������
		pgc::Data pgr = con.query(
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
			).data()[0];
		if(pgc::ersCommandOk != pgr.status())
		{
			return false;
		}

		pgr = con.query(
			"CREATE TRIGGER "+triggerName(re->_category, re->_name+"_del")+"\n"
			"	BEFORE DELETE\n"
			"	ON "+tableName(re->_category, true, true)+"\n"
			"	FOR EACH ROW\n"
			"	EXECUTE PROCEDURE "+triggerFuncName(re->_category, re->_name+"_del")+"();\n"
			).data()[0];
		if(pgc::ersCommandOk != pgr.status())
		{
			return false;
		}

		//////////////////////////////////////////////////////////////////////////
		//�� ����������
		pgr = con.query(
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
			).data()[0];
		if(pgc::ersCommandOk != pgr.status())
		{
			return false;
		}

		pgr = con.query(
			"CREATE TRIGGER "+triggerName(re->_category, re->_name+"_upd")+"\n"
			"	BEFORE UPDATE\n"
			"	ON "+tableName(re->_category, true, true)+"\n"
			"	FOR EACH ROW\n"
			"	EXECUTE PROCEDURE "+triggerFuncName(re->_category, re->_name+"_upd")+"();\n"
			).data()[0];
		if(pgc::ersCommandOk != pgr.status())
		{
			return false;
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool ClusterImpl::drop_schemaExistence(pgc::Connection con, pgs::meta::SchemaCPtr s)
	{
		pgc::Data pgr = con.query(
			"SELECT COUNT(*) FROM information_schema.schemata WHERE schema_name=$1",
			schemaName(s, false, false)).data()[0];
		if(pgc::ersTuplesOk != pgr.status())
		{
			return false;
		}

		if(pgr.fetchInt32(0,0))
		{
			//log.push_back(SyncLogLine("schema present", schemaName(s, false, false)));
			ILOG("schema present: "<<schemaName(s, false, false));

			pgr = con.query("DROP SCHEMA "+schemaName(s, true, true)+" CASCADE").data()[0];
			if(pgc::ersCommandOk != pgr.status())
			{
				return false;
			}
			//log.push_back(SyncLogLine("schema droppped", schemaName(s, false, false)));
			ILOG("schema droppped: "<<schemaName(s, false, false));
		}

		return true;
	}


	//////////////////////////////////////////////////////////////////////////
	ClusterImpl::ClusterImpl(pgs::meta::Cluster metaCluster)
		: _metaCluster(metaCluster)
		, _prefix()
		, _suffix()
		, _isSynced(false)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void ClusterImpl::setUnicators(const std::string &prefix, const std::string &suffix)
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
	bool ClusterImpl::sync(pgc::Connection con, bool allowCreate)
	{
		_isSynced = false;

		_oid2schema.clear();
		_schema2oid.clear();
		_oid2cat.clear();
		_cat2oid.clear();

		if(!_metaCluster.isInitialized())
		{
			//log.push_back(SyncLogLine("meta cluster is not initialized"));
			WLOG("meta cluster is not initialized");
			return false;
		}

		bool res = true;

		//������� ����
		BOOST_FOREACH(pgs::meta::SchemaCPtr s, _metaCluster.getSchemas())
		{
			res &= sync_schemaExistence(con, s, allowCreate);
		}
		if(!res)
		{
			return res;
		}

		//������� ������
		BOOST_FOREACH(pgs::meta::SchemaCPtr s, _metaCluster.getSchemas())
		{
			BOOST_FOREACH(pgs::meta::CategoryCPtr c, s->_categories)
			{
				res &= sync_tableExistence(con, c, allowCreate);
			}
		}
		if(!res)
		{
			return res;
		}

		//������� �����
		BOOST_FOREACH(pgs::meta::SchemaCPtr s, _metaCluster.getSchemas())
		{
			BOOST_FOREACH(pgs::meta::CategoryCPtr c, s->_categories)
			{
				BOOST_FOREACH(pgs::meta::FieldCPtr f, c->_fields)
				{
					res &= sync_columnExistence(con, f, allowCreate);
				}
			}
		}
		if(!res)
		{
			return res;
		}

		//������� ��������
		BOOST_FOREACH(pgs::meta::SchemaCPtr s, _metaCluster.getSchemas())
		{
			BOOST_FOREACH(pgs::meta::CategoryCPtr c, s->_categories)
			{
				BOOST_FOREACH(pgs::meta::IndexCPtr i, c->_indices)
				{
					res &= sync_indexExistence(con, i, allowCreate);
				}
			}
		}
		if(!res)
		{
			return res;
		}

		//������� ������ ������
		BOOST_FOREACH(pgs::meta::SchemaCPtr s, _metaCluster.getSchemas())
		{
			BOOST_FOREACH(pgs::meta::RelationCPtr r, s->_relations)
			{
				res &= sync_crossExistence(con, r, allowCreate);
			}
		}
		if(!res)
		{
			return res;
		}

		//������������
		BOOST_FOREACH(pgs::meta::SchemaCPtr s, _metaCluster.getSchemas())
		{
			BOOST_FOREACH(pgs::meta::CategoryCPtr c, s->_categories)
			{
				res &= sync_tableInherits(con, c, allowCreate);
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
	bool ClusterImpl::drop(pgc::Connection con)
	{
		if(!_metaCluster.isInitialized())
		{
			//log.push_back(SyncLogLine("meta cluster is not initialized"));
			ELOG("meta cluster is not initialized");
			return false;
		}

		bool res = true;

		//�����
		BOOST_FOREACH(pgs::meta::SchemaCPtr s, _metaCluster.getSchemas())
		{
			res &= drop_schemaExistence(con, s);
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
