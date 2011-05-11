#ifndef R3META_BONSCANTY_H
#define R3META_BONSCANTY_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   ScantyImpl
//*******************************************************************
class ScantyImpl :
	  virtual public BON::ModelImpl
	, public FieldImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<R3Meta_BON::ScantyValue>         getScantyValue();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
