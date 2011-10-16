#ifndef __CATEGORYSPART_H_
#define __CATEGORYSPART_H_


#include "StdAfx.h"
#include "ClassComplexPart.h"
#include "CategoryAttributePart.h"


namespace Decor {

class CategoryPart: public DecoratorSDK::ClassComplexPart
{
	bool _isReference;
public:
	CategoryPart(DecoratorSDK::PartBase* pPart, CComPtr<IMgaCommonDecoratorEvents> eventSink);
	virtual ~CategoryPart();

// =============== resembles IMgaElementDecorator
public:
	virtual void	InitializeEx				(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart,
												 CComPtr<IMgaFCO>& pFCO, HWND parentWnd, DecoratorSDK::PreferenceMap& preferences);

	virtual void	CollectAttributes			(CComPtr<IMgaFCO> mgaFco = NULL);

	typedef std::set<CComPtr<IMgaFCO> > TSFco;
	void CollectBases(CComPtr<IMgaFCO> from, TSFco &bases);

	void AddAttributes(CComPtr<IMgaFCO> mgaFco, ECategoryAttributeKind kind);
	void AddLinks(CComPtr<IMgaFCO> mgaFco);

	void ModifyAttributes(CComPtr<IMgaFCO> mgaFco);

	CComPtr<IMgaFCO> Dereference(CComPtr<IMgaFCO> fco);
};

};

#endif
