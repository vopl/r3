#ifndef _DBMETA_COMMON_HPP_
#define _DBMETA_COMMON_HPP_

#include "dbMeta/ptrContainer.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	class ClusterStorage;
	typedef ClusterStorage *ClusterStoragePtr;

	//////////////////////////////////////////////////////////////////////////
	class Schema;
	typedef Schema *SchemaPtr;
	typedef PtrContainer<Schema> SchemaPtrs;

	//////////////////////////////////////////////////////////////////////////
	class Field;
	typedef Field *FieldPtr;
	typedef PtrContainer<Field> FieldPtrs;

	//////////////////////////////////////////////////////////////////////////
	class FieldScanty;
	typedef FieldScanty *FieldScantyPtr;
	typedef PtrContainer<FieldScanty> FieldScantyPtrs;

	//////////////////////////////////////////////////////////////////////////
	class FieldScantyValue;
	typedef FieldScantyValue *FieldScantyValuePtr;
	typedef PtrContainer<FieldScantyValue> FieldScantyValuePtrs;

	//////////////////////////////////////////////////////////////////////////
	class Index;
	typedef Index *IndexPtr;
	typedef PtrContainer<Index> IndexPtrs;

	//////////////////////////////////////////////////////////////////////////
	class Category;
	typedef Category * CategoryPtr;
	typedef PtrContainer<Category> CategoryPtrs;

	//////////////////////////////////////////////////////////////////////////
	class Relation;
	typedef Relation * RelationPtr;
	typedef PtrContainer<Relation> RelationPtrs;

	//////////////////////////////////////////////////////////////////////////
	class RelationEnd;
	typedef RelationEnd * RelationEndPtr;
	typedef PtrContainer<RelationEnd> RelationEndPtrs;

}

#endif
