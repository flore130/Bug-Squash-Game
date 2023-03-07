/**
 * @file BugNull.cpp
 * @author npmar
 */

#include "pch.h"
#include "BugNull.h"
#include "Level.h"

using namespace std;

/// The bug sprite image
const wstring NullBugSpriteImageName = L"scarlet-gray-bug.png";

/// The splat image
const wstring NullBugSplatImageName = L"scarlet-gray-splat.png";

/// Number of sprite images
const int NullBugNumSpriteImages = 6;




/**
 * Constructor
 * @param level Level that this bug is a member of
 */

BugNull::BugNull(Level *level) : Bug(level, NullBugSpriteImageName)
{
}
