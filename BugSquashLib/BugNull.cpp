/**
 * @file BugNull.cpp
 * @author npmar
 */

#include "pch.h"
#include "BugNull.h"
#include "Level.h"

using namespace std;

/// Bug filename
const wstring BugNullImageName = L"images/scarlet-gray-bug.png";

/**
 * Constructor
 * @param level Level that this bug is a member of
 */

BugNull::BugNull(Level *level) : Bug(level, BugNullImageName)
{
}