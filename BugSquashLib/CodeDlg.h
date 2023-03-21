/**
 * @file CodeDlg.h
 * @author Kyle Nowak
 *
 * Dialog box class for displaying FatBug code
 */

#ifndef PROJECT1_BUGSQUASHLIB_CODEDLG_H
#define PROJECT1_BUGSQUASHLIB_CODEDLG_H

#include "Code.h"

/**
 * Dialog box class for displaying FatBug code
 */
class CodeDlg : public wxDialog
{
private:
	/// The parent window for this dialog box
	wxWindow* mWindow = nullptr;

	/// The code object for this dialog box
	std::shared_ptr<Code> mCode = nullptr;

public:
	/// Default constructor (disabled)
	CodeDlg() = delete;

	/// Copy constructor (disabled)
	CodeDlg(const CodeDlg &) = delete;

	/// Assignment operator
	void operator=(const CodeDlg &) = delete;

	CodeDlg(wxWindow* window, std::shared_ptr<Code> code);

	void Initialize();

};

#endif //PROJECT1_BUGSQUASHLIB_CODEDLG_H
