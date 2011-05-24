#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::CategoryOutputImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Connection
	pVisitor->visitConnection( BON::Connection( this));

}


//********************************************************************************
// 
//********************************************************************************
std::string R3Meta_BON::CategoryOutputImpl::getNodeManager() 
{
	return FCOImpl::getAttribute("NodeManager")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string R3Meta_BON::CategoryOutputImpl::getValueAdapter() 
{
	return FCOImpl::getAttribute("ValueAdapter")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::CategoryOutputImpl::setNodeManager( const std::string& val)
{
	FCOImpl::getAttribute("NodeManager")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::CategoryOutputImpl::setValueAdapter( const std::string& val)
{
	FCOImpl::getAttribute("ValueAdapter")->setStringValue( val);
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to R3Meta_BON::Channel
//********************************************************************************
R3Meta_BON::Channel R3Meta_BON::CategoryOutputImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	R3Meta_BON::Channel sp( ce);
	if ( sp)
		return sp;

	R3Meta_BON::Channel empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to R3Meta_BON::CategoryReference
//********************************************************************************
R3Meta_BON::CategoryReference R3Meta_BON::CategoryOutputImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	R3Meta_BON::CategoryReference sp( ce);
	if ( sp)
		return sp;

	R3Meta_BON::CategoryReference empty;
	return empty;
}


