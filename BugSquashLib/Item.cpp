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
Item::Item(Level *level, const wstring &filename) : mLevel(level)
{
	mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
	mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}
