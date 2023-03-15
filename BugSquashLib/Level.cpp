/**
 * @file Level.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "Level.h"
#include "BugGarbage.h"
#include "BugNull.h"
#include "BugRedundancy.h"
#include "Feature.h"
#include "Program.h"
#include "FatGarbageBug.h"
#include "FatNullBug.h"
#include "Item.h"

using namespace std;

/**
 * Base function for handling loading XML nodes
 *
 * Probably will be temporary, will most likely be more
 * beneficial to split into ~3 different XmlBug/XmlProgram functions
 *
 * @param node the node to load
 */
void Level::XmlItem(wxXmlNode *node, shared_ptr<Program> parent)
{
	// A pointer for the item we are loading
	shared_ptr<Item> item;

	auto name = node->GetName();

	if (name == L"bug")
	{
		auto type = node->GetAttribute(L"type");
		if (type == L"garbage")
		{
			item = make_shared<BugGarbage>(this);
		}
		else if (type == L"null")
		{
			item = make_shared<BugNull>(this);
		}
		else if (type == L"redundancy")
		{
			item = make_shared<BugRedundancy>(this);
		}
		item->SetProgram(node, parent);
	}
	else if (name == L"feature")
	{
		item = make_shared<Feature>(this);
		item->SetProgram(node, parent);
	}

	if (item != nullptr)
	{
		Add(item);
		item->XmlLoad(node);
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
 * Save the level as a .xml XML file.
 *
 * Open an XML file and stream the level data to it.
 *
 * @param filename The filename of the file to save the level to
 */
void Level::Save(const wxString &filename)
{
	wxXmlDocument xmlDoc;

	auto root = new wxXmlNode(wxXML_ELEMENT_NODE, L"xml");
	xmlDoc.SetRoot(root);

	// Iterate over all items and save them
	for (auto item : mItems)
	{
		item->XmlSave(root);
	}

	if(!xmlDoc.Save(filename, wxXML_NO_INDENTATION))
	{
		wxMessageBox(L"Write to XML failed");
		return;
	}
}

/**
 * Handle translating data from XML file into actual game
 * @param filename the XML file to read
 */
void Level::Load(const wxString &filename)
{
	wxXmlDocument xmlDoc;
	if(!xmlDoc.Load(filename))
	{
		wxMessageBox(L"Unable to load BugSquash file");
		return;
	}

	// Get the XML document root node
	auto root = xmlDoc.GetRoot();

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
			shared_ptr<Item> program_item;
			program_item = make_shared<Program>(this);
			mItems.push_back(program_item);
			program_item->XmlLoad(child);
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
 * Add an Item to our current level in the field
 * @param item the item that we are adding to our game
 */
void Level::Add( std::shared_ptr< Item > item )
{
	mItems.push_back( item );
}

/**
 * Clear the level data.
 *
 * Deletes all known items in the level.
 */
void Level::Clear()
{
	mItems.clear();
}


/**
 * Getter for the list of items in level
 * @return All items data in the level
 */
std::vector<std::shared_ptr< Item >> Level::GetItem()
{
	return mItems;
}

