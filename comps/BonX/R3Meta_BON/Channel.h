#ifndef R3META_BONCHANNEL_H
#define R3META_BONCHANNEL_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   ChannelImpl
//*******************************************************************
class ChannelImpl :
	  virtual public BON::AtomImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::multiset<R3Meta_BON::CategoryReference> getCategoryInputDsts();
	virtual std::multiset<R3Meta_BON::CategoryReference> getCategoryOutputSrcs();
	virtual std::set<R3Meta_BON::CategoryOutput>      getInCategoryOutputLinks();
	virtual std::set<R3Meta_BON::CategoryInput>       getOutCategoryInputLinks();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
