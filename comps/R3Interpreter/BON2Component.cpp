//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	BON2Component.cpp
//
//###############################################################################################################################################

/*
	Copyright (c) Vanderbilt University, 2000-2004
	ALL RIGHTS RESERVED

	Vanderbilt University disclaims all warranties with regard to this
	software, including all implied warranties of merchantability
	and fitness.  In no event shall Vanderbilt University be liable for
	any special, indirect or consequential damages or any damages
	whatsoever resulting from loss of use, data or profits, whether
	in an action of contract, negligence or other tortious action,
	arising out of or in connection with the use or performance of
	this software.
*/

#include "stdafx.h"
#include <Console.h>
#include "BON2Component.h"

#include "R3MetaBonX.h"

#include "workers/wSchema.hpp"


namespace BON
{

//###############################################################################################################################################
//
// 	C L A S S : BON::Component
//
//###############################################################################################################################################

Component::Component()
	: m_bIsInteractive( false )
{
}

Component::~Component()
{
	if ( m_project ) {
		m_project->finalizeObjects();
		finalize( m_project );
		m_project = NULL;
	}
}

// ====================================================
// This method is called after all the generic initialization is done
// This should be empty unless application-specific initialization is needed

void Component::initialize( Project& project )
{
	// ======================
	// Insert application specific code here
}

// ====================================================
// This method is called before the whole BON2 project released and disposed
// This should be empty unless application-specific finalization is needed

void Component::finalize( Project& project )
{
	// ======================
	// Insert application specific code here
}

// ====================================================
// This is the obsolete component interface
// This present implementation either tries to call InvokeEx, or does nothing except of a notification

void Component::invoke( Project& project, const std::set<FCO>& setModels, long lParam )
{
	#ifdef SUPPORT_OLD_INVOKE
		Object focus;
		invokeEx( project, focus, setModels, lParam );
	#else
		if ( m_bIsInteractive )
			AfxMessageBox("This BON2 Component does not support the obsolete invoke mechanism!");
	#endif
}

// ====================================================
// This is the main component method for Interpereters and Plugins.
// May also be used in case of invokeable Add-Ons


void Component::invokeEx( Project& project, FCO& currentFCO, const std::set<FCO>& setSelectedFCOs, long lParam )
{

	boost::filesystem::path genDir;
	if(!browseGenDir(project, genDir))
	{
		return;
	}

	//////////////////////////////////////////////////////////////////////////
#ifdef GME_ADDON
	project->setAutoCommit( false);
#endif
	using namespace GMEConsole;
	Console::Out::WriteLine("R3 Interpreter started...");



	// ======================
	// TODO: Insert application specific code here
	std::set<FCO> roots = project->getRootFolder()->getRootFCOs();
	BOOST_FOREACH(Folder f, project->getLibraries())
	{
		std::set<FCO> lroots = f->getRootFCOs();
		roots.insert(lroots.begin(), lroots.end());
	}

	{
		workers::WSchema w(genDir);
		//w(roots);
		w.mk(roots);
	}
// 	{
// 		workers::WProtocol w(genDir);
// 		w(roots);
// 	}

	Console::Out::WriteLine("R3 Interpreter completed...");
}

// ====================================================
// GME currently does not use this function
// You only need to implement it if other invokation mechanisms are used

void Component::objectInvokeEx( Project& project, Object& currentObject, const std::set<Object>& setSelectedObjects, long lParam )
	{
		if ( m_bIsInteractive )
			AfxMessageBox("This BON2 Component does not support objectInvokeEx method!");
	}

// ====================================================
// Implement application specific parameter-mechanism in these functions

Util::Variant Component::getParameter( const std::string& strName )
{
	// ======================
	// Insert application specific code here

	return Util::Variant();
}

void Component::setParameter( const std::string& strName, const Util::Variant& varValue )
{
	// ======================
	// Insert application specific code here
}

#ifdef GME_ADDON

// ====================================================
// If the component is an Add-On, then this method is called for every Global Event

void Component::globalEventPerformed( globalevent_enum event )
{
	// ======================
	// Insert application specific code here
}

// ====================================================
// If the component is an Add-On, then this method is called for every Object Event

void Component::objectEventPerformed( Object& object, unsigned long event, VARIANT v )
{
	// ======================
	// Insert application specific code here
}

#endif // GME_ADDON


//////////////////////////////////////////////////////////////////////////
int CALLBACK BrowseCallbackProc( HWND hWnd, UINT uMsg, LPARAM lParam,
								LPARAM lpData )
{
	TCHAR szPath[_MAX_PATH];
	switch (uMsg) {
	case BFFM_INITIALIZED:
		if (lpData)
			SendMessage(hWnd,BFFM_SETSELECTION,TRUE,lpData);
		break;
	case BFFM_SELCHANGED:
		SHGetPathFromIDList(LPITEMIDLIST(lParam),szPath);
		SendMessage(hWnd, BFFM_SETSTATUSTEXT, NULL, LPARAM(szPath));
		break;
	}
	return 0;
}

bool Component::browseGenDir(Project& project, boost::filesystem::path &genDir)
{
	//взять путь из реестра модели, отложить его от пути к модели
	//прогнать через диалог выбора пути
	//преобразовать обратно в относительный от пути к модели и запомнить в реестре
	boost::filesystem::path projectDir = project->getProjectPath();
	projectDir = projectDir.parent_path();
	Folder rootFolder = project->getRootFolder();
	boost::filesystem::path genRelDir = rootFolder->getRegistry()->getValueByPath("/R3/GeneratePath");

	if(genRelDir.has_root_directory() && genRelDir.has_root_path())
	{
		genDir = genRelDir;
	}
	else
	{
		genDir = projectDir / genRelDir;
	}
	genDir.normalize();

	TCHAR brPath[MAX_PATH*10];
	strcpy(brPath, genDir.string().c_str());
	std::replace(brPath, brPath+strlen(brPath), '/', '\\');


	BROWSEINFO bi = {};
	bi.lpszTitle = "select generation target directory";
	bi.pszDisplayName = brPath;
	bi.ulFlags = 
		BIF_RETURNONLYFSDIRS|
		BIF_USENEWUI|
		BIF_STATUSTEXT|
		0;                       // Flags that control the return stuff
	bi.lpfn = BrowseCallbackProc;
	bi.lParam = (LPARAM)brPath;
	PIDLIST_ABSOLUTE pidl = SHBrowseForFolder(&bi);

	if(pidl)
	{
		if(SHGetPathFromIDList(pidl, brPath))
		{
			genDir = brPath;
		}

		// free memory used
		IMalloc * imalloc = 0;
		if ( SUCCEEDED( SHGetMalloc ( &imalloc )) )
		{
			imalloc->Free ( pidl );
			imalloc->Release ( );
		}
	}
	else
	{
		//отмена
		return false;
	}

	boost::filesystem::path genRelDir2;
	if(genDir.root_name() == projectDir.root_name())
	{
		boost::filesystem::path::iterator gIter = genDir.begin();
		boost::filesystem::path::iterator gEnd = genDir.end();
		boost::filesystem::path::iterator pIter = projectDir.begin();
		boost::filesystem::path::iterator pEnd = projectDir.end();
		for(; gIter!=gEnd && pIter!=pEnd && *gIter==*pIter; gIter++, pIter++);

		for(; pIter!=pEnd; pIter++)
		{
			genRelDir2 /= "..";
		}
		for(; gIter!=gEnd; gIter++)
		{
			genRelDir2 /= *gIter;
		}
	}
	else
	{
		genRelDir2 = genDir;
	}

	if(genRelDir2 != genRelDir)
	{
		strcpy(brPath, genRelDir2.string().c_str());
		std::replace(brPath, brPath+strlen(brPath), '/', '\\');

		rootFolder->getRegistry()->setValueByPath("/R3/GeneratePath", brPath);
	}

	return true;
}


}; // namespace BON

