#ifndef R3META_BONREAL64_H
#define R3META_BONREAL64_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   Real64Impl
//*******************************************************************
class Real64Impl :
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
