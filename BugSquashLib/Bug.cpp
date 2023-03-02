/**
 * @file Bug.cpp
 * @author Kyle Nowak
 */

#include "pch.h"

#include "Bug.h"

/// The radius tolerance for successful hit tests
const double BugHitRange = 50;


/**
 * Hit test x,y to see if they are clicking on this bug.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @return true if clicked on bug
 */
bool Bug::HitTest(double x, double y)
{
	double dx = x - GetX();
	double dy = y - GetY();

	return sqrt(dx * dx + dy * dy) < BugHitRange;
}