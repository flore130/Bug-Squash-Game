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

Program::Program(Level* level) : Item(level, ProgramImage)
{
	///Program must be behind bugs so the only way to do that is to add it to the beginning of the list
	///GetBugSquash will need to be added to the list of functions in BugSquash
//GetBugSquash->mItems.insert(mItems.begin(), this);
}
