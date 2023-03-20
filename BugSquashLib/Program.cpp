/**
 * @file Program.cpp
 * @author Ricardo Flores
 */

#include "pch.h"
#include "Program.h"


/// Program image filename
const std::wstring ProgramImage = L"images/laptop.png";

/// Program name font size
const int ProgramNameFontSize = 22;

/**
 * Constructor for feature
 * @param level The level that this program is a member of
 */
Program::Program(Level* level) : Item(level, ProgramImage)
{
}

/**
 * Load this XML Node to bug
 * @param node The parent node we are going to be a child of
 */
void Program::XmlLoad(wxXmlNode* node)
{
	Item::XmlLoad(node);
}

