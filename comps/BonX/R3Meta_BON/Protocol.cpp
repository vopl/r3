#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::ProtocolImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "Context" among "R3Meta_BON::Context"s
//********************************************************************************
std::set<R3Meta_BON::Context> R3Meta_BON::ProtocolImpl::getContext()
{
	std::set<R3Meta_BON::Context> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Context");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Context elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


