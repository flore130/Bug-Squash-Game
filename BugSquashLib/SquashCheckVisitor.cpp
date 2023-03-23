/**
 * @file SquashCheckVisitor.cpp
 * @author Kev
 */

#include "pch.h"
#include "SquashCheckVisitor.h"
#include "BugGarbage.h"
#include "FatGarbageBug.h"
#include "BugNull.h"
#include "FatNullBug.h"
#include "BugRedundancy.h"
#include "Feature.h"

/**
  * Visit the BugGarbage object
  * @param bug Bug we are visiting
  */
void SquashCheckVisitor::VisitBugGarbage( BugGarbage* bug )
{
	mAllSquashed &= bug->GetIsSquashed();
}

/**
 * Visit the FatGarbageBug object
 * @param bug Bug we are visiting
 */
void SquashCheckVisitor::VisitFatGarbage( FatGarbageBug* bug )
{
	mAllSquashed &= bug->GetIsSquashed();
}

/**
  * Visit the BugNull object
  * @param bug Bug we are visiting
  */
void SquashCheckVisitor::VisitBugNull( BugNull* bug )
{
	mAllSquashed &= bug->GetIsSquashed();
}

/**
 * Visit the FatNullBug object
 * @param bug Bug we are visiting
 */
void SquashCheckVisitor::VisitFatNull( FatNullBug* bug )
{
	mAllSquashed &= bug->GetIsSquashed();
}

/**
  * Visit the BugRedundancy object
  * @param bug Bug we are visiting
  */
void SquashCheckVisitor::VisitBugRedundancy( BugRedundancy *bug )
{
	mAllSquashed &= bug->GetIsSquashed();
}

/**
 * Visit the Feature object
 * @param feature Feature we are visiting
 */
void SquashCheckVisitor::VisitFeature( Feature *feature )
{
	mAllSquashed &= feature->GetIsSquashed();
}