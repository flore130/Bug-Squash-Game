/**
 * @file MainFrame.cpp
 * @author Kev
 */

#include "pch.h"
#include "BugSquashView.h"
#include "MainFrame.h"
#include "ids.h"

/**
 * Initialize the MainFrame window
 */
void MainFrame::Initialize()
{
	Create(nullptr, wxID_ANY, L"BugSquash", wxDefaultPosition, wxSize( 1000, 800));

	// Bind OnExit to Exit button
	Bind( wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT );

	// Bind OnAbout to About button
	Bind( wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT );

	// Create the view class object as a child of MainFrame
	auto sizer = new wxBoxSizer(wxVERTICAL);

	auto bugSquashView = new BugSquashView();

	bugSquashView->Initialize(this);

	sizer->Add(bugSquashView, 1, wxEXPAND|wxALL);

	SetSizer(sizer);

	Layout();

	// Set the bar
	auto menuBar = new wxMenuBar( );

	// Set the menus
	auto fileMenu = new wxMenu();
	auto levelMenu = new wxMenu();
	auto viewMenu = new wxMenu();
	auto helpMenu = new wxMenu();

	// Add to the top-level menuBar
	menuBar->Append(fileMenu, L"&File" );
	menuBar->Append( levelMenu, L"&Level" );
	menuBar->Append( viewMenu, L"&View" );
	menuBar->Append( helpMenu, L"&Help" );

	fileMenu->Append( wxID_OPEN, "Load &File...\tCtrl-F", L"Load Bug Squash File" );
	fileMenu->Append( wxID_EXIT, "E&xit\tAlt-X", "Quit this program" );

	levelMenu->Append( IDM_LEVELONE, L"&Level One", L"Play Level One" );
	levelMenu->Append( IDM_LEVELTWO, L"&Level Two", L"Play Level Two" );
	levelMenu->Append( IDM_LEVELTHREE, L"&Level Three", L"Play Level Three" );
	levelMenu->Append( IDM_LEVELFOUR, L"&Level Four", L"Play Level Four" );

	viewMenu->Append( IDM_SHRINK, L"Shrink", L"Shrink the window to see outside of the game" );

	helpMenu->Append( wxID_ABOUT, "&About\tF1", "Show about dialogue" );

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

