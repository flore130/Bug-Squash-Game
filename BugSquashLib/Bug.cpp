/**
 * @file Bug.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "Program.h"
#include "Bug.h"

using namespace std;

/// The radius tolerance for successful hit tests
const double BugHitRange = 50;


/**
 * Constructor
 * @param level the game level
 * @param filename the filename for the bug image
 */
Bug::Bug(Level *level, const std::wstring &filename, const std::wstring& squashedFilename, int spriteCount) : Item(level, filename)
{
	mSpriteCount = spriteCount;
	mSquashedBugImage = std::make_shared<wxImage>( squashedFilename );
	mStopWatch.Start();
}


/**
 * Hit test x,y to see if they are clicking on this bug.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @return true if clicked on bug
 */
bool Bug::HitTest(double x, double y)
{
	auto bugSpriteImage = GetImage();

	double wid = bugSpriteImage->GetWidth();
	double hit = bugSpriteImage->GetHeight();
	if ( mSpriteCount > 0 )
	{
		hit /= mSpriteCount;
	}

	// Make x and y relative to the top-left corner of the bitmap image
	// Subtracting the center makes x, y relative to the image center
	// Adding half the size makes x, y relative to the image top corner
	double testX = x - GetX() + wid / 2;
	double testY = y - GetY() + hit / 2;

	// Test to see if x, y are in the image
	if( testX < 0 || testY < 0 || testX >= wid || testY >= hit )
	{
		// We are outside the image
		return false;
	}

	double dx = x - GetX();
	double dy = y - GetY();

	return sqrt(dx * dx + dy * dy) < BugHitRange;
}


/**
 * Handles updates for animations
 * @param elapsed the seconds elapsed since last update
 */
void Bug::Update(double elapsed)
{
	if (mStartTime - elapsed <= 0)
	{
		double programX = mProgram->GetX();
		double programY = mProgram->GetY();
		double programDistance = DistanceTo(mProgram);

		if (programDistance > 0)
		{
			// Get difference in X and Y between bug and program
			double diffX = programX - GetX();
			double diffY = programY - GetY();

			// Scale to normalize the vector
			double directionX = diffX / programDistance;
			double directionY = diffY / programDistance;

			// Set location to pixels/second * seconds * direction + current position
			SetLocation(GetX() + (directionX * mSpeed * elapsed),
						GetY() + (directionY * mSpeed * elapsed));
		}
	}
	mStartTime -= elapsed;
}

/**
* Set the program this bug is associated with
* @param node The bug we are looking at
* @param parent The program to set
*/
void Bug::SetProgram(wxXmlNode *node, shared_ptr<Program> parent)
{
	mProgram = parent;
}

/**
 * Load the attributes for bug node.
 *
 * @param node The Xml node we are loading the item from
 */
void Bug::XmlLoad(wxXmlNode *node)
{
	Item::XmlLoad(node);
	node->GetAttribute(L"speed", L"0").ToDouble(&mSpeed);
}

/**
 * Draw a bug onto the screen, changing the sprite as necessary to animate
 * @param graphics The graphs we are drawing on
 */
void Bug::Draw(shared_ptr<wxGraphicsContext> graphics)
{
	// Obtain the angle to rotate the bug so it faces the program
	auto x = mProgram->GetX();
	auto y = mProgram->GetY();
	auto theta = 2 * M_PI - atan2(y - GetY(),x - GetX());

	// Obtain the bug image
	auto bugSpriteImage = GetImage();
	auto bugWidth = bugSpriteImage->GetWidth();

	// Obtain the height needed to get the specific bug image
	auto bugHeight = bugWidth; //bugSpriteImage->GetHeight() / (mSpriteCount + 1);

	// If we are squashed, just draw the squashed image
	if ( mIsSquashed )
	{
		graphics->DrawBitmap(  graphics->CreateBitmapFromImage( *mSquashedBugImage ) ,
							  GetX() - (bugWidth / 2),
							  GetY() - (bugHeight / 2),
							  bugWidth,
							  bugHeight );
		return;
	}

	// Get the sub image from the sprite image
	auto bugImageBitmap = GetBitmap();
	if (bugImageBitmap.IsNull())
	{
		bugImageBitmap = graphics->CreateBitmapFromImage(*bugSpriteImage);
		SetBitmap(bugImageBitmap);
	}

	// Get the time the bug has been displayed
	auto newTime = mStopWatch.Time();
	auto elapsed = (double) (newTime - mTime) * 0.001;

	if (elapsed >= 3.0/mSpeed)
	{
		ChangeSpriteImageIndex(mSpriteCount);
		mTime = newTime;
	}

	auto bugImageIndex = GetSpriteImageIndex();
	auto bugBitmap= graphics->CreateSubBitmap(bugImageBitmap,0, bugImageIndex * bugHeight, bugWidth, bugHeight);

	auto image = bugBitmap.ConvertToImage();
	image = image.Rotate(theta, wxPoint(GetX(), GetY()));

	bugBitmap = graphics->CreateBitmapFromImage(image);

	bugHeight *= mScale;
	bugWidth *= mScale;

	graphics->DrawBitmap(bugBitmap, GetX() - (bugWidth / 2), GetY() - (bugHeight / 2), bugWidth, bugHeight );
}

/**
 * Update the squashed bug's rotation to match the program
 * This function is only called once by the visitor when it's
 * squashed the first time
 */
void Bug::FaceSquashToProgram()
{
	// Obtain the angle to rotate the bug so it faces the program
	auto x = mProgram->GetX();
	auto y = mProgram->GetY();
	auto theta = 2 * M_PI - atan2(y - GetY(),x - GetX());

	*mSquashedBugImage = mSquashedBugImage->Rotate( theta, wxPoint( GetX(), GetY() ) );
}
