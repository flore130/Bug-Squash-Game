/**
 * @file Item.h
 * @author Kyle Nowak
 *
 * Base class representing items that can be displayed on screen
 */

#ifndef PROJECT1_BUGSQUASHLIB_ITEM_H
#define PROJECT1_BUGSQUASHLIB_ITEM_H

#include <wx/graphics.h>
#include "ItemVisitor.h"

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
	wxGraphicsBitmap mItemBitmap;

	/// The amount of sprites of each item
	int mSpriteCount = 1;

protected:
	/// Constructor
	Item(Level *level, const std::wstring &filename);

	/**
	 * Get the image associated with the item
	 * @return
	 */
	std::shared_ptr<wxImage> GetImage() { return mItemImage;}

	/**
	 * Set the bitmap associated with the item
	 * @param bitmap
	 */
	void SetBitmap(wxGraphicsBitmap bitmap) { mItemBitmap = bitmap; }

	/**
	 * Gets the current bitmap of the item
	 * @return bitmap The current bitmap of the item
	 */
	wxGraphicsBitmap GetBitmap() { return mItemBitmap; }

public:
	/// The amount of time (in seconds) the text shows on the screen
	const static int TextDelay = 2;

	/// Default constructor (disabled)
	Item() = delete;

	/// Copy constructor (disabled)
	Item(const Item &) = delete;

	/// Assignment operator
	void operator=(const Item &) = delete;


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
	double GetWidth() {return mItemImage->GetWidth();}

	/**
     * Get the height of the item
     * @return Item height in pixels
     */
	double GetHeight() {return mItemImage->GetHeight();}

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	virtual void Accept( ItemVisitor* visitor ) = 0;

	virtual double DistanceTo(std::shared_ptr<Item> item);

	virtual void XmlLoad(wxXmlNode *node);

	/**
	 * Handle update event for animations
	 * @param elapsed the seconds elapsed since last update
	 */
	virtual void Update(double elapsed) {}

	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics);

	virtual void SetProgram(wxXmlNode *node,std::shared_ptr<Program> parent);

	virtual bool HitTest(double x, double y);

	/**
	 * Get the level the item is associated with
	 * @return a pointer to the level the game is associated with
	 */
	 Level * GetLevel() { return mLevel; };

	 bool GetVisibilityState ();

	 /**
	  * Remove an item if the Nuke button is pressed
	  * @return false Return the default value of false
	  */
	 virtual bool NukeItem() { return false; }

};

#endif //PROJECT1_BUGSQUASHLIB_ITEM_H

