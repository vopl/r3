#ifndef R3META_BONDATA_H
#define R3META_BONDATA_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   DataImpl
//*******************************************************************
class DataImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<R3Meta_BON::Category>  getCategory();
	virtual std::set<R3Meta_BON::CategoryInheritance> getCategoryInheritance();
	virtual std::set<R3Meta_BON::CategoryOrReference> getCategoryOrReference();
	virtual std::set<R3Meta_BON::CategoryReference>   getCategoryReference();
	virtual std::set<R3Meta_BON::CategoryRelation>    getCategoryRelation();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
