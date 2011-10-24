#ifndef _DBMETA_RELATIONEND_HPP_
#define _DBMETA_RELATIONEND_HPP_

#include "dbMeta/common.hpp"

namespace dbMeta
{
	enum ERelationMult
	{
		ermMany,
		ermOne,
	};

	//////////////////////////////////////////////////////////////////////////
	class RelationEnd
	{
		CategoryPtr		__category;
		CategoryPtrs	__categories;
		friend class Relation;

	public:
		RelationEnd(const Relation &relation, ERelationMult mult);

		const RelationPtr	_relation;
		const ERelationMult	_mult;

		const CategoryPtr	&_category;
		const CategoryPtrs	_categories;
	};
}

#endif
