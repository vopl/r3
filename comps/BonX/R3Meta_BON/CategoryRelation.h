#ifndef R3META_BONCATEGORYRELATION_H
#define R3META_BONCATEGORYRELATION_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   CategoryRelationImpl
//*******************************************************************
class CategoryRelationImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);
	typedef enum
	{
		one_Multiplier1_Type,
		many_Multiplier1_Type
	} Multiplier1_Type;
	typedef enum
	{
		one_Multiplier2_Type,
		many_Multiplier2_Type
	} Multiplier2_Type;

	//
	// attribute getters and setters
	virtual R3Meta_BON::CategoryRelationImpl::Multiplier1_Type getMultiplier1();
	virtual R3Meta_BON::CategoryRelationImpl::Multiplier2_Type getMultiplier2();
	virtual std::string getName1() ;
	virtual std::string getName2() ;
	virtual void        setMultiplier1( CategoryRelationImpl::Multiplier1_Type val);
	virtual void        setMultiplier2( CategoryRelationImpl::Multiplier2_Type val);
	virtual void        setName1( const std::string& val);
	virtual void        setName2( const std::string& val);
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
