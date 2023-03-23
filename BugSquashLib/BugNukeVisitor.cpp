/**
 * @file BugNukeVisitor.cpp
 * @author npmar
 */

#include "pch.h"
#include "BugNukeVisitor.h"
#include "BugNuke.h"

/**
 * Visit the BugNuke object
 * @param nuke BugNuke we are visiting
 */
void BugNukeVisitor::VisitBugNuke(BugNuke *nuke)
{
	if (!nuke->GetSpawned())
	{
		return;
	}
	nuke->Activate();
}