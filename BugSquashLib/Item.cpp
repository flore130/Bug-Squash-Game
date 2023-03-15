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
	mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
	mItemBitmap = make_unique<wxBitmap>(*mItemImage);
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

void Item::SetProgram(wxXmlNode *node, shared_ptr<Program> parent)
{

}