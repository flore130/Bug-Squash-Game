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


/// Number of images in the sample sprite object
int imageIndex = 0;

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
	mLevel->Load(filename);
	vector<shared_ptr< Item >> levelLoad;

	if (mLevel != nullptr)
	{
		levelLoad = mLevel->GetItem();
		for (auto item : levelLoad)
		{
			Add(item);
		}
	}
}

/**
 * Handle a node of type item.
 * @param node XML node
 */
void BugSquash::XmlItem(wxXmlNode *node)
{
	// A pointer for the item we are loading
	shared_ptr<Item> item = nullptr;

	// We have an item. What type?
	auto type = node->GetAttribute(L"type");
	if (type == L"program")
	{
//		item = make_shared<Program>(this);
	}
	else if (type == L"feature")
	{
//		item = make_shared<Feature>(this);
	}
	else if (type == L"garbage")
	{
//		item = make_shared<BugGarbage>(this);
	}
	else if (type == L"redundancy")
	{
//		item = make_shared<BugRedundancy>(this);
	}
	else if (type == L"null")
	{
//		item = make_shared<BugNull>(this);
	}

	if (item != nullptr)
	{

		Add(item);
		item->XmlLoad(node);
	}
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

	//
	// Your drawing code goes here
	//

	wxBrush brush(*wxWHITE);
	graphics->SetBrush(brush);

	graphics->DrawRectangle(0, 0, Width, Height);


	for (auto item : mItems)
	{
		item->Draw(graphics);
	}

	mScoreboard->Draw(graphics);
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

BugSquash::BugSquash()
{
	mScoreboard = make_unique<Scoreboard>(this);
}