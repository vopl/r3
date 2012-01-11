#ifndef R3META_BONBITSET8_H
#define R3META_BONBITSET8_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   Bitset8Impl
//*******************************************************************
class Bitset8Impl :
	  public BitsetImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
