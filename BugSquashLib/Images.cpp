/**
 * @file Images.cpp
 * @author Kev
 */

#include "pch.h"
#include "Images.h"

/**
 * Constructor
 * Populate the image map with all of the pairs
 */
Images::Images()
{
	// Load the Garbage Bug images
	const std::wstring blueMaizeBug = L"images/blue-maize-bug.png";
	const std::wstring blueMaizeBugSplat = L"images/blue-maize-splat.png";

	mItemImages[ blueMaizeBug ] = std::make_shared< wxImage >( blueMaizeBug );
	mItemImages[ blueMaizeBugSplat ] = std::make_shared< wxImage >( blueMaizeBugSplat );

	// Load our Nuke Bug image
	const std::wstring bugNuke = L"images/bug-nuke.png";

	mItemImages[ bugNuke ] = std::make_shared< wxImage >( bugNuke );

	// Load our Feature images
	const std::wstring featureBug = L"images/feature.png";
	const std::wstring featureBugSplat = L"images/feature-splat.png";

	mItemImages[ featureBug ] = std::make_shared< wxImage >( featureBug );
	mItemImages[ featureBugSplat ] = std::make_shared< wxImage >( featureBugSplat );

	// Load our Program image
	const std::wstring program = L"images/laptop.png";

	mItemImages[ program ] = std::make_shared< wxImage >( program );

	// Load our Redundancy Fly images
	const std::wstring RedundancyFlyImageName = L"images/redundancy-fly-base.png";
	const std::wstring RedundancyFlyTopImageName = L"images/redundancy-fly-top.png";
	const std::wstring RedundancyFlyLeftWingImageName = L"images/redundancy-fly-lwing.png";
	const std::wstring RedundancyFlyRightWingImageName = L"images/redundancy-fly-rwing.png";
	const std::wstring RedundancyFlySplatImageName = L"images/redundancy-fly-splat.png";

	mItemImages[ RedundancyFlyImageName ] = std::make_shared< wxImage >( RedundancyFlyImageName );
	mItemImages[ RedundancyFlyTopImageName ] = std::make_shared< wxImage >( RedundancyFlyTopImageName );
	mItemImages[ RedundancyFlyLeftWingImageName ] = std::make_shared< wxImage >( RedundancyFlyLeftWingImageName );
	mItemImages[ RedundancyFlyRightWingImageName ] = std::make_shared< wxImage >( RedundancyFlyRightWingImageName );
	mItemImages[ RedundancyFlySplatImageName ] = std::make_shared< wxImage >( RedundancyFlySplatImageName );

	// Load our Null Bug images
	const std::wstring NullBugSpriteImageName = L"images/scarlet-gray-bug.png";
	const std::wstring NullBugSplatImageName = L"images/scarlet-gray-splat.png";

	mItemImages[ NullBugSpriteImageName ] = std::make_shared< wxImage >( NullBugSpriteImageName );
	mItemImages[ NullBugSplatImageName ] = std::make_shared< wxImage >( NullBugSplatImageName );
}