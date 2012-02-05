#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::Bitset128Impl::accept( BON::Visitor *pVisitor)
{
	// visit the Atom
	pVisitor->visitAtom( BON::Atom( this));

}


