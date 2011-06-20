#ifndef __EVENTATTRIBUTEPART_H_
#define __EVENTATTRIBUTEPART_H_


#include "StdAfx.h"
#include "AttributePart.h"


namespace Decor {

class EventAttributePart: public DecoratorSDK::AttributePart
{
protected:
	CComPtr<IMgaFCO>	m_spActualFCO;

public:
	EventAttributePart(
		PartBase* pPart, 
		CComPtr<IMgaCommonDecoratorEvents> eventSink,
		const CString& nameStr, const CString& typeStr,
		CComPtr<IMgaFCO>& pFCO);
	virtual ~EventAttributePart();

	void InitializeEx(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart, CComPtr<IMgaFCO>& pFCO,
		HWND parentWnd, DecoratorSDK::PreferenceMap& preferences);

	virtual void	ExecuteOperation			(const CString& newString);
	virtual bool	IsLesser					(const AttributePart* other);
	virtual void	Draw						(CDC* pDC, Gdiplus::Graphics* gdip);
};

};

#endif
