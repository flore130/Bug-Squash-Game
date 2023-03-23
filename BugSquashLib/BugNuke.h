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
	bool mIsActive = false;

	bool mHasSpawned = false;
	/// The time the nuke should appear
	double mStartTime = 0;

	/// The last stopwatch time
	long mTime = 0;

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

	bool GetSpawned() { return mHasSpawned; }

	/**
	 * Determine if the BugNuke power up has been activated
 	 * @return a boolean indicating whether the power up was used or not
	 */
	bool GetIsActive() { return mIsActive; }

	void XmlLoad(wxXmlNode* node) override;

	/**
	 * Accept a visitor
	 * @param visitor The visitor to accept
	 */
	void Accept( ItemVisitor* visitor ) override { visitor->VisitBugNuke( this ); }

	void Draw(std::shared_ptr<wxGraphicsContext> gc) override;
};


#endif //PROJECT1_BUGSQUASHLIB_BUGNUKE_H
