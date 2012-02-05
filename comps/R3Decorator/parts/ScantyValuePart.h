#ifndef __SCANTYVALUEPART_H_
#define __SCANTYVALUEPART_H_


#include "StdAfx.h"
#include "ClassComplexPart.h"


namespace Decor
{

class ScantyValuePart
	: public DecoratorSDK::ClassComplexPart
{
public:
	ScantyValuePart(DecoratorSDK::PartBase* pPart, CComPtr<IMgaCommonDecoratorEvents> eventSink);
	virtual ~ScantyValuePart();

// =============== resembles IMgaElementDecorator
public:
	virtual void	InitializeEx				(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart,
												 CComPtr<IMgaFCO>& pFCO, HWND parentWnd, DecoratorSDK::PreferenceMap& preferences);

	virtual void	CollectAttributes			(CComPtr<IMgaFCO> mgaFco = NULL);
};

};

#endif
