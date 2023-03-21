/**
 * @file BugRedundancy.cpp
 * @author npmar
 */

#include "pch.h"
#include "Program.h"
#include "BugRedundancy.h"
#include "Level.h"

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

void BugRedundancy::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
	/// Obtain the angle to rotate the bug so it faces the program
	auto x = GetProgram()->GetX();
	auto y = GetProgram()->GetY();
	auto theta = atan2(y - GetY(),x - GetX());

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
	auto wingTheta = WingRotateStart + (elapsed * (WingRotateEnd - WingRotateStart));

	if (elapsed >= WingPeriod)
	{
		mTime = newTime;
		mWingRelaxed = !mWingRelaxed;
	}




	auto bugWidth = GetImage()->GetWidth();
	auto bugHeight = GetImage()->GetHeight();

	gc->PushState();
	gc->Translate(GetX(), GetY());
	gc->Rotate(theta);
	gc->DrawBitmap(bugImageBitmap,-bugWidth/2, -bugHeight/2, bugWidth, bugHeight );
	gc->PopState();


	gc->PushState();
	gc->Translate(GetX(), GetY());
	gc->Rotate(theta - wingTheta);

	auto xPos = -mLeftWingImage->GetWidth()/2 + FirstWingSetX;
	auto yPos = -mLeftWingImage->GetHeight()/2 - WingSetY;

	for (int i = 0; i < NumberOfSetsOfWings; i++)
	{
		gc->DrawBitmap(mLeftWingBitmap, xPos + WingSetXOffset * i, yPos , mLeftWingImage->GetWidth(), mLeftWingImage->GetHeight());
	}
	gc->PopState();

	gc->PushState();
	gc->Translate(GetX(), GetY());
	gc->Rotate(theta + wingTheta);

	xPos = -mRightWingImage->GetWidth()/2 + FirstWingSetX;
	yPos = -mRightWingImage->GetHeight()/2 + WingSetY;

	for (int i = 0; i < NumberOfSetsOfWings; i++)
	{
		gc->DrawBitmap(mRightWingBitmap,  xPos + WingSetXOffset * i,yPos , mRightWingImage->GetWidth(), mRightWingImage->GetHeight());
	}

	gc->PopState();

	gc->PushState();
	gc->Translate(GetX(), GetY());
	gc->Rotate(theta);
	gc->DrawBitmap(mTopBitmap, -mTopImage->GetWidth()/2, -mTopImage->GetHeight()/2, mTopImage->GetWidth(), mTopImage->GetHeight());
	gc->PopState();
}

