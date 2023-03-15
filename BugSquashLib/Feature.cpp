/**
 * @file Feature.cpp
 * @author Ricardo Flores
 * @author Kyle Nowak
 */

#include "pch.h"
#include "Feature.h"

/// The feature sprite image
const std::wstring FeatureImageName = L"images/feature.png";

/// The splat image
const std::wstring FeatureSplatImageName = L"images/feature-splat.png";

/// Number of sprite images
const int FeatureNumSpriteImages = 7;

Feature::Feature(Level* level) : Bug(level, FeatureImageName)
{

}

/**
 * Save this bug to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* Feature::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);

	itemNode->AddAttribute(L"type", L"feature");


	return itemNode;
}

/**
 * Load this XML Node to bug
 * @param node The parent node we are going to be a child of
 */
void Feature::XmlLoad(wxXmlNode* node)
{
	Bug::XmlLoad(node);
}

/**
 * Draw the Garbage Bug
 * @param gc graphics context we want to draw on
 */
void Feature::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
	/// Obtain the bug image
	auto bugFeatureSpriteImage = GetImage();
	auto bugFeatureWidth = bugFeatureSpriteImage->GetWidth();

	/// Obtain the height needed to get the specific bug image
	auto bugFeatureHeight = bugFeatureSpriteImage->GetHeight() / (FeatureNumSpriteImages);
	auto bugFeatureImageIndex = GetSpriteImageIndex();

	/// Get the sub image from the sprite image
	auto bugGarbageImage = bugFeatureSpriteImage->GetSubImage(wxRect(0, bugFeatureImageIndex * bugFeatureHeight, bugFeatureWidth, bugFeatureHeight));
	wxBitmap bugGarbageBitmap(bugGarbageImage);
	Bug::ChangeSpriteImageIndex(FeatureNumSpriteImages);

	gc->DrawBitmap(bugGarbageBitmap, GetX(), GetY(), bugFeatureWidth, bugFeatureHeight);
}

