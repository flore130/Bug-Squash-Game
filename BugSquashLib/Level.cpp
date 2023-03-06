/**
 * @file Level.cpp
 * @author Kyle Nowak
 */

#include "pch.h"

#include "Level.h"
#include "Item.h"


/**
 * Accepts a visitor into this level
 * @param visitor the visitor that is visiting this level
 */
void Level::Accept( ItemVisitor* visitor )
{
	for (auto item : mItems)
	{
		item->Accept(visitor);
	}
}


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
		if(name == L"bug" || name == L"program" || name == L"feature")
		{
			XmlItem(child);
		}
	}
}