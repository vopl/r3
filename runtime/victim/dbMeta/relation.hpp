#ifndef _DBMETA_RELATION_HPP_
#define _DBMETA_RELATION_HPP_

#include "dbMeta/common.hpp"
#include "dbMeta/relationEnd.hpp"

namespace dbMeta
{
	class Relation
	{
	public:
		Relation(
			const Schema &schema, 
			const std::string &name);

		const Schema &		_schema;
		const std::string	_name;
		const RelationEnd	_inputEnd;
		const RelationEnd	_outputEnd;
	};
}

#endif
