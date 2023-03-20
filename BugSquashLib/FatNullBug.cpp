/**
 * @file FatNullBug.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "FatNullBug.h"

using namespace std;

/// The bug sprite image
const wstring NullBugSpriteImageName = L"images/scarlet-gray-bug.png";

/// The splat image
const wstring NullBugSplatImageName = L"images/scarlet-gray-splat.png";

/// Number of sprite images
const int NullBugNumSpriteImages = 6;

/**
 * Constructor
 * @param level Level that this bug is a member of
 */
FatNullBug::FatNullBug(Level* level) : BugNull(level)
{

}

/**
 * Load this XML Node to bug
 * @param node The parent node we are going to be a child of
 */
void FatNullBug::XmlLoad(wxXmlNode* node)
{
	Bug::XmlLoad(node);
}

/**
 * Draw the Garbage Bug
 * @param gc graphics context we want to draw on
 */
void FatNullBug::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
	SetScale(1.25);
	Bug::Draw(gc);
}