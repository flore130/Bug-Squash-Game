/**
 * @file BugNukeTest.cpp
 * @author npmar
 */

#include <pch.h>
#include <BugNuke.h>
#include <BugNull.h>
#include <BugSquash.h>
#include <Level.h>
#include "gtest/gtest.h"

TEST(BugNukeTest, Construct)
{
	BugSquash bugSquash;
	Level newLevel( &bugSquash );
	BugNuke newNuke( &newLevel );
}

TEST(BugNukeTest, HitTest)
{
	BugSquash bugSquash;
	Level newLevel( &bugSquash );
	BugNuke newNuke( &newLevel );

	// Testing at origin
	ASSERT_TRUE(newNuke.HitTest(0,0));
	ASSERT_TRUE(newNuke.HitTest(25, 25));
	ASSERT_TRUE(newNuke.HitTest(-45, 0));

	ASSERT_FALSE(newNuke.HitTest(100, 0));
	ASSERT_FALSE(newNuke.HitTest(0, 100));
	ASSERT_FALSE(newNuke.HitTest(-100, -100));


	// Testing at random point
	newNuke.SetLocation(220, 341);

	ASSERT_TRUE(newNuke.HitTest(220,341));
	ASSERT_TRUE(newNuke.HitTest(200, 331));
	ASSERT_TRUE(newNuke.HitTest(220, 360));

	ASSERT_FALSE(newNuke.HitTest(0, 0));
	ASSERT_FALSE(newNuke.HitTest(150, 400));
	ASSERT_FALSE(newNuke.HitTest(300, 300));
}

TEST(BugNukeTest, KillTest)
{
	BugSquash bugSquash;
	Level newLevel( &bugSquash );

	std::shared_ptr<BugNull> nullBug = std::make_shared<BugNull>(&newLevel);

	nullBug->SetLocation(200, 200);

	bugSquash.Add(nullBug);
	ASSERT_TRUE(nullBug->HitTest(200,200));
	bugSquash.KillAll();
	ASSERT_TRUE(nullBug->GetIsSquashed());
}