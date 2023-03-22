/**
 * @file BugGarbageTest.cpp
 * @author Kev
 */

#include <pch.h>
#include <BugSquash.h>
#include <BugGarbage.h>
#include <Feature.h>
#include <Program.h>
#include "gtest/gtest.h"

/// Test sprite count
const int SpriteCount = 1;

TEST(GarbageBugTest, Construct)
{
	BugSquash bugSquash;
	Level newLevel( &bugSquash );
	BugGarbage myBug( &newLevel );
}

TEST(GarbageBugTest, HitTest)
{
	BugSquash bugSquash;
	Level newLevel( &bugSquash );
	BugGarbage myBug( &newLevel );

	// Testing at origin
	ASSERT_TRUE(myBug.HitTest(0,0));
	ASSERT_TRUE(myBug.HitTest(25, 25));
	ASSERT_TRUE(myBug.HitTest(-45, 0));

	ASSERT_FALSE(myBug.HitTest(100, 0));
	ASSERT_FALSE(myBug.HitTest(0, 51));
	ASSERT_FALSE(myBug.HitTest(-60, -20));


	// Testing at random point
	myBug.SetLocation(220, 341);

	ASSERT_TRUE(myBug.HitTest(220,341));
	ASSERT_TRUE(myBug.HitTest(200, 331));
	ASSERT_TRUE(myBug.HitTest(220, 360));

	ASSERT_FALSE(myBug.HitTest(0, 0));
	ASSERT_FALSE(myBug.HitTest(183, 378));
	ASSERT_FALSE(myBug.HitTest(300, 300));
}

TEST(GarbageBugTest, MovementTest)
{
	BugSquash bugSquash;
	Level level( &bugSquash );
	std::shared_ptr<Program> program = std::make_shared<Program>(&level);
	program->SetLocation(200, 100);

	BugGarbage myBug(&level);
	myBug.SetProgram(nullptr, program);
	myBug.SetLocation(200, 200); // Position bug directly below program

	ASSERT_NEAR(myBug.GetX(), 200, 0.01);
	ASSERT_NEAR(myBug.GetY(), 200, 0.01);

	myBug.SetSpeed(5);
	myBug.Update(1);

	ASSERT_NEAR(myBug.GetX(), 200, 0.01);
	ASSERT_NEAR(myBug.GetY(), 195, 0.01) << L"Test single second of movement";
}