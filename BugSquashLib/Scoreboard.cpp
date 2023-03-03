/**
 * @file Scoreboard.cpp
 * @author Ricar
 */

#include "Scoreboard.h"
#include "BugSquash.h"
#include "Item.h"

Scoreboard::Scoreboard(BugSquash *bugsquash) : mBugSquash(bugsquash)
{
}

//void Scoreboard::SquashIncrement(){
//	///if item is a feature it will increment the oops count
//	///if item is not a feature (normal bug) then increment the fixed count
//}


void Scoreboard::FixedIncrement()
{
	mFixed++;
}
void Scoreboard::OopsIncrement()
{
	mOops++;
}

void Scoreboard::MissedIncrement()
{
	///if item is a bug and makes it to the program it will increment the missed count
	mMissed++;
}

void Scoreboard::Reset(){
	mFixed = 0;
	mMissed = 0;
	mOops = 0;
}