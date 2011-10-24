#ifndef _DBMETA_RELATION_HPP_
#define _DBMETA_RELATION_HPP_

#include "dbMeta/common.hpp"
#include "dbMeta/relationEnd.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	class Relation
	{
		RelationEnd		__inputEnd;
		RelationEnd		__outputEnd;

		friend class Manager;
		virtual bool setCategories();

	public:
		Relation(
			const Schema &schema, 
			const std::string &name,
			ERelationMult inputMult,
			ERelationMult outputMult);

		const SchemaPtr			_schema;
		const std::string		_name;

		const RelationEnd		&inputEnd;
		const RelationEnd		&outputEnd;
	};
}

#endif
