#ifndef R3META_BONLOGIC_H
#define R3META_BONLOGIC_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   LogicImpl
//*******************************************************************
class LogicImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<R3Meta_BON::Context>   getContext();
	virtual std::set<R3Meta_BON::ContextOrReference>  getContextOrReference();
	virtual std::set<R3Meta_BON::ContextReference>    getContextReference();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
