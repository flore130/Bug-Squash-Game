/**
 * @file FatNullBug.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "FatNullBug.h"

/**
 * Constructor
 * @param level Level that this bug is a member of
 */
FatNullBug::FatNullBug(Level* level) : BugNull(level)
{

}

/**
 * Save this bug to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* FatNullBug::XmlSave(wxXmlNode* node)
{
	auto itemNode = Bug::XmlSave(node);

	itemNode->AddAttribute(L"type", L"fatnull");


	return itemNode;
}

/**
 * Load this XML Node to bug
 * @param node The parent node we are going to be a child of
 */
void FatNullBug::XmlLoad(wxXmlNode* node)
{
	Bug::XmlLoad(node);
}

