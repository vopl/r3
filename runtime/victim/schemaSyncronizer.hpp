#ifndef _SCHEMASYNCRONIZER_HPP_
#define _SCHEMASYNCRONIZER_HPP_

#include "dbMeta/schema.hpp"
#include "pgc/connection.hpp"

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
class SchemaSyncronizer
{
	dbMeta::SchemaCPtr _s;
	pgc::Connection _con;
	std::string _suffix;

	std::string _s_name;

	std::string db_quoteId(const std::string &name);
	std::string db_name(const std::string &name, const std::string &name2="");
	std::string db_fldType(dbMeta::FieldPtr fld);

	bool syncTableField(
		dbMeta::FieldPtr fld,
		TSyncLog &log,
		bool allowCreate = true,
		bool allowAlter = true,
		bool allowDrop = false);

public:
	SchemaSyncronizer();
	void init(
		dbMeta::SchemaCPtr s, 
		pgc::Connection con, 
		const std::string &suffix);

	void sync(TSyncLog &log,
		bool allowCreate = true,
		bool allowAlter = true,
		bool allowDrop = false);
};

#endif
