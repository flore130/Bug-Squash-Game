/**
 * @file BugGarbage.cpp
 * @author Ajuisiwon Azantilow
 */

#include "pch.h"
#include "BugGarbage.h"

using namespace std;

/// The bug sprite image
const std::wstring GarbageBugSpriteImageName = L"images/blue-maize-bug.png";

/// The splat image
const std::wstring GarbageBugSplatImageName = L"images/blue-maize-splat.png";

/// Number of sprite images
const int GarbageBugNumSpriteImages = 5;


/**
* Constructor
 * @param level level that this bug is a member of
*/

BugGarbage::BugGarbage(Level *level) : Bug(level, GarbageBugSpriteImageName)
{

}

/**
 * Save this bug to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* BugGarbage::XmlSave(wxXmlNode* node)
{
	auto itemNode = Bug::XmlSave(node);

	itemNode->AddAttribute(L"type", L"garbage");


	return itemNode;
}

/**
 * Load this XML Node to bug
 * @param node The parent node we are going to be a child of
 */
void BugGarbage::XmlLoad(wxXmlNode* node)
{
	Bug::XmlLoad(node);
}

