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
const int FeatureNumSpriteImages = 6;

Feature::Feature(Level* level) : Bug(level, FeatureImageName, FeatureNumSpriteImages)
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


