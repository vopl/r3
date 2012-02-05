#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::SchemaImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "Category" among "CategoryOrReference"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Category> R3Meta_BON::SchemaImpl::getCategory()
{
	std::set<R3Meta_BON::Category> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Category");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Category elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "CategoryInheritance" among "R3Meta_BON::CategoryInheritance"s
//********************************************************************************
std::set<R3Meta_BON::CategoryInheritance> R3Meta_BON::SchemaImpl::getCategoryInheritance()
{
	std::set<R3Meta_BON::CategoryInheritance> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CategoryInheritance");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::CategoryInheritance elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "R3Meta_BON::" among "R3Meta_BON::CategoryOrReference"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::CategoryOrReference> R3Meta_BON::SchemaImpl::getCategoryOrReference()
{
	std::set<R3Meta_BON::CategoryOrReference> res;
	const int len = 2;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("Category");
	roles_vec[1] = ModelImpl::getChildFCOsAs("CategoryReference");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			R3Meta_BON::CategoryOrReference elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "CategoryReference" among "CategoryOrReference"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::CategoryReference> R3Meta_BON::SchemaImpl::getCategoryReference()
{
	std::set<R3Meta_BON::CategoryReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CategoryReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::CategoryReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "CategoryRelation" among "R3Meta_BON::CategoryRelation"s
//********************************************************************************
std::set<R3Meta_BON::CategoryRelation> R3Meta_BON::SchemaImpl::getCategoryRelation()
{
	std::set<R3Meta_BON::CategoryRelation> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CategoryRelation");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::CategoryRelation elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


