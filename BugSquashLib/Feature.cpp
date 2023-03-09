/**
 * @file Feature.cpp
 * @author Ricardo Flores
 * @author Kyle Nowak
 */

#include "pch.h"
#include "Feature.h"

/// The feature sprite image
const std::wstring FeatureImageName = L"feature.png";

/// The splat image
const std::wstring FeatureSplatImageName = L"feature-splat.png";

/// Number of sprite images
const int FeatureNumSpriteImages = 7;

Feature::Feature(Level* level) : Bug(level, FeatureImageName)
{

}
