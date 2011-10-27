#include "stdafx.h"
#include "schemaSyncronizer.hpp"
#include "dbMeta/category.hpp"
#include "dbMeta/field.hpp"


//////////////////////////////////////////////////////////////////////////
std::string SchemaSyncronizer::db_quoteId(const std::string &name)
{
	return "\""+name+"\"";
}

//////////////////////////////////////////////////////////////////////////
std::string SchemaSyncronizer::db_name(const std::string &name, const std::string &name2)
{
	return _s_name + "."+db_quoteId(name)+ (name2.empty()?"":("."+db_quoteId(name2)));
}

//////////////////////////////////////////////////////////////////////////
std::string SchemaSyncronizer::db_fldType(dbMeta::FieldPtr fld)
{
	switch(fld->_type)
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
SchemaSyncronizer::SchemaSyncronizer()
	: _s()
	, _con()
	, _suffix()
{

}

//////////////////////////////////////////////////////////////////////////
void SchemaSyncronizer::init(
		  const dbMeta::SchemaCPtr s, 
		  pgc::Connection con, 
		  const std::string &suffix)
{
	_s = s;
	_con = con;
	_suffix = suffix;

	_s_name = db_quoteId(s->_name+_suffix);
}

//////////////////////////////////////////////////////////////////////////
void SchemaSyncronizer::sync(TSyncLog &log,
							   bool allowCreate,
							   bool allowAlter,
							   bool allowDrop)
{
	pgc::Result pgr;

	bool canContinue = true;
	//наличие схемы
	pgr = _con
		.once("SELECT COUNT(*) FROM information_schema.schemata WHERE schema_name=$1")
		.exec(_s->_name+_suffix)
		.throwIfError();
	if(!pgr.fetchInt(0,0))
	{
		log.push_back(SyncLogLine("schema absent", _s->_name));

		if(allowCreate)
		{
			_con.once("CREATE SCHEMA "+_s_name).exec().throwIfError();
			log.push_back(SyncLogLine("schema created", _s->_name));
		}
		else
		{
			//без схемы куда?
			canContinue = false;
		}
	}
	if(!canContinue) return;

	//генератор идентификаторов объектов
	pgr = _con.once("SELECT COUNT(*) FROM information_schema.sequences WHERE sequence_schema=$1 AND sequence_name=$2").exec(_s->_name+_suffix, std::string("idGen")).throwIfError();
	if(!pgr.fetchInt(0, 0))
	{
		log.push_back(SyncLogLine("idGen absent", _s->_name));

		if(allowCreate)
		{
			_con.once("CREATE SEQUENCE "+db_name("idGen")).exec().throwIfError();
			log.push_back(SyncLogLine("idGen created", _s->_name));
		}
		else
		{
			canContinue = false;
		}
	}
	if(!canContinue) return;

	//наличие табличек категорий
	BOOST_FOREACH(dbMeta::CategoryPtr cat, _s->_categories)
	{
		pgr = _con.once("SELECT * FROM information_schema.tables WHERE table_schema=$1 AND table_name=$2").exec(_s->_name+_suffix, cat->_name).throwIfError();
		if(!pgr.rows())
		{
			log.push_back(SyncLogLine("table absent", _s->_name, cat->_name));
			if(allowCreate)
			{
				_con.once("CREATE TABLE "+db_name(cat->_name)+"()").exec().throwIfError();
				log.push_back(SyncLogLine("table created", _s->_name, cat->_name));
			}
			else
			{
				canContinue = false;
			}
		}
	}
	if(!canContinue) return;

	//поля в табличках
	BOOST_FOREACH(dbMeta::CategoryPtr cat, _s->_categories)
	{
		BOOST_FOREACH(dbMeta::FieldPtr fld, cat->_fields)
		{
			canContinue &= syncTableField(fld, log, allowCreate, allowAlter, allowDrop);
		}
	}
	if(!canContinue) return;

	//связи
	BOOST_FOREACH(dbMeta::RelationPtr rel, _s->_relations)
	{
		//canContinue &= syncRelation(rel, log, allowCreate, allowAlter, allowDrop);
	}
	if(!canContinue) return;


	int k = 220;
}


//////////////////////////////////////////////////////////////////////////
bool SchemaSyncronizer::syncTableField(
										dbMeta::FieldPtr fld,
										TSyncLog &log,
										bool allowCreate,
										bool allowAlter,
										bool allowDrop)
{
	pgc::Result pgr;

	dbMeta::CategoryPtr cat = fld->_category;

	pgr = _con.once("SELECT * FROM information_schema.columns WHERE table_schema=$1 AND table_name=$2 AND column_name=$3").exec(_s->_name+_suffix, cat->_name, fld->_name).throwIfError();
	if(!pgr.rows())
	{
		log.push_back(SyncLogLine("field absent", _s->_name, cat->_name, fld->_name));
		if(allowCreate)
		{
			_con.once("ALTER TABLE "+db_name(cat->_name)+" ADD COLUMN "+db_quoteId(fld->_name)+" "+db_fldType(fld)).exec().throwIfError();
			log.push_back(SyncLogLine("field created", _s->_name, cat->_name, fld->_name));
		}
		else
		{
			return false;
		}
	}

	return true;
}


