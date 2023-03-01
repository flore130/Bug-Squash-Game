/**
 * @file MainFrame.cpp
 * @author Kev
 */

#include "pch.h"
#include "MainFrame.h"

/**
 * Initialize the MainFrame window
 */
void MainFrame::Initialize()
{
	Create( nullptr, wxID_ANY, L"BugSquash", wxDefaultPosition, wxSize( 1250, 1000 ) );

	auto menuBar = new wxMenuBar( );
	auto fileMenu = new wxMenu();

	menuBar->Append(fileMenu, L"&File" );
	fileMenu->Append(wxID_OPEN, "Load &File...\tCtrl-F", L"Load Bug Squash File");

	SetMenuBar( menuBar );
}
