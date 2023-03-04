/**
 * @file Scoreboard.cpp
 * @author Ricar
 */

#include "Scoreboard.h"
#include "BugSquash.h"
#include "Item.h"

/// Score font size to use
const int ScoreSize = 85;

/// Lable for score font size to use
const int LabelSize = 40;

/// The font color to use
const wxColour FontColor = wxColour(0, 200, 200);

/// Left score X location. The right score is
/// the width minus this value.
const int LeftScoreX = 150;

/// Score Y location
const int ScoreY = 20;

/// Score label Y location
const int ScoreLabelY = 100;

Scoreboard::Scoreboard(BugSquash *bugsquash) : mBugSquash(bugsquash)
{
}

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