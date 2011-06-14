#ifndef R3META_BONCONTEXTORREFERENCE_H
#define R3META_BONCONTEXTORREFERENCE_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   ContextOrReferenceImpl
//*******************************************************************
class ContextOrReferenceImpl :
	  virtual public BON::FCOImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<R3Meta_BON::Right4Context>       getInRight4ContextLinks();
	virtual std::multiset<R3Meta_BON::Right>          getRight4ContextSrcs();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
