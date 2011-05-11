#ifndef __SCANTYPART_H_
#define __SCANTYPART_H_


#include "StdAfx.h"
#include "ClassComplexPart.h"


namespace Decor
{

class ScantyPart
	: public DecoratorSDK::ClassComplexPart
{
public:
	ScantyPart(DecoratorSDK::PartBase* pPart, CComPtr<IMgaCommonDecoratorEvents> eventSink);
	virtual ~ScantyPart();

// =============== resembles IMgaElementDecorator
public:
	virtual void	InitializeEx				(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart,
												 CComPtr<IMgaFCO>& pFCO, HWND parentWnd, DecoratorSDK::PreferenceMap& preferences);

	virtual void	CollectAttributes			(CComPtr<IMgaFCO> mgaFco = NULL);
};

};

#endif
