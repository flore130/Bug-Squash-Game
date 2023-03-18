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

	/// The last stopwatch time
	long mTime = 0;

	/// Stopwatch used to measure elapsed time
	wxStopWatch mStopWatch;

	/// The speed the bug should move at in pixels per second
	double mSpeed = 0;

	/// The image index of the bug in the sprite image
	int mImageIndex = 0;

	/// The number of sprites this bug will swap through
	int mSpriteCount = 0;

	/// The program this bug is associated with
	std::shared_ptr<Program> mProgram = nullptr;

	/// The splash image associated with the bug
	std::shared_ptr<wxImage> mSplashedImage = nullptr;

	/// The bitmap associated with the splash image
	wxGraphicsBitmap mSplashedBugBitmap;

	/// The squashed image
	std::shared_ptr<wxImage> mSquashedBugBitmap = nullptr;

protected:
	Bug(Level *level, const std::wstring &filename, const std::wstring& squashedFilename, int spriteCount);

public:
	bool HitTest(double x, double y);

	/**
	 * Sets the speed of this bug
	 * @param newSpeed The new speed in pixels per second
	 */
	void SetSpeed(double newSpeed) { mSpeed = newSpeed; }

	
	/**
 	* Sets the start time for this bug
 	* @param newStart How many seconds before a bug starts to move
 	*/
	void SetStart(double newStart) { mStartTime = newStart; }


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

	/**
	 * Determine if the bug is squashed or not
	 * @return a boolean indicating whether the bug is squashed or not
	 */
	bool GetIsSquashed() { return mIsSquashed; }

	/**
	 * Set the Bug status to squashed. Once true it can never be false
	 * @param squashStatus Set the bug's squash status
	 */
	 void SetIsSquashed( bool squashStatus ) { mIsSquashed |= squashStatus; }

};

#endif //PROJECT1_BUGSQUASHLIB_BUG_H


