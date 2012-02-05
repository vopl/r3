#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::IndexOnCategoryFieldImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Connection
	pVisitor->visitConnection( BON::Connection( this));

}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to R3Meta_BON::Index
//********************************************************************************
R3Meta_BON::Index R3Meta_BON::IndexOnCategoryFieldImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	R3Meta_BON::Index sp( ce);
	if ( sp)
		return sp;

	R3Meta_BON::Index empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to R3Meta_BON::Field
//********************************************************************************
R3Meta_BON::Field R3Meta_BON::IndexOnCategoryFieldImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	R3Meta_BON::Field sp( ce);
	if ( sp)
		return sp;

	R3Meta_BON::Field empty;
	return empty;
}


