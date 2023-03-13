/**
 * @file FatGarbageBug.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "FatGarbageBug.h"


FatGarbageBug::FatGarbageBug(Level* level) : BugGarbage(level)
{

}

/**
 * Save this bug to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* FatGarbageBug::XmlSave(wxXmlNode* node)
{
	auto itemNode = Bug::XmlSave(node);

	itemNode->AddAttribute(L"type", L"fatgarbage");


	return itemNode;
}

/**
 * Load this XML Node to bug
 * @param node The parent node we are going to be a child of
 */
void FatGarbageBug::XmlLoad(wxXmlNode* node)
{
	Bug::XmlLoad(node);
}

