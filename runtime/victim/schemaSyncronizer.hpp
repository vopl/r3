#ifndef _SCHEMASYNCRONIZER_HPP_
#define _SCHEMASYNCRONIZER_HPP_

#include "dbMeta/schema.hpp"
#include "pgc/connection.hpp"

class SchemaSyncronizer
{
	dbMeta::SchemaPtr _s;
	pgc::Connection _con;
	std::string _suffix;

	std::string _s_name;

	std::string db_name(const std::string &name);

public:
	SchemaSyncronizer();
	void init(
		dbMeta::SchemaPtr s, 
		pgc::Connection con, 
		const std::string &suffix);

	typedef std::deque<std::string> TSyncLog;
	void sync(TSyncLog &log,
		bool allowCreate = true,
		bool allowAlter = true,
		bool allowDrop = false);
};

#endif
