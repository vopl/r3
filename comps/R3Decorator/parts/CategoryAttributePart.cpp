#include "StdAfx.h"
#include "CategoryAttributePart.h"

#include "CategoryPart.h"
#include "DecoratorCusts.h"

namespace Decor {

	using namespace DecoratorSDK;

//################################################################################################
//
// CLASS : CategoryAttributePart
//
//################################################################################################

CategoryAttributePart::CategoryAttributePart(
	PartBase* pPart, 
	CComPtr<IMgaCommonDecoratorEvents> eventSink,
	const CString& nameStr, const CString& typeStr, ECategoryAttributeKind	kind,
	CComPtr<IMgaFCO>& pFCO)
	: AttributePart(pPart, eventSink)
	, m_spActualFCO(pFCO)
	, _kind(kind)
{
	SetName(nameStr);
	SetType(typeStr);
}

CategoryAttributePart::~CategoryAttributePart()
{
}

void CategoryAttributePart::InitializeEx(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart, CComPtr<IMgaFCO>& pFCO,
				  HWND parentWnd, PreferenceMap& preferences)
{
	AttributePart::InitializeEx(pProject, pPart, pFCO, parentWnd, preferences);

	switch(_kind)
	{
	case ecak_own:
		m_crText = R3_CATEGORY_ATTRIBUTE_PART_COLOR_OWN;
		m_iFontKey = R3_CATEGORY_ATTRIBUTE_PART_FONT_OWN;
		break;
	case ecak_inherited:
		m_crText = R3_CATEGORY_ATTRIBUTE_PART_COLOR_INH;
		m_iFontKey = R3_CATEGORY_ATTRIBUTE_PART_FONT_INH;
		break;
	case ecak_separator:
		m_crText = R3_CATEGORY_ATTRIBUTE_PART_COLOR_SEP;
		m_iFontKey = R3_CATEGORY_ATTRIBUTE_PART_FONT_SEP;
		m_bTextEditable = false;
		break;
	case ecak_enumValue:
		m_crText = R3_ENUM_ATTRIBUTE_PART_COLOR;
		m_iFontKey = R3_ENUM_ATTRIBUTE_PART_FONT;
		break;
	case ecak_link:
		m_crText = R3_CATEGORY_ATTRIBUTE_PART_COLOR_LINK;
		m_iFontKey = R3_CATEGORY_ATTRIBUTE_PART_FONT_LINK;
		break;
	default:
		ASSERT(!"unknown ECategoryAttributeKind value");
	}
}

void CategoryAttributePart::ExecuteOperation(const CString& newString)
{
	// transaction operation begin
	m_strText = newString;

	if(m_spActualFCO)
	{
		CategoryPart* categoryPart = dynamic_cast<CategoryPart*> (GetParent());
		if(categoryPart)
		{
			categoryPart->ModifyAttributes(m_spActualFCO);	// Had to assemble attribute string also from the other attributes, so pass this to the parent
		}

		// transaction operation end
		m_spActualFCO->put_Name(CComBSTR(newString));
	}
}

bool CategoryAttributePart::IsLesser(const AttributePart* other)
{
	// dummy implementation, not used
	return false;
}


void CategoryAttributePart::Draw(CDC* pDC, Gdiplus::Graphics* gdip)
{
	if (m_bTextEnabled)
	{
		if(ecak_enumValue == _kind)
		{
			CRect loc = GetLocation();
			GdipFont* pFont = getFacilities().GetFont(m_iFontKey);
			CSize size = getFacilities().MeasureText(gdip, pFont, m_strText);

			getFacilities().DrawString(gdip,
				m_strText,
				CRect(loc.left + DECORATOR_MARGINX, loc.top + m_textRelYPosition - size.cy,
				loc.right - DECORATOR_MARGINX, loc.top + m_textRelYPosition),
				pFont,
				(m_bActive) ? m_crText : COLOR_GREY,
				TA_BOTTOM | TA_LEFT,
				m_iMaxTextLength,
				"",
				"",
				false);
		}
		else if(ecak_separator == _kind)
		{
			CRect loc = GetLocation();
			GdipFont* pFont = getFacilities().GetFont(m_iFontKey);
			CSize size = getFacilities().MeasureText(gdip, pFont, m_strText);
			
			getFacilities().DrawString(gdip,
				m_strText,
				CRect(loc.left + DECORATOR_MARGINX, loc.top + m_textRelYPosition - size.cy,
				loc.right - DECORATOR_MARGINX, loc.top + m_textRelYPosition),
				pFont,
				(m_bActive) ? m_crText : COLOR_GREY,
				TA_BOTTOM | TA_CENTER,
				m_iMaxTextLength,
				"",
				"",
				false);

			getFacilities().DrawString(gdip,
				"-",
				CRect(loc.left + DECORATOR_MARGINX, loc.top + m_textRelYPosition - size.cy,
				loc.right - DECORATOR_MARGINX, loc.top + m_textRelYPosition),
				pFont,
				(m_bActive) ? m_crText : COLOR_GREY,
				TA_BOTTOM | TA_LEFT,
				m_iMaxTextLength,
				"",
				"",
				false);

			getFacilities().DrawString(gdip,
				"-",
				CRect(loc.left + DECORATOR_MARGINX, loc.top + m_textRelYPosition - size.cy,
				loc.right - DECORATOR_MARGINX, loc.top + m_textRelYPosition),
				pFont,
				(m_bActive) ? m_crText : COLOR_GREY,
				TA_BOTTOM | TA_RIGHT,
				m_iMaxTextLength,
				"",
				"",
				false);
		}
		else
		{
			CRect loc = GetLocation();
			GdipFont* pFont = getFacilities().GetFont(m_iFontKey);
			CSize size = getFacilities().MeasureText(gdip, pFont, m_strText);
			getFacilities().DrawString(gdip,
				m_strText + ATTRIBUTE_SEP,
				CRect(loc.left + DECORATOR_MARGINX, loc.top + m_textRelYPosition - size.cy,
				loc.right - DECORATOR_MARGINX, loc.top + m_textRelYPosition),
				pFont,
				(m_bActive) ? m_crText : COLOR_GREY,
				TA_BOTTOM | TA_LEFT,
				m_iMaxTextLength,
				"",
				"",
				false);
			getFacilities().DrawString(gdip,
				m_strType,
				CRect(loc.left + DECORATOR_MARGINX, loc.top + m_textRelYPosition - size.cy,
				loc.right - DECORATOR_MARGINX, loc.top + m_textRelYPosition),
				pFont,
				(m_bActive) ? m_crText : COLOR_GREY,
				TA_BOTTOM | TA_RIGHT,
				m_iMaxTextLength,
				"",
				"",
				false);
		}
	}
	if (m_spFCO)
		resizeLogic.Draw(pDC, gdip);
}
}; // namespace UMLDecor
