#ifndef R3META_BONSCANTYVALUE_H
#define R3META_BONSCANTYVALUE_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   ScantyValueImpl
//*******************************************************************
class ScantyValueImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getLongDescription() ;
	virtual std::string getShortDescription() ;
	virtual void        setLongDescription( const std::string& val);
	virtual void        setShortDescription( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
