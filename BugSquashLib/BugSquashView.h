/**
 * @file BugSquashView.h
 * @author Ajuisiwon Azantilow
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_BUGSQUASHVIEW_H
#define PROJECT1_BUGSQUASHLIB_BUGSQUASHVIEW_H

#include "BugSquash.h"
/**
 * Class that contains all the views on the bug squash game
 */
class BugSquashView : public wxWindow
{
private:
	/// An object that describes our bug squash
	BugSquash mBugSquash;

	/// An object that describes the clicked item in the bug squash
	std::shared_ptr<Item> mClickedItem = nullptr;

	/// The timer that allows for animation
	wxTimer mTimer;

	/// Stopwatch used to measure elapsed time
	wxStopWatch mStopWatch;

	/// The last stopwatch time
	long mTime = 0;

	void OnTimer(wxTimerEvent& event);
	void OnLeftDown(wxMouseEvent &event);
	void OnPaint(wxPaintEvent& event);
	void OnDoubleClick(wxMouseEvent& event);
	void OnMouseMove(wxMouseEvent& event);

	void OnShrink( wxCommandEvent& event );
	void OnUpdateShrink( wxUpdateUIEvent& event );

public:
	void Initialize(wxFrame* parent);
	void OnFileOpen(wxCommandEvent& event);
	void AddMenus(wxFrame *mainFrame, wxMenuBar *menuBar, wxMenu *levelMenu, wxMenu *viewMenu);
	void OnLevelZero(wxCommandEvent& event);
	void OnLevelOne(wxCommandEvent& event);
	void OnLevelTwo(wxCommandEvent& event);
	void OnLevelThree(wxCommandEvent& event);

	/**
	 * Stop the timer so we can close
	 */
	void StopTimer() {mTimer.Stop();}

	/**
	 * Pause stopwatch
	 *
	 * Used to pause game while player edits fat bug code
	 */
	void PauseStopwatch() { mStopWatch.Pause(); }

	/**
	 * Resume stopwatch
	 */
	void ResumeStopwatch() { mStopWatch.Resume(); }

	/**
	 * Increments fixed count of the current level's scoreboard
	 */
	void FixedIncrement() { mBugSquash.FixedIncrement(); }
};

#endif //PROJECT1_BUGSQUASHLIB_BUGSQUASHVIEW_H
