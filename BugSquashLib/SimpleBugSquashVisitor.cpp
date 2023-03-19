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
	mIsSimpleBug = true;
	mIsAlreadySquashed = bug->GetIsSquashed();

	// If the bug isn't squashed, and it's simple, squash it
	if ( mIsSimpleBug && !mIsAlreadySquashed )
	{
		bug->SetIsSquashed( true );

		// Set the speed of the bug to 0
		bug->SetSpeed( 0 );

		// One time call to set the squash image to face the program
		bug->FaceSquashToProgram();
	}
}

/**
  * Visit the BugNull object
  * @param bug Bug we are visiting
  */
void SimpleBugSquashVisitor::VisitBugNull( BugNull* bug )
{
	mIsSimpleBug = true;
	mIsAlreadySquashed = bug->GetIsSquashed();

	// If the bug isn't squashed, and it's simple, squash it
	if ( mIsSimpleBug && !mIsAlreadySquashed )
	{
		bug->SetIsSquashed( true );

		// Set the speed of the bug to 0
		bug->SetSpeed( 0 );

		// One time call to set the squash image to face the program
		bug->FaceSquashToProgram();
	}
}

/**
  * Visit the BugRedundancy object
  * @param bug Bug we are visiting
  */
void SimpleBugSquashVisitor::VisitBugRedundancy( BugRedundancy *bug )
{
	mIsSimpleBug = true;
	mIsAlreadySquashed = bug->GetIsSquashed();

	// If the bug isn't squashed, and it's simple, squash it
	if ( mIsSimpleBug && !mIsAlreadySquashed )
	{
		bug->SetIsSquashed( true );

		// Set the speed of the bug to 0
		bug->SetSpeed( 0 );

		// One time call to set the squash image to face the program
		bug->FaceSquashToProgram();
	}
}

/**
 * Visit the Feature object
 * @param feature Feature we are visiting
 */
void SimpleBugSquashVisitor::VisitFeature( Feature *feature )
{
	mIsSimpleBug = true;
	mIsAlreadySquashed = feature->GetIsSquashed();

	// If the bug isn't squashed, and it's simple, squash it
	if ( mIsSimpleBug && !mIsAlreadySquashed )
	{
		feature->SetIsSquashed( true );

		// Set the speed of the bug to 0
		feature->SetSpeed( 0 );

		// One time call to set the squash image to face the program
		feature->FaceSquashToProgram();
	}
}