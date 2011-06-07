#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::MethodImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Atom
	pVisitor->visitAtom( BON::Atom( this));

}


//********************************************************************************
// 
//********************************************************************************
std::set<R3Meta_BON::Right4Method> R3Meta_BON::MethodImpl::getInRight4MethodLinks()
{
	std::set<R3Meta_BON::Right4Method> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		R3Meta_BON::Right4Method c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst R3Meta_BON::ContextOrReferences
//********************************************************************************
std::multiset<R3Meta_BON::ContextOrReference> R3Meta_BON::MethodImpl::getMethodResultDsts()
{
	std::multiset<R3Meta_BON::ContextOrReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("MethodResult");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			R3Meta_BON::ContextOrReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<R3Meta_BON::MethodResult> R3Meta_BON::MethodImpl::getOutMethodResultLinks()
{
	std::set<R3Meta_BON::MethodResult> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		R3Meta_BON::MethodResult c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src R3Meta_BON::Rights
//********************************************************************************
std::multiset<R3Meta_BON::Right> R3Meta_BON::MethodImpl::getRight4MethodSrcs()
{
	std::multiset<R3Meta_BON::Right> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Right4Method");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			R3Meta_BON::Right dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
bool R3Meta_BON::MethodImpl::isCanTransite() 
{
	return FCOImpl::getAttribute("CanTransite")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::MethodImpl::setCanTransite( bool val)
{
	FCOImpl::getAttribute("CanTransite")->setBooleanValue( val);
}


