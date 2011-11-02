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
		RelationEndPtr	_inputEnd;

		//исходящий край
		RelationEndPtr	_outputEnd;

		//объемлющая схема
		SchemaPtr		_schema;
	};
}

#endif
