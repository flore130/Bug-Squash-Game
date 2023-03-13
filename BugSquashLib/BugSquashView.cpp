/**
 * @file BugSquashView.cpp
 * @author Ajuisiwon Azantilow
 */

#include "pch.h"
#include "BugSquashView.h"
#include <wx/dcbuffer.h>
#include "ids.h"

using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
 * Initialize the bug squash view class
 * @param mainFrame parent Frame
 */

void BugSquashView::Initialize(wxFrame *mainFrame)
{
	Create(mainFrame, wxID_ANY,
		   wxDefaultPosition, wxDefaultSize,
		   wxFULL_REPAINT_ON_RESIZE);

	wxWindow::SetBackgroundStyle(wxBG_STYLE_PAINT);

	// Bind the event handler to initialize
	Bind(wxEVT_PAINT, &BugSquashView::OnPaint, this);

	// Bind mouse to BugSquashView window
	Bind(wxEVT_LEFT_DOWN, &BugSquashView::OnLeftDown, this);
	Bind(wxEVT_LEFT_DCLICK, &BugSquashView::OnDoubleClick, this);
	Bind(wxEVT_TIMER, &BugSquashView::OnTimer, this);
	Bind(wxEVT_MOTION, &BugSquashView::OnMouseMove, this);

	/// Bind the menu handlers
	mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &BugSquashView::OnFileOpen, this, wxID_OPEN);

	mTimer.SetOwner(this);
	mTimer.Start(FrameDuration);

	mStopWatch.Start();
}

/**
 * Add menus specific to the view
 * @param mainFrame The main frame that owns the menu bar
 * @param menuBar The menu bar to add menus to
 * @param levelMenu The level menu, so we can add to it if we wish
 * @param viewMenu The view menu, so we can add to it if we wish
 */
void BugSquashView::AddMenus( wxFrame* mainFrame, wxMenuBar* menuBar, wxMenu* levelMenu, wxMenu* viewMenu )
{
	// Add the options to our level menu to select certain levels
	levelMenu->Append( IDM_LEVELZERO, L"&Level 0", L"Play Level Zero" );
	levelMenu->Append( IDM_LEVELONE, L"&Level 1", L"Play Level One" );
	levelMenu->Append( IDM_LEVELTWO, L"&Level 2", L"Play Level Two" );
	levelMenu->Append( IDM_LEVELTHREE, L"&Level 3", L"Play Level Three" );

	// Add the option of shrink to our view menu
	viewMenu->Append( IDM_SHRINK, L"Shrink", L"Shrink the window to see outside of the game", wxITEM_CHECK );
	mainFrame->Bind( wxEVT_COMMAND_MENU_SELECTED, &BugSquashView::OnShrink, this, IDM_SHRINK );
	mainFrame->Bind( wxEVT_UPDATE_UI, &BugSquashView::OnUpdateShrink, this, IDM_SHRINK );
}



/**
* Handle the timer event
 * @param event Timer event
*/

void BugSquashView::OnTimer(wxTimerEvent &event)
{
	Refresh();
}

/**
* Handle the left mouse button down event
 * @param event
*/

void BugSquashView::OnLeftDown(wxMouseEvent &event)
{
	mBugSquash.OnLeftDown(event.GetX(), event.GetY());
}

/**
 Paint event, draws the window
 * @param event Paint event object
*/

void BugSquashView::OnPaint(wxPaintEvent &event)
{
	// Create a double-buffered display context
	wxAutoBufferedPaintDC dc(this);

	// Clear the image to black
	wxBrush background(*wxBLACK);
	wxWindow::SetBackgroundStyle(wxBG_STYLE_PAINT);
	dc.SetBackground(background);
	dc.Clear();

	// Compute the time that has elapsed
	// since the last call to OnPaint.
	auto newTime = mStopWatch.Time();
	auto elapsed = (double)(newTime - mTime) * 0.001;
	mTime = newTime;

	mBugSquash.Update(elapsed);

	// Create a graphics context
	auto gc =
		std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

	// Tell the game class to draw
	wxRect rect = GetRect();
	mBugSquash.OnDraw(gc, rect.GetWidth(), rect.GetHeight());
}

/**
* Handle the left mouse button down event
 * @param event Mouse event
*/

void BugSquashView::OnMouseMove(wxMouseEvent &event)
{
	// TODO : When will this function be useful?
}

/**
* Handle the double click mouse button event
 * @param event Mouse event
*/

void BugSquashView::OnDoubleClick(wxMouseEvent &event)
{
//	mClickedItem = mBugSquash.HitTest(event.GetX(), event.GetY());
//	if (mClickedItem != nullptr)
//	{
//		// TODO : Decide what to do for the item. A visitor or a virtual function may be useful here
//	}
}

/**
 * File>Open menu handler
 * @param event Menu event
 */
void BugSquashView::OnFileOpen(wxCommandEvent& event)
{
	wxFileDialog loadFileDialog(this, L"Load BugSquash file", L"", L"",
								L"BugSquash Files (*.xml)|*.xml", wxFD_OPEN);
	if (loadFileDialog.ShowModal() == wxID_CANCEL)
	{
		return;
	}

	auto filename = loadFileDialog.GetPath();
	mBugSquash.Load(filename);
	Refresh();

}

/**
 * Menu event handler for View>Shrink menu option
 * @param event Menu event
 */
void BugSquashView::OnShrink( wxCommandEvent& event )
{
	mBugSquash.SetShrinked( !mBugSquash.GetShrinked() );
}

/**
 * Update handler for View>Shrink menu option
 * @param event Update event
 */
void BugSquashView::OnUpdateShrink( wxUpdateUIEvent& event )
{
	event.Check( mBugSquash.GetShrinked() );
}

