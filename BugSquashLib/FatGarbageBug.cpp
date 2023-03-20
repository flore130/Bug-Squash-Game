/**
 * @file FatGarbageBug.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "FatGarbageBug.h"

using namespace std;

/// The bug sprite image
const std::wstring GarbageBugSpriteImageName = L"images/blue-maize-bug.png";

/// The splat image
const std::wstring GarbageBugSplatImageName = L"images/blue-maize-splat.png";

/// Number of sprite images
const int GarbageBugNumSpriteImages = 5;

/**
 * Constructor
 * @param level Level that this bug is a member of
 */
FatGarbageBug::FatGarbageBug(Level* level) : BugGarbage(level)
{

}

/**
 * Load this XML Node to bug
 * @param node The parent node we are going to be a child of
 */
void FatGarbageBug::XmlLoad(wxXmlNode* node)
{
	Bug::XmlLoad(node);
}

/**
 * Draw the Garbage Bug
 * @param gc graphics context we want to draw on
 */
void FatGarbageBug::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
	SetScale(1.25);
	Bug::Draw(gc);
}