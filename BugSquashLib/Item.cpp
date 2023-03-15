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
 * Save this item to an XML node
 * @param node The parent node we are going to be a child of
 * @return wxXmlNode that we saved the item into
 */
wxXmlNode *Item::XmlSave(wxXmlNode *node)
{
	auto itemNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"item");
	node->AddChild(itemNode);

	itemNode->AddAttribute(L"x", wxString::FromDouble(mX));
	itemNode->AddAttribute(L"y", wxString::FromDouble(mY));

	return itemNode;
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
void Item::SetProgram(wxXmlNode *node, shared_ptr<Program> parent)
{

}

bool Item::HitTest(int x, int y)
{
	return false;
}
