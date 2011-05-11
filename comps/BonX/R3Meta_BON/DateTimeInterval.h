#ifndef R3META_BONDATETIMEINTERVAL_H
#define R3META_BONDATETIMEINTERVAL_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   DateTimeIntervalImpl
//*******************************************************************
class DateTimeIntervalImpl :
	  virtual public BON::AtomImpl
	, public DateTimeImpl
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
