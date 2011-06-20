#include "StdAfx.h"
#include "ContextAttributePart.h"

#include "CategoryPart.h"
#include "DecoratorCusts.h"

namespace Decor {

	using namespace DecoratorSDK;

//################################################################################################
//
// CLASS : ContextAttributePart
//
//################################################################################################

ContextAttributePart::ContextAttributePart(
	PartBase* pPart, 
	CComPtr<IMgaCommonDecoratorEvents> eventSink,
	const CString& nameStr, const CString& typeStr, EContextAttributeKind	kind,
	CComPtr<IMgaFCO>& pFCO)
	: AttributePart(pPart, eventSink)
	, m_spActualFCO(pFCO)
	, _kind(kind)
{
	SetName(nameStr);
	SetType(typeStr);
}

ContextAttributePart::~ContextAttributePart()
{
}

void ContextAttributePart::InitializeEx(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart, CComPtr<IMgaFCO>& pFCO,
				  HWND parentWnd, PreferenceMap& preferences)
{
	AttributePart::InitializeEx(pProject, pPart, pFCO, parentWnd, preferences);

	switch(_kind)
	{
	case ecoak_context:
		m_crText = R3_CONTEXT_ATTRIBUTE_PART_COLOR_CTX;
		m_iFontKey = R3_CONTEXT_ATTRIBUTE_PART_FONT_CTX;
		break;
	case ecoak_event:
		m_crText = R3_CONTEXT_ATTRIBUTE_PART_COLOR_EVT;
		m_iFontKey = R3_CONTEXT_ATTRIBUTE_PART_FONT_EVT;
		break;
	case ecoak_separator:
		m_crText = R3_CONTEXT_ATTRIBUTE_PART_COLOR_SEP;
		m_iFontKey = R3_CONTEXT_ATTRIBUTE_PART_FONT_SEP;
		m_bTextEditable = false;
		break;
	default:
		ASSERT(!"unknown ECategoryAttributeKind value");
	}
}

void ContextAttributePart::ExecuteOperation(const CString& newString)
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

bool ContextAttributePart::IsLesser(const AttributePart* other)
{
	// dummy implementation, not used
	return false;
}


void ContextAttributePart::Draw(CDC* pDC, Gdiplus::Graphics* gdip)
{
	if (m_bTextEnabled)
	{
		if(ecoak_separator == _kind)
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
