#ifndef _DBMETA_COMMON_HPP_
#define _DBMETA_COMMON_HPP_

#include <vector>
#include <string>
#include <boost/assign/list_of.hpp>

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	class Manager;
	typedef Manager *ManagerPtr;

	//////////////////////////////////////////////////////////////////////////
	class Schema;
	typedef Schema *SchemaPtr;
	typedef std::vector<SchemaPtr> SchemaPtrs;

	//////////////////////////////////////////////////////////////////////////
	class Field;
	typedef Field *FieldPtr;
	typedef std::vector<FieldPtr> FieldPtrs;

	//////////////////////////////////////////////////////////////////////////
	class Index;
	typedef Index *IndexPtr;
	typedef std::vector<IndexPtr> IndexPtrs;

	//////////////////////////////////////////////////////////////////////////
	class Category;
	typedef Category * CategoryPtr;
	typedef std::vector<CategoryPtr> CategoryPtrs;

	//////////////////////////////////////////////////////////////////////////
	class Relation;
	typedef Relation * RelationPtr;
	typedef std::vector<RelationPtr> RelationPtrs;

	//////////////////////////////////////////////////////////////////////////
	class RelationEnd;
	typedef RelationEnd * RelationEndPtr;
	typedef std::vector<RelationEndPtr> RelationEndPtrs;

}

#endif
