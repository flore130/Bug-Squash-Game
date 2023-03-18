/**
 * @file Code.h
 * @author Kyle Nowak
 *
 * Class to handle Fat Bug code checking
 */

#ifndef PROJECT1_BUGSQUASHLIB_CODE_H
#define PROJECT1_BUGSQUASHLIB_CODE_H

#include <regex>


/**
 * Class to handle Fat Bug code checking
 */
class Code
{
private:
	/// The code the player currently has typed in for this <code> tag
	std::wstring mCurrentCode;

	/// The regular expression needed in mCurrentCode to be considered passing
	std::wstring mPass;

protected:
	/**
	 * Used in testing to print the code currently in this object
	 * @return the code currently stored in this object
	 */
	std::wstring GetCurrentCode() { return mCurrentCode; }

public:
	/// Default constructor (disabled)
	Code() = delete;

	/// Copy constructor (disabled)
	Code(const Code &) = delete;

	/// Assignment operator
	void operator=(const Code &) = delete;

	Code(wxXmlNode* node);

	bool Passes();

	void SetCode(const std::wstring &newCode);


};

#endif //PROJECT1_BUGSQUASHLIB_CODE_H
