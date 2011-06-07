#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::RightImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Atom
	pVisitor->visitAtom( BON::Atom( this));

}


//********************************************************************************
// 
//********************************************************************************
std::set<R3Meta_BON::Right4Context> R3Meta_BON::RightImpl::getOutRight4ContextLinks()
{
	std::set<R3Meta_BON::Right4Context> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		R3Meta_BON::Right4Context c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<R3Meta_BON::Right4Method> R3Meta_BON::RightImpl::getOutRight4MethodLinks()
{
	std::set<R3Meta_BON::Right4Method> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
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
std::multiset<R3Meta_BON::ContextOrReference> R3Meta_BON::RightImpl::getRight4ContextDsts()
{
	std::multiset<R3Meta_BON::ContextOrReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Right4Context");
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
// returns dst R3Meta_BON::Methods
//********************************************************************************
std::multiset<R3Meta_BON::Method> R3Meta_BON::RightImpl::getRight4MethodDsts()
{
	std::multiset<R3Meta_BON::Method> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Right4Method");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			R3Meta_BON::Method dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


