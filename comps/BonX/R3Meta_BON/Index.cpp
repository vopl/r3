#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::IndexImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Atom
	pVisitor->visitAtom( BON::Atom( this));

}


//********************************************************************************
// 
//********************************************************************************
std::set<R3Meta_BON::IndexOnCategoryField> R3Meta_BON::IndexImpl::getInIndexOnCategoryFieldLinks()
{
	std::set<R3Meta_BON::IndexOnCategoryField> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		R3Meta_BON::IndexOnCategoryField c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src R3Meta_BON::Fields
//********************************************************************************
std::multiset<R3Meta_BON::Field> R3Meta_BON::IndexImpl::getIndexOnCategoryFieldSrcs()
{
	std::multiset<R3Meta_BON::Field> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("IndexOnCategoryField");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			R3Meta_BON::Field dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
R3Meta_BON::IndexImpl::IndexType_Type R3Meta_BON::IndexImpl::getIndexType()
{
	std::string val = FCOImpl::getAttribute("IndexType")->getStringValue();

	if ( val == "tree") return tree_IndexType_Type;
	else if ( val == "hash") return hash_IndexType_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::IndexImpl::setIndexType( IndexImpl::IndexType_Type val)
{
	std::string str_val = "";

	if ( val == tree_IndexType_Type) str_val = "tree";
	else if ( val == hash_IndexType_Type) str_val = "hash";
	else throw("None of the possible items");

	FCOImpl::getAttribute("IndexType")->setStringValue( str_val);
}


