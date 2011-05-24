#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::ChannelImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Atom
	pVisitor->visitAtom( BON::Atom( this));

}


//********************************************************************************
// returns dst R3Meta_BON::CategoryReferences
//********************************************************************************
std::multiset<R3Meta_BON::CategoryReference> R3Meta_BON::ChannelImpl::getCategoryInputDsts()
{
	std::multiset<R3Meta_BON::CategoryReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("CategoryInput");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			R3Meta_BON::CategoryReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns src R3Meta_BON::CategoryReferences
//********************************************************************************
std::multiset<R3Meta_BON::CategoryReference> R3Meta_BON::ChannelImpl::getCategoryOutputSrcs()
{
	std::multiset<R3Meta_BON::CategoryReference> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("CategoryOutput");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			R3Meta_BON::CategoryReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<R3Meta_BON::CategoryOutput> R3Meta_BON::ChannelImpl::getInCategoryOutputLinks()
{
	std::set<R3Meta_BON::CategoryOutput> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
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
std::set<R3Meta_BON::CategoryInput> R3Meta_BON::ChannelImpl::getOutCategoryInputLinks()
{
	std::set<R3Meta_BON::CategoryInput> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		R3Meta_BON::CategoryInput c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


