#ifndef R3META_BONINT8_H
#define R3META_BONINT8_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   Int8Impl
//*******************************************************************
class Int8Impl :
	  virtual public BON::AtomImpl
	, public IntImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
