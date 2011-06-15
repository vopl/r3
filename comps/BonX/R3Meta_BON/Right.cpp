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
std::set<R3Meta_BON::Right4Event> R3Meta_BON::RightImpl::getOutRight4EventLinks()
{
	std::set<R3Meta_BON::Right4Event> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		R3Meta_BON::Right4Event c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst R3Meta_BON::Contexts
//********************************************************************************
std::multiset<R3Meta_BON::Context> R3Meta_BON::RightImpl::getRight4ContextDsts()
{
	std::multiset<R3Meta_BON::Context> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Right4Context");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			R3Meta_BON::Context dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst R3Meta_BON::EventOrReferences
//********************************************************************************
std::multiset<R3Meta_BON::EventOrReference> R3Meta_BON::RightImpl::getRight4EventDsts()
{
	std::multiset<R3Meta_BON::EventOrReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Right4Event");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			R3Meta_BON::EventOrReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


