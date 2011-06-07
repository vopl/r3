#ifndef R3META_BONRIGHT4METHOD_H
#define R3META_BONRIGHT4METHOD_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   Right4MethodImpl
//*******************************************************************
class Right4MethodImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// connectionEnd getters
	virtual R3Meta_BON::Method              getDst();
	virtual R3Meta_BON::Right               getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
