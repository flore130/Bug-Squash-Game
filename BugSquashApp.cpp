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
	if ( !wxApp::OnInit() )
	{
		return false;
	}

	auto frame = new MainFrame();
	frame->Initialize();
	frame->Show( true );
	return true;
}

