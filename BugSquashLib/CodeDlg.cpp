/**
 * @file CodeDlg.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "CodeDlg.h"
#include "BugSquashView.h"
#include "Bug.h"

using namespace std;

/**
 * Constructor
 * @param window the window this dialog box should be a child of
 * @param code the code this dialog box should display
 */
CodeDlg::CodeDlg(BugSquashView* view, shared_ptr<Code> code) : mView(view), mCode(code)
{
}

/**
 * Initialize this dialog box
 */
void CodeDlg::Initialize()
{
	mView->PauseStopwatch();
	Create(mView, wxID_ANY, L"FatBug Code Editor",
		   wxDefaultPosition, wxSize( 500, 600));

	Bind(wxEVT_CLOSE_WINDOW, &CodeDlg::OnClose, this);

	auto sizer = new wxBoxSizer(wxVERTICAL);

	mTextCtrl = new wxTextCtrl(this,wxID_ANY, wxEmptyString,
								   wxDefaultPosition, wxSize( 500, 500), wxTE_MULTILINE);

	auto button = new wxButton(this, wxID_ANY, L"OK", wxDefaultPosition, wxSize(100, 10));

	button->Bind(wxEVT_BUTTON, &CodeDlg::OnOk, this);

	sizer->Add(mTextCtrl, 1, wxALIGN_LEFT | wxEXPAND, 5);
	sizer->Add(button, 1, wxALIGN_CENTER | wxALL, 10);
	// wxButton.Connect to bind button to event handler

	mTextCtrl->AppendText(mCode->GetCurrentCode());

	SetSizer(sizer);
	Layout();

}


/**
 * Event handler for button press
 * @param event
 */
void CodeDlg::OnOk(wxCommandEvent& event)
{
	wxString currentText = mTextCtrl->GetValue();
	mCode->SetCode(currentText.ToStdWstring());

	if (mCode->Passes())
	{
		mCode->GetBug()->SetIsSquashed(true);
		mView->FixedIncrement();
	}

	mView->ResumeStopwatch();
	EndModal(wxID_OK);
}

/**
 * Event handler for closing this window
 * @param event
 */
void CodeDlg::OnClose(wxCloseEvent& event)
{
	mView->ResumeStopwatch();
	EndModal(wxID_CANCEL);
}