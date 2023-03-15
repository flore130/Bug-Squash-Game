/**
 * @file Bug.h
 * @author Kyle Nowak
 *
 * Base bug class
 */

#ifndef PROJECT1_BUGSQUASHLIB_BUG_H
#define PROJECT1_BUGSQUASHLIB_BUG_H

#include "Item.h"

class Program;

/**
 * Base bug class
 */
class Bug : public Item
{
private:
	/// The status of whether the bug is squashed or not
	bool mIsSquashed = false;

	/// The time the bug should start moving
	double mStartTime = 0;

	/// The speed the bug should move at in pixels per second
	double mSpeed = 0;

	/// The program this bug is associated with
	std::shared_ptr<Program> mProgram = nullptr;


public:
	bool HitTest(double x, double y);

	/**
	 * Set the program this bug is associated with
	 * @param program The program to set
	 */
	void SetProgram(std::shared_ptr<Program> program) { mProgram = program; }

	/**
	 * Sets the speed of this bug
	 * @param newSpeed The new speed in pixels per second
	 */
	void SetSpeed(double newSpeed) { mSpeed = newSpeed; }

	Bug(Level *level, const std::wstring &filename);

	/**
	 * Accept a visitor
	 * @param visitor The visitor to accept
	 */
	void Accept( ItemVisitor* visitor ) override {};

	void Update(double elapsed) override;

	void SetProgram(wxXmlNode *node, std::shared_ptr<Program> parent) override;

	void XmlLoad(wxXmlNode *node);

};

#endif //PROJECT1_BUGSQUASHLIB_BUG_H

