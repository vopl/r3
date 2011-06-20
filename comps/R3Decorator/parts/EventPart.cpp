#include "StdAfx.h"

#include "NEStereoLabelPart.h"
#include "EventPart.h"
#include "Resource.h"
#include "DecoratorCusts.h"

#include <algorithm>

namespace Decor {

EventPart::EventPart(DecoratorSDK::PartBase* pPart, CComPtr<IMgaCommonDecoratorEvents> eventSink)
	: ClassComplexPart(pPart, eventSink)
{
}

EventPart::~EventPart()
{
}

// New functions
void EventPart::InitializeEx(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart, CComPtr<IMgaFCO>& pFCO,
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
	

	m_LabelPart = new DecoratorSDK::ClassLabelPart(this, m_eventSink, false);

	if(pFCO)
	{
		CComBSTR name;
		COMTHROW(pFCO->get_Name(&name));

		m_LabelPart->SetText(CString(name));


		CComBSTR dname;
		pFCO->GetStrAttrByNameDisp(CComBSTR(R3_EVENT_DIRECTION_NAME), &dname);


		m_StereotypePart = new NEStereoLabelPart(this, m_eventSink);
		m_StereotypePart->SetText(CString(R3_EVENT_NAME) + " " + CString(dname));

		CollectAttributes(pFCO);
	}
	else
	{
		m_LabelPart->SetText(CString(R3_EVENT_NAME));
	}

	ClassComplexPart::InitializeEx(pProject, pPart, pFCO, parentWnd, preferences);

	CalcRelPositions(NULL, NULL);
}

void EventPart::CollectAttributes(CComPtr<IMgaFCO> fco)
{
	if (!fco)
	{
		fco = m_spFCO;
	}


	CComPtr<IMgaObjects> childs;
	HRESULT hr;

	hr = fco->get_ChildObjects(&childs);
	//if(S_OK != hr) return;
	COMTHROW(hr);

	long count;
	COMTHROW(childs->get_Count(&count));

	//отсортировать
	std::vector<CComPtr<IMgaFCO> > childFcos;
	for(long i(0); i<count; i++)
	{
		CComPtr<IMgaObject> child;
		COMTHROW(childs->get_Item(i+1, &child));

		CComPtr<IMgaFCO> fco;
		child.QueryInterface(&fco);
		if(!fco)
		{
			continue;
		}

		childFcos.push_back(fco);
	}

	struct SAttrSortPred{bool operator()(const CComPtr<IMgaFCO> &af, const CComPtr<IMgaFCO> &bf)
	{
		CComBSTR ap, bp;
		af->get_RegistryValue(CComBSTR("PartRegs/AspectContext/Position"), &ap);
		bf->get_RegistryValue(CComBSTR("PartRegs/AspectContext/Position"), &bp);

		unsigned t,ay=0,by=0;
		sscanf_s(CString(ap), "%u,%u", &t, &ay);
		sscanf_s(CString(bp), "%u,%u", &t, &by);

		return ay<by;
	}};
	std::sort(childFcos.begin(), childFcos.end(), SAttrSortPred());

	for(size_t i(0); i<childFcos.size(); i++)
	{
		CComPtr<IMgaFCO> fco = childFcos[i];
		CComBSTR nameFco;
		COMTHROW(fco->get_Name(&nameFco));

		CComPtr<IMgaMetaFCO> meta;
		fco->get_Meta(&meta);
		if(!meta)
		{
			continue;
		}

		CComBSTR nameMeta;
		COMTHROW(meta->get_Name(&nameMeta));

		m_AttributeParts.push_back(new EventAttributePart(this, m_eventSink, CString(nameFco), CString(nameMeta), fco));
	}
}


void EventPart::ModifyAttributes(CComPtr<IMgaFCO> mgaFco)
{
	//ничего
}




}; // namespace UMLDecor
