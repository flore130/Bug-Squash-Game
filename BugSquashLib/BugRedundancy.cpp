/**
 * @file BugRedundancy.cpp
 * @author npmar
 */

#include "pch.h"
#include "BugRedundancy.h"
#include "Level.h"

using namespace std;

/// The bug base image
const std::wstring RedundancyFlyImageName = L"redundancy-fly-base.png";

/// The bug top image
const std::wstring RedundancyFlyTopImageName = L"redundancy-fly-top.png";

/// The left wing image
const std::wstring RedundancyFlyLeftWingImageName = L"redundancy-fly-lwing.png";

/// The right wing image
const std::wstring RedundancyFlyRightWingImageName = L"redundancy-fly-rwing.png";

/// The splat image
const std::wstring RedundancyFlySplatImageName = L"redundancy-fly-splat.png";

/// Wing flapping period in seconds
const double WingPeriod = 0.2;

/// Starting rotation angle for wings in radians
const double WingRotateStart = 0.0;

/// End rotation angle for wings in radians
const double WingRotateEnd = 1.5;

/// How many sets of wings does this bug have?
const int NumberOfSetsOfWings = 4;

/// Number of virtual pixels between each of the wing sets
const int WingSetXOffset = 12;

/// X position relative to center of bug for the first (back) wing set
const int FirstWingSetX = -36;

/// Y position relative to center of bug for the right wings. The negative
/// of this is the Y position for the left wings.
const int WingSetY = 5;

/**
 * Constructor
 * @param level Level that this bug is a member of
 */

BugRedundancy::BugRedundancy(Level *level) : Bug(level, RedundancyFlyImageName)
{
}

/**
 * Test distance between two fish
 * @param item Item we are computing distance to
 * @return distance in pixels
 */
double BugRedundancy::DistanceTo(std::shared_ptr<Item> item)
{
	auto dx = item->GetX() - GetX();
	auto dy = item->GetY() - GetY();
	return sqrt(dx * dx + dy * dy);

}


/**
 * Load this XML Node to fish
 * @param node The parent node we are going to be a child of
 */
void BugRedundancy::XmlLoad(wxXmlNode* node)
{
	Bug::XmlLoad(node);
}