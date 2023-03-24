/**
 * @file BugSquashView.cpp
 * @author Ajuisiwon Azantilow
 */

#include "pch.h"
#include <wx/dcbuffer.h>
#include "BugSquashView.h"
#include "SimpleBugSquashVisitor.h"
#include "FatBugSquashVisitor.h"
#include "CodeDlg.h"
#include "FatGarbageBug.h"
#include "FatNullBug.h"
#include "Level.h"
#include "Item.h"
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

	// Bind the menu handlers
	mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &BugSquashView::OnFileOpen, this, wxID_OPEN);

	mTimer.SetOwner(this);
	mTimer.Start(FrameDuration);

	mStopWatch.Start();

	// Start the game on level one
	wxCommandEvent blank_event;
	OnLevelOne( blank_event );
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
	levelMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, &BugSquashView::OnLevelZero, this, IDM_LEVELZERO);
	levelMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, &BugSquashView::OnLevelOne, this, IDM_LEVELONE);
	levelMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, &BugSquashView::OnLevelTwo, this, IDM_LEVELTWO);
	levelMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, &BugSquashView::OnLevelThree, this, IDM_LEVELTHREE);
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
 * Paint event, draws the window
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

	// Get BugSquash to check the current items
	mBugSquash.CheckIfAllBugsAreSquashed();

	// Tell the game class to draw
	wxRect rect = GetRect();
	mBugSquash.OnDraw(gc, rect.GetWidth(), rect.GetHeight());
}

/**
 * Handle the left mouse button down event
 * @param event
 */
void BugSquashView::OnLeftDown(wxMouseEvent &event)
{
	auto item = mBugSquash.HitTest(event.GetX(), event.GetY());
	if ( item != nullptr )
	{
		// Initialize our visitor
		SimpleBugSquashVisitor visitor;

		// Send the visitor to just this item
		// If the item is a simple & un-squashed bug, the visitor
		// tell the item to squash itself.
		item->Accept( &visitor );

		// If we squashed the bug this time around, scoreboard must be updated
		if ( visitor.JustSquashed() )
		{
			// Did we squash a bug
			if ( visitor.GoodSquash() )
			{
				mBugSquash.FixedIncrement();
			}
			// Did we squash a feature
			else if ( visitor.BadSquash() )
			{
				mBugSquash.OopsIncrement();
			}
		}
	}
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
	auto item = mBugSquash.HitTest(event.GetX(), event.GetY());
	if ( item != nullptr )
	{
		// Initialize our visitor
		FatBugSquashVisitor visitor;

		// Send the visitor to just this item
		// If the item is a simple & un-squashed bug, the visitor
		// tell the item to squash itself.
		item->Accept( &visitor );

		FatGarbageBug* visitedGarbage = visitor.GetVisitedGarbage();
		FatNullBug* visitedNull = visitor.GetVisitedNull();

		shared_ptr<Code> code = nullptr;
		if (visitedGarbage != nullptr)
		{
			code = visitedGarbage->GetCode();
		}
		else if (visitedNull != nullptr)
		{
			code = visitedNull->GetCode();
		}


		if (code != nullptr)
		{
			mBugSquash.SetIsEditingCode(true);
			CodeDlg dlg(this, code);
			dlg.Initialize();

			dlg.ShowModal();
		}

	}
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

/**
 * Level>Level Zero menu handler
 * @param event Menu event
 */
void BugSquashView::OnLevelZero(wxCommandEvent &event)
{
	auto filename = L"data/level0.xml";
	mBugSquash.Load(filename);
	Refresh();
}

/**
 * Level>Level One menu handler
 * @param event Menu event
 */
void BugSquashView::OnLevelOne(wxCommandEvent &event)
{
	auto filename = L"data/level1.xml";
	mBugSquash.Load(filename);
	Refresh();
}

/**
 * Level>Level Two menu handler
 * @param event Menu event
 */
void BugSquashView::OnLevelTwo(wxCommandEvent &event)
{
	auto filename = L"data/level2.xml";
	mBugSquash.Load(filename);
	Refresh();
}

/**
 * Level>Level Three menu handler
 * @param event Menu event
 */
void BugSquashView::OnLevelThree(wxCommandEvent &event)
{
	auto filename = L"data/level3.xml";
	mBugSquash.Load(filename);
	Refresh();
}
