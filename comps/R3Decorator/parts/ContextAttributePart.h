#ifndef __CONTEXTATTRIBUTEPART_H_
#define __CONTEXTATTRIBUTEPART_H_


#include "StdAfx.h"
#include "AttributePart.h"


namespace Decor {

	enum EContextAttributeKind
	{
		ecoak_event,
		ecoak_context,
		ecoak_separator,
	};
class ContextAttributePart: public DecoratorSDK::AttributePart
{
protected:
	CComPtr<IMgaFCO>	m_spActualFCO;
	EContextAttributeKind	_kind;

public:
	ContextAttributePart(
		PartBase* pPart, 
		CComPtr<IMgaCommonDecoratorEvents> eventSink,
		const CString& nameStr, const CString& typeStr, EContextAttributeKind	kind,
		CComPtr<IMgaFCO>& pFCO);
	virtual ~ContextAttributePart();

	void InitializeEx(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart, CComPtr<IMgaFCO>& pFCO,
		HWND parentWnd, DecoratorSDK::PreferenceMap& preferences);

	virtual void	ExecuteOperation			(const CString& newString);
	virtual bool	IsLesser					(const AttributePart* other);
	virtual void	Draw						(CDC* pDC, Gdiplus::Graphics* gdip);
};

};

#endif
