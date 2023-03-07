/**
 * @file MainFrame.h
 * @author Kev
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_MAINFRAME_H
#define PROJECT1_BUGSQUASHLIB_MAINFRAME_H

/**
 * The top-level ( main ) frame of the application
 */
class MainFrame : public wxFrame
{
private:
	void OnExit( wxCommandEvent& event );
	void OnAbout( wxCommandEvent& event );

public:
	void Initialize();
};

#endif //PROJECT1_BUGSQUASHLIB_MAINFRAME_H
