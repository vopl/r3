#ifndef _DBMETA_COMMON_HPP_
#define _DBMETA_COMMON_HPP_

#include <vector>
#include <string>
#include <boost/assign/list_of.hpp>
#include "dbMeta/ptrContainer.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	class Manager;
	typedef Manager *ManagerPtr;

	//////////////////////////////////////////////////////////////////////////
	class Schema;
	typedef Schema *SchemaPtr;
	typedef PtrContainer<Schema*, const Schema *> SchemaPtrs;

	//////////////////////////////////////////////////////////////////////////
	class Field;
	typedef Field *FieldPtr;
	typedef PtrContainer<Field*, const Field *> FieldPtrs;

	//////////////////////////////////////////////////////////////////////////
	class FieldScanty;
	typedef FieldScanty *FieldScantyPtr;
	typedef PtrContainer<FieldScanty*, const FieldScanty *> FieldScantyPtrs;

	//////////////////////////////////////////////////////////////////////////
	class FieldScantyValue;
	typedef FieldScantyValue *FieldScantyValuePtr;
	typedef PtrContainer<FieldScantyValue*, const FieldScantyValue *> FieldScantyValuePtrs;

	//////////////////////////////////////////////////////////////////////////
	class Index;
	typedef Index *IndexPtr;
	typedef PtrContainer<Index*, const Index *> IndexPtrs;

	//////////////////////////////////////////////////////////////////////////
	class Category;
	typedef Category * CategoryPtr;
	typedef PtrContainer<Category*, const Category *> CategoryPtrs;

	//////////////////////////////////////////////////////////////////////////
	class Relation;
	typedef Relation * RelationPtr;
	typedef PtrContainer<Relation*, const Relation *> RelationPtrs;

	//////////////////////////////////////////////////////////////////////////
	class RelationEnd;
	typedef RelationEnd * RelationEndPtr;
	typedef PtrContainer<RelationEnd*, const RelationEnd *> RelationEndPtrs;

}

#endif
