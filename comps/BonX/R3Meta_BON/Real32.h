#ifndef R3META_BONREAL32_H
#define R3META_BONREAL32_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   Real32Impl
//*******************************************************************
class Real32Impl :
	  virtual public BON::AtomImpl
	, public RealImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
