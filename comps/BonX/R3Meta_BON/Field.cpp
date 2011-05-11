#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// returns dst R3Meta_BON::Indexs
//********************************************************************************
std::multiset<R3Meta_BON::Index> R3Meta_BON::FieldImpl::getIndexOnCategoryFieldDsts()
{
	std::multiset<R3Meta_BON::Index> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("IndexOnCategoryField");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			R3Meta_BON::Index dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<R3Meta_BON::IndexOnCategoryField> R3Meta_BON::FieldImpl::getOutIndexOnCategoryFieldLinks()
{
	std::set<R3Meta_BON::IndexOnCategoryField> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		R3Meta_BON::IndexOnCategoryField c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


