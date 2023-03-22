/**
 * @file BugNuke.cpp
 * @author npmar
 */

#include "pch.h"
#include "BugNuke.h"

/// The feature sprite image
const std::wstring NukeImageName = L"images/bug-nuke.png";

BugNuke::BugNuke(Level* level) : Item(level, NukeImageName)
{

}

/**
 * Load this XML Node to bug
 * @param node The parent node we are going to be a child of
 */
void BugNuke::XmlLoad(wxXmlNode* node)
{
	Item::XmlLoad(node);
}


