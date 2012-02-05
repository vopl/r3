#ifndef __FIELDPART_H_
#define __FIELDPART_H_


#include "StdAfx.h"
#include "ClassComplexPart.h"


namespace Decor
{

class FieldPart
	: public DecoratorSDK::ClassComplexPart
{
public:
	FieldPart(DecoratorSDK::PartBase* pPart, CComPtr<IMgaCommonDecoratorEvents> eventSink);
	virtual ~FieldPart();

// =============== resembles IMgaElementDecorator
public:
	virtual void	InitializeEx				(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart,
												 CComPtr<IMgaFCO>& pFCO, HWND parentWnd, DecoratorSDK::PreferenceMap& preferences);

	virtual void	CollectAttributes			(CComPtr<IMgaFCO> mgaFco = NULL){}
};

};

#endif
