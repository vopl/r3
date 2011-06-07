#ifndef R3META_BONMETHOD_H
#define R3META_BONMETHOD_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   MethodImpl
//*******************************************************************
class MethodImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<R3Meta_BON::Right4Method>        getInRight4MethodLinks();
	virtual std::multiset<R3Meta_BON::ContextOrReference> getMethodResultDsts();
	virtual std::set<R3Meta_BON::MethodResult>        getOutMethodResultLinks();
	virtual std::multiset<R3Meta_BON::Right>          getRight4MethodSrcs();
	//
	// attribute getters and setters
	virtual bool        isCanTransite() ;
	virtual void        setCanTransite( bool val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
