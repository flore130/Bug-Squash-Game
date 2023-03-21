/**
 * @file RemoveBugVisitor.h
 * @author Ajuisiwon Azantilow
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_REMOVEBUGVISITOR_H
#define PROJECT1_BUGSQUASHLIB_REMOVEBUGVISITOR_H

#include "ItemVisitor.h"
#include "BugGarbage.h"
#include "BugNull.h"
#include "BugRedundancy.h"
#include "Feature.h"
#include "FatNullBug.h"
#include "FatGarbageBug.h"

class RemoveBugVisitor : public ItemVisitor
{
private:
	bool mRemoveItem = false;

public:
	void VisitBugGarbage( BugGarbage* bug ) override;

	void VisitBugNull( BugNull* bug ) override;

	void VisitBugRedundancy( BugRedundancy* bug ) override;

	void VisitFeature( Feature* feature ) override;

	void VisitFatNull(FatNullBug* fatNullBug) override;

	void VisitFatGarbage(FatGarbageBug* fatGarbage) override;

	bool GetRemoveItemState () { return mRemoveItem; }

};

#endif //PROJECT1_BUGSQUASHLIB_REMOVEBUGVISITOR_H
