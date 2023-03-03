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

}

void Scoreboard::ProgramIncrement(){}

void Scoreboard::Reset(){
	mFixed = 0;
	mMissed = 0;
	mOops = 0;
}