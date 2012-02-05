#include "StdAfx.h"

#include "NEStereoLabelPart.h"
#include "ScantyPart.h"
#include "Resource.h"
#include "DecoratorCusts.h"

#include "CategoryAttributePart.h"
namespace Decor {

ScantyPart::ScantyPart(DecoratorSDK::PartBase* pPart, CComPtr<IMgaCommonDecoratorEvents> eventSink)
	: ClassComplexPart(pPart, eventSink)
{
}

ScantyPart::~ScantyPart()
{
}

// New functions
void ScantyPart::InitializeEx(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart, CComPtr<IMgaFCO>& pFCO,
								HWND parentWnd, DecoratorSDK::PreferenceMap& preferences)
{
	DecoratorSDK::getFacilities().getMetaFCO(pPart, m_spMetaFCO);

	preferences[DecoratorSDK::PREF_LABELFONT]		= DecoratorSDK::PreferenceVariant((long)DecoratorSDK::FONT_PORTNAME);
	preferences[DecoratorSDK::PREF_LABELLENGTH]		= DecoratorSDK::PreferenceVariant((long)-1);
	preferences[DecoratorSDK::PREF_LABELENABLED]	= DecoratorSDK::PreferenceVariant(true);
	preferences[DecoratorSDK::PREF_LABELWRAP]		= DecoratorSDK::PreferenceVariant((long)0);
	preferences[DecoratorSDK::PREF_TEXTOVERRIDE]	= DecoratorSDK::PreferenceVariant(true);

	//установленные вручную размеры запоминаются средой и не переделываются если габарит должен быть изменен
	preferences[DecoratorSDK::PREF_ITEMRESIZABLE]	= DecoratorSDK::PreferenceVariant(false);
	
	preferences[DecoratorSDK::PREF_DECORATOR_MINATTRSIZE] = DecoratorSDK::PreferenceVariant((long)0);
	preferences[DecoratorSDK::PREF_DECORATOR_MARGINX] = DecoratorSDK::PreferenceVariant((long)4);
	preferences[DecoratorSDK::PREF_DECORATOR_MARGINY] = DecoratorSDK::PreferenceVariant((long)2);


	m_StereotypePart = new NEStereoLabelPart(this, m_eventSink);
	CComBSTR name;
	COMTHROW(m_spMetaFCO->get_Name(&name));
	m_StereotypePart->SetText(CString(name));

	if(pFCO)
	{
		m_LabelPart = new DecoratorSDK::ClassLabelPart(this, m_eventSink, true);
		CComBSTR name;
		COMTHROW(pFCO->get_Name(&name));
		m_LabelPart->SetText(CString(name));

		CollectAttributes(pFCO);
	}

	ClassComplexPart::InitializeEx(pProject, pPart, pFCO, parentWnd, preferences);

	CalcRelPositions(NULL, NULL);
}

//////////////////////////////////////////////////////////////////////////
void ScantyPart::CollectAttributes(CComPtr<IMgaFCO> mgaFco)
{
	if (!mgaFco)
	{
		mgaFco = m_spFCO;
	}

	CComPtr<IMgaObjects> childs;
	HRESULT hr;

	hr = mgaFco->get_ChildObjects(&childs);
	if(S_OK != hr) return;
	//COMTHROW(hr);

	long count;
	COMTHROW(childs->get_Count(&count));

	for(long i(0); i<count; i++)
	{
		CComPtr<IMgaObject> child;
		COMTHROW(childs->get_Item(i+1, &child));

		CComPtr<IMgaFCO> fco;
		COMTHROW(child.QueryInterface(&fco));

		CComBSTR name;
		COMTHROW(fco->get_Name(&name));

		m_AttributeParts.push_back(new CategoryAttributePart(this, m_eventSink, CString(name), CString(), ecak_enumValue, fco));
	}
}


}; // namespace UMLDecor
