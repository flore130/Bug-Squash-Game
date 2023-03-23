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

void BugStateVisitor::VisitBugGarbage(BugGarbage* bug )
{
	if (bug->GetHitProgram())
	{
		mRemoveItem = true;
	}
}

void BugStateVisitor::VisitBugNull(BugNull* bug )
{
	if (bug->GetHitProgram())
	{
		mRemoveItem = true;
	}
}

void BugStateVisitor::VisitBugRedundancy(BugRedundancy* bug )
{
	if (bug->GetHitProgram() || bug->GetDisappearState())
	{
		mRemoveItem = true;
	}
}

void BugStateVisitor::VisitFeature(Feature* feature )
{
	if (feature->GetHitProgram())
	{
		mRemoveItem = true;
		mGotMissed = false;
	}
}

void BugStateVisitor::VisitFatNull(FatNullBug* fatNullBug)
{
	if (fatNullBug->GetHitProgram())
	{
		mRemoveItem = true;
	}
}

void BugStateVisitor::VisitFatGarbage(FatGarbageBug* fatGarbage)
{
	if (fatGarbage->GetHitProgram())
	{
		mRemoveItem = true;
	}
}
