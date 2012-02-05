#ifndef R3META_BONCATEGORYREFERENCE_H
#define R3META_BONCATEGORYREFERENCE_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   CategoryReferenceImpl
//*******************************************************************
class CategoryReferenceImpl :
	  virtual public BON::ReferenceImpl
	, public CategoryOrReferenceImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// ref getters
	virtual R3Meta_BON::Category            getCategory();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
