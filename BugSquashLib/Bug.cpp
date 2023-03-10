/**
 * @file Bug.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "Program.h"
#include "Bug.h"

/// The radius tolerance for successful hit tests
const double BugHitRange = 50;


/**
 * Constructor
 * @param level the game level
 * @param filename the filename for the bug image
 */
Bug::Bug(Level *level, const std::wstring &filename) : Item(level, filename) {}


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


/**
 * Handles updates for animations
 * @param elapsed the seconds elapsed since last update
 */
void Bug::Update(double elapsed)
{
	double programX = mProgram->GetX();
	double programY = mProgram->GetY();
	double programDistance = DistanceTo(mProgram);

	double diffX = programX - GetX();
	double diffY = programY - GetY();

	double directionX = diffX / programDistance;
	double directionY = diffY / programDistance;

	SetLocation(GetX() + (directionX * mSpeed * elapsed),
				GetY() + (directionY * mSpeed * elapsed));
}