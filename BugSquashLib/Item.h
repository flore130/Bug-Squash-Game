/**
 * @file Item.h
 * @author Kyle Nowak
 *
 * Base class representing items that can be displayed on screen
 */

#ifndef PROJECT1_BUGSQUASHLIB_ITEM_H
#define PROJECT1_BUGSQUASHLIB_ITEM_H

class Level;

/**
 * Base class representing items that can be displayed on screen
 */
class Item
{
private:
	/// The level this item is a part of
	Level* mLevel = nullptr;

	/// The x location of the item in virtual pixels
	double mX = 0;

	/// The y location of the item in virtual pixels
	double mY = 0;

	/// The item image
	std::shared_ptr<wxImage> mItemImage = nullptr;

	/// The item bitmap
	std::unique_ptr<wxBitmap> mItemBitmap = nullptr;

public:
	/**
     * The X location of the item
     * @return X location in pixels
     */
	double GetX() const { return mX; }

	/**
	 * The Y location of the item
	 * @return Y location in pixels
	 */
	double GetY() const { return mY; }

	/**
	 * Set the item location
	 * @param x X location in pixels
	 * @param y Y location in pixels
	 */
	void SetLocation(double x, double y) { mX = x; mY = y; }

	/**
     * Get the width of the item
     * @return Item width in pixels
     */
	double GetWidth() {return mItemBitmap->GetWidth();}

	/**
     * Get the height of the item
     * @return Item height in pixels
     */
	double GetHeight() {return mItemBitmap->GetHeight();}


};

#endif //PROJECT1_BUGSQUASHLIB_ITEM_H
