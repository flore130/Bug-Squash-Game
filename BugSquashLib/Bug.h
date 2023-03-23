/**
 * @file Bug.h
 * @author Kyle Nowak
 *
 * Base bug class
 */

#ifndef PROJECT1_BUGSQUASHLIB_BUG_H
#define PROJECT1_BUGSQUASHLIB_BUG_H

#include "Item.h"

class Code;
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
	double mTime = 0;

	/// The speed the bug should move at in pixels per second
	double mSpeed = 0;

	/// The scale factor for the bug
	double mScale = 1;

	/// The image index of the bug in the sprite image
	int mImageIndex = 0;

	/// The number of sprites this bug will swap through
	int mSpriteCount = 0;

	/// The program this bug is associated with
	std::shared_ptr<Program> mProgram = nullptr;

	/// The squashed image
	std::shared_ptr<wxImage> mSquashedBugImage = nullptr;

	/// The code associated with this bug (fat bugs only)
	std::shared_ptr<Code> mCode = nullptr;

	/// A boolean to show if the bug has gotten to the program
	bool mHitProgram = false;


protected:
	Bug(Level *level, const std::wstring &filename, const std::wstring& squashedFilename, int spriteCount);

public:

	bool HitTest(double x, double y) override;

	/**
	 * Sets the speed of this bug
	 * @param newSpeed The new speed in pixels per second
	 */
	void SetSpeed(double newSpeed) { mSpeed = newSpeed; }

	/**
	 * Sets the scaling of this bug
 	* @param newScale The new scaling factor of the bug
 	*/
	void SetScale(double newScale) { mScale = newScale; }

	/**
	 * Sets the indicator whether the bug got to the program or not
	 */

	void SetHitProgram() { mHitProgram = true; }

	/**
	 * Get whether the bug hit the program or not
	 * @return a boolean indicating the bug got to the program
	 */
	 bool GetHitProgram() { return mHitProgram; }

	
	/**
 	* Sets the start time for this bug
 	* @param newStart How many seconds before a bug starts to move
 	*/
	void SetStart(double newStart) { mStartTime = newStart + 2; }

	/**
 	* Obtains the start time for this bug
 	* @return Returns the value of the start time member variable for this bug
	 */
	double GetStart() { return mStartTime; }

	/**
	 * Accept a visitor
	 * @param visitor The visitor to accept
	 */
	void Accept( ItemVisitor* visitor ) override {};

	virtual void Update(double elapsed) override;

	void SetProgram(wxXmlNode *node,std::shared_ptr<Program> parent) override;

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

	void SetIsSquashed( bool squashStatus );

	bool NukeItem() override;

	/**
	* Set the code that must be solved to squash a fat garbage or null bug
	* @param fatCode The code that is to be associated with a fat bug
	*/
	void SetCode (std::shared_ptr<Code> fatCode) {mCode = fatCode;}

	/**
	 * Get the code for this fat bug
	 * @return Pointer to this bug's code
	 */
	std::shared_ptr<Code> GetCode() { return mCode; }

	 /**
	  * Get the program the bug is associated with
	  * @return a pointer to the program the fly is associated with
	  */
	  std::shared_ptr<Program> GetProgram() { return mProgram;}

	  /**
	   * Get the speed the bug is moving at
	   * @return speed the bug is moving with
	   */
	   double GetSpeed () { return mSpeed; }
};

#endif //PROJECT1_BUGSQUASHLIB_BUG_H


