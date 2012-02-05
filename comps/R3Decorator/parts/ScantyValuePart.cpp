#include "StdAfx.h"

#include "NEStereoLabelPart.h"
#include "ScantyValuePart.h"
#include "Resource.h"
#include "DecoratorCusts.h"

#include "CategoryAttributePart.h"
namespace Decor {

ScantyValuePart::ScantyValuePart(DecoratorSDK::PartBase* pPart, CComPtr<IMgaCommonDecoratorEvents> eventSink)
	: ClassComplexPart(pPart, eventSink)
{
}

ScantyValuePart::~ScantyValuePart()
{
}

// New functions
void ScantyValuePart::InitializeEx(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart, CComPtr<IMgaFCO>& pFCO,
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


	if(pFCO)
	{
		m_LabelPart = new DecoratorSDK::ClassLabelPart(this, m_eventSink, true);
		CComBSTR name;
		COMTHROW(pFCO->get_Name(&name));
		m_LabelPart->SetText(CString(name));
	}
	else
	{
		m_LabelPart = new DecoratorSDK::ClassLabelPart(this, m_eventSink, true);
		m_LabelPart->SetText(CString(R3_SCANTYVALUE_NAME));
	}

	ClassComplexPart::InitializeEx(pProject, pPart, pFCO, parentWnd, preferences);

	CalcRelPositions(NULL, NULL);
}

//////////////////////////////////////////////////////////////////////////
void ScantyValuePart::CollectAttributes(CComPtr<IMgaFCO> mgaFco)
{
}


}; // namespace UMLDecor
