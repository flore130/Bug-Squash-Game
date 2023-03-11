/**
 * @file MainFrame.h
 * @author Kev
 */

#ifndef PROJECT1_BUGSQUASHLIB_MAINFRAME_H
#define PROJECT1_BUGSQUASHLIB_MAINFRAME_H

class BugSquashView;

/**
 * The top-level ( main ) frame of the application
 */
class MainFrame : public wxFrame
{
private:
	/// View class for our game
	BugSquashView* mBugSquashView;

	void OnExit( wxCommandEvent& event );
	void OnAbout( wxCommandEvent& event );

public:
	void Initialize();
};

#endif //PROJECT1_BUGSQUASHLIB_MAINFRAME_H
