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
// returns src R3Meta_BON::Channels
//********************************************************************************
std::multiset<R3Meta_BON::Channel> R3Meta_BON::CategoryReferenceImpl::getCategoryInputSrcs()
{
	std::multiset<R3Meta_BON::Channel> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("CategoryInput");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			R3Meta_BON::Channel dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst R3Meta_BON::Channels
//********************************************************************************
std::multiset<R3Meta_BON::Channel> R3Meta_BON::CategoryReferenceImpl::getCategoryOutputDsts()
{
	std::multiset<R3Meta_BON::Channel> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("CategoryOutput");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			R3Meta_BON::Channel dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<R3Meta_BON::CategoryInput> R3Meta_BON::CategoryReferenceImpl::getInCategoryInputLinks()
{
	std::set<R3Meta_BON::CategoryInput> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		R3Meta_BON::CategoryInput c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<R3Meta_BON::CategoryOutput> R3Meta_BON::CategoryReferenceImpl::getOutCategoryOutputLinks()
{
	std::set<R3Meta_BON::CategoryOutput> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		R3Meta_BON::CategoryOutput c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
R3Meta_BON::Category R3Meta_BON::CategoryReferenceImpl::getCategory()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return R3Meta_BON::Category(r);
}


