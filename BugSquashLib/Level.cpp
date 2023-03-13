/**
 * @file Level.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "Level.h"
#include "Item.h"

/**
 * Base function for handling loading XML nodes
 *
 * Probably will be temporary, will most likely be more
 * beneficial to split into ~3 different XmlBug/XmlProgram functions
 *
 * @param node the node to load
 */
void Level::XmlItem(wxXmlNode *node)
{

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
}

/**
 * Save the aquarium as a .aqua XML file.
 *
 * Open an XML file and stream the aquarium data to it.
 *
 * @param filename The filename of the file to save the aquarium to
 */
void Level::Save(const wxString &filename)
{
	wxXmlDocument xmlDoc;

	auto root = new wxXmlNode(wxXML_ELEMENT_NODE, L"aqua");
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
			XmlProgram(child);
		}
	}
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

