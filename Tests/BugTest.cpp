/**
 * @file BugTest.cpp
 * @author Kyle Nowak
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <Bug.h>

TEST(BugTest, Construct)
{
	Bug myBug;
}


TEST(BugTest, HitTest)
{
	Bug bug;

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