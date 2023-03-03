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

void Scoreboard::SquashIncrement(Item* item){
	///if item is a feature it will increment the oops count
	///if item is not a feature (normal bug) then increment the fixed count
}

void Scoreboard::ProgramIncrement(Item* item){
	///if item is a bug and makes it to the program it will increment the missed count
}

void Scoreboard::Reset(){
	mFixed = 0;
	mMissed = 0;
	mOops = 0;
}