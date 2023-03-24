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

/// font size to use
const int TextSize = 200;

/// Label for font size to use
const int LabelSize = 140;

/// The font color to use
const wxColour FontColor = wxColour(255, 255, 255);

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

/**
 * Draws in each program text for each respective program
 * @param gc The graphs we are drawing on
 */
void Program::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
	Item::Draw(gc);
	for(auto programText : mProgramTexts)
	{
		DrawText(gc, programText, GetX(), GetY());
	}
}

/**
 * Takes care of the specific font, color, and text properties
 * @param graphics The graphs we are drawing on
 * @param text program name
 * @param x coordinate
 * @param y coordinate
 */
void Program::DrawText(std::shared_ptr<wxGraphicsContext> graphics, wxString text, double x, double y)
{
	wxFont scoreFont(wxSize(ProgramNameFontSize,ProgramNameFontSize), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont labelFont(wxSize(ProgramNameFontSize, ProgramNameFontSize), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	graphics->SetFont(scoreFont, FontColor);
	double width, height;

	graphics->SetFont(labelFont, FontColor);

	graphics->GetTextExtent(text, &width, &height);
	graphics->DrawText(text, x-width/2, y - height/2);
}