#ifndef _DBMETA_RELATION_HPP_
#define _DBMETA_RELATION_HPP_

#include "dbMeta/common.hpp"
#include "dbMeta/relationEnd.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	class Relation
	{
	public:
		//наименование
		std::string		_name;

		//входящий край
		RelationEnd		inputEnd;

		//исходящий край
		RelationEnd		outputEnd;

		//объемлющая схема
		SchemaPtr		_schema;
	};
}

#endif
