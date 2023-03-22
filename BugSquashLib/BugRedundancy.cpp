/**
 * @file BugRedundancy.cpp
 * @author npmar
 */

#include "pch.h"
#include "Program.h"
#include "BugRedundancy.h"
#include "Level.h"
#include <vector>

using namespace std;

/// The bug base image
const std::wstring RedundancyFlyImageName = L"images/redundancy-fly-base.png";

/// The bug top image
const std::wstring RedundancyFlyTopImageName = L"images/redundancy-fly-top.png";

/// The left wing image
const std::wstring RedundancyFlyLeftWingImageName = L"images/redundancy-fly-lwing.png";

/// The right wing image
const std::wstring RedundancyFlyRightWingImageName = L"images/redundancy-fly-rwing.png";

/// The splat image
const std::wstring RedundancyFlySplatImageName = L"images/redundancy-fly-splat.png";

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

///The Constant to delay bugs from crawling in when text appears
const double TextDelay = 2;

/**
 * Constructor
 * @param level Level that this bug is a member of
 */
BugRedundancy::BugRedundancy(Level *level) : Bug(level, RedundancyFlyImageName, RedundancyFlySplatImageName, 0)
{
	mLeftWingImage = std::make_shared<wxImage>(RedundancyFlyLeftWingImageName);
	mRightWingImage = std::make_shared<wxImage>(RedundancyFlyRightWingImageName);
	mTopImage = std::make_shared<wxImage>(RedundancyFlyTopImageName);
	mSquashedImage = std::make_shared<wxImage>(RedundancyFlySplatImageName);
}

/**
 * Test distance between two bugs
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
 * Load this XML Node to bug
 * @param node The parent node we are going to be a child of
 */
void BugRedundancy::XmlLoad(wxXmlNode* node)
{
	Bug::XmlLoad(node);
}

/**
 * Draw the redundancy fly
 * @param gc the graphics context to draw on
 */
void BugRedundancy::Draw(std::shared_ptr<wxGraphicsContext> gc)
{

//	/// Obtain the angle to rotate the bug so it faces the program
	auto x = GetProgram()->GetX();
	auto y = GetProgram()->GetY();
	auto theta = 0;
	if (GetStart() <= 0)
	{
		theta = atan2(y - GetY(),x - GetX());
	}

	/// Get the sub image from the sprite image
	auto bugImageBitmap = GetBitmap();
	if (bugImageBitmap.IsNull())
	{
		bugImageBitmap = gc->CreateBitmapFromImage(*GetImage());
		SetBitmap(bugImageBitmap);
	}

	if (mSquashedFly.IsNull())
	{
		mSquashedFly = gc->CreateBitmapFromImage(*mSquashedImage);
	}

	/// Set the left wing bitmap of the redundancy fly
	if (mLeftWingBitmap.IsNull())
	{
		mLeftWingBitmap = gc->CreateBitmapFromImage(*mLeftWingImage);
	}

	/// Set the right wing bitmap of the redundancy fly
	if (mRightWingBitmap.IsNull())
	{
		mRightWingBitmap = gc->CreateBitmapFromImage(*mRightWingImage);
	}

	/// Set the top wing bitmap of the redundancy fly
	if (mTopBitmap.IsNull())
	{
		mTopBitmap = gc->CreateBitmapFromImage(*mTopImage);
	}

	if (GetIsSquashed())
	{
		auto squashedImageWidth = mSquashedImage->GetWidth();
		auto squashedImageHeight = mSquashedImage->GetHeight();
		gc->PushState();
		gc->Translate(GetX(), GetY());
		gc->Rotate(theta);
		gc->DrawBitmap(  mSquashedFly,
							   - (squashedImageWidth/ 2),
							   - (squashedImageHeight/ 2),
							   squashedImageWidth,
							   squashedImageHeight);
		gc->PopState();
		return;
	}

//	/// Get the time the bug has been displayed
	auto newTime = mStopWatch.Time();
	auto elapsed = (double) (newTime - mTime) * 0.001;
	auto time = 2 * fmod(mTime, WingPeriod) / WingPeriod;
	if (time > 1)
	{
		time = 2.0 - time;
	}
	auto wingTheta = WingRotateStart + (time * (WingRotateEnd - WingRotateStart));
//
	auto bugWidth = GetImage()->GetWidth();
	auto bugHeight = GetImage()->GetHeight();

	gc->PushState();
	gc->Translate(GetX(),GetY());
	gc->Rotate(theta);
	gc->DrawBitmap(bugImageBitmap, -bugWidth/2, -bugHeight/2, bugWidth, bugHeight);

	auto xPos = FirstWingSetX;// + GetX();
	auto yPos = - WingSetY;
	for (int i = 0; i < NumberOfSetsOfWings; i++)
	{
		gc->PushState();
		gc->Translate(xPos, yPos);
		gc->Rotate(wingTheta);
		gc->DrawBitmap(mLeftWingBitmap, -mLeftWingImage->GetWidth()/2, -mLeftWingImage->GetHeight()/2,mLeftWingImage->GetWidth(), mLeftWingImage->GetHeight());
		xPos += WingSetXOffset;
		gc->PopState();
	}

	xPos = FirstWingSetX;
	for (int i = 0; i < NumberOfSetsOfWings; i++)
	{
		gc->PushState();
		gc->Translate(xPos,-yPos);
		gc->Rotate(-wingTheta);
		gc->DrawBitmap(mRightWingBitmap,-mRightWingImage->GetWidth()/2, -mRightWingImage->GetHeight()/2, mRightWingImage->GetWidth(), mRightWingImage->GetHeight());
		xPos += WingSetXOffset;
		gc->PopState();
	}

	gc->DrawBitmap(mTopBitmap, -mTopImage->GetWidth()/2, -mTopImage->GetHeight()/2,mTopImage->GetWidth(),mTopImage->GetHeight());

	gc->PopState();
}

/**
 * Generate random points given a point with some average distance
 * @param x the x coordinate of the point
 * @param y the y coordinate of the point
 * @param numberOfPoints the number of points to generate
 * @param dispersion the radius which the points are supposed to be dispersed by
 * @return a vector containing the points
 */
std::vector<std::vector<double>> GenerateRandomPoints(int x, int y, int numberOfPoints, int dispersion)
{
	std::vector<std::vector<double>> points{};
	random_device rd;
	mt19937 gen(rd());
	normal_distribution<double> dist(dispersion, 5);

	for (int i = 0; i < numberOfPoints; i++)
	{
		double angle = (double)rand() * 2 * M_PI / RAND_MAX;

		// Generate random distance
		double distance = dist(gen);

		// Calculate x and y coordinates of new point
		double x0 = x + distance * cos(angle);
		double y0 = y + distance * sin(angle);
		std::vector<double> temp {x0, y0};
		points.push_back(temp);
	}
	return points;
}

/**
* Spawn redundancy bugs
 *
*/
void BugRedundancy::SpawnRedundancyFlies()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(3, 6);

	int numberOfFlies = distrib(gen);

	auto points = GenerateRandomPoints(GetX(), GetY(),numberOfFlies, 200);

	auto bugSquash = GetLevel()->GetBugSquash();
	for (int i = 0; i < numberOfFlies; ++i)
	{
		std::shared_ptr<BugRedundancy> bugPtr;
		bugPtr = std::make_shared<BugRedundancy>(GetLevel());

		auto locationX = points[i][0];
		auto locationY = points[i][1];
		bugPtr->SetLocation(locationX, locationY);
		bugPtr->SetProgram(nullptr,GetProgram());
		bugPtr->SetSpeed(GetSpeed());
		bugPtr->SetStart(0 - TextDelay);
		bugPtr->mParentSquashed = true;
		bugSquash->Add(bugPtr);
	}

	mDisappearState = true;
}

void BugRedundancy::Update(double elapsed)
{
	Bug::Update(elapsed);
	mTime += elapsed;
}