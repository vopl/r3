#ifndef R3META_BONCATEGORYORREFERENCE_H
#define R3META_BONCATEGORYORREFERENCE_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   CategoryOrReferenceImpl
//*******************************************************************
class CategoryOrReferenceImpl :
	  virtual public BON::FCOImpl
{
public:

	//
	// connectionEnd getters
	virtual std::multiset<R3Meta_BON::CategoryOrReference> getCategoryInheritanceDsts();
	virtual std::set<R3Meta_BON::CategoryInheritance> getCategoryInheritanceLinks();
	virtual std::multiset<R3Meta_BON::CategoryOrReference> getCategoryInheritanceSrcs();
	virtual std::multiset<R3Meta_BON::CategoryOrReference> getCategoryRelationDsts();
	virtual std::set<R3Meta_BON::CategoryRelation>    getCategoryRelationLinks();
	virtual std::multiset<R3Meta_BON::CategoryOrReference> getCategoryRelationSrcs();
	virtual std::set<R3Meta_BON::CategoryInheritance> getInCategoryInheritanceLinks();
	virtual std::set<R3Meta_BON::CategoryRelation>    getInCategoryRelationLinks();
	virtual std::set<R3Meta_BON::CategoryInheritance> getOutCategoryInheritanceLinks();
	virtual std::set<R3Meta_BON::CategoryRelation>    getOutCategoryRelationLinks();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
