/**
 * @file MainFrame.cpp
 * @author Kev
 */

#include "pch.h"
#include "BugSquashView.h"
#include "MainFrame.h"

/**
 * Initialize the MainFrame window
 */
void MainFrame::Initialize()
{
	Create(nullptr, wxID_ANY, L"BugSquash", wxDefaultPosition, wxSize( 1000, 800));

	// Create the view class object as a child of MainFrame
	auto sizer = new wxBoxSizer(wxVERTICAL);

	mBugSquashView = new BugSquashView();
	mBugSquashView->Initialize( this );

	sizer->Add( mBugSquashView, 1, wxEXPAND|wxALL );

	SetSizer(sizer);
	Layout();

	CreateStatusBar();

	// Set the bar
	auto menuBar = new wxMenuBar( );

	// Set the menus
	auto fileMenu = new wxMenu();
	auto levelMenu = new wxMenu();
	auto viewMenu = new wxMenu();
	auto helpMenu = new wxMenu();

	// Add the file menu options
	fileMenu->Append( wxID_OPEN, "Load &File...\tCtrl-F", L"Load Bug Squash File" );
	fileMenu->Append( wxID_EXIT, "E&xit\tAlt-X", "Quit this program" );

	// Add the help menu option
	helpMenu->Append( wxID_ABOUT, "&About\tF1", "Show about dialogue" );

	// Bind OnExit to Exit button
	Bind( wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT );

	// Bind OnAbout to About button
	Bind( wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT );

	// Bind OnClose to when user tries to close the window
	Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);


	// Add to the top-level menuBar
	menuBar->Append(fileMenu, L"&File" );
	menuBar->Append( levelMenu, L"&Level" );
	menuBar->Append( viewMenu, L"&View" );
	mBugSquashView->AddMenus( this, menuBar, levelMenu, viewMenu );
	menuBar->Append( helpMenu, L"&Help" );

	SetMenuBar( menuBar );
}

/**
 * Exit option menu handler
 * @param event
 */
void MainFrame::OnExit( wxCommandEvent& event )
{
	Close( true );
}

/**
 * About menu option handler
 * @param event
 */
void MainFrame::OnAbout( wxCommandEvent& event )
{
	wxMessageBox( L"Welcome to the BugSquash Game!",
				  L"About BugSquash",
				  wxOK,
				  this );
}

/**
 * Handle a close event. Stop the animation and destroy this window.
 * @param event The Close event
 */
void MainFrame::OnClose(wxCloseEvent& event)
{
	mBugSquashView->StopTimer();
	Destroy();
}