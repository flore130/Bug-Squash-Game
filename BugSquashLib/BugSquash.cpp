/**
 * @file BugSquash.cpp
 * @author npmar
 * @author Kyle Nowak
 */

#include "pch.h"
#include <wx/wx.h>
#include <memory>
#include <random>
#include <algorithm>
#include "Level.h"
#include "BugSquash.h"
#include "Item.h"
#include "BugGarbage.h"
#include "Program.h"
#include "BugNull.h"
#include "Scoreboard.h"

using namespace std;



/// Scale to shrink to when in shrink mode
const double ShrinkScale = 0.75;

/**
 * Load the BugSquash application from an XML file.
 *
 * Opens the XML file and reads through, creating items as appropriate.
 *
 * @param filename The filename of the file to load the BugSquash application from.
 */
void BugSquash::Load(const wxString &filename)
{
	mScoreboard->Reset();
	mLevel = std::make_unique<Level>();
	mLevel->SetBugSquash( this );
	mLevel->Load(filename);
}

/**
 * Add an Item to our current level in the field
 * @param item the item that we are adding to our game
 */
void BugSquash::Add( std::shared_ptr< Item > item )
{
	mItems.push_back( item );
}


/**
 * Draw the BugSquash game area
 * @param graphics The graphics context to draw on
 * @param width Width of the client window
 * @param height Height of the client window
 */
void BugSquash::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
	//
	// Automatic Scaling
	//
	auto scaleX = double(width) / double(Width);
	auto scaleY = double(height) / double(Height);
	mScale = std::min(scaleX, scaleY);


	if(mShrinked)
	{
		mScale *= ShrinkScale;
	}

	mXOffset = (width - Width * mScale) / 2;
	mYOffset = (height - Height * mScale) / 2;

	graphics->PushState();

	graphics->Translate(mXOffset, mYOffset);
	graphics->Scale(mScale, mScale);

	// From here on you are drawing virtual pixels

	wxBrush brush(*wxWHITE);
	graphics->SetBrush(brush);

	graphics->DrawRectangle(0, 0, Width, Height);


	for (auto item : mItems)
	{
		item->Draw(graphics);
	}

	mScoreboard->Draw(graphics);

	auto temp = Scoreboard(this);
	temp.Draw(graphics);
	graphics->PopState();

}

/**
 * Clear the game data
 * Deletes all known items in the game
 */
void BugSquash::Clear()
{
	mItems.clear();
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void BugSquash::Update(double elapsed)
{
	for (auto item : mItems)
	{
		item->Update(elapsed);
	}
}

/**
 * Handle left mouse button click
 * @param x x position of clicked screen
 * @param y y position of clicked screen
 */
std::shared_ptr<Item> BugSquash::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}
	return  nullptr;
}

/**
 * Accepts a visitor to the program
 * @param visitor the visitor that is visiting this program
 */
void BugSquash::Accept( ItemVisitor* visitor )
{
	for ( auto item : mItems )
	{
		item->Accept( visitor );
	}
}


/**
 * Constructor
 * Initializes the scoreboard for BugSquash to use
 */
BugSquash::BugSquash()
{
	mScoreboard = std::make_unique<Scoreboard>(this);
}