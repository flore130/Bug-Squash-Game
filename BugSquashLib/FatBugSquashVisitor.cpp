/**
 * @file FatBugSquashVisitor.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "FatBugSquashVisitor.h"
#include "FatGarbageBug.h"
#include "FatNullBug.h"

/**
 * Visit a FatGarbageBug
 * @param bug the FatGarbageBug to visit
 */
void FatBugSquashVisitor::VisitFatGarbage(FatGarbageBug *bug)
{
	if (!bug->GetVisibilityState())
	{
		return;
	}

	if (!bug->GetIsSquashed())
	{
		mVisitedFat = true;
		mGarbageBugVisited = bug;
	}
}

/**
 * Visit a VisitFatNull
 * @param bug the VisitFatNull to visit
 */
void FatBugSquashVisitor::VisitFatNull(FatNullBug *bug)
{
	if (!bug->GetVisibilityState())
	{
		return;
	}
	if (!bug->GetIsSquashed())
	{
		mVisitedFat = true;
		mNullBugVisited = bug;
	}
}