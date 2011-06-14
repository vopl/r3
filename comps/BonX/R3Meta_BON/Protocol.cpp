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
// getter for role "Context" among "ContextOrReference"s and its descendants
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


//********************************************************************************
// aggregated getter for role "R3Meta_BON::" among "R3Meta_BON::ContextOrReference"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::ContextOrReference> R3Meta_BON::ProtocolImpl::getContextOrReference()
{
	std::set<R3Meta_BON::ContextOrReference> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("Context");
	roles_vec[1] = ModelImpl::getChildFCOsAs("ContextReference");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			R3Meta_BON::ContextOrReference elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "ContextReference" among "ContextOrReference"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::ContextReference> R3Meta_BON::ProtocolImpl::getContextReference()
{
	std::set<R3Meta_BON::ContextReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ContextReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::ContextReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


