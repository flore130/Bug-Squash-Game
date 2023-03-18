/**
 * @file Code.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "Code.h"

/**
 * Constructor
 * @param node the <code> node to read from
 */
Code::Code(wxXmlNode* node)
{
	wxString code = node->GetNodeContent();
	mCurrentCode = code.ToStdWstring();

	mPass = node->GetAttribute(L"pass", L"");
}


/**
 * Check whether or not the code is currently passing
 * @return true if this code passes, false otherwise
 */
bool Code::Passes()
{
	return std::regex_search(mCurrentCode, std::wregex(mPass));
}