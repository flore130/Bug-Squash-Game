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
Scoreboard::Scoreboard(BugSquash* bugsquash) : mBugSquash(bugsquash)
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

void Scoreboard::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
	DrawScore(graphics, L"Fixed", LeftScoreX, mFixed);
	DrawScore(graphics, L"Missed", BugSquash::Width/2, mMissed);
	DrawScore(graphics, L"Oops", BugSquash::Width - LeftScoreX, mOops);
}

//string
//upcalls
//width and height
//constructor for bugsqussh call

void Scoreboard::DrawScore(std::shared_ptr<wxGraphicsContext> graphics, std::wstring label, float x, int score)
{
	wxFont scoreFont(wxSize(1,ScoreSize), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont labelFont(wxSize(1, LabelSize), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	graphics->SetFont(scoreFont, FontColor);
	double width = 1;
	double height = 1;
	std::string s = std::to_string(score);

	graphics->GetTextExtent(s, &width, &height);
	graphics->DrawText(s, x-width/2, ScoreY);

	graphics->SetFont(labelFont, FontColor);

	graphics->GetTextExtent(label, &width, &height);
	graphics->DrawText(label, x-width/2, ScoreLabelY);

}