/**
 * @file BugStateVisitor.cpp
 * @author Ajuisiwon Azantilow
 */

#include "pch.h"
#include "BugStateVisitor.h"
#include "BugGarbage.h"
#include "BugNull.h"
#include "BugRedundancy.h"
#include "Feature.h"
#include "FatNullBug.h"
#include "FatGarbageBug.h"

/**
 * Visit the BugGarbage object
 * @param bug Bug we are visiting
 */
void BugStateVisitor::VisitBugGarbage(BugGarbage* bug )
{
	if (bug->GetHitProgram())
	{
		mRemoveItem = true;
	}
}

/**
 * Visit the BugNull object
 * @param bug Bug we are visiting
 */
void BugStateVisitor::VisitBugNull(BugNull* bug )
{
	if (bug->GetHitProgram())
	{
		mRemoveItem = true;
	}
}

/**
 * Visit the BugRedundancy object
 * @param bug Bug we are visiting
 */
void BugStateVisitor::VisitBugRedundancy(BugRedundancy* bug )
{
	if (bug->GetHitProgram() || bug->GetDisappearState())
	{
		mRemoveItem = true;
	}
}

/**
 * Visit the feature object
 * @param feature feature we are visiting
 */
void BugStateVisitor::VisitFeature(Feature* feature )
{
	if (feature->GetHitProgram())
	{
		mRemoveItem = true;
		mGotMissed = false;
	}
}

/**
 * Visit the FatNullBug object
 * @param fatNullBug Bug we are visiting
 */
void BugStateVisitor::VisitFatNull(FatNullBug* fatNullBug)
{
	if (fatNullBug->GetHitProgram())
	{
		mRemoveItem = true;
	}
}

/**
 * Visit the FatGarbageBug object
 * @param fatGarbage Bug we are visiting
 */
void BugStateVisitor::VisitFatGarbage(FatGarbageBug* fatGarbage)
{
	if (fatGarbage->GetHitProgram())
	{
		mRemoveItem = true;
	}
}
