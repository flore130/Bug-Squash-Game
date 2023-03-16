/**
 * @file Scoreboard.cpp
 * @author Ricar
 */

#include "pch.h"
#include <wx/wx.h>
#include <wx/graphics.h>


#include "Scoreboard.h"
#include "BugSquash.h"
#include "Item.h"
#include "string"

using namespace std;

/// Score font size to use
const int ScoreSize = 85;

/// Label for score font size to use
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
 * @param bugSquash A pointer to a BugSquash object
 */
Scoreboard::Scoreboard(BugSquash* bugSquash) : mBugSquash(bugSquash)
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

/**
 * Draw our graphics
 * @param graphics The graphics to be drawn
 */
void Scoreboard::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
	DrawScore(graphics, L"Fixed", LeftScoreX, mFixed);
	DrawScore(graphics, L"Missed", BugSquash::Width/2, mMissed);
	DrawScore(graphics, L"Oops", BugSquash::Width - LeftScoreX, mOops);
}

/**
 * Draw the current score
 * @param graphics The graphics to draw on
 * @param label The title of the score
 * @param x Location of the score
 * @param score Value of the score
 */
void Scoreboard::DrawScore(std::shared_ptr<wxGraphicsContext> graphics, std::wstring label, float x, int score)
{
	wxFont scoreFont(wxSize(ScoreSize,ScoreSize), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont labelFont(wxSize(LabelSize, LabelSize), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	graphics->SetFont(scoreFont, FontColor);
	double width, height;
	std::string s = std::to_string(score);


	graphics->GetTextExtent(s, &width, &height);
	graphics->DrawText(s, x-width/2, ScoreY);

	graphics->SetFont(labelFont, FontColor);

	graphics->GetTextExtent(label, &width, &height);
	graphics->DrawText(label, x-width/2, ScoreLabelY);

}