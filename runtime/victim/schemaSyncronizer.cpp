#include "stdafx.h"
#include "schemaSyncronizer.hpp"
#include "dbMeta/category.hpp"


//////////////////////////////////////////////////////////////////////////
std::string SchemaSyncronizer::db_name(const std::string &name)
{
	return _s_name + ".\""+name+"\"";
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
		  const dbMeta::SchemaPtr s, 
		  pgc::Connection con, 
		  const std::string &suffix)
{
	_s = s;
	_con = con;
	_suffix = suffix;

	_s_name = "\""+s->_name+_suffix+"\"";
}

//////////////////////////////////////////////////////////////////////////
void SchemaSyncronizer::sync(TSyncLog &log,
							   bool allowCreate,
							   bool allowAlter,
							   bool allowDrop)
{
	pgc::Result pgr;

	//наличие схемы
	pgr = _con
		.once("SELECT COUNT(*) FROM information_schema.schemata WHERE schema_name=$1")
		.exec(_s->_name+_suffix)
		.throwIfError();
	if(!pgr.fetchInt(0,0))
	{
		log.push_back("schema absent");

		if(allowCreate)
		{
			_con.once("CREATE SCHEMA "+_s_name).exec().throwIfError();
			log.push_back("schema created");
		}
		else
		{
			//без схемы куда?
			return;
		}
	}

	//генератор идентификаторов объектов
	pgr = _con.once("SELECT COUNT(*) FROM information_schema.sequences WHERE sequence_schema=$1 AND sequence_name=$2").exec(_s->_name+_suffix, std::string("idGen")).throwIfError();
	if(!pgr.fetchInt(0, 0))
	{
		log.push_back("idGen absent");

		if(allowCreate)
		{
			_con.once("CREATE SEQUENCE "+db_name("idGen")).exec().throwIfError();
			log.push_back("idGen created");
		}
	}

	//наличие табличек категорий
	BOOST_FOREACH(dbMeta::CategoryPtr cat, _s->_categories)
	{
		pgr = _con.once("SELECT * FROM information_schema.tables WHERE table_schema=$1 AND table_name=$2").exec(_s->_name+_suffix, cat->_name).throwIfError();
		if(!pgr.rows())
		{
			log.push_back("table "+cat->_name+" absent");
			if(allowCreate)
			{
				_con.once("CREATE TABLE "+db_name(cat->_name)+"()").exec().throwIfError();
				log.push_back("table "+cat->_name+" created");
				pgr = _con.once("SELECT * FROM information_schema.tables WHERE table_schema=$1 AND table_name=$2").exec(_s->_name+_suffix, cat->_name).throwIfError();
			}
		}

	}

	int k = 220;
}

