#ifndef R3META_BONCATEGORYINHERITANCE_H
#define R3META_BONCATEGORYINHERITANCE_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   CategoryInheritanceImpl
//*******************************************************************
class CategoryInheritanceImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// connectionEnd getters
	virtual R3Meta_BON::CategoryOrReference getDst();
	virtual R3Meta_BON::CategoryOrReference getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
