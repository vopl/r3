#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::ScantyImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "ScantyValue" among "R3Meta_BON::ScantyValue"s
//********************************************************************************
std::set<R3Meta_BON::ScantyValue> R3Meta_BON::ScantyImpl::getScantyValue()
{
	std::set<R3Meta_BON::ScantyValue> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ScantyValue");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::ScantyValue elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


