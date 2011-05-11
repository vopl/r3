#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::ScantyValueImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Atom
	pVisitor->visitAtom( BON::Atom( this));

}


//********************************************************************************
// 
//********************************************************************************
std::string R3Meta_BON::ScantyValueImpl::getLongDescription() 
{
	return FCOImpl::getAttribute("LongDescription")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string R3Meta_BON::ScantyValueImpl::getShortDescription() 
{
	return FCOImpl::getAttribute("ShortDescription")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::ScantyValueImpl::setLongDescription( const std::string& val)
{
	FCOImpl::getAttribute("LongDescription")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::ScantyValueImpl::setShortDescription( const std::string& val)
{
	FCOImpl::getAttribute("ShortDescription")->setStringValue( val);
}


