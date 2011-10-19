#ifndef _DBMETA_RELATION_HPP_
#define _DBMETA_RELATION_HPP_

#include "dbMeta/common.hpp"

namespace dbMeta
{
	class Relation
	{
	public:
		Relation(const SchemaPtr shcema);

		const std::string	_name;
		const RelationEndPtr getInputEnd();
		const RelationEndPtr getOutputEnd();
	};
}

#endif
