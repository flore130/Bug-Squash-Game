/**
 * @file BugRedundancy.h
 * @author npmar
 */

#ifndef PROJECT1_BUGSQUASHLIB_BUGREDUNDANCY_H
#define PROJECT1_BUGSQUASHLIB_BUGREDUNDANCY_H

#include <wx/wx.h>
#include <random>
#include "Bug.h"


/**
 * Class for a bug of type Redundancy
 */
class BugRedundancy : public Bug
{
private:
	/// When this is false, it means that it is the parent and will spawn children when squashed.
	/// When it is true, it means that this redundancy bug's parent is squashed, and it's a child from it.
	/// Squashing it now will not spawn additional children.
	bool mParentSquashed = false;

	/// The left wing image of the bug
	std::shared_ptr<wxImage> mLeftWingImage;

	/// The left wing bitmap of the fly
	wxGraphicsBitmap mLeftWingBitmap;

	/// The right wing image of the bug
	std::shared_ptr<wxImage> mRightWingImage;

	/// The right wing bitmap of the fly
	wxGraphicsBitmap mRightWingBitmap;

	/// The top image
	std::shared_ptr<wxImage> mTopImage;

	/// The top image bitmap of the fly
	wxGraphicsBitmap mTopBitmap;

	/// The squashed image of the fly
	std::shared_ptr<wxImage> mSquashedImage;

	/// The last stopwatch time
	double mTime = 0;

	/// The bitmap of the squashed fly
	wxGraphicsBitmap mSquashedFly;

	/// Stopwatch used to measure elapsed time
	wxStopWatch mStopWatch;

	/// Determine whether the bug is to disappear or not
	bool mDisappearState = false;

	/// wing angle for rotation
	double mWingAngle = 0;



public:
	/// Default constructor (disabled)
	BugRedundancy() = delete;

	/// Copy constructor (disabled)
	BugRedundancy(const BugRedundancy &) = delete;

	/// Assignment operator
	void operator=(const BugRedundancy &) = delete;

	BugRedundancy(Level* level);

	double DistanceTo(std::shared_ptr<Item> item) override;

	void XmlLoad(wxXmlNode* node) override;

	void Draw(std::shared_ptr<wxGraphicsContext> gc) override;

	/**
	 * Accept a visitor
	 * @param visitor The visitor to accept
	 */
	void Accept( ItemVisitor* visitor ) override { visitor->VisitBugRedundancy( this ); }

	/**
	 * Returns the status of mParentSquashed
	 * @return mParentSquashed
	 */
	bool GetParentSquashedStatus() { return mParentSquashed; }

	/**
	 * Returns whether the bug should be shown on the screen or not
	 * @return a boolean indicating whether the bug should appear on the screen
	 */
	bool GetDisappearState() { return mDisappearState; }

	/**
	 * Create multiple redundancy flies
	 */
	 void SpawnRedundancyFlies();

	 void Update(double elapsed) override;

	 bool NukeItem() override;
};

#endif //PROJECT1_BUGSQUASHLIB_BUGREDUNDANCY_H


