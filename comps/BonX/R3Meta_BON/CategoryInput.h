#ifndef R3META_BONCATEGORYINPUT_H
#define R3META_BONCATEGORYINPUT_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   CategoryInputImpl
//*******************************************************************
class CategoryInputImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getNodeManager() ;
	virtual std::string getValueAdapter() ;
	virtual void        setNodeManager( const std::string& val);
	virtual void        setValueAdapter( const std::string& val);
	//
	// connectionEnd getters
	virtual R3Meta_BON::CategoryReference   getDst();
	virtual R3Meta_BON::Channel             getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
