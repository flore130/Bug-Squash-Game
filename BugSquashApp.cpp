/**
 * @file BugSquashApp.cpp
 * @author Kev
 */

#include "pch.h"
#include <MainFrame.h>
#include "BugSquashApp.h"

/**
 * Initialize the application
 * @return
 */
bool BugSquashApp::OnInit()
{
	#ifdef WIN32
		_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	#endif
	if ( !wxApp::OnInit() )
	{
		return false;
	}

	// Add image type handlers
	wxInitAllImageHandlers();

	auto frame = new MainFrame();
	frame->Initialize();
	frame->Show( true );
	return true;
}

