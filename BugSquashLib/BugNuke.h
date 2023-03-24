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
	/// Whether or not the BugNuke item has spawned in the level yet
	bool mHasSpawned = false;

	/// Whether or not the BugNuke item has despawned/disappeared yet
	bool mHasDespawned = false;

	/// The time the nuke should appear
	double mStartTime = 0;

	/// The amount of time that the BugNuke power up will display on screen
	const static int SpawnTime = 2;

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
	void SetStart(double newStart) { mStartTime = newStart + Item::TextDelay; }


	bool HitTest(double x, double y) override;

	void XmlLoad(wxXmlNode* node) override;

	void Activate();

	/**
	 * Accept a visitor
	 * @param visitor The visitor to accept
	 */
	void Accept( ItemVisitor* visitor ) override { visitor->VisitBugNuke( this ); }

	void Update (double elapsed) override;

	void Draw(std::shared_ptr<wxGraphicsContext> gc) override;
};


#endif //PROJECT1_BUGSQUASHLIB_BUGNUKE_H
