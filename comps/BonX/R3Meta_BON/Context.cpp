#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::ContextImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
std::set<R3Meta_BON::Right4Context> R3Meta_BON::ContextImpl::getInRight4ContextLinks()
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
// returns src R3Meta_BON::Rights
//********************************************************************************
std::multiset<R3Meta_BON::Right> R3Meta_BON::ContextImpl::getRight4ContextSrcs()
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


//********************************************************************************
// 
//********************************************************************************
R3Meta_BON::ContextImpl::Mult_Type R3Meta_BON::ContextImpl::getMult()
{
	std::string val = FCOImpl::getAttribute("Mult")->getStringValue();

	if ( val == "one") return one_Mult_Type;
	else if ( val == "many") return many_Mult_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::ContextImpl::setMult( ContextImpl::Mult_Type val)
{
	std::string str_val = "";

	if ( val == one_Mult_Type) str_val = "one";
	else if ( val == many_Mult_Type) str_val = "many";
	else throw("None of the possible items");

	FCOImpl::getAttribute("Mult")->setStringValue( str_val);
}


//********************************************************************************
// getter for role "Context" among "R3Meta_BON::Context"s
//********************************************************************************
std::set<R3Meta_BON::Context> R3Meta_BON::ContextImpl::getContext()
{
	std::set<R3Meta_BON::Context> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Context");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Context elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Event" among "R3Meta_BON::Event"s
//********************************************************************************
std::set<R3Meta_BON::Event> R3Meta_BON::ContextImpl::getEvent()
{
	std::set<R3Meta_BON::Event> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Event");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Event elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Right" among "R3Meta_BON::Right"s
//********************************************************************************
std::set<R3Meta_BON::Right> R3Meta_BON::ContextImpl::getRight()
{
	std::set<R3Meta_BON::Right> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Right");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Right elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Right4Context" among "R3Meta_BON::Right4Context"s
//********************************************************************************
std::set<R3Meta_BON::Right4Context> R3Meta_BON::ContextImpl::getRight4Context()
{
	std::set<R3Meta_BON::Right4Context> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Right4Context");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Right4Context elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Right4Event" among "R3Meta_BON::Right4Event"s
//********************************************************************************
std::set<R3Meta_BON::Right4Event> R3Meta_BON::ContextImpl::getRight4Event()
{
	std::set<R3Meta_BON::Right4Event> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Right4Event");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Right4Event elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


