/**
 * @file Code.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include <wx/regex.h>
#include "Code.h"


/**
 * Constructor
 * @param node the <code> node to read from
 */
Code::Code(wxXmlNode* node, std::shared_ptr<Bug> bug)
{
	mBug = bug;

	wxString code = node->GetNodeContent();
	mCurrentCode = code.ToStdWstring();

	mPass = node->GetAttribute(L"pass", L"");

	auto child = node->GetChildren();
	for( ; child; child = child->GetNext())
	{
		if (child->GetName() == "answer")
		{
			mExampleAnswer = child->GetNodeContent().ToStdWstring();
		}
	}
}


/**
 * Check whether or not the code is currently passing
 * @return true if this code passes, false otherwise
 */
bool Code::Passes()
{
	wxRegEx regex = wxRegEx(mPass);
	if (regex.IsValid())
	{
		return regex.Matches(mCurrentCode);
	}
	//return std::regex_search(mCurrentCode, std::wregex(mPass));
	return false;
}


/**
 * Sets the current code in this object
 * @param newCode the string to replace the old code with
 */
void Code::SetCode(const std::wstring &newCode)
{
	mCurrentCode = newCode;
}