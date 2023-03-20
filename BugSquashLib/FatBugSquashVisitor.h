/**
 * @file FatBugSquashVisitor.h
 * @author Kyle Nowak
 *
 * Concrete visitor used to squash Fat Bugs
 */

#ifndef PROJECT1_BUGSQUASHLIB_FATBUGSQUASHVISITOR_H
#define PROJECT1_BUGSQUASHLIB_FATBUGSQUASHVISITOR_H

#include "ItemVisitor.h"

class FatBugSquashVisitor : public ItemVisitor
{
private:
	/// Whether or not this visitor just visited a fat bug
	bool mVisitedFat = false;

	/// The FatNullBug this visitor just visited, if any
	FatNullBug* mNullBugVisited = nullptr;

	/// The FatGarbageBug this visitor just visited, if any
	FatGarbageBug* mGarbageBugVisited = nullptr;

public:
	void VisitFatNull(FatNullBug* bug) override;
	void VisitFatGarbage(FatGarbageBug* bug) override;

};

#endif //PROJECT1_BUGSQUASHLIB_FATBUGSQUASHVISITOR_H
