#ifndef R3META_BONRIGHT4CONTEXT_H
#define R3META_BONRIGHT4CONTEXT_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   Right4ContextImpl
//*******************************************************************
class Right4ContextImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// connectionEnd getters
	virtual R3Meta_BON::ContextOrReference  getDst();
	virtual R3Meta_BON::Right               getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
