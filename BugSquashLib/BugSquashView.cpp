/**
 * @file BugSquashView.cpp
 * @author Ajuisiwon Azantilow
 */

#include "pch.h"
#include "BugSquashView.h"
#include <wx/dcbuffer.h>

using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
 * Initialize the bug squash view class
 * @param parent parent Frame
 */

void BugSquashView::Initialize(wxFrame *mainFrame)
{
	Create(mainFrame, wxID_ANY,
		   wxDefaultPosition, wxDefaultSize,
		   wxFULL_REPAINT_ON_RESIZE);
	wxWindow::SetBackgroundStyle(wxBG_STYLE_PAINT);
	Bind(wxEVT_PAINT, &BugSquashView::OnPaint, this);
	Bind(wxEVT_LEFT_DOWN, &BugSquashView::OnLeftDown, this);
	Bind(wxEVT_LEFT_DCLICK, &BugSquashView::OnDoubleClick, this);
	Bind(wxEVT_TIMER, &BugSquashView::OnTimer, this);
	Bind(wxEVT_MOTION, &BugSquashView::OnMouseMove, this);

	mTimer.SetOwner(this);
	mTimer.Start(FrameDuration);

	mStopWatch.Start();
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
//	mClickedItem = mBugSquash.HitTest(event.GetX(), event.GetY());
//	if (mClickedItem != nullptr)
//	{
//		// TODO: Decide what to do for the item. A visitor looks like a good option here
//	}
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
	dc.SetBackground(background);
	dc.Clear();

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