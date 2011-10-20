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
	typedef const Schema *SchemaPtr;
	typedef std::vector<SchemaPtr> SchemaPtrs;

	//////////////////////////////////////////////////////////////////////////
	class Field;
	typedef const Field *FieldPtr;
	typedef std::vector<FieldPtr> FieldPtrs;

	//////////////////////////////////////////////////////////////////////////
	class Index;
	typedef const Index *IndexPtr;
	typedef std::vector<IndexPtr> IndexPtrs;

	//////////////////////////////////////////////////////////////////////////
	class Category;
	typedef const Category * CategoryPtr;
	typedef std::vector<CategoryPtr> CategoryPtrs;

	//////////////////////////////////////////////////////////////////////////
	class Relation;
	typedef const Relation * RelationPtr;
	typedef std::vector<RelationPtr> RelationPtrs;

	//////////////////////////////////////////////////////////////////////////
	class RelationEnd;
	typedef const RelationEnd * RelationEndPtr;
	typedef std::vector<RelationEndPtr> RelationEndPtrs;

}

#endif
