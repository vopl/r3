#ifndef R3META_BONCONTEXTREFERENCE_H
#define R3META_BONCONTEXTREFERENCE_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   ContextReferenceImpl
//*******************************************************************
class ContextReferenceImpl :
	  virtual public BON::ReferenceImpl
	, public ContextOrReferenceImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// ref getters
	virtual R3Meta_BON::Context             getContext();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
