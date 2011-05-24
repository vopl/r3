#ifndef R3META_BONINDEXONCATEGORYFIELD_H
#define R3META_BONINDEXONCATEGORYFIELD_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   IndexOnCategoryFieldImpl
//*******************************************************************
class IndexOnCategoryFieldImpl :
	  virtual public BON::ConnectionImpl
	, public CategoryMemberImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// connectionEnd getters
	virtual R3Meta_BON::Index               getDst();
	virtual R3Meta_BON::Field               getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
