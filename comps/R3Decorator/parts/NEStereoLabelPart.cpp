#include "StdAfx.h"
#include "NEStereoLabelPart.h"


namespace Decor {

NEStereoLabelPart::NEStereoLabelPart(PartBase* pPart, CComPtr<IMgaCommonDecoratorEvents> eventSink)
	: DecoratorSDK::StereoLabelPart(pPart, eventSink)
{
	m_bTextEditable = false;
}

NEStereoLabelPart::~NEStereoLabelPart()
{
}

void NEStereoLabelPart::ExecuteOperation(const CString& newString)
{
	//ничего, не редактируется
}

}; // namespace Decor
