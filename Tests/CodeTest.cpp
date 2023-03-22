/**
 * @file CodeTest.cpp
 * @author Kyle Nowak
 */

#include <pch.h>
#include <Code.h>
#include <Bug.h>
#include <BugGarbage.h>
#include <BugNull.h>
#include <FatGarbageBug.h>
#include <FatNullBug.h>
#include <BugSquash.h>
#include "gtest/gtest.h"

using namespace std;


class CodeTest : public ::testing::Test {
protected:
	shared_ptr<Code> mCode = nullptr;

	/**
	 * Load the proper xml file into the code block
	 * @param filename the name of the xml file
	 */
	void Load(const wstring &filename, shared_ptr<Bug> bug )
	{
		wxXmlDocument doc;
		ASSERT_TRUE(doc.Load(filename));

		auto node = doc.GetRoot();
		mCode = make_shared<Code>( node, bug );

		cout << "Initial code: \n" << mCode->GetCurrentCode() << endl;
	}

	/**
	 * Checks if the currently loaded code would pass
	 * if user put in correct regular expression
	 */
	void CheckAnswers()
	{
		mCode->SetCode(L"This is the wrong answer");

		ASSERT_FALSE(mCode->Passes());

		ASSERT_FALSE(mCode->GetExampleAnswer().empty()) <<
														L"Code didn't have example answer provided";
		mCode->SetCode(mCode->GetExampleAnswer());

		cout << "Answer code:\n" << mCode->GetCurrentCode() << endl << endl;

		ASSERT_TRUE(mCode->Passes());
	}
};


TEST_F(CodeTest, Construct){
	BugSquash bugSquash;
	Level newLevel(&bugSquash);
	shared_ptr<FatGarbageBug> myBug = make_shared<FatGarbageBug>(&newLevel);

	Load( L"../Tests/test-data/garbage-bug-1.xml", myBug);
}


TEST_F(CodeTest, AnswerChecks){
	BugSquash bugSquash;
	Level newLevel(&bugSquash);
	std::shared_ptr<FatGarbageBug> myBug = std::make_shared<FatGarbageBug>(&newLevel);

	Load( L"../Tests/test-data/garbage-bug-1.xml", myBug);
	ASSERT_FALSE(mCode->Passes()) << L"Garbage bug 1";
	CheckAnswers();

	std::shared_ptr<FatGarbageBug> myBug2 = std::make_shared<FatGarbageBug>(&newLevel);
	Load( L"../Tests/test-data/garbage-bug-2.xml", myBug2);
	ASSERT_FALSE(mCode->Passes()) << L"Garbage bug 2";
	CheckAnswers();

	std::shared_ptr<FatNullBug> myBug3 = std::make_shared<FatNullBug>(&newLevel);
	Load( L"../Tests/test-data/null-bug-1.xml", myBug3);
	ASSERT_FALSE(mCode->Passes()) << L"Null bug 1";
	CheckAnswers();
}