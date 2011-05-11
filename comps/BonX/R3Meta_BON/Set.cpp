#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::SetImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

	// then its children
	std::set<BON::FCO> children = ModelImpl::getChildFCOs();
	for( std::set<BON::FCO>::const_iterator it = children.begin(); it != children.end(); ++it)
	{
		(*it)->accept( pVisitor);
	}
}


