/**
 * @file LoadTest.cpp
 * @author npmar
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <BugSquash.h>
#include <BugNull.h>
#include <BugGarbage.h>
#include <FatNullBug.h>
#include <FatGarbageBug.h>
#include <BugRedundancy.h>
#include <Feature.h>
#include <Program.h>
#include <Bug.h>
#include <Level.h>
#include <regex>
#include <string>
#include <fstream>
#include <wx/filename.h>

using namespace std;

void TestLevelZero(BugSquash *bugSquash)
{
	auto items = bugSquash->LoadTest();
	//Tests that there are three items in level 0
	ASSERT_TRUE(items.size() == 3);
	// Tests that every item is valid and not nullptr
	for (auto i : items)
	{
		ASSERT_TRUE(i != nullptr);
	}

	// Grabs an item and confirms its position
	ASSERT_TRUE(items[0]->GetX() == 625);
	ASSERT_TRUE(items[0]->GetY() == 500);

	ASSERT_TRUE(items[1]->GetX() == 100);
	ASSERT_TRUE(items[1]->GetY() == 600);
	// Tests if item is moving
	items[1]->Update(1);
	ASSERT_FALSE(items[1]->GetX() == (100));
	ASSERT_FALSE(items[1]->GetY() == (600));
	// Resets item's position
	items[1]->Update(-1);
	ASSERT_TRUE(items[1]->GetX() == 100);
	ASSERT_TRUE(items[1]->GetY() == 600);

	ASSERT_TRUE(items[2]->GetX() == 100);
	ASSERT_TRUE(items[2]->GetY() == 800);
	// Tests if item is moving
	items[2]->Update(1);
	ASSERT_FALSE(items[2]->GetX() == (100));
	ASSERT_FALSE(items[2]->GetY() == (800));
	// Resets item's position
	items[2]->Update(-1);
	ASSERT_TRUE(items[2]->GetX() == 100);
	ASSERT_TRUE(items[2]->GetY() == 800);

	// Test invalid location
	auto item = bugSquash->HitTest(300, 200);
	ASSERT_TRUE(item == nullptr);

}

void TestLevelOne(BugSquash *bugSquash)
{
	auto items = bugSquash->LoadTest();
	//Tests that there are 13 items in level 1
	ASSERT_TRUE(items.size() == 13);
	// Test that all items are loaded and not nullptr
	for (auto i : items)
	{
		ASSERT_TRUE(i != nullptr);
	}

	// Grabs an item and confirms its position
	ASSERT_TRUE(items[0]->GetX() == 625);
	ASSERT_TRUE(items[0]->GetY() == 500);
	items[0]->Update(1);
	// Since this is a program, it will not be moved when update is called on it
	ASSERT_TRUE(items[0]->GetX() == 625);
	ASSERT_TRUE(items[0]->GetY() == 500);

	ASSERT_TRUE(items[1]->GetX() == 500);
	ASSERT_TRUE(items[1]->GetY() == -100);
	// Tests if item is moving
	items[1]->Update(1);
	ASSERT_FALSE(items[1]->GetX() == (500));
	ASSERT_FALSE(items[1]->GetY() == (-100));
	// Resets item's position
	items[1]->Update(-1);
	ASSERT_TRUE(items[1]->GetX() == 500);
	ASSERT_TRUE(items[1]->GetY() == -100);

	ASSERT_TRUE(items[2]->GetX() == 1350);
	ASSERT_TRUE(items[2]->GetY() == 100);

	ASSERT_TRUE(items[3]->GetX() == -100);
	ASSERT_TRUE(items[3]->GetY() == 500);

	ASSERT_TRUE(items[4]->GetX() == 1000);
	ASSERT_TRUE(items[4]->GetY() == -100);

	ASSERT_TRUE(items[5]->GetX() == 600);
	ASSERT_TRUE(items[5]->GetY() == 1100);

	ASSERT_TRUE(items[6]->GetX() == -100);
	ASSERT_TRUE(items[6]->GetY() == 900);

	ASSERT_TRUE(items[7]->GetX() == 500);
	ASSERT_TRUE(items[7]->GetY() == 1100);
	// Tests if item is moving
	items[7]->Update(2);
	ASSERT_FALSE(items[7]->GetX() == (500));
	ASSERT_FALSE(items[7]->GetY() == (1100));
	// Resets item's position
	items[7]->Update(-2);
	ASSERT_TRUE(items[7]->GetX() == 500);
	ASSERT_TRUE(items[7]->GetY() == 1100);

	ASSERT_TRUE(items[8]->GetX() == 600);
	ASSERT_TRUE(items[8]->GetY() == -100);

	ASSERT_TRUE(items[9]->GetX() == -100);
	ASSERT_TRUE(items[9]->GetY() == 100);

	ASSERT_TRUE(items[10]->GetX() == 1350);
	ASSERT_TRUE(items[10]->GetY() == 1100);

	ASSERT_TRUE(items[11]->GetX() == -100);
	ASSERT_TRUE(items[11]->GetY() == 1200);

	ASSERT_TRUE(items[12]->GetX() == -100);
	ASSERT_TRUE(items[12]->GetY() == 900);


	// Test invalid location
	auto item = bugSquash->HitTest(300, 200);
	ASSERT_TRUE(item == nullptr);
}

void TestLevelTwo(BugSquash *bugSquash)
{
	auto items = bugSquash->LoadTest();
	//Tests that there are 27 items in level 2
	ASSERT_TRUE(items.size() == 27);
	// Test that all items are loaded and not nullptr
	for (auto i : items)
	{
		ASSERT_TRUE(i != nullptr);
	}

	// Grabs an item and confirms its position
	ASSERT_TRUE(items[0]->GetX() == 300);
	ASSERT_TRUE(items[0]->GetY() == 200);
	items[0]->Update(1);
	// Since this is a program, it will not be moved when update is called on it
	ASSERT_TRUE(items[0]->GetX() == 300);
	ASSERT_TRUE(items[0]->GetY() == 200);

	ASSERT_TRUE(items[1]->GetX() == 600);
	ASSERT_TRUE(items[1]->GetY() == 800);

	ASSERT_TRUE(items[2]->GetX() == 850);
	ASSERT_TRUE(items[2]->GetY() == 200);

	ASSERT_TRUE(items[3]->GetX() == 500);
	ASSERT_TRUE(items[3]->GetY() == -100);

	ASSERT_TRUE(items[4]->GetX() == 1350);
	ASSERT_TRUE(items[4]->GetY() == 1300);

	ASSERT_TRUE(items[5]->GetX() == 500);
	ASSERT_TRUE(items[5]->GetY() == 1400);

	ASSERT_TRUE(items[6]->GetX() == 600);
	ASSERT_TRUE(items[6]->GetY() == 1100);

	ASSERT_TRUE(items[7]->GetX() == -100);
	ASSERT_TRUE(items[7]->GetY() == 900);
	// Tests if item is moving
	items[7]->Update(2);
	ASSERT_FALSE(items[7]->GetX() == -100);
	ASSERT_FALSE(items[7]->GetY() == 900);
	// Resets item's position
	items[7]->Update(-2);
	ASSERT_TRUE(items[7]->GetX() == -100);
	ASSERT_TRUE(items[7]->GetY() == 900);

	ASSERT_TRUE(items[8]->GetX() == 1550);
	ASSERT_TRUE(items[8]->GetY() == 1190);

	ASSERT_TRUE(items[9]->GetX() == 100);
	ASSERT_TRUE(items[9]->GetY() == 1300);

	ASSERT_TRUE(items[10]->GetX() == 1300);
	ASSERT_TRUE(items[10]->GetY() == 500);

	ASSERT_TRUE(items[11]->GetX() == 500);
	ASSERT_TRUE(items[11]->GetY() == -100);

	ASSERT_TRUE(items[12]->GetX() == -100);
	ASSERT_TRUE(items[12]->GetY() == 100);

	ASSERT_TRUE(items[13]->GetX() == 200);
	ASSERT_TRUE(items[13]->GetY() == -100);

	ASSERT_TRUE(items[14]->GetX() == 1140);
	ASSERT_TRUE(items[14]->GetY() == 1400);

	ASSERT_TRUE(items[15]->GetX() == 1550);
	ASSERT_TRUE(items[15]->GetY() == 190);

	ASSERT_TRUE(items[16]->GetX() == -100);
	ASSERT_TRUE(items[16]->GetY() == -100);
	// Tests if item is moving
	items[16]->Update(2);
	ASSERT_FALSE(items[16]->GetX() == (-100));
	ASSERT_FALSE(items[16]->GetY() == (-100));
	// Resets item's position
	items[16]->Update(-2);
	ASSERT_TRUE(items[16]->GetX() == -100);
	ASSERT_TRUE(items[16]->GetY() == -100);

	ASSERT_TRUE(items[17]->GetX() == 1000);
	ASSERT_TRUE(items[17]->GetY() == 1180);

	ASSERT_TRUE(items[18]->GetX() == 1050);
	ASSERT_TRUE(items[18]->GetY() == -100);

	ASSERT_TRUE(items[19]->GetX() == 200);
	ASSERT_TRUE(items[19]->GetY() == -700);

	ASSERT_TRUE(items[20]->GetX() == -100);
	ASSERT_TRUE(items[20]->GetY() == 1150);

	ASSERT_TRUE(items[21]->GetX() == 1050);
	ASSERT_TRUE(items[21]->GetY() == -100);

	ASSERT_TRUE(items[22]->GetX() == -100);
	ASSERT_TRUE(items[22]->GetY() == 100);

	ASSERT_TRUE(items[23]->GetX() == 1000);
	ASSERT_TRUE(items[23]->GetY() == 1150);

	ASSERT_TRUE(items[24]->GetX() == 100);
	ASSERT_TRUE(items[24]->GetY() == 1160);

	ASSERT_TRUE(items[25]->GetX() == 1000);
	ASSERT_TRUE(items[25]->GetY() == -100);

	ASSERT_TRUE(items[26]->GetX() == 1550);
	ASSERT_TRUE(items[26]->GetY() == 190);


	// Test invalid location
	auto item = bugSquash->HitTest(650, 1100);
	ASSERT_TRUE(item == nullptr);
}

TEST(LoadTest, Load)
{
BugSquash bugSquash;


auto file1 = L"data/level0.xml";

bugSquash.Load(file1);

TestLevelZero(&bugSquash);

BugSquash bugSquash2;


auto file2 = L"data/level1.xml";

bugSquash2.Load(file2);

TestLevelOne(&bugSquash2);

BugSquash bugSquash3;

auto file3 = L"data/level2.xml";

bugSquash3.Load(file3);

TestLevelTwo(&bugSquash3);
}
