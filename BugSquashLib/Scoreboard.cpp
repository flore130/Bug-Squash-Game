/**
 * @file Scoreboard.cpp
 * @author Ricar
 */

#include "pch.h"
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

/**
 * Constructor
 * @param bugsquash a pointer to a bugsquash object
 */
Scoreboard::Scoreboard(BugSquash *bugsquash) : mBugSquash(bugsquash)
{
}

/**
 * Increase the count of squashed bugs
 */
void Scoreboard::FixedIncrement()
{
	mFixed++;
}

/**
 * Increase the count of squashed features
 */
void Scoreboard::OopsIncrement()
{
	mOops++;
}

/**
 * Increase the count of missed bugs
 */
void Scoreboard::MissedIncrement()
{
	///if item is a bug and makes it to the program it will increment the missed count
	mMissed++;
}

/**
 * Reset the scoreboard to zeros
 */
void Scoreboard::Reset(){
	mFixed = 0;
	mMissed = 0;
	mOops = 0;
}