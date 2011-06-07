//################################################################################################
//
// Decorator composite part class
//	DecoratorCompositePart.cpp
// Contains the specific decorator parts which compose the final decorator
//
//################################################################################################

#include "StdAfx.h"
#include "DecoratorLib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include "GMEOLEData.h"
#include "DecoratorCompositePart.h"
#include "DiamondVectorPart.h"
#include "TypeableLabelPart.h"
#include "ReferenceBitmapPart.h"

#include "DecoratorExceptions.h"

#include "DecoratorCusts.h"
#include "parts/CategoryPart.h"
#include "parts/FieldPart.h"
#include "parts/ScantyPart.h"
#include "parts/ScantyValuePart.h"

static const unsigned int	CTX_MENU_ID_SAMPLE		= DECORATOR_CTX_MENU_MINID + 100;	// Should be unique
static const char*			CTX_MENU_STR_SAMPLE		= "Decorator Ctx Menu Item";


namespace Decor {

	using namespace DecoratorSDK;

//################################################################################################
//
// CLASS : DecoratorCompositePart
//
//################################################################################################

DecoratorCompositePart::DecoratorCompositePart(PartBase* pPart, CComPtr<IMgaCommonDecoratorEvents>& eventSink):
	ObjectAndTextPart(pPart, eventSink)
{
}

DecoratorCompositePart::~DecoratorCompositePart()
{
}

CRect DecoratorCompositePart::GetPortLocation(CComPtr<IMgaFCO>& fco) const
{
	throw PortNotFoundException();
}

CRect DecoratorCompositePart::GetLabelLocation(void) const
{
	HRESULT retVal = S_OK;
	std::vector<PartBase*>::const_iterator ii = m_compositeParts.begin();
	if (m_compositeParts.size() > 1)
		++ii;	// we expect that the second part is the label if there's more than one part
	if (ii != m_compositeParts.end()) {
		try {
			return (*ii)->GetLabelLocation();
		}
		catch(hresult_exception& e) {
			retVal = e.hr;
		}
		catch(DecoratorException& e) {
			retVal = e.GetHResult();
		}
	}

	throw DecoratorException((DecoratorExceptionCode)retVal);
}

// New functions
void DecoratorCompositePart::InitializeEx(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart, CComPtr<IMgaFCO>& pFCO,
									   HWND parentWnd, PreferenceMap& preferences)
{
	//
	// TODO: Add needed parts to the composite
	//		 This time it is the desired vectorial shape plus a versatile label part
	//
	try {
		if(pProject && pPart)
		{
			getFacilities().getMetaFCO(pPart, m_spMetaFCO);
			if(!m_spMetaFCO) throw DecoratorException(EFail);

			CComBSTR name;
			COMTHROW(m_spMetaFCO->get_Name(&name));

			if(name == R3_CATEGORY_NAME || name == R3_CATEGORYREFERENCE_NAME)
			{
				AddObjectPart(new CategoryPart(this, m_eventSink));
			}
			else if(name == R3_SET_NAME || name == R3_ENUM_NAME)
			{
				AddObjectPart(new ScantyPart(this, m_eventSink));
			}
			else if(
				   name == R3_FILE_NAME
				|| name == R3_IMAGE_NAME
				|| name == R3_AUDIO_NAME
				|| name == R3_VIDEO_NAME
				|| name == R3_REAL32_NAME
				|| name == R3_REAL64_NAME
				|| name == R3_BINARY_NAME
				|| name == R3_BOOL_NAME
				|| name == R3_CHAR_NAME
				|| name == R3_STRING_NAME
				|| name == R3_MONEY_NAME
				|| name == R3_INT8_NAME
				|| name == R3_INT16_NAME
				|| name == R3_INT32_NAME
				|| name == R3_INT64_NAME
				|| name == R3_TIME_NAME
				|| name == R3_DATE_NAME
				|| name == R3_TIMESTAMP_NAME
				|| name == R3_DATETIMEINTERVAL_NAME)
			{
				AddObjectPart(new FieldPart(this, m_eventSink));
			}
			else if(name == R3_SCANTYVALUE_NAME)
			{
				AddObjectPart(new ScantyValuePart(this, m_eventSink));
			}
			else
			{
				AddObjectPart(new DecoratorSDK::DiamondVectorPart(this, m_eventSink,
					static_cast<long> (24 * 2),
					static_cast<long> (24)));
				AddTextPart(new DecoratorSDK::TypeableLabelPart(this, m_eventSink));
			}

		}
	}
	catch (hresult_exception& e) {
		throw DecoratorException((DecoratorExceptionCode)e.hr);
	}

	CompositePart::InitializeEx(pProject, pPart, pFCO, parentWnd, preferences);
}

void DecoratorCompositePart::InitializeEx(CComPtr<IMgaProject>& pProject, CComPtr<IMgaMetaPart>& pPart, CComPtr<IMgaFCO>& pFCO,
									   HWND parentWnd)
{
	//
	// Initialize the Decorator utilities facility framework
	//
	getFacilities().loadPathes(pProject, true);

	PreferenceMap preferencesMap;
	InitializeEx(pProject, pPart, pFCO, parentWnd, preferencesMap);
}

bool DecoratorCompositePart::MouseLeftButtonDoubleClick(UINT nFlags, const CPoint& point, HDC transformHDC)
{
// 	CRect ptRect = m_compositeParts[0]->GetBoxLocation();
// 	if (ptRect.PtInRect(point)) {
// 		AfxMessageBox("Decorator double clicked!");
// 		GeneralOperationStarted(NULL);
// 		// TODO: do something
// 		GeneralOperationFinished(NULL);
// 		return true;
// 	}

	return CompositePart::MouseLeftButtonDoubleClick(nFlags, point, transformHDC);
}

bool DecoratorCompositePart::MouseRightButtonDown(HMENU hCtxMenu, UINT nFlags, const CPoint& point, HDC transformHDC)
{
	CRect ptRect = m_compositeParts[0]->GetBoxLocation();
	if (ptRect.PtInRect(point)) {
		::AppendMenu(hCtxMenu, MF_STRING | MF_ENABLED, CTX_MENU_ID_SAMPLE, CTX_MENU_STR_SAMPLE);
		return true;
	}

	return CompositePart::MouseRightButtonDown(hCtxMenu, nFlags, point, transformHDC);
}

bool DecoratorCompositePart::DragEnter(DROPEFFECT* dropEffect, COleDataObject* pDataObject, DWORD dwKeyState, const CPoint& point, HDC transformHDC)
{
	if (pDataObject->IsDataAvailable(CF_HDROP)) {
		*dropEffect = DROPEFFECT_COPY;
		return true;
	}

	return CompositePart::DragEnter(dropEffect, pDataObject, dwKeyState, point, transformHDC);
}

bool DecoratorCompositePart::DragOver(DROPEFFECT* dropEffect, COleDataObject* pDataObject, DWORD dwKeyState, const CPoint& point, HDC transformHDC)
{
	if (pDataObject->IsDataAvailable(CF_HDROP)) {
		*dropEffect = DROPEFFECT_COPY;
		return true;
	}

	return CompositePart::DragOver(dropEffect, pDataObject, dwKeyState, point, transformHDC);
}

bool DecoratorCompositePart::Drop(COleDataObject* pDataObject, DROPEFFECT dropEffect, const CPoint& point, HDC transformHDC)
{
	if (pDataObject->IsDataAvailable(CF_HDROP) && dropEffect == DROPEFFECT_COPY) {
		STGMEDIUM medium;
		medium.tymed = TYMED_HGLOBAL;
		pDataObject->GetData(CF_HDROP, &medium);
		return DropFile((HDROP)medium.hGlobal, point, transformHDC);
	}

	return CompositePart::Drop(pDataObject, dropEffect, point, transformHDC);
}

bool DecoratorCompositePart::DropFile(HDROP p_hDropInfo, const CPoint& point, HDC transformHDC)
{
	UINT nFiles = DragQueryFile(p_hDropInfo, 0xFFFFFFFF, NULL, 0);
	if (nFiles < 1)
		return false;

	for (UINT iF = 0; iF < nFiles; ++iF) {
		TCHAR szFileName[_MAX_PATH];
		UINT res = DragQueryFile(p_hDropInfo, iF, szFileName, _MAX_PATH);
		if (res > 0) {
			bool is_dir = false; 
			struct _stat fstatus;
			if (0 == _tstat(szFileName, &fstatus))
				is_dir = (fstatus.st_mode & _S_IFDIR) == _S_IFDIR;

			CString conn(szFileName);
			if (!is_dir && conn.Right(4).CompareNoCase(".txt") == 0) {
				CFile txtFile(conn, CFile::modeRead);
				char pbufRead[100];
				UINT readLen = txtFile.Read(pbufRead, sizeof(pbufRead) - 1);
				pbufRead[readLen] = 0;
				GeneralOperationStarted(NULL);
				// TODO: do something
				GeneralOperationFinished(NULL);
				AfxMessageBox("Decorator drop: '" + conn + "' first 100 bytes: " + pbufRead + ".");
				return true;
			} else {
				AfxMessageBox("Decorator drop: '.txt' files may be dropped only. Can't open file: " + conn + "!");
			}
		} else {
			AfxMessageBox("Decorator drop: Can't inquire file information!");
		}
	}

	return CompositePart::DropFile(p_hDropInfo, point, transformHDC);
}

bool DecoratorCompositePart::MenuItemSelected(UINT menuItemId, UINT nFlags, const CPoint& point, HDC transformHDC)
{
	if (menuItemId == CTX_MENU_ID_SAMPLE) {
		AfxMessageBox("Decorator Ctx Menu Item clicked!");
		GeneralOperationStarted(NULL);
		// TODO: do something
		GeneralOperationFinished(NULL);
		return true;
	}

	return CompositePart::MenuItemSelected(menuItemId, nFlags, point, transformHDC);
}

}; // namespace Decor
