#ifndef _PGS_META_COMMON_HPP_
#define _PGS_META_COMMON_HPP_

#include "pgc/api.h"
#include "pgs/meta/ptrContainer.hpp"

namespace pgs
{
	namespace meta
	{
		//////////////////////////////////////////////////////////////////////////
		class ClusterStorage;
		typedef ClusterStorage *ClusterStoragePtr;
		typedef const ClusterStorage *ClusterStorageCPtr;

		//////////////////////////////////////////////////////////////////////////
		class Schema;
		typedef Schema *SchemaPtr;
		typedef const Schema *SchemaCPtr;
		typedef PtrContainer<Schema> SchemaPtrs;

		//////////////////////////////////////////////////////////////////////////
		class Field;
		typedef Field *FieldPtr;
		typedef const Field *FieldCPtr;
		typedef PtrContainer<Field> FieldPtrs;

		//////////////////////////////////////////////////////////////////////////
		class FieldScanty;
		typedef FieldScanty *FieldScantyPtr;
		typedef const FieldScanty *FieldScantyCPtr;
		typedef PtrContainer<FieldScanty> FieldScantyPtrs;

		//////////////////////////////////////////////////////////////////////////
		class FieldScantyValue;
		typedef FieldScantyValue *FieldScantyValuePtr;
		typedef const FieldScantyValue *FieldScantyValueCPtr;
		typedef PtrContainer<FieldScantyValue> FieldScantyValuePtrs;

		//////////////////////////////////////////////////////////////////////////
		class Index;
		typedef Index *IndexPtr;
		typedef const Index *IndexCPtr;
		typedef PtrContainer<Index> IndexPtrs;

		//////////////////////////////////////////////////////////////////////////
		class Category;
		typedef Category * CategoryPtr;
		typedef const Category * CategoryCPtr;
		typedef PtrContainer<Category> CategoryPtrs;

		//////////////////////////////////////////////////////////////////////////
		class Relation;
		typedef Relation * RelationPtr;
		typedef const Relation * RelationCPtr;
		typedef PtrContainer<Relation> RelationPtrs;

		//////////////////////////////////////////////////////////////////////////
		class RelationEnd;
		typedef RelationEnd * RelationEndPtr;
		typedef const RelationEnd * RelationEndCPtr;
		typedef PtrContainer<RelationEnd> RelationEndPtrs;

	}
}

#endif
