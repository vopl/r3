#include "StdAfx.h"

#include "NEStereoLabelPart.h"
#include "CategoryPart.h"
#include "Resource.h"
#include "DecoratorCusts.h"

namespace Decor {

CategoryPart::CategoryPart(DecoratorSDK::PartBase* pPart, CComPtr<IMgaCommonDecoratorEvents> eventSink):
	ClassComplexPart(pPart, eventSink)
		, _isReference(false)
{
}

CategoryPart::~CategoryPart()
{
}

// New functions
void CategoryPart::InitializeEx(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart, CComPtr<IMgaFCO>& pFCO,
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
	


	objtype_enum typ;
	COMTHROW(m_spMetaFCO->get_ObjType(&typ));
	_isReference = OBJTYPE_REFERENCE == typ;

	VARIANT_BOOL abstr = FALSE;
	if(pFCO && FAILED(pFCO->get_BoolAttrByName(CComBSTR("Abstract"), &abstr)))
	{
		abstr = FALSE;
	}

	m_LabelPart = new DecoratorSDK::ClassLabelPart(this, m_eventSink, abstr?true:false);

	if(pFCO)
	{
		CComBSTR name;
		COMTHROW(pFCO->get_Name(&name));

		if(_isReference)
		{
			//preferences[DecoratorSDK::PREF_ITEMEDITABLE]	= DecoratorSDK::PreferenceVariant(false);

			CComPtr<IMgaFCO> deref = Dereference(pFCO);

			if(deref)
			{
				CComBSTR named;
				COMTHROW(deref->get_Name(&named));

				m_StereotypePart = new NEStereoLabelPart(this, m_eventSink);
				m_StereotypePart->SetText(CString(named));
			}
			else
			{
				m_StereotypePart = new NEStereoLabelPart(this, m_eventSink);
				m_StereotypePart->SetText(CString("NULL"));
			}
		}
		m_LabelPart->SetText(CString(name));

		CollectAttributes(pFCO);
	}
	else
	{
		if(_isReference)
		{
			m_LabelPart->SetText(CString(R3_CATEGORYREFERENCE_NAME));
		}
		else
		{
			m_LabelPart->SetText(CString(R3_CATEGORY_NAME));
		}
	}

	if(_isReference)
	{
		m_copySignPart = new DecoratorSDK::MaskedBitmapPart(this, m_eventSink, IDB_REFERENCE_SIGN,
			DecoratorSDK::COLOR_TRANSPARENT,
			DecoratorSDK::COLOR_GRAYED_OUT);
	}

	ClassComplexPart::InitializeEx(pProject, pPart, pFCO, parentWnd, preferences);

	CalcRelPositions(NULL, NULL);
}

void CategoryPart::CollectAttributes(CComPtr<IMgaFCO> fco)
{
	if (!fco)
	{
		fco = m_spFCO;
	}

	//разыменовать все ссылки
	CComPtr<IMgaFCO> derefered = Dereference(fco);

	if (!derefered)
	{
		//разименована null ссылка?
		return;
	}

	//добавить свои атрибуты
	AddAttributes(derefered, ecak_own);

	//построить перечень базовых категорий и ссылок
	TSFco bases;
	{
		//взять все ссылки
		CComPtr<IMgaFCOs> refs;
		COMTHROW(derefered->get_ReferencedBy(&refs));

		//добавить туда сам объект
		COMTHROW(refs->Append(derefered));

		//перебрать ссылки и вытащить все наследования
		long count;
		COMTHROW(refs->get_Count(&count));
		for(long i(0); i<count; i++)
		{
			CComPtr<IMgaFCO> ref;
			COMTHROW(refs->get_Item(i+1, &ref));

			CollectBases(ref, bases);
		}
	}

	//TODO: упорядочить
	//bases.sort(pred);

	//из базовых изъять сам оригинальный объект и ноль от пустых ссылок
	bases.erase(derefered);
	bases.erase(CComPtr<IMgaFCO>());

	TSFco baseCats;

	//обросить ссылки (оставить только категории)
	//добавить атрибуты от базовых
	for(TSFco::iterator iter=bases.begin(); iter!=bases.end(); iter++)
	{
		CComPtr<IMgaMetaFCO> meta;
		COMTHROW((*iter)->get_Meta(&meta));
		CComBSTR name;
		meta->get_Name(&name);

		if(name != R3_CATEGORY_NAME)
		{
			continue;
		}

		baseCats.insert(*iter);
	}

	for(TSFco::iterator iter=baseCats.begin(); iter!=baseCats.end(); iter++)
	{
		AddAttributes(*iter, ecak_inherited);
	}

}

//////////////////////////////////////////////////////////////////////////
void CategoryPart::CollectBases(CComPtr<IMgaFCO> from, TSFco &bases)
{
	if(!from)
	{
		//разыменовано по null ссылке?
		return;
	}

	if(bases.end() != bases.find(from))
	{
		//цикл в наследовании?
		//или дублирующее наследование
		return;
	}
	bases.insert(from);

	if(!from)
	{
		//разыменовано по null ссылке?
		return;
	}

	//раскрутить ссылки и рекурсивно собирать базовые
	{
		CComPtr<IMgaFCO> rec = from;
		for(;;)
		{
			if(!rec)
			{
				//null или ссылка на null
				break;
			}

			//собрать атрибуты на текущем уровне ссылочности
			CollectBases(rec, bases);

			CComPtr<IMgaReference> ref;
			if(SUCCEEDED(rec->QueryInterface(&ref)) && ref)
			{
				rec.Release();
				COMTHROW(ref->get_Referred(&rec));
			}
			else
			{
				break;
			}
		}
	}

	//для текущего перебрать наследования и взять базовые
	{
		//взять все точки соединения
		CComPtr<IMgaConnPoints> connPoints;
		COMTHROW(from->get_PartOfConns(&connPoints));

		//перебрать их
		long count;
		COMTHROW(connPoints->get_Count(&count));
		for(long i(0); i<count; i++)
		{
			//одна точка соединения
			CComPtr<IMgaConnPoint> connPoint;
			COMTHROW(connPoints->get_Item(i+1, &connPoint));


			//взять ее объкт соединения
			CComPtr<IMgaConnection> con;
			COMTHROW(connPoint->get_Owner(&con));

			//и его мета
			CComPtr<IMgaMetaFCO> conMeta;
			COMTHROW(con->get_Meta(&conMeta));

			//если мета - не наследование, то игнорировать такое соединение
			CComBSTR name;
			conMeta->get_Name(&name);

			if(name != R3_CATEGORYINHERITANCE_NAME)
			{
				continue;
			}

			//взять источник соединения
			CComPtr<IMgaSimpleConnection> scon;
			COMTHROW(con.QueryInterface(&scon));
			CComPtr<IMgaFCO> dst;
			COMTHROW(scon->get_Dst(&dst));

			//теперь dst - это назначение наследования, тоесть базовая категория или ссылка на нее
			//отработать ее рекурсивно
			CollectBases(dst, bases);
		}
	}
}

//////////////////////////////////////////////////////////////////////////
CComPtr<IMgaFCO> CategoryPart::Dereference(CComPtr<IMgaFCO> fco)
{
	//раскрутить ссылки
	for(;;)
	{
		if(!fco)
		{
			//null или ссылка на null
			break;
		}
		CComPtr<IMgaReference> ref;
		if(SUCCEEDED(fco->QueryInterface(&ref)) && ref)
		{
			fco.Release();
			COMTHROW(ref->get_Referred(&fco));
		}
		else
		{
			break;
		}
	}

	return fco;
}


//////////////////////////////////////////////////////////////////////////
void CategoryPart::AddAttributes(CComPtr<IMgaFCO> mgaFco, ECategoryAttributeKind kind)
{
	if(ecak_inherited == kind)
	{
		CComBSTR name;
		mgaFco->get_Name(&name);
		m_AttributeParts.push_back(new CategoryAttributePart(this, m_eventSink, ""+CString(name)+"", CString(""), ecak_separator, CComPtr<IMgaFCO>()));
	}

	CComPtr<IMgaObjects> childs;
	HRESULT hr;

	hr = mgaFco->get_ChildObjects(&childs);
	//if(S_OK != hr) return;
	COMTHROW(hr);

	long count;
	COMTHROW(childs->get_Count(&count));

	for(long i(0); i<count; i++)
	{
		CComPtr<IMgaObject> child;
		COMTHROW(childs->get_Item(i+1, &child));

		CComPtr<IMgaFCO> fco;
		COMTHROW(child.QueryInterface(&fco));

		CComPtr<IMgaMetaFCO> meta;
		COMTHROW(fco->get_Meta(&meta));


		CComBSTR nameMeta;
		COMTHROW(meta->get_Name(&nameMeta));

		if(
			   nameMeta == R3_INDEX_NAME
			|| nameMeta == R3_INDEXLINK_NAME)
		{
			continue;
		}

		CComBSTR nameFco;
		COMTHROW(fco->get_Name(&nameFco));

		m_AttributeParts.push_back(new CategoryAttributePart(this, m_eventSink, CString(nameFco), CString(nameMeta), kind, fco));
	}
}


void CategoryPart::ModifyAttributes(CComPtr<IMgaFCO> mgaFco)
{
	//ничего
}




}; // namespace UMLDecor
