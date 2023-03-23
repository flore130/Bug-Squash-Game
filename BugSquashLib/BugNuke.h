/**
 * @file BugNuke.h
 * @author npmar
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_BUGNUKE_H
#define PROJECT1_BUGSQUASHLIB_BUGNUKE_H

#include "Level.h"
#include "Item.h"

/**
 * Class for the nuke power up item
 */
class BugNuke : public Item
{
private:
	/// Whether or not the power up has been activated
	bool mIsActive = false;

	/// Whether or not the BugNuke item has spawned in the level yet
	bool mHasSpawned = false;

	/// The time the nuke should appear
	double mStartTime = 0;

	/// The amount of time the BugNuke has between spawning and despawning
	long mTime = 2;

	/// Stopwatch used to measure elapsed time
	wxStopWatch mStopWatch;

public:
	/// Default constructor (disabled)
	BugNuke() = delete;

	/// Copy constructor (disabled)
	BugNuke(const BugNuke &) = delete;

	/// Assignment operator
	void operator=(const BugNuke &) = delete;

	BugNuke(Level* level);

	/**
 	* Sets the start time for this bug nuke item
 	* @param newStart How many seconds before a bug nuke will appear
 	*/
	void SetStart(double newStart) { mStartTime = newStart + 2; }


	bool HitTest(double x, double y) override;

	void XmlLoad(wxXmlNode* node) override;

	/**
 	* Activates the BugNuke ability, which squashes all bugs on screen
 	*/
	void Activate();

	/**
	 * Accept a visitor
	 * @param visitor The visitor to accept
	 */
	void Accept( ItemVisitor* visitor ) override { visitor->VisitBugNuke( this ); }

	void Draw(std::shared_ptr<wxGraphicsContext> gc) override;
};


#endif //PROJECT1_BUGSQUASHLIB_BUGNUKE_H
