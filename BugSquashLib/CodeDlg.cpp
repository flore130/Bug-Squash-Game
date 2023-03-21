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

	auto sizer = new wxBoxSizer(wxVERTICAL);

	auto textCtrl = new wxTextCtrl(this,wxID_ANY, wxEmptyString,
								   wxDefaultPosition, wxSize( 1000, 800), wxTE_MULTILINE);

	sizer->Add(textCtrl, 1, wxALIGN_LEFT | wxEXPAND, 5);
	// wxButton.Connect to bind button to event handler
	// Add button to sizer

	textCtrl->AppendText(mCode->GetCurrentCode());

	SetSizer(sizer);
	Layout();

}