/**
 * @file BugTest.cpp
 * @author Kyle Nowak
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <BugNull.h>
#include <Bug.h>
#include <Level.h>
#include <Program.h>
#include <regex>
#include <string>
#include <fstream>
#include <wx/filename.h>

using namespace std;

const std::wstring GarbageSplatImage = L"../images/blue-maize-bug.png";


TEST(BugTest, Construct)
{
	Level newLevel;
	Bug myBug(&newLevel, GarbageSplatImage);
}

/**
* Add three null bugs to the level
* @param level The level to populate
*/
void PopulateThreeNullBugs(Level *level)
{
	auto bug1 = make_shared<BugNull>(level);
	level->Add(bug1);
	bug1->SetLocation(100, 200);

	auto bug2 = make_shared<BugNull>(level);
	level->Add(bug2);
	bug2->SetLocation(400, 400);

	auto bug3 = make_shared<BugNull>(level);
	level->Add(bug3);
	bug3->SetLocation(600, 100);
}

/**
* Read a file into a wstring and return it.
* @param filename Name of the file to read
* @return File contents
*/
wstring ReadFile(const wxString &filename)
{
	ifstream t(filename.ToStdString());
	wstring str((istreambuf_iterator<char>(t)),
				istreambuf_iterator<char>());

	return str;
}

/**
* Test a file which is just an empty level
* @param filename Name of the file to read
*/
void TestEmpty(wxString filename)
{
	cout << "Temp file: " << filename << endl;

	auto xml = ReadFile(filename);
	cout << xml << endl;

	ASSERT_TRUE(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
	ASSERT_TRUE(regex_search(xml, wregex(L"<xml/>")));

}


/**
* Test a file which has three null bugs
* @param filename Name of the file to read
*/
void TestThreeNullBugs(wxString filename)
{
	cout << "Temp file: " << filename << endl;

	auto xml = ReadFile(filename);
	cout << xml << endl;

	// Ensure three items
	ASSERT_TRUE(regex_search(xml, wregex(L"<xml><item.*<item.*<item.*</xml>")));

	// Ensure the positions are correct
	ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
	ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
	ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));

	// Ensure the types are correct
	ASSERT_TRUE(regex_search(xml,
							 wregex(L"<xml><item.* type=\"null\"/><item.* type=\"null\"/><item.* type=\"null\"/></xml>")));
}

/**
* Create a path to a place to put temporary files
*/
wxString TempPath()
{
	// Create a temporary filename we can use
	auto path = wxFileName::GetTempDir() + L"/xml";
	if(!wxFileName::DirExists(path))
	{
		wxFileName::Mkdir(path);
	}

	return path;
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

	bug.SetLocation(190, 110); // reset location

	bug.Update(1.41421);

	ASSERT_NEAR(bug.GetX(), 195, 0.01) << L"Test fractional time of diagonal movement";
	ASSERT_NEAR(bug.GetY(), 105, 0.01) << L"Test fractional time of diagonal movement";

	bug.SetLocation(245, 300);

	bug.Update(4);

	ASSERT_NEAR(bug.GetX(), 240.610, 0.01) << L"Test 4 seconds of diagonal movement";
	ASSERT_NEAR(bug.GetY(), 280.488, 0.01) << L"Test 4 seconds of diagonal movement";

}

TEST(BugTest, Load)
{
	// Create a path to temporary files
	auto path = TempPath();

	// Create a level
	Level level;
	Level level2;

	//
	// First test, saving an empty level
	//
	auto file1 = path + L"/test1.xml";
	level.Save(file1);

	TestEmpty(file1);

	level2.Load(file1);
	level2.Save(file1);
	TestEmpty(file1);

	//
	// Now populate the level
	//
	PopulateThreeNullBugs(&level);

	auto file2 = path + L"/test2.xml";
	level.Save(file2);
	TestThreeNullBugs(file2);

	//
	// Test all types
	//
//	Level level3;
//	level3.GetRandom().seed(RandomSeed);

//	PopulateAllTypes(&level3);

//	wstring file3 = path + L"/test3.xml";
//	level3.Save(file3);
//	TestAllTypes(file3);

//	level2.Load(file2);
//	level2.Save(file2);
//	TestThreeNullBugs(file2);

//	level3.Load(file3);
//	level3.Save(file3);
//	TestAllTypes(file3);

}

