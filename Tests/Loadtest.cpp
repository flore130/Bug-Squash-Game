/**
 * @file LoadTest.cpp
 * @author npmar
 */

#include <pch.h>
#include <BugSquash.h>
#include "gtest/gtest.h"

using namespace std;

TEST(LoadTest, Load)
{
	BugSquash bugSquash;

	auto file1 = L"data/level0.xml";


	Level level( &bugSquash );

	level.Load(file1);

	ASSERT_EQ(8, bugSquash.GetNumItems());


	ASSERT_EQ(1, level.GetNumPrograms());

	ASSERT_EQ(7, level.GetNumBugs());

	BugSquash bugSquash2;


	auto file2 = L"data/level1.xml";


	Level level2( &bugSquash2 );


	level2.Load(file2);

	ASSERT_EQ(13, bugSquash2.GetNumItems());

	ASSERT_EQ(1, level2.GetNumPrograms());

	ASSERT_EQ(12, level2.GetNumBugs());

	BugSquash bugSquash3;

	auto file3 = L"data/level2.xml";

	Level level3( &bugSquash3 );


	level3.Load(file3);

	ASSERT_EQ(27, bugSquash3.GetNumItems());

	ASSERT_EQ(3, level3.GetNumPrograms());

	ASSERT_EQ(24, level3.GetNumBugs());
}
