/**
 * @file Scoreboard.h
 * @author Ricardo Flores
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_SCOREBOARD_H
#define PROJECT1_BUGSQUASHLIB_SCOREBOARD_H


#include "BugSquash.h"
class Item;

/**
 * Class that keeps track of the scores displayed on the scoreboard
 */
class Scoreboard
{
private:
	/// A pointer to a BugSquash object
	BugSquash* mBugSquash = nullptr;

	/// Variable to keep track of squashed bugs
	int mFixed = 0;

	/// Variable to keep track of missed bugs
	int mMissed = 0;

	/// Variable to keep track of squashed features
	int mOops = 0;

public:
	Scoreboard(BugSquash* bugsqaush);

	void FixedIncrement();
	void OopsIncrement();
	void MissedIncrement();
	void Reset();

};

#endif //PROJECT1_BUGSQUASHLIB_SCOREBOARD_H
