/**
 * @file FatGarbageBug.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "FatGarbageBug.h"

/// The bug sprite image
const std::wstring GarbageBugSpriteImageName = L"images/blue-maize-bug.png";

/// The splat image
const std::wstring GarbageBugSplatImageName = L"images/blue-maize-splat.png";

/// Number of sprite images
const int GarbageBugNumSpriteImages = 5;


FatGarbageBug::FatGarbageBug(Level* level) : BugGarbage(level)
{

}

/**
 * Save this bug to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* FatGarbageBug::XmlSave(wxXmlNode* node)
{
	auto itemNode = Bug::XmlSave(node);

	itemNode->AddAttribute(L"type", L"fatgarbage");


	return itemNode;
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
	/// Obtain the bug image
	auto bugGarbageSpriteImage = GetImage();
	auto bugGarbageWidth = bugGarbageSpriteImage->GetWidth();

	/// Obtain the height needed to get the specific bug image
	auto bugGarbageHeight = bugGarbageSpriteImage->GetHeight() / (GarbageBugNumSpriteImages + 1);
	auto bugGarbageImageIndex = GetSpriteImageIndex();

	/// Get the sub image from the sprite image
	auto bugGarbageImage = bugGarbageSpriteImage->GetSubImage(wxRect(0, bugGarbageImageIndex * bugGarbageHeight, bugGarbageWidth, bugGarbageHeight));
	wxBitmap bugGarbageBitmap(bugGarbageImage);
	Bug::ChangeSpriteImageIndex(GarbageBugNumSpriteImages + 1);

	gc->DrawBitmap(bugGarbageBitmap, GetX(), GetY(), bugGarbageWidth * 1.25, bugGarbageHeight * 1.25);
}