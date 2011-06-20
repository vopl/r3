#ifndef __EVENTPART_H_
#define __EVENTPART_H_


#include "StdAfx.h"
#include "ClassComplexPart.h"
#include "EventAttributePart.h"


namespace Decor {

class EventPart: public DecoratorSDK::ClassComplexPart
{
public:
	EventPart(DecoratorSDK::PartBase* pPart, CComPtr<IMgaCommonDecoratorEvents> eventSink);
	virtual ~EventPart();

// =============== resembles IMgaElementDecorator
public:
	virtual void	InitializeEx				(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart,
												 CComPtr<IMgaFCO>& pFCO, HWND parentWnd, DecoratorSDK::PreferenceMap& preferences);

	virtual void	CollectAttributes			(CComPtr<IMgaFCO> mgaFco = NULL);


	void ModifyAttributes(CComPtr<IMgaFCO> mgaFco);
};

};

#endif
