#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::CategoryRelationImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Connection
	pVisitor->visitConnection( BON::Connection( this));

}


//********************************************************************************
// 
//********************************************************************************
R3Meta_BON::CategoryRelationImpl::Multiplier1_Type R3Meta_BON::CategoryRelationImpl::getMultiplier1()
{
	std::string val = FCOImpl::getAttribute("Multiplier1")->getStringValue();

	if ( val == "1") return _1_Multiplier1_Type;
	else if ( val == "n") return n_Multiplier1_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
R3Meta_BON::CategoryRelationImpl::Multiplier2_Type R3Meta_BON::CategoryRelationImpl::getMultiplier2()
{
	std::string val = FCOImpl::getAttribute("Multiplier2")->getStringValue();

	if ( val == "1") return _1_Multiplier2_Type;
	else if ( val == "n") return n_Multiplier2_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
std::string R3Meta_BON::CategoryRelationImpl::getName1() 
{
	return FCOImpl::getAttribute("Name1")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string R3Meta_BON::CategoryRelationImpl::getName2() 
{
	return FCOImpl::getAttribute("Name2")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::CategoryRelationImpl::setMultiplier1( CategoryRelationImpl::Multiplier1_Type val)
{
	std::string str_val = "";

	if ( val == _1_Multiplier1_Type) str_val = "1";
	else if ( val == n_Multiplier1_Type) str_val = "n";
	else throw("None of the possible items");

	FCOImpl::getAttribute("Multiplier1")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::CategoryRelationImpl::setMultiplier2( CategoryRelationImpl::Multiplier2_Type val)
{
	std::string str_val = "";

	if ( val == _1_Multiplier2_Type) str_val = "1";
	else if ( val == n_Multiplier2_Type) str_val = "n";
	else throw("None of the possible items");

	FCOImpl::getAttribute("Multiplier2")->setStringValue( str_val);
}


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::CategoryRelationImpl::setName1( const std::string& val)
{
	FCOImpl::getAttribute("Name1")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::CategoryRelationImpl::setName2( const std::string& val)
{
	FCOImpl::getAttribute("Name2")->setStringValue( val);
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to R3Meta_BON::CategoryOrReference
//********************************************************************************
R3Meta_BON::CategoryOrReference R3Meta_BON::CategoryRelationImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	R3Meta_BON::CategoryOrReference sp( ce);
	if ( sp)
		return sp;

	R3Meta_BON::CategoryOrReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to R3Meta_BON::CategoryOrReference
//********************************************************************************
R3Meta_BON::CategoryOrReference R3Meta_BON::CategoryRelationImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	R3Meta_BON::CategoryOrReference sp( ce);
	if ( sp)
		return sp;

	R3Meta_BON::CategoryOrReference empty;
	return empty;
}


