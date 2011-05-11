#ifndef R3META_BONINT16_H
#define R3META_BONINT16_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   Int16Impl
//*******************************************************************
class Int16Impl :
	  virtual public BON::AtomImpl
	, public IntImpl
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
