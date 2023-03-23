/**
 * @file SimpleBugSquashVisitor.h
 * @author Kev
 *
 * Class for the SimpleBugSquashVisitor
 */

#ifndef PROJECT1_BUGSQUASHLIB_SIMPLEBUGSQUASHVISITOR_H
#define PROJECT1_BUGSQUASHLIB_SIMPLEBUGSQUASHVISITOR_H

#include "ItemVisitor.h"

/*
 * Class SimpleBugSquashVisitor, visits and squashes simple bugs
 */
class SimpleBugSquashVisitor : public ItemVisitor
{
private:
	/// Is this Bug squashed yet
	bool mIsAlreadySquashed = false;

	/// Bug was squashed on this visit
	bool mJustSquashed = false;

	/// Squashed a bug
	bool mBugSquashed = false;

	/// Squashed a feature
	bool mFeatureSquashed = false;

public:

	/**
	 * Get whether it's a simple bug or not
	 * @return Is it a simple bug
	 */
	 bool JustSquashed() const { return mJustSquashed; }

	 void VisitBugGarbage( BugGarbage* bug ) override;

	 void VisitBugNull( BugNull* bug ) override;

	 void VisitBugRedundancy( BugRedundancy* bug ) override;

	 void VisitFeature( Feature* feature ) override;

	 void VisitBugNuke ( BugNuke* nuke) override;

	 /**
	  * Get if it was a bug that was squashed
	  * @return true if a bug was squashed
	  */
	 bool GoodSquash() const { return mBugSquashed; }

	 /**
	  * Get if it was a feature that was squashed
	  * @return true if a feature was squashed
	  */
	 bool BadSquash() const { return mFeatureSquashed; }

};

#endif //PROJECT1_BUGSQUASHLIB_SIMPLEBUGSQUASHVISITOR_H
