/**
 * @file FatBugSquashVisitor.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "FatBugSquashVisitor.h"


/**
 * Visit a FatGarbageBug
 * @param bug the FatGarbageBug to visit
 */
void FatBugSquashVisitor::VisitFatGarbage(FatGarbageBug *bug)
{
	mVisitedFat = true;
	mGarbageBugVisited = bug;
}

/**
 * Visit a VisitFatNull
 * @param bug the VisitFatNull to visit
 */
void FatBugSquashVisitor::VisitFatNull(FatNullBug *bug)
{
	mVisitedFat = true;
	mNullBugVisited = bug;
}