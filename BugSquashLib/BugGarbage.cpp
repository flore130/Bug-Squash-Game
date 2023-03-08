/**
 * @file BugGarbage.cpp
 * @author Ajuisiwon Azantilow
 */

#include "BugGarbage.h"

using namespace std;

/// The bug sprite image
const std::wstring GarbageBugSpriteImageName = L"blue-maize-bug.png";

/// The splat image
const std::wstring GarbageBugSplatImageName = L"blue-maize-splat.png";

/// Number of sprite images
const int GarbageBugNumSpriteImages = 5;


/**
* Constructor
 * @param level level that this bug is a member of
*/

BugGarbage::BugGarbage(Level *level) : Bug(level, GarbageBugSpriteImageName)
{

}