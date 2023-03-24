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
	if (mHasSpawned == true && mHasDespawned == false)
	{
		Item::Draw(gc);
	}
}

/**
 * Activates the BugNuke ability, which squashes all bugs on screen
 */
void BugNuke::Activate()
{
	if (!mHasDespawned)
	{
		mHasDespawned = true;
		auto level = GetLevel();
		level->GetBugSquash()->KillAll();
	}
}

/**
 * Check whether the nuke button is where we clicked
 * @param x x-coordinate to check
 * @param y y-coordinate to check
 * @return true if the button is where we clicked and spawned in
 */
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

/**
 * Handles updates for spawn status
 * @param elapsed the seconds elapsed since last update
 */
void BugNuke::Update(double elapsed)
{
	if (mStartTime - elapsed + TextDelay <= 0 && mHasSpawned == false)
	{
		mHasSpawned = true;
	}
	if (mStartTime - elapsed + TextDelay <= -SpawnTime && mHasSpawned == true)
	{
		mHasDespawned = true;
	}
	mStartTime -= elapsed;
}