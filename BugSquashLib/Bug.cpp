/**
 * @file Bug.cpp
 * @author Kyle Nowak
 */

#include "pch.h"
#include "Program.h"
#include "Bug.h"

using namespace std;

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

//	// Get difference in X and Y between bug and program
	double diffX = programX - GetX();
	double diffY = programY - GetY();

	// Scale to normalize the vector
	double directionX = diffX / programDistance;
	double directionY = diffY / programDistance;

	// Set location to pixels/second * seconds * direction + current position
	SetLocation(GetX() + (directionX * mSpeed * elapsed),
				GetY() + (directionY * mSpeed * elapsed));
}

void Bug::SetProgram(wxXmlNode *node, shared_ptr<Program> parent)
{
	this->mProgram = parent;
}