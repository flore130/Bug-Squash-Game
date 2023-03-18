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
	/// Is the item clicked on a simple bug
	bool mIsSimpleBug = false;

	/// Is this Bug squashed yet
	bool mIsAlreadySquashed = false;

public:
	/**
	 * Get whether it's a simple bug or not
	 * @return Is it a simple bug
	 */
	 bool IsSimpleBug() const { return mIsSimpleBug; }

	 /**
	  * Get whether the bug has been squashed
	  * @return If it's been squashed
	  */
	  bool IsAlreadySquashed() const { return mIsAlreadySquashed; }

	 void VisitBugGarbage( BugGarbage* bug );

	 void VisitBugNull( BugNull* bug );

	 void VisitBugRedundancy( BugRedundancy* bug );

	 void VisitFeature( Feature* feature );

};

#endif //PROJECT1_BUGSQUASHLIB_SIMPLEBUGSQUASHVISITOR_H
