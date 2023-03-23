/**
 * @file SimpleBugSquashVisitor.cpp
 * @author Kev
 */

#include "pch.h"
#include "SimpleBugSquashVisitor.h"
#include "BugGarbage.h"
#include "BugNull.h"
#include "BugRedundancy.h"
#include "Feature.h"

/**
  * Visit the BugGarbage object
  * @param bug Bug we are visiting
  */
void SimpleBugSquashVisitor::VisitBugGarbage( BugGarbage* bug )
{
	if (!bug->GetVisibilityState())
	{
		return;
	}

	mIsAlreadySquashed = bug->GetIsSquashed();

	// If the bug isn't squashed, and it's simple, squash it
	if ( !mIsAlreadySquashed )
	{
		bug->SetIsSquashed( true );

		// Set the speed of the bug to 0
		bug->SetSpeed( 0 );

		// Tell us that we just squashed the bug, so we can update the scoreboard
		mJustSquashed = true;

		// It was a good squash
		mBugSquashed = true;
	}
}

/**
  * Visit the BugNull object
  * @param bug Bug we are visiting
  */
void SimpleBugSquashVisitor::VisitBugNull( BugNull* bug )
{
	if (!bug->GetVisibilityState())
	{
		return;
	}
	mIsAlreadySquashed = bug->GetIsSquashed();

	// If the bug isn't squashed, and it's simple, squash it
	if ( !mIsAlreadySquashed )
	{
		bug->SetIsSquashed( true );

		// Set the speed of the bug to 0
		bug->SetSpeed( 0 );

		// Tell us that we just squashed the bug, so we can update the scoreboard
		mJustSquashed = true;

		// It was a good squash
		mBugSquashed = true;
	}
}

/**
  * Visit the BugRedundancy object
  * @param bug Bug we are visiting
  */
void SimpleBugSquashVisitor::VisitBugRedundancy( BugRedundancy *bug )
{
	if (!bug->GetVisibilityState())
	{
		return;
	}

	if (bug->GetParentSquashedStatus())
	{
		mIsAlreadySquashed = bug->GetIsSquashed();

		// If the bug isn't squashed, and it's simple, squash it
		if ( !mIsAlreadySquashed )
		{
			bug->SetIsSquashed( true );

			// Set the speed of the bug to 0
			bug->SetSpeed( 0 );

			// Tell us that we just squashed the bug, so we can update the scoreboard
			mJustSquashed = true;

			// It was a good squash
			mBugSquashed = true;
		}
	}
	else
	{
		bug->SpawnRedundancyFlies();
	}

}

/**
 * Visit the Feature object
 * @param feature Feature we are visiting
 */
void SimpleBugSquashVisitor::VisitFeature( Feature *feature )
{
	if (!feature->GetVisibilityState())
	{
		return;
	}
	mIsAlreadySquashed = feature->GetIsSquashed();

	// If the bug isn't squashed, and it's simple, squash it
	if (  !mIsAlreadySquashed )
	{
		feature->SetIsSquashed( true );

		// Set the speed of the bug to 0
		feature->SetSpeed( 0 );

		// Tell us that we just squashed the bug, so we can update the scoreboard
		mJustSquashed = true;

		// It was a bad squash
		mFeatureSquashed = true;
	}
}