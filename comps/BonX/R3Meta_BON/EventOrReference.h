#ifndef R3META_BONEVENTORREFERENCE_H
#define R3META_BONEVENTORREFERENCE_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   EventOrReferenceImpl
//*******************************************************************
class EventOrReferenceImpl :
	  virtual public BON::FCOImpl
{
public:

	//
	// connectionEnd getters
	virtual std::set<R3Meta_BON::Right4Event>         getInRight4EventLinks();
	virtual std::multiset<R3Meta_BON::Right>          getRight4EventSrcs();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
