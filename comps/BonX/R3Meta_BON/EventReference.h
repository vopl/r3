#ifndef R3META_BONEVENTREFERENCE_H
#define R3META_BONEVENTREFERENCE_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   EventReferenceImpl
//*******************************************************************
class EventReferenceImpl :
	  virtual public BON::ReferenceImpl
	, public EventOrReferenceImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// ref getters
	virtual R3Meta_BON::Event               getEvent();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
