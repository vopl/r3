#ifndef R3META_BONMONEY_H
#define R3META_BONMONEY_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   MoneyImpl
//*******************************************************************
class MoneyImpl :
	  virtual public BON::AtomImpl
	, public SimpleImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
