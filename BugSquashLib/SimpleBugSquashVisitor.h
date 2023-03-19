/**
 * @file SimpleBugSquashVisitor.h
 * @author Kev
 *
 * Class for the SimpleBugSquashVisitor
 */

#ifndef PROJECT1_BUGSQUASHLIB_SIMPLEBUGSQUASHVISITOR_H
#define PROJECT1_BUGSQUASHLIB_SIMPLEBUGSQUASHVISITOR_H

#include "ItemVisitor.h"

class BugGarbage;
class BugNull;
class BugGarbage;
class BugRedundancy;


class SimpleBugSquashVisitor : public ItemVisitor
{
private:
	/// Is this Bug squashed yet
	bool mIsAlreadySquashed = false;

	/// Bug was squashed on this visit
	bool mJustSquashed = false;

public:
	/**
	 * Get whether it's a simple bug or not
	 * @return Is it a simple bug
	 */
	 bool JustSquashed() const { return mJustSquashed; }

	 void VisitBugGarbage( BugGarbage* bug );

	 void VisitBugNull( BugNull* bug );

	 void VisitBugRedundancy( BugRedundancy* bug );

	 void VisitFeature( Feature* feature );

};

#endif //PROJECT1_BUGSQUASHLIB_SIMPLEBUGSQUASHVISITOR_H
