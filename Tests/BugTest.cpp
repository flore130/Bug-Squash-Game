/**
 * @file BugTest.cpp
 * @author Kyle Nowak
 */

#include <pch.h>
#include <BugSquash.h>
#include <BugNull.h>
#include <BugGarbage.h>
#include <FatNullBug.h>
#include <FatGarbageBug.h>
#include <BugRedundancy.h>
#include <Feature.h>
#include <Program.h>
#include <Bug.h>
#include <string>
#include <fstream>
#include "gtest/gtest.h"


using namespace std;

/// Test image
const std::wstring GarbageSplatImage = L"../images/blue-maize-splat.png";

/// Test sprite
const std::wstring GarbageBugImage = L"images/blue-maize-bug.png";

/// Test sprite count
const int SpriteCount = 1;


class BugMock : public Bug
{
public:
	BugMock(Level *level, const std::wstring &filename, const std::wstring &squashedFile) : Bug(level, filename, squashedFile, SpriteCount) {}
};


TEST(BugTest, Construct)
{
	BugSquash bugSquash;
	Level newLevel( &bugSquash );
	BugMock myBug(&newLevel, GarbageBugImage, GarbageSplatImage);
}

TEST(BugTest, HitTest)
{
	BugSquash bugSquash;
	Level newLevel( &bugSquash );
	BugMock bug(&newLevel, GarbageBugImage, GarbageSplatImage);

	// Testing at origin
	ASSERT_TRUE(bug.HitTest(0,0));
	ASSERT_TRUE(bug.HitTest(25, 25));
	ASSERT_TRUE(bug.HitTest(-45, 0));

	ASSERT_FALSE(bug.HitTest(100, 0));
	ASSERT_FALSE(bug.HitTest(0, 51));
	ASSERT_FALSE(bug.HitTest(-60, -20));


	// Testing at random point
	bug.SetLocation(220, 341);

	ASSERT_TRUE(bug.HitTest(220,341));
	ASSERT_TRUE(bug.HitTest(200, 331));
	ASSERT_TRUE(bug.HitTest(220, 360));

	ASSERT_FALSE(bug.HitTest(0, 0));
	ASSERT_FALSE(bug.HitTest(183, 378));
	ASSERT_FALSE(bug.HitTest(300, 300));
}


TEST(BugTest, MovementTest)
{
	BugSquash bugSquash;
	Level level( &bugSquash );
	std::shared_ptr<Program> program = std::make_shared<Program>(&level);
	program->SetLocation(200, 100);

	BugMock bug(&level, GarbageBugImage, GarbageSplatImage);
	bug.SetProgram(nullptr, program);
	bug.SetLocation(200, 200); // Position bug directly below program

	ASSERT_NEAR(bug.GetX(), 200, 0.01);
	ASSERT_NEAR(bug.GetY(), 200, 0.01);

	bug.SetSpeed(5);
	bug.Update(1);

	ASSERT_NEAR(bug.GetX(), 200, 0.01);
	ASSERT_NEAR(bug.GetY(), 195, 0.01) << L"Test single second of movement";

	bug.Update(3);

	ASSERT_NEAR(bug.GetX(), 200, 0.01);
	ASSERT_NEAR(bug.GetY(), 180, 0.01) << L"Testing multiple seconds elapsed of movement";

//	 Testing diagonal movement, setting bug 10 to left and 10 down
	bug.SetLocation(190, 110);

	bug.Update(1);

	ASSERT_NEAR(bug.GetX(), 193.535, 0.01) << L"Test single second of diagonal movement";
	ASSERT_NEAR(bug.GetY(), 106.464, 0.01) << L"Test single second of diagonal movement";

	bug.SetLocation(190, 110); // reset location

	bug.Update(1.41421);

	ASSERT_NEAR(bug.GetX(), 195, 0.01) << L"Test fractional time of diagonal movement";
	ASSERT_NEAR(bug.GetY(), 105, 0.01) << L"Test fractional time of diagonal movement";

	bug.SetLocation(245, 300);

	bug.Update(4);

	ASSERT_NEAR(bug.GetX(), 240.610, 0.01) << L"Test 4 seconds of diagonal movement";
	ASSERT_NEAR(bug.GetY(), 280.488, 0.01) << L"Test 4 seconds of diagonal movement";

}

