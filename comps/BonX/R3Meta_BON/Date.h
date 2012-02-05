#ifndef R3META_BONDATE_H
#define R3META_BONDATE_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   DateImpl
//*******************************************************************
class DateImpl :
	  virtual public BON::AtomImpl
	, public DateTimeValueImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
