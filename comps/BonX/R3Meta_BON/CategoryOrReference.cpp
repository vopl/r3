#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// returns dst R3Meta_BON::CategoryOrReferences
//********************************************************************************
std::multiset<R3Meta_BON::CategoryOrReference> R3Meta_BON::CategoryOrReferenceImpl::getCategoryInheritanceDsts()
{
	std::multiset<R3Meta_BON::CategoryOrReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("CategoryInheritance");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			R3Meta_BON::CategoryOrReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<R3Meta_BON::CategoryInheritance> R3Meta_BON::CategoryOrReferenceImpl::getCategoryInheritanceLinks()
{
	std::set<R3Meta_BON::CategoryInheritance> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		R3Meta_BON::CategoryInheritance c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src R3Meta_BON::CategoryOrReferences
//********************************************************************************
std::multiset<R3Meta_BON::CategoryOrReference> R3Meta_BON::CategoryOrReferenceImpl::getCategoryInheritanceSrcs()
{
	std::multiset<R3Meta_BON::CategoryOrReference> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("CategoryInheritance");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			R3Meta_BON::CategoryOrReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// returns dst R3Meta_BON::CategoryOrReferences
//********************************************************************************
std::multiset<R3Meta_BON::CategoryOrReference> R3Meta_BON::CategoryOrReferenceImpl::getCategoryRelationDsts()
{
	std::multiset<R3Meta_BON::CategoryOrReference> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("CategoryRelation");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			R3Meta_BON::CategoryOrReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<R3Meta_BON::CategoryRelation> R3Meta_BON::CategoryOrReferenceImpl::getCategoryRelationLinks()
{
	std::set<R3Meta_BON::CategoryRelation> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		R3Meta_BON::CategoryRelation c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src R3Meta_BON::CategoryOrReferences
//********************************************************************************
std::multiset<R3Meta_BON::CategoryOrReference> R3Meta_BON::CategoryOrReferenceImpl::getCategoryRelationSrcs()
{
	std::multiset<R3Meta_BON::CategoryOrReference> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("CategoryRelation");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			R3Meta_BON::CategoryOrReference dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<R3Meta_BON::CategoryInheritance> R3Meta_BON::CategoryOrReferenceImpl::getInCategoryInheritanceLinks()
{
	std::set<R3Meta_BON::CategoryInheritance> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		R3Meta_BON::CategoryInheritance c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<R3Meta_BON::CategoryRelation> R3Meta_BON::CategoryOrReferenceImpl::getInCategoryRelationLinks()
{
	std::set<R3Meta_BON::CategoryRelation> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		R3Meta_BON::CategoryRelation c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<R3Meta_BON::CategoryInheritance> R3Meta_BON::CategoryOrReferenceImpl::getOutCategoryInheritanceLinks()
{
	std::set<R3Meta_BON::CategoryInheritance> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		R3Meta_BON::CategoryInheritance c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<R3Meta_BON::CategoryRelation> R3Meta_BON::CategoryOrReferenceImpl::getOutCategoryRelationLinks()
{
	std::set<R3Meta_BON::CategoryRelation> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		R3Meta_BON::CategoryRelation c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


