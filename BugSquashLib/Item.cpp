/**
 * @file Item.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "Item.h"

using namespace std;


/**
 * Constructor
 * @param level The level this item is a part of
 * @param filename The filename for the image of this item
 */
Item::Item(Level *level, const std::wstring &filename) : mLevel(level)
{
	mItemImage = std::make_shared<wxImage>(filename);
}

/**
 * Compute the distance from this item to another item
 * @param item Item we are computing the distance to
 * @return Distance in pixels
 */
double Item::DistanceTo(std::shared_ptr<Item> item)
{
	auto dx = item->GetX() - GetX();
	auto dy = item->GetY() - GetY();
	return sqrt(dx * dx + dy * dy);
}


/**
 * Load the position for an item node.
 * @param node The Xml node we are loading the item from
 */
void Item::XmlLoad(wxXmlNode *node)
{
	node->GetAttribute(L"x", L"0").ToDouble(&mX);
	node->GetAttribute(L"y", L"0").ToDouble(&mY);
}

/**
* Draw the item on the graphics context
 * @param graphics graphics context to draw on
*/
void Item::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
	if (mItemBitmap.IsNull())
	{
		mItemBitmap = graphics->CreateBitmapFromImage(*mItemImage);
	}

	//
	// Draw a bitmap
	//
	int imageWidth = mItemImage->GetWidth();
	int imageHeight = mItemImage->GetHeight();
	graphics->DrawBitmap(mItemBitmap, mX - (imageWidth / 2), mY - (imageHeight / 2), imageWidth, imageHeight);
}

/**
* Assigns an item to a program
* @param node The item that we are looking at
 *@param parent The program that the item is being assigned to
*/
void Item::SetProgram(shared_ptr<Program> parent)
{

}

/**
 * Returns true if an item has been clicked on
 * @param x The x position of the item
 * @param y The y position of the item
 * @return false The basic return of any item will be false
 */
bool Item::HitTest(double x, double y)
{
	double wid = mItemImage->GetWidth();
	double hit = mItemImage->GetHeight();

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

	// Test to see if x, y are in the drawn part of the image
	// If the location is transparent, we are not in the drawn
	// part of the image
	return !mItemImage->IsTransparent((int)testX, (int)testY );
}
