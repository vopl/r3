#ifndef R3META_BONCONTEXT_H
#define R3META_BONCONTEXT_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   ContextImpl
//*******************************************************************
class ContextImpl :
	  virtual public BON::ModelImpl
	, public ContextOrReferenceImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<R3Meta_BON::Context>   getContext();
	virtual std::set<R3Meta_BON::ContextOrReference>  getContextOrReference();
	virtual std::set<R3Meta_BON::ContextReference>    getContextReference();
	virtual std::set<R3Meta_BON::Event>     getEvent();
	virtual std::set<R3Meta_BON::Right>     getRight();
	virtual std::set<R3Meta_BON::Right4Context>       getRight4Context();
	virtual std::set<R3Meta_BON::Right4Event>         getRight4Event();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
