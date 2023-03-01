/**
 * @file BugSquash.cpp
 * @author npmar
 */

#include "pch.h"
#include "BugSquash.h"
#include <wx/wx.h>
#include <memory>
#include <random>

#include <algorithm>

using namespace std;


/**
 * Load the BugSquash application from an XML file.
 *
 * Opens the XML file and reads through, creating items as appropriate.
 *
 * @param filename The filename of the file to load the aquarium from.
 */
void BugSquash::Load(const wxString &filename)
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
		if(name == L"item")
		{
			XmlItem(child);
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
	shared_ptr<Item> item;

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
//		item->XmlLoad(node);
	}
}

/**
 * Add an item to the application
 * @param item New item to add
 */
void BugSquash::Add(std::shared_ptr<Item> item)
{

}
