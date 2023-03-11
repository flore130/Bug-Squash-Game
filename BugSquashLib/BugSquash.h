/**
 * @file BugSquash.h
 * @author npmar
 * @author Kyle Nowak
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_BUGSQUASH_H
#define PROJECT1_BUGSQUASHLIB_BUGSQUASH_H

#include <wx/wx.h>
#include <wx/graphics.h>
#include <memory>
#include <random>
#include "Level.h"
#include "ItemVisitor.h"

class Item;
//class Level;

/**
 * The main BugSquash class.
 */
class BugSquash
{
private:
	/// Game area in virtual pixels
	const static int Width = 1250;

	/// Game area height in virtual pixels
	const static int Height = 1000;

	/// Whether or not the the window is in shrink mode
	bool mShrinked = false;

	/// Offset used to adjust the origin of the screen in the X plane
	double mXOffset = 0;

	/// Offset used to adjust the origin of the screen in the Y plane
	double mYOffset = 0;

	/// Scale used to adjust the dimensions of the window
	double mScale = 1;

	/// All of the items in the bug squash application
	std::vector<std::shared_ptr<Item>> mItems;

	/// The level that is currently loaded
	std::unique_ptr<Level> mLevel = nullptr;

public:
	void Load(const wxString &filename);
	void XmlItem(wxXmlNode *node);
	void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
	void Clear();
	void OnLeftDown(int x, int y);
	void Update(double elapsed);
	void Accept( ItemVisitor* visitor );
	void Add( std::shared_ptr< Item > item );
};

#endif //PROJECT1_BUGSQUASHLIB_BUGSQUASH_H
