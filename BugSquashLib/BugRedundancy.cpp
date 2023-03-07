/**
 * @file BugRedundancy.cpp
 * @author npmar
 */

#include "pch.h"
#include "BugRedundancy.h"
#include "Level.h"

using namespace std;

/// Bug filename
const wstring BugRedundancyImageName = L"images/redundancy-fly-base.png";

/**
 * Constructor
 * @param level Level that this bug is a member of
 */

BugRedundancy::BugRedundancy(Level *level) : Bug(level, BugRedundancyImageName)
{
}