#ifndef R3META_BONBITSET512_H
#define R3META_BONBITSET512_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   Bitset512Impl
//*******************************************************************
class Bitset512Impl :
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
