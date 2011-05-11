#ifndef R3META_BONTIMESTAMP_H
#define R3META_BONTIMESTAMP_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   TimestampImpl
//*******************************************************************
class TimestampImpl :
	  virtual public BON::AtomImpl
	, public DateTimeValueImpl
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
