#ifndef R3META_BONRIGHT4EVENT_H
#define R3META_BONRIGHT4EVENT_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   Right4EventImpl
//*******************************************************************
class Right4EventImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// connectionEnd getters
	virtual R3Meta_BON::EventOrReference    getDst();
	virtual R3Meta_BON::Right               getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
