#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
std::set<R3Meta_BON::MethodResult> R3Meta_BON::ContextOrReferenceImpl::getInMethodResultLinks()
{
	std::set<R3Meta_BON::MethodResult> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
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
// 
//********************************************************************************
std::set<R3Meta_BON::Right4Context> R3Meta_BON::ContextOrReferenceImpl::getInRight4ContextLinks()
{
	std::set<R3Meta_BON::Right4Context> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
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
// returns src R3Meta_BON::Methods
//********************************************************************************
std::multiset<R3Meta_BON::Method> R3Meta_BON::ContextOrReferenceImpl::getMethodResultSrcs()
{
	std::multiset<R3Meta_BON::Method> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("MethodResult");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			R3Meta_BON::Method dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src R3Meta_BON::Rights
//********************************************************************************
std::multiset<R3Meta_BON::Right> R3Meta_BON::ContextOrReferenceImpl::getRight4ContextSrcs()
{
	std::multiset<R3Meta_BON::Right> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Right4Context");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			R3Meta_BON::Right dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


