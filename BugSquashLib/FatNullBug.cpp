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
 * Save this bug to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* FatNullBug::XmlSave(wxXmlNode* node)
{
	auto itemNode = Bug::XmlSave(node);

	itemNode->AddAttribute(L"type", L"fatnull");


	return itemNode;
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
void BugNull::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
	/// Obtain the bug image
	auto bugNullSpriteImage = GetImage();
	auto bugNullWidth = bugNullSpriteImage->GetWidth();

	/// Obtain the height needed to get the specific bug image
	auto bugNullHeight = bugNullSpriteImage->GetHeight() / (NullBugNumSpriteImages + 1);
	auto bugNullImageIndex = GetSpriteImageIndex();

	/// Get the sub image from the sprite image
	auto bugNullImage = bugNullSpriteImage->GetSubImage(wxRect(0, bugNullImageIndex * bugNullHeight, bugNullWidth, bugNullHeight));
	wxBitmap bugGarbageBitmap(bugNullImage);
	Bug::ChangeSpriteImageIndex(NullBugNumSpriteImages+ 1);

	gc->DrawBitmap(bugGarbageBitmap, GetX(), GetY(), bugNullWidth * 1.25, bugNullHeight * 1.25);
}
