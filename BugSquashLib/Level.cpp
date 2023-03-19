/**
 * @file Level.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "BugSquash.h"
#include "Code.h"
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
			if (node->GetChildren() != nullptr)
			{
				item = make_shared<FatGarbageBug>(this);
				auto code = make_shared<Code>(node->GetChildren());
				item->SetCode(code);
			}
			else
			{
				item = make_shared<BugGarbage>(this);
			}
		}
		else if (type == L"null")
		{
			if (node->GetChildren() != nullptr)
			{
				item = make_shared<FatNullBug>(this);
				auto code = make_shared<Code>(node->GetChildren());
				item->SetCode(code);
			}
			else
			{
				item = make_shared<BugNull>(this);
			}
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
		item->SetStart(start);
		mBugSquash->Add( item );
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

	// Check to make sure we have a BugSquash to send them to
	if ( mBugSquash == nullptr )
	{
		wxMessageBox( L"Unable to find BugSquash to send items to");
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
			mBugSquash->Add( program_item );
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
