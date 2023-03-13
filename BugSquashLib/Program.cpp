/**
 * @file Program.cpp
 * @author Ricardo Flores
 */

#include "Program.h"
#include "Level.h"
#include "Item.h"

/// Program image filename
const std::wstring ProgramImage = L"../images/laptop.png";

/// Program name font size
const int ProgramNameFontSize = 22;

/**
 * Construcor for feature
 * @param level The level that this program is a member of
 */
Program::Program(Level* level) : Item(level, ProgramImage)
{
	///Program must be behind bugs so the only way to do that is to add it to the beginning of the list
	///GetBugSquash will need to be added to the list of functions in BugSquash
//GetBugSquash->mItems.insert(mItems.begin(), this);
}

/**
 * Save this bug to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* Program::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);

	itemNode->AddAttribute(L"type", L"program");


	return itemNode;
}

/**
 * Load this XML Node to bug
 * @param node The parent node we are going to be a child of
 */
void Program::XmlLoad(wxXmlNode* node)
{
	Item::XmlLoad(node);
}

