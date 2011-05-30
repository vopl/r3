#ifndef R3META_BONAUDIO_H
#define R3META_BONAUDIO_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   AudioImpl
//*******************************************************************
class AudioImpl :
	  public FileImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
