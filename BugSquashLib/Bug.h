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

	/// The image index of the bug in the sprite image
	int mImageIndex = 0;

	/// The number of sprites this bug will swap through
	int mSpriteCount = 0;

	/// The program this bug is associated with
	std::shared_ptr<Program> mProgram = nullptr;


public:
	bool HitTest(double x, double y);

	/**
	 * Sets the speed of this bug
	 * @param newSpeed The new speed in pixels per second
	 */
	void SetSpeed(double newSpeed) { mSpeed = newSpeed; }

	Bug(Level *level, const std::wstring &filename, int spriteCount);

	/**
	 * Accept a visitor
	 * @param visitor The visitor to accept
	 */
	void Accept( ItemVisitor* visitor ) override {};

	void Update(double elapsed) override;

	void SetProgram(wxXmlNode *node, std::shared_ptr<Program> parent) override;

	void XmlLoad(wxXmlNode *node) override;

	/**
	 * Changes the index of the bug image to be used in the sprite image
	 * @param numBugs
	 */
	void ChangeSpriteImageIndex(int numBugs){ mImageIndex = (mImageIndex + 1) % numBugs; }

	/**
	 * Get the index of the sprite image to use
	 * @return the index of the sprite image to use
	 */
	int GetSpriteImageIndex(){ return mImageIndex; }

	void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

};

#endif //PROJECT1_BUGSQUASHLIB_BUG_H

