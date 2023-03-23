/**
 * @file BugNuke.cpp
 * @author npmar
 */

#include "pch.h"
#include "BugNuke.h"

///The Constant to delay bugs from crawling in when text appears
const double TextDelay = 2;

/// The feature sprite image
const std::wstring NukeImageName = L"images/bug-nuke.png";

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
	if (mHasSpawned == true)
	{
		// After first being drawn on the screen, the power up will stay for another 2 seconds before vanishing
		if (mStartTime - elapsed + TextDelay > -2)
		{
			Item::Draw(gc);
		}
	}
	else if (mStartTime - elapsed + TextDelay <= 0 && mHasSpawned == false)
	{
		Item::Draw(gc);
		mHasSpawned = true;
	}
}