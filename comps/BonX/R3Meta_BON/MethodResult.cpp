#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::MethodResultImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Connection
	pVisitor->visitConnection( BON::Connection( this));

}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to R3Meta_BON::ContextOrReference
//********************************************************************************
R3Meta_BON::ContextOrReference R3Meta_BON::MethodResultImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	R3Meta_BON::ContextOrReference sp( ce);
	if ( sp)
		return sp;

	R3Meta_BON::ContextOrReference empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to R3Meta_BON::Method
//********************************************************************************
R3Meta_BON::Method R3Meta_BON::MethodResultImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	R3Meta_BON::Method sp( ce);
	if ( sp)
		return sp;

	R3Meta_BON::Method empty;
	return empty;
}

