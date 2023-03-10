/**
 * @file BugTest.cpp
 * @author Kyle Nowak
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <Bug.h>
#include <Level.h>
#include <Program.h>

const std::wstring GarbageSplatImage = L"../images/blue-maize-bug.png";


TEST(BugTest, Construct)
{
	Level newLevel;
	Bug myBug(&newLevel, GarbageSplatImage);
}


TEST(BugTest, HitTest)
{
	Level newLevel;
	Bug bug(&newLevel, GarbageSplatImage);

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
	Level level;
	std::shared_ptr<Program> program = std::make_shared<Program>(&level);
	program->SetLocation(200, 100);

	Bug bug(&level, GarbageSplatImage);
	bug.SetProgram(program);
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

	// Testing diagonal movement, setting bug 10 to left and 10 down
	bug.SetLocation(190, 110);

	bug.Update(1);

	ASSERT_NEAR(bug.GetX(), 193.535, 0.01) << L"Test single second of diagonal movement";
	ASSERT_NEAR(bug.GetY(), 106.464, 0.01) << L"Test single second of diagonal movement";

}
