#ifndef R3META_BONBITSET256_H
#define R3META_BONBITSET256_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   Bitset256Impl
//*******************************************************************
class Bitset256Impl :
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
