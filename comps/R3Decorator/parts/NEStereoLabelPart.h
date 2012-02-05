#ifndef __NESTEREOLABELPART_H_
#define __NESTEREOLABELPART_H_


#include "StdAfx.h"
#include "StereoLabelPart.h"


namespace Decor {

class NEStereoLabelPart: public DecoratorSDK::StereoLabelPart
{
public:
	NEStereoLabelPart(PartBase* pPart, CComPtr<IMgaCommonDecoratorEvents> eventSink);
	virtual ~NEStereoLabelPart();

	virtual void	ExecuteOperation			(const CString& newString);
};

}; // namespace Decor

#endif //__NESTEREOLABELPART_H_
