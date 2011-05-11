#ifndef R3META_BONFIELD_H
#define R3META_BONFIELD_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   FieldImpl
//*******************************************************************
class FieldImpl :
	  public CategoryMemberImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual std::multiset<R3Meta_BON::Index>          getIndexOnCategoryFieldDsts();
	virtual std::set<R3Meta_BON::IndexOnCategoryField> getOutIndexOnCategoryFieldLinks();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
