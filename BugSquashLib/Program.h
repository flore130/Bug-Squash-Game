/**
 * @file Program.h
 * @author Ricardo Flores
 *
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_PROGRAM_H
#define PROJECT1_BUGSQUASHLIB_PROGRAM_H

#include "Level.h"
#include "Item.h"
#include <vector>

/**
 * Program item class
 */
class Program : public Item
{
private:
	/// Default constructor (disabled)
	Program() = delete;
	
	/// Copy constructor (disabled)
	Program(const Program &) = delete;
	
	/// Assignment operator
	void operator=(const Program &) = delete;

	///coordinates for program text location
	int mX=0;
	int mY=0;

	///Contains the program text for each program in level
	std::vector<wxString> mProgramTexts;


public:
	Program(Level* level);

	void XmlLoad(wxXmlNode* node) override;

	/**
	 * Accept a visitor
	 * @param visitor The visitor to accept
	 */
	void Accept( ItemVisitor* visitor ) override { visitor->VisitProgram( this ); }

	void Draw(std::shared_ptr<wxGraphicsContext> gc);

	void DrawText(std::shared_ptr<wxGraphicsContext> gc, wxString text, int x, int y);

	///Gets location from xml file
	void SetLocation(int x, int y)
	{
		mX = x;
		mY = y;
	}

	///Adds to the list of program texts we have for the level
	void SetProgramTexts(wxString name) {mProgramTexts.push_back(name);}
};

#endif //PROJECT1_BUGSQUASHLIB_PROGRAM_H


