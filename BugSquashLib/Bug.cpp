/**
 * @file Bug.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "Program.h"
#include "Bug.h"
#include "Code.h"

using namespace std;

/// The radius tolerance for successful hit tests
const double BugHitRange = 50;

/**
 * Constructor
 * @param level the game level
 * @param filename the filename for the bug image
 * @param spriteCount the number of sprites in the bug image
 * @param squashedFilename the filename for the squashed bug image
 */
Bug::Bug(Level *level, const std::wstring &filename, const std::wstring& squashedFilename, int spriteCount) : Item(level, filename)
{
	mSpriteCount = spriteCount;
	mSquashedBugImage = level->GetImage( squashedFilename );
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

		if (programDistance < BugHitRange)
		{
			mHitProgram = true;
		}

		mTime += elapsed;
	}


	mStartTime -= elapsed;
}

/**
* Set the program this bug is associated with
* @param node The bug we are looking at
* @param parent The program to set
*/
void Bug::SetProgram(wxXmlNode* Node,shared_ptr<Program> parent)
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
	if (!GetVisibilityState())
	{
		return;
	}
	// Obtain the angle to rotate the bug so it faces the program
	auto x = mProgram->GetX();
	auto y = mProgram->GetY();
	auto theta = atan2(y - GetY(),x - GetX());

	// Obtain the bug image
	auto bugSpriteImage = GetImage();
	auto bugWidth = bugSpriteImage->GetWidth();

	// Obtain the height needed to get the specific bug image
	auto bugHeight = bugWidth; //bugSpriteImage->GetHeight() / (mSpriteCount + 1);

	// If we are squashed, just draw the squashed image
	if ( mIsSquashed )
	{
		auto squashedImageWidth = mSquashedBugImage->GetWidth() * mScale;
		auto squashedImageHeight = mSquashedBugImage->GetHeight() * mScale;
		graphics->PushState();
		graphics->Translate(GetX(), GetY());
		graphics->Rotate(theta);
		graphics->DrawBitmap(  graphics->CreateBitmapFromImage( *mSquashedBugImage ) ,
							  - (squashedImageWidth/ 2),
							  - (squashedImageHeight/ 2),
							  squashedImageWidth,
							  squashedImageHeight);
		graphics->PopState();
		return;
	}

	// Get the sub image from the sprite image
	auto bugImageBitmap = GetBitmap();
	if (bugImageBitmap.IsNull())
	{
		bugImageBitmap = graphics->CreateBitmapFromImage(*bugSpriteImage);
		SetBitmap(bugImageBitmap);
	}

	if (mSpeed > 0 && mTime >= 3.0/mSpeed && mStartTime <= 0 && !GetLevel()->GetIsEditingCode())
	{
		ChangeSpriteImageIndex(mSpriteCount);
		mTime = 0;
	}

	auto bugImageIndex = GetSpriteImageIndex();
	if (mStartTime > 0)
	{
		bugImageIndex = mSpriteCount;
	}

	auto bugBitmap= graphics->CreateSubBitmap(bugImageBitmap,0, bugImageIndex * bugHeight, bugWidth, bugHeight);

	graphics->PushState();
	graphics->Translate(GetX(), GetY());

	if (mStartTime <= 0)
	{
		graphics->Rotate(theta);
	}

	bugHeight *= mScale;
	bugWidth *= mScale;

	graphics->DrawBitmap(bugBitmap, - (bugWidth / 2), - (bugHeight / 2), bugWidth, bugHeight );
	graphics->PopState();
}
