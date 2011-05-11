#ifndef R3META_BONVIDEO_H
#define R3META_BONVIDEO_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   VideoImpl
//*******************************************************************
class VideoImpl :
	  virtual public BON::AtomImpl
	, public FileImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
