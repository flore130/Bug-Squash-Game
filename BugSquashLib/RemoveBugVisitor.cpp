/**
 * @file RemoveBugVisitor.cpp
 * @author Ajuisiwon Azantilow
 */

#include "pch.h"
#include "RemoveBugVisitor.h"

void RemoveBugVisitor::VisitBugGarbage( BugGarbage* bug )
{
	if (bug->GetHitProgram())
	{
		mRemoveItem = true;
	}
}

void RemoveBugVisitor::VisitBugNull( BugNull* bug )
{
	if (bug->GetHitProgram())
	{
		mRemoveItem = true;
	}
}

void RemoveBugVisitor::VisitBugRedundancy( BugRedundancy* bug )
{
	if (bug->GetHitProgram() || bug->GetDisappearState())
	{
		mRemoveItem = true;
	}
}

void RemoveBugVisitor::VisitFeature( Feature* feature )
{
	if (feature->GetHitProgram())
	{
		mRemoveItem = true;
	}
}

void RemoveBugVisitor::VisitFatNull(FatNullBug* fatNullBug)
{
	if (fatNullBug->GetHitProgram())
	{
		mRemoveItem = true;
	}
}

void RemoveBugVisitor::VisitFatGarbage(FatGarbageBug* fatGarbage)
{
	if (fatGarbage->GetHitProgram())
	{
		mRemoveItem = true;
	}
}
