#ifndef R3META_BONVARIANT_H
#define R3META_BONVARIANT_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   VariantImpl
//*******************************************************************
class VariantImpl :
	  virtual public BON::AtomImpl
	, public SimpleImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
