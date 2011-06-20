#ifndef __CONTEXTPART_H_
#define __CONTEXTPART_H_


#include "StdAfx.h"
#include "ClassComplexPart.h"
#include "ContextAttributePart.h"


namespace Decor {

class ContextPart: public DecoratorSDK::ClassComplexPart
{
public:
	ContextPart(DecoratorSDK::PartBase* pPart, CComPtr<IMgaCommonDecoratorEvents> eventSink);
	virtual ~ContextPart();

// =============== resembles IMgaElementDecorator
public:
	virtual void	InitializeEx				(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart,
												 CComPtr<IMgaFCO>& pFCO, HWND parentWnd, DecoratorSDK::PreferenceMap& preferences);

	virtual void	CollectAttributes			(CComPtr<IMgaFCO> mgaFco = NULL);


	void ModifyAttributes(CComPtr<IMgaFCO> mgaFco);
};

};

#endif
