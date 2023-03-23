/**
 * @file Code.h
 * @author Kyle Nowak
 *
 * Class to handle Fat Bug code checking
 */

#ifndef PROJECT1_BUGSQUASHLIB_CODE_H
#define PROJECT1_BUGSQUASHLIB_CODE_H

#include <regex>

class Bug;

/**
 * Class to handle Fat Bug code checking
 */
class Code
{
private:
	/// The code the player currently has typed in for this <code> </code> tag
	std::wstring mCurrentCode;

	/// The regular expression needed in mCurrentCode to be considered passing
	std::wstring mPass;

	/// Example answer code that will pass the regular expression determined by mPass
	std::wstring mExampleAnswer;

	/// The bug this code is for
	std::shared_ptr<Bug> mBug = nullptr;

public:
	/// Default constructor (disabled)
	Code() = delete;

	/// Copy constructor (disabled)
	Code(const Code &) = delete;

	/// Assignment operator
	void operator=(const Code &) = delete;

	Code(wxXmlNode* node, std::shared_ptr<Bug> bug);

	bool Passes();

	void SetCode(const std::wstring &newCode);

	/**
	 * Return string representation of the code currently stored in this object
	 * @return the code currently stored in this object
	 */
	std::wstring GetCurrentCode() { return mCurrentCode; }

	/**
	 * Get an example solution to this code problem
	 * @return string containing the example solution
	 */
	std::wstring GetExampleAnswer() { return mExampleAnswer; }

	/**
	 * Get the bug this code is associated with
	 * @return shared ptr to the bug
	 */
	std::shared_ptr<Bug> GetBug() { return mBug; }

};

#endif //PROJECT1_BUGSQUASHLIB_CODE_H
