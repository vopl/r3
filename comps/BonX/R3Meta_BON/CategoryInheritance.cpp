#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::CategoryInheritanceImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Connection
	pVisitor->visitConnection( BON::Connection( this));

}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to R3Meta_BON::CategoryOrReference
//********************************************************************************
R3Meta_BON::CategoryOrReference R3Meta_BON::CategoryInheritanceImpl::getDst()
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
R3Meta_BON::CategoryOrReference R3Meta_BON::CategoryInheritanceImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	R3Meta_BON::CategoryOrReference sp( ce);
	if ( sp)
		return sp;

	R3Meta_BON::CategoryOrReference empty;
	return empty;
}


