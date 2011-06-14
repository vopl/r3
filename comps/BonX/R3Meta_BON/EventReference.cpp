#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::EventReferenceImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Reference
	pVisitor->visitReference( BON::Reference( this));

}


//********************************************************************************
// 
//********************************************************************************
R3Meta_BON::Event R3Meta_BON::EventReferenceImpl::getEvent()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return R3Meta_BON::Event(r);
}


