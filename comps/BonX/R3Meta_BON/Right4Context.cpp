#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::Right4ContextImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Connection
	pVisitor->visitConnection( BON::Connection( this));

}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to R3Meta_BON::Context
//********************************************************************************
R3Meta_BON::Context R3Meta_BON::Right4ContextImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	R3Meta_BON::Context sp( ce);
	if ( sp)
		return sp;

	R3Meta_BON::Context empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to R3Meta_BON::Right
//********************************************************************************
R3Meta_BON::Right R3Meta_BON::Right4ContextImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	R3Meta_BON::Right sp( ce);
	if ( sp)
		return sp;

	R3Meta_BON::Right empty;
	return empty;
}


