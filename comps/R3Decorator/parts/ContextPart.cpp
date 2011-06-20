#include "StdAfx.h"

#include "NEStereoLabelPart.h"
#include "ContextPart.h"
#include "Resource.h"
#include "DecoratorCusts.h"

#include <algorithm>

namespace Decor {

ContextPart::ContextPart(DecoratorSDK::PartBase* pPart, CComPtr<IMgaCommonDecoratorEvents> eventSink)
	: ClassComplexPart(pPart, eventSink)
{
}

ContextPart::~ContextPart()
{
}

// New functions
void ContextPart::InitializeEx(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart, CComPtr<IMgaFCO>& pFCO,
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

		m_StereotypePart = new NEStereoLabelPart(this, m_eventSink);
		m_StereotypePart->SetText(CString(R3_CONTEXT_NAME));

		CollectAttributes(pFCO);
	}
	else
	{
		m_LabelPart->SetText(CString(R3_CONTEXT_NAME));
	}

	ClassComplexPart::InitializeEx(pProject, pPart, pFCO, parentWnd, preferences);

	CalcRelPositions(NULL, NULL);
}

void ContextPart::CollectAttributes(CComPtr<IMgaFCO> fco)
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
	std::vector<CComPtr<IMgaFCO> > childContexts;
	std::vector<CComPtr<IMgaFCO> > childEvents;
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

		CComPtr<IMgaMetaFCO> meta;
		COMTHROW(fco->get_Meta(&meta));


		CComBSTR nameMeta;
		COMTHROW(meta->get_Name(&nameMeta));

		if(nameMeta == R3_CONTEXT_NAME)
		{
			childContexts.push_back(fco);
		}
		else if(nameMeta == R3_EVENT_NAME)
		{
			childEvents.push_back(fco);
		}
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
	std::sort(childContexts.begin(), childContexts.end(), SAttrSortPred());
	std::sort(childEvents.begin(), childEvents.end(), SAttrSortPred());

	for(size_t i(0); i<childContexts.size(); i++)
	{
		CComPtr<IMgaFCO> fco = childContexts[i];
		CComBSTR nameFco;
		COMTHROW(fco->get_Name(&nameFco));
		m_AttributeParts.push_back(new ContextAttributePart(this, m_eventSink, CString(nameFco), CString(R3_CONTEXT_NAME), ecoak_context, fco));
	}
	m_AttributeParts.push_back(new ContextAttributePart(this, m_eventSink, ""+CString("-")+"", CString(""), ecoak_separator, CComPtr<IMgaFCO>()));
	for(size_t i(0); i<childEvents.size(); i++)
	{
		CComPtr<IMgaFCO> fco = childEvents[i];
		CComBSTR nameFco;
		COMTHROW(fco->get_Name(&nameFco));

		CComBSTR dname;
		fco->GetStrAttrByNameDisp(CComBSTR(R3_EVENT_DIRECTION_NAME), &dname);
		m_AttributeParts.push_back(new ContextAttributePart(this, m_eventSink, CString(nameFco), CString(dname), ecoak_context, fco));
	}
}


void ContextPart::ModifyAttributes(CComPtr<IMgaFCO> mgaFco)
{
	//ничего
}




}; // namespace UMLDecor
