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
	Create( nullptr, wxID_ANY, L"BugSquash", wxDefaultPosition, wxSize( 1000, 1250 ) );
}
