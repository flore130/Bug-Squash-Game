/**
 * @file BugNuke.cpp
 * @author npmar
 */

#include "pch.h"
#include "BugNuke.h"
#include "Item.h"
#include "BugSquash.h"


/// The feature sprite image
const std::wstring NukeImageName = L"images/bug-nuke.png";


/**
* Constructor
* @param level level that this item is a member of
*/
BugNuke::BugNuke(Level* level) : Item(level, NukeImageName)
{
	mStopWatch.Start();
}

/**
 * Load this XML Node to bug
 * @param node The parent node we are going to be a child of
 */
void BugNuke::XmlLoad(wxXmlNode* node)
{
	Item::XmlLoad(node);
}


/**
 * Draw the Garbage Bug
 * @param gc graphics context we want to draw on
 */
void BugNuke::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
	// Get the time the bug has been displayed
	auto newTime = mStopWatch.Time();
	auto elapsed = (double) (newTime - mTime) * 0.001;
	if (mHasSpawned == true && mIsActive == false)
	{
		// If less than two seconds have passed since the BugNuke was spawned, it will continue to exist
		if (mTime - elapsed > 0)
		{
			Item::Draw(gc);
		}
	}
	else if (mStartTime - elapsed + TextDelay <= 0 && mHasSpawned == false)
	{
		Item::Draw(gc);
		mHasSpawned = true;
		// mTime will be set to the start time plus two seconds in which the nuke will display
		mTime += mStartTime + TextDelay;
	}
}

void BugNuke::Activate()
{
	mIsActive = true;
	auto level = GetLevel();
	level->GetBugSquash()->KillAll();
}

bool BugNuke::HitTest(double x, double y)
{
	if(Item::HitTest(x, y))
	{
		if (mHasSpawned)
		{
			Activate();
		}
		return true;
	}
	return false;
}