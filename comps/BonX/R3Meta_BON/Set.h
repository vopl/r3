#ifndef R3META_BONSET_H
#define R3META_BONSET_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   SetImpl
//*******************************************************************
class SetImpl :
	  public ScantyImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
