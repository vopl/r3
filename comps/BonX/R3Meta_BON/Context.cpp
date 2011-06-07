#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::ContextImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "Context" among "ContextOrReference"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Context> R3Meta_BON::ContextImpl::getContext()
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
std::set<R3Meta_BON::ContextOrReference> R3Meta_BON::ContextImpl::getContextOrReference()
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
std::set<R3Meta_BON::ContextReference> R3Meta_BON::ContextImpl::getContextReference()
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


//********************************************************************************
// getter for role "Method" among "R3Meta_BON::Method"s
//********************************************************************************
std::set<R3Meta_BON::Method> R3Meta_BON::ContextImpl::getMethod()
{
	std::set<R3Meta_BON::Method> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Method");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Method elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "MethodResult" among "R3Meta_BON::MethodResult"s
//********************************************************************************
std::set<R3Meta_BON::MethodResult> R3Meta_BON::ContextImpl::getMethodResult()
{
	std::set<R3Meta_BON::MethodResult> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("MethodResult");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::MethodResult elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Right" among "R3Meta_BON::Right"s
//********************************************************************************
std::set<R3Meta_BON::Right> R3Meta_BON::ContextImpl::getRight()
{
	std::set<R3Meta_BON::Right> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Right");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Right elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Right4Context" among "R3Meta_BON::Right4Context"s
//********************************************************************************
std::set<R3Meta_BON::Right4Context> R3Meta_BON::ContextImpl::getRight4Context()
{
	std::set<R3Meta_BON::Right4Context> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Right4Context");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Right4Context elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Right4Method" among "R3Meta_BON::Right4Method"s
//********************************************************************************
std::set<R3Meta_BON::Right4Method> R3Meta_BON::ContextImpl::getRight4Method()
{
	std::set<R3Meta_BON::Right4Method> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Right4Method");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Right4Method elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


