/**
 * @file Scoreboard.h
 * @author Ricardo Flores
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_SCOREBOARD_H
#define PROJECT1_BUGSQUASHLIB_SCOREBOARD_H
#include "pch.h"
#include "BugSquash.h"
class Item;

class Scoreboard
{
private:
	BugSquash* mBugSquash = nullptr;
	int mFixed = 0;
	int mMissed = 0;
	int mOops = 0;

public:
	Scoreboard(BugSquash* bugsqaush);

	void SquashIncrement(Item* item);
	void ProgramIncrement();
	void Reset();

};

#endif //PROJECT1_BUGSQUASHLIB_SCOREBOARD_H
