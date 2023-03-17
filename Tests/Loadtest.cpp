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
	// Checks type of every item
	ASSERT_TRUE(items[0]->GetType() == "Program");
	ASSERT_TRUE(items[1]->GetType() == "Redundancy");
	ASSERT_TRUE(items[2]->GetType() == "Feature");

	// Grabs an item and confirms its position
	auto item = bugSquash->HitTest(625, 500);
	ASSERT_TRUE(item->HitTest(625, 500));

	item = bugSquash->HitTest(100, 800);
	ASSERT_TRUE(item->HitTest(100, 800));
	// Tests if item is moving
	item->Update(1);
	ASSERT_FALSE(item->HitTest(100, 800));
	// Resets item's position
	item->Update(-1);
	ASSERT_TRUE(item->HitTest(100, 800));

	// Test invalid location
	item = bugSquash->HitTest(300, 200);
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
	// Checks type of every item
	ASSERT_TRUE(items[0]->GetType() == "Program");
	ASSERT_TRUE(items[1]->GetType() == "Garbage");
	ASSERT_TRUE(items[2]->GetType() == "Garbage");
	ASSERT_TRUE(items[3]->GetType() == "Null");
	ASSERT_TRUE(items[4]->GetType() == "Redundancy");
	ASSERT_TRUE(items[5]->GetType() == "Feature");
	ASSERT_TRUE(items[6]->GetType() == "Garbage");
	ASSERT_TRUE(items[7]->GetType() == "Null");
	ASSERT_TRUE(items[8]->GetType() == "Feature");
	ASSERT_TRUE(items[9]->GetType() == "Garbage");
	ASSERT_TRUE(items[10]->GetType() == "Null");
	ASSERT_TRUE(items[11]->GetType() == "Redundancy");
	ASSERT_TRUE(items[12]->GetType() == "Garbage");
	auto item = bugSquash->HitTest(625, 500);
	ASSERT_FALSE(item == nullptr);
	ASSERT_TRUE(item->HitTest(625, 500));
	// We call update on the program, but its location stays the same because it is not a bug
	item->Update(1);
	ASSERT_TRUE(item->HitTest(625, 500));

	item = bugSquash->HitTest(-100, 500);
	ASSERT_FALSE(item == nullptr);
	ASSERT_TRUE(item->HitTest(-100, 500));
	// Tests if item is moving
	item->Update(1);
	ASSERT_FALSE(item->HitTest(-100, 500));
	// Resets item's position
	item->Update(-1);
	ASSERT_TRUE(item->HitTest(-100, 500));

	item = bugSquash->HitTest(500, 1100);
	ASSERT_FALSE(item == nullptr);
	ASSERT_TRUE(item->HitTest(500, 1100));
	// Tests if item is moving
	item->Update(1);
	ASSERT_FALSE(item->HitTest(500, 1100));
	// Resets item's position
	item->Update(-1);
	ASSERT_TRUE(item->HitTest(500, 1100));

	// Test invalid location
	item = bugSquash->HitTest(300, 200);
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
	// Check all item types
	ASSERT_TRUE(items[0]->GetType() == "Program");
	ASSERT_TRUE(items[1]->GetType() == "Program");
	ASSERT_TRUE(items[2]->GetType() == "Program");
	ASSERT_TRUE(items[3]->GetType() == "Null");
	ASSERT_TRUE(items[4]->GetType() == "Garbage");
	ASSERT_TRUE(items[5]->GetType() == "Null");
	ASSERT_TRUE(items[6]->GetType() == "Feature");
	ASSERT_TRUE(items[7]->GetType() == "Garbage");
	ASSERT_TRUE(items[8]->GetType() == "Null");
	ASSERT_TRUE(items[9]->GetType() == "Redundancy");
	ASSERT_TRUE(items[10]->GetType() == "Feature");
	ASSERT_TRUE(items[11]->GetType() == "Null");
	ASSERT_TRUE(items[12]->GetType() == "Garbage");
	ASSERT_TRUE(items[13]->GetType() == "Feature");
	ASSERT_TRUE(items[14]->GetType() == "Feature");
	ASSERT_TRUE(items[15]->GetType() == "Null");
	ASSERT_TRUE(items[16]->GetType() == "Feature");
	ASSERT_TRUE(items[17]->GetType() == "Null");
	ASSERT_TRUE(items[18]->GetType() == "Garbage");
	ASSERT_TRUE(items[19]->GetType() == "Feature");
	ASSERT_TRUE(items[20]->GetType() == "Garbage");
	ASSERT_TRUE(items[21]->GetType() == "Null");
	ASSERT_TRUE(items[22]->GetType() == "Garbage");
	ASSERT_TRUE(items[23]->GetType() == "Redundancy");
	ASSERT_TRUE(items[24]->GetType() == "Feature");
	ASSERT_TRUE(items[25]->GetType() == "Garbage");
	ASSERT_TRUE(items[26]->GetType() == "Garbage");


	auto item = bugSquash->HitTest(300, 200);
	ASSERT_FALSE(item == nullptr);
	ASSERT_TRUE(item->HitTest(300, 200));

	item = bugSquash->HitTest(600, 800);
	ASSERT_FALSE(item == nullptr);
	ASSERT_TRUE(item->HitTest(600, 800));
	// Tests if item is moving; in this case it is a program, so its position will stay the same
	item->Update(1);
	ASSERT_TRUE(item->HitTest(600, 800));

	item = bugSquash->HitTest(600, 1100);
	ASSERT_FALSE(item == nullptr);
	ASSERT_TRUE(item->HitTest(600, 1100));
	// Tests if item is moving
	item->Update(1);
	ASSERT_FALSE(item->HitTest(600, 1100));
	// Resets item's position
	item->Update(-1);
	ASSERT_TRUE(item->HitTest(600, 1100));

	// Test invalid location
	item = bugSquash->HitTest(650, 1100);
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