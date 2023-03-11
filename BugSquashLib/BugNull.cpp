/**
 * @file BugNull.cpp
 * @author npmar
 */

#include "pch.h"
#include "BugNull.h"
#include "Level.h"

using namespace std;

/// The bug sprite image
const wstring NullBugSpriteImageName = L"scarlet-gray-bug.png";

/// The splat image
const wstring NullBugSplatImageName = L"scarlet-gray-splat.png";

/// Number of sprite images
const int NullBugNumSpriteImages = 6;




/**
 * Constructor
 * @param level Level that this bug is a member of
 */

BugNull::BugNull(Level *level) : Bug(level, NullBugSpriteImageName)
{
}

/**
 * Test distance between two bugs
 * @param item Item we are computing distance to
 * @return distance in pixels
 */
double BugNull::DistanceTo(std::shared_ptr<Item> item)
{
	auto dx = item->GetX() - GetX();
	auto dy = item->GetY() - GetY();
	return sqrt(dx * dx + dy * dy);
}


/**
 * Load this XML Node to fish
 * @param node The parent node we are going to be a child of
 */
void BugNull::XmlLoad(wxXmlNode* node)
{
	Bug::XmlLoad(node);
}
