#ifndef __CATEGORYATTRIBUTEPART_H_
#define __CATEGORYATTRIBUTEPART_H_


#include "StdAfx.h"
#include "AttributePart.h"


namespace Decor {

	enum ECategoryAttributeKind
	{
		ecak_own,
		ecak_inherited,
		ecak_separator,
		ecak_enumValue,
		ecak_link,
	};
class CategoryAttributePart: public DecoratorSDK::AttributePart
{
protected:
	CComPtr<IMgaFCO>	m_spActualFCO;
	ECategoryAttributeKind	_kind;

public:
	CategoryAttributePart(
		PartBase* pPart, 
		CComPtr<IMgaCommonDecoratorEvents> eventSink,
		const CString& nameStr, const CString& typeStr, ECategoryAttributeKind	kind,
		CComPtr<IMgaFCO>& pFCO);
	virtual ~CategoryAttributePart();

	void InitializeEx(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart, CComPtr<IMgaFCO>& pFCO,
		HWND parentWnd, DecoratorSDK::PreferenceMap& preferences);

	virtual void	ExecuteOperation			(const CString& newString);
	virtual bool	IsLesser					(const AttributePart* other);
	virtual void	Draw						(CDC* pDC, Gdiplus::Graphics* gdip);
};

};

#endif
