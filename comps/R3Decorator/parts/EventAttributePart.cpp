#include "StdAfx.h"
#include "EventAttributePart.h"

#include "CategoryPart.h"
#include "DecoratorCusts.h"

namespace Decor {

	using namespace DecoratorSDK;

//################################################################################################
//
// CLASS : EventAttributePart
//
//################################################################################################

EventAttributePart::EventAttributePart(
	PartBase* pPart, 
	CComPtr<IMgaCommonDecoratorEvents> eventSink,
	const CString& nameStr, const CString& typeStr, 
	CComPtr<IMgaFCO>& pFCO)
	: AttributePart(pPart, eventSink)
	, m_spActualFCO(pFCO)
{
	SetName(nameStr);
	SetType(typeStr);
}

EventAttributePart::~EventAttributePart()
{
}

void EventAttributePart::InitializeEx(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart, CComPtr<IMgaFCO>& pFCO,
				  HWND parentWnd, PreferenceMap& preferences)
{
	AttributePart::InitializeEx(pProject, pPart, pFCO, parentWnd, preferences);

	m_crText = R3_EVENT_ATTRIBUTE_PART_COLOR;
	m_iFontKey = R3_EVENT_ATTRIBUTE_PART_FONT;
}

void EventAttributePart::ExecuteOperation(const CString& newString)
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

bool EventAttributePart::IsLesser(const AttributePart* other)
{
	// dummy implementation, not used
	return false;
}


void EventAttributePart::Draw(CDC* pDC, Gdiplus::Graphics* gdip)
{
	if (m_bTextEnabled)
	{
		
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
