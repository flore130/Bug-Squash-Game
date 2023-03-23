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
#include "Scoreboard.h"
#include "Images.h"

class Item;

/**
 * The main BugSquash class.
 */
class BugSquash
{
private:
	/**
	 * This enum class will tell us what state the current level
	 * is in. Beginning state of the level (Start of Level Text appears)
	 * Playing state of the level is when after beginning when user is playing
	 * Finished is when there are no bugs left and shows the level complete frame
	 */
	enum class Type
	{
		Beginning, Playing, Finished
	};

	///The state the level is currently in
	Type mState = Type::Beginning;

	/// Whether or not the the window is in shrink mode
	bool mShrinked = false;

	/// Offset used to adjust the origin of the screen in the X plane
	double mXOffset = 0;

	/// Offset used to adjust the origin of the screen in the Y plane
	double mYOffset = 0;

	/// Scale used to adjust the dimensions of the window
	double mScale = 1;

	/// The level that is currently loaded
	std::unique_ptr<Level> mLevel = nullptr;

	/// The scoreboard currently being used
	std::shared_ptr<Scoreboard> mScoreboard = nullptr;

	/**
	 * Stopwatch to keep track of the 2 second intro frames
	 * in the beginning and end of the levels
	 */
	wxStopWatch mStopWatch;

	/// Are all bugs in mItems squashed
	bool mAllBugsSquashed = false;

	/// Pointer to the image class which holds all of the images used
	std::shared_ptr< Images > mImages = nullptr;

	/// Whether or not the player is editing a FatBug's code
	bool mIsEditingCode = false;

	///makes sure drawing "Finished" appears before starting next level
	bool mDrawComplete = true;

	///Time meant to Draw finished text on the screen
	double mFinishDrawing = 0;

protected:
	/// All of the items in the bug squash application
	std::vector<std::shared_ptr<Item>> mItems {};

public:
	BugSquash();
	void Load(const wxString &filename);
	void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
	void Clear();
	std::shared_ptr<Item> HitTest(int x, int y);
	void Update(double elapsed);
	void Accept( ItemVisitor* visitor );
	void Add( std::shared_ptr< Item > item );

	/// Game area in virtual pixels
	const static int Width = 1250;

	/// Game area height in virtual pixels
	const static int Height = 1000;

	/**
	 * Gets the current value of mShrinked
	 * @return Current value of mShrinked
	 */
	bool GetShrinked() const { return mShrinked; }

	/**
 	* Obtains the number of items in the game
 	* @return The size of/ number of items in mItems
 	*/
	int GetNumItems() const { return mItems.size(); }

	/**
	 * Set the Height of mShrinked
	 * @param val The value to set mShrinked to
	 */
	 void SetShrinked( bool val ) { mShrinked = val; }

	 /**
	  * Tells the scoreboard to increment the fixed value
	  */
	 void FixedIncrement() { mScoreboard->FixedIncrement(); }

	 /**
	  * Tells the scoreboard to increment the missed value
	  */
	 void MissedIncrement() { mScoreboard->MissedIncrement(); }

	 /**
	  * Tells the scoreboard to increment the oops value
	  */
	 void OopsIncrement() { mScoreboard->OopsIncrement(); }


	 void KillAll();

	/**
	 * Gets an image or a nullptr from map of images
	 * @param filename The filename of the image we want
	 * @return A shared point to the wxImage or a nullptr if it's not in the map
	 */
	std::shared_ptr< wxImage > GetImage( const std::wstring& filename ) { return mImages->GetImage( filename ); }

	/**
	 * Whether a FatBug's code is currently being edited
	 * @return true if player is editing fat bugs, false otherwise
	 */
	bool GetIsEditingCode() { return mIsEditingCode; }

	/**
	 * Set whether or not the player is editing code
	 * @param newVal true if player is editing code, false otherwise
	 */
	void SetIsEditingCode(bool newVal) { mIsEditingCode = newVal; }
	void CheckIfAllBugsAreSquashed();

};

#endif //PROJECT1_BUGSQUASHLIB_BUGSQUASH_H

