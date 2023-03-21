/**
 * @file CodeDlg.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "CodeDlg.h"

using namespace std;

/**
 * Constructor
 * @param window the window this dialog box should be a child of
 * @param code the code this dialog box should display
 */
CodeDlg::CodeDlg(wxWindow* window, shared_ptr<Code> code) : mWindow(window), mCode(code)
{
}

/**
 * Initialize this dialog box
 */
void CodeDlg::Initialize()
{
	Create(mWindow, wxID_ANY, L"FatBug Code Editor", wxDefaultPosition, wxSize( 1000, 800));

	wxTextCtrl textCtrl = wxTextCtrl(this,wxID_ANY, mCode->GetCurrentCode(),
															  wxDefaultPosition, wxSize( 1000, 800));

	textCtrl.Show(true);
	bool isShown = textCtrl.IsShown();
	bool canSee = textCtrl.IsShownOnScreen();

}