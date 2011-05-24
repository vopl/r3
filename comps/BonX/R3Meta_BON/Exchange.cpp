#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::ExchangeImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "CategoryInput" among "R3Meta_BON::CategoryInput"s
//********************************************************************************
std::set<R3Meta_BON::CategoryInput> R3Meta_BON::ExchangeImpl::getCategoryInput()
{
	std::set<R3Meta_BON::CategoryInput> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CategoryInput");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::CategoryInput elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "CategoryOutput" among "R3Meta_BON::CategoryOutput"s
//********************************************************************************
std::set<R3Meta_BON::CategoryOutput> R3Meta_BON::ExchangeImpl::getCategoryOutput()
{
	std::set<R3Meta_BON::CategoryOutput> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CategoryOutput");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::CategoryOutput elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "CategoryReference" among "R3Meta_BON::CategoryReference"s
//********************************************************************************
std::set<R3Meta_BON::CategoryReference> R3Meta_BON::ExchangeImpl::getCategoryReference()
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
// getter for role "Channel" among "R3Meta_BON::Channel"s
//********************************************************************************
std::set<R3Meta_BON::Channel> R3Meta_BON::ExchangeImpl::getChannel()
{
	std::set<R3Meta_BON::Channel> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Channel");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Channel elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


