#ifndef R3META_BONEXCHANGE_H
#define R3META_BONEXCHANGE_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   ExchangeImpl
//*******************************************************************
class ExchangeImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<R3Meta_BON::CategoryInput>       getCategoryInput();
	virtual std::set<R3Meta_BON::CategoryOutput>      getCategoryOutput();
	virtual std::set<R3Meta_BON::CategoryReference>   getCategoryReference();
	virtual std::set<R3Meta_BON::Channel>   getChannel();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
