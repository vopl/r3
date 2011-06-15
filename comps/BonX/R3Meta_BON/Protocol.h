#ifndef R3META_BONPROTOCOL_H
#define R3META_BONPROTOCOL_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   ProtocolImpl
//*******************************************************************
class ProtocolImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<R3Meta_BON::Context>   getContext();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif