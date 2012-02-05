#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::CategoryReferenceImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Reference
	pVisitor->visitReference( BON::Reference( this));

}


//********************************************************************************
// 
//********************************************************************************
R3Meta_BON::Category R3Meta_BON::CategoryReferenceImpl::getCategory()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return R3Meta_BON::Category(r);
}


