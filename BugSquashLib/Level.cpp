/**
 * @file Level.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "BugSquash.h"
#include "Code.h"
#include "BugRedundancy.h"
#include "Feature.h"
#include "BugNuke.h"
#include "Program.h"
#include "FatGarbageBug.h"
#include "FatNullBug.h"

using namespace std;

/// font size to use
const int TextSize = 200;

/// Label for font size to use
const int LabelSize = 140;

/// The font color to use
const wxColour FontColor = wxColour(255, 0, 0);

/// Left  X location. The right score is
/// the width minus this value.
const int LeftX = 625;

/// Y location
const int LabelY = 425;

/**
 * Constructor
 * @param bugSquash the bugSquash object the level belongs to
 */
Level::Level(BugSquash* bugSquash) : mBugSquash(bugSquash){}

/**
 * Base function for handling loading XML nodes
 *
 * Probably will be temporary, will most likely be more
 * beneficial to split into ~3 different XmlBug/XmlProgram functions
 *
 * @param node the node to load
  * @param parent the program that the item is a child of
 */
void Level::XmlItem(wxXmlNode *node, shared_ptr<Program> parent)
{
	// A pointer for the item we are loading
	shared_ptr<Bug> item;

	auto name = node->GetName();
	auto start = 0.0;
	node->GetAttribute(L"start").ToDouble(&start);

	if (name == L"bug")
	{
		auto type = node->GetAttribute(L"type");
		if (type == L"garbage")
		{
			item = make_shared<BugGarbage>(this);
			if (node->GetChildren() != nullptr)
			{
				item = make_shared<FatGarbageBug>(this);
				auto code = make_shared<Code>(node->GetChildren(), item);
				item->SetCode(code);
			}
		}
		else if (type == L"null")
		{
			item = make_shared<BugNull>(this);

			if (node->GetChildren() != nullptr)
			{
				item = make_shared<FatNullBug>(this);
				auto code = make_shared<Code>(node->GetChildren(), item);
				item->SetCode(code);
			}
		}
		else if (type == L"redundancy")
		{
			item = make_shared<BugRedundancy>(this);
		}
		item->SetProgram(nullptr,parent);
	}
	else if (name == L"feature")
	{
		item = make_shared<Feature>(this);
		item->SetProgram(nullptr,parent);
	}

	if (item != nullptr)
	{
		item->SetStart(start);
		mBugSquash->Add( item );
		item->XmlLoad(node);
		mNumBugs += 1;
	}
}

/**
 * Handles loading the bugs that are associated with a given program node
 * @param node The program node to loop through
 */
void Level::XmlProgram(wxXmlNode *node)
{
	/*
	 * Position program on screen properly with an upcall to Item::XmlItem
	 * Add to the level's list (need a function for this)
	 *
	 * Here we'll need to loop through the program node's children,
	 * which need to be translated into bugs/features, positioned properly (upcall),
	 * and then, if they are bugs, checked for any <code> child tag
	 */
	shared_ptr<Program> program_item;
	program_item = make_shared<Program>(this);
	program_item->XmlLoad(node);

	auto child = node->GetChildren();
	for( ; child; child = child->GetNext())
	{
		XmlItem(child, program_item);
	}

}

/**
 * Handle translating data from XML file into actual game
 * @param filename the XML file to read
 */
void Level::Load(const wxString &filename)
{
	//mNumPrograms = 0;

	wxXmlDocument xmlDoc;
	if(!xmlDoc.Load(filename))
	{
		wxMessageBox(L"Unable to load BugSquash file");
		return;
	}

	// Check to make sure we have a BugSquash to send them to
	if ( mBugSquash == nullptr )
	{
		wxMessageBox( L"Unable to find BugSquash to send items to");
		return;
	}

	// Get the XML document root node
	auto root = xmlDoc.GetRoot();

	auto main = root->GetAttribute("level");
	mName = main + " Begin";

	//
	// Traverse the children of the root
	// node of the XML document in memory!!!!
	//
	auto child = root->GetChildren();
	for( ; child; child=child->GetNext())
	{
		auto name = child->GetName();
		if(name == L"program")
		{
			mNumPrograms += 1;
			shared_ptr<Program> program_item;
			program_item = make_shared<Program>(this);
			mBugSquash->Add( program_item );
			program_item->XmlLoad(child);

			auto programText = child->GetAttribute("name");

			program_item->SetProgramTexts(programText);
		}
		else if (name == L"nuke")
		{
			auto start = 0.0;
			child->GetAttribute(L"start").ToDouble(&start);
			shared_ptr<BugNuke> nuke_item;
			nuke_item = make_shared<BugNuke>(this);
			mBugSquash->Add(nuke_item);
			nuke_item->XmlLoad(child);
			nuke_item->SetStart(start);
		}
	}
	child = root->GetChildren();
	for( ; child; child=child->GetNext())
	{
		auto name = child->GetName();
		if(name == L"program")
		{
			XmlProgram(child);
		}
	}
}

/**
 * Draw our graphics
 * @param graphics The graphics to be drawn
 */
void Level::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
	DrawLevel(graphics, mName);
}

/**
 * Draw our level information
 * @param graphics The graphics we are drawing on
 * @param label The content we are drawing
 */
void Level::DrawLevel(std::shared_ptr<wxGraphicsContext> graphics, std::wstring label)
{
	wxFont scoreFont(wxSize(TextSize,TextSize), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont labelFont(wxSize(LabelSize, LabelSize), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	graphics->SetFont(scoreFont, FontColor);
	double width, height;

	graphics->SetFont(labelFont, FontColor);

	graphics->GetTextExtent(label, &width, &height);
	graphics->DrawText(label, LeftX-width/2, LabelY);
}

/**
 * Gets an image or a nullptr from the map of images
 * @param filename The filename of the image we want
 * @return A shared point to the wxImage or a nullptr if it's not in the map
 */
std::shared_ptr< wxImage > Level::GetImage( const std::wstring& filename )
{
	return mBugSquash->GetImage( filename );
}


/**
 * Whether a FatBug's code is currently being edited
 * @return true if player is editing fat bugs, false otherwise
 */
bool Level::GetIsEditingCode()
{
	return mBugSquash->GetIsEditingCode();
}