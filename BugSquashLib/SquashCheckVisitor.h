/**
 * @file SquashCheckVisitor.h
 * @author Kev
 *
 * Class for SquashCheckVisitor
 */

#ifndef PROJECT1_BUGSQUASHLIB_SQUASHCHECKVISITOR_H
#define PROJECT1_BUGSQUASHLIB_SQUASHCHECKVISITOR_H

#include "ItemVisitor.h"

/**
 * Class SquashCheckVisitor, checks if bugs are squashed or not
 */
class SquashCheckVisitor : public ItemVisitor
{
private:
	/// Whether or not all items are squashed, uses negative logic. Will start high and be set low if
	/// any bug is not squashed
	bool mAllSquashed = true;

public:

	void VisitBugGarbage( BugGarbage* bug ) override;

	void VisitFatGarbage( FatGarbageBug* bug ) override;

	void VisitBugNull( BugNull* bug ) override;

	void VisitFatNull( FatNullBug* bug ) override;

	void VisitBugRedundancy( BugRedundancy* bug ) override;

	void VisitFeature( Feature* feature ) override;

	/**
	 * Get the squashed status of all bugs
	 * @return true if all bugs are squashed
	 */
	bool GetAllSquashed() const { return mAllSquashed; }
};

#endif //PROJECT1_BUGSQUASHLIB_SQUASHCHECKVISITOR_H
