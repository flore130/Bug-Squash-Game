/**
 * @file BugStateVisitor.h
 * @author Ajuisiwon Azantilow
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_BUGSTATEVISITOR_H
#define PROJECT1_BUGSQUASHLIB_BUGSTATEVISITOR_H

#include "ItemVisitor.h"

/**
 * Class BugStateVisitor. Visits and determines if bugs are to be removed or if they are missed
 */
class BugStateVisitor : public ItemVisitor
{
private:
	/// A boolean to detect that the bug needs to be removed from the program
	bool mRemoveItem = false;

	/// A boolean to determine if missed counter should be increased on the scoreboard or not
	bool mGotMissed = true;

public:
	void VisitBugGarbage( BugGarbage* bug ) override;

	void VisitBugNull( BugNull* bug ) override;

	void VisitBugRedundancy( BugRedundancy* bug ) override;

	void VisitFeature( Feature* feature ) override;

	void VisitFatNull(FatNullBug* fatNullBug) override;

	void VisitFatGarbage(FatGarbageBug* fatGarbage) override;

	/**
	 * Return whether the item should be removed from the game or not
	 * @return the removal state of the bug
	 */
	bool GetRemoveItemState () { return mRemoveItem; }


	/**
	 * Return whether the bug should increase the missed counter on the scoreboard
	 * @return a boolean indicating whether the bug should be removed from the item or not
	 */
	bool GetMissedItemState () { return mGotMissed; }

};

#endif //PROJECT1_BUGSQUASHLIB_BUGSTATEVISITOR_H
