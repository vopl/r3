#ifndef R3META_BONRIGHT_H
#define R3META_BONRIGHT_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   RightImpl
//*******************************************************************
class RightImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<R3Meta_BON::Right4Context>       getOutRight4ContextLinks();
	virtual std::set<R3Meta_BON::Right4Event>         getOutRight4EventLinks();
	virtual std::multiset<R3Meta_BON::ContextOrReference> getRight4ContextDsts();
	virtual std::multiset<R3Meta_BON::EventOrReference> getRight4EventDsts();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
