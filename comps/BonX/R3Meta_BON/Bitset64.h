#ifndef R3META_BONBITSET64_H
#define R3META_BONBITSET64_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   Bitset64Impl
//*******************************************************************
class Bitset64Impl :
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
