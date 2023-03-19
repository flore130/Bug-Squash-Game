/**
 * @file CodeTest.cpp
 * @author Kyle Nowak
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Code.h>

using namespace std;


class CodeTest : public ::testing::Test {
protected:
	shared_ptr<Code> mCode = nullptr;

	/**
	 * Load the proper xml file into the code block
	 * @param filename the name of the xml file
	 */
	void Load(const wstring &filename)
	{
		wxXmlDocument doc;
		ASSERT_TRUE(doc.Load(filename));

		auto node = doc.GetRoot();
		mCode = make_shared<Code>(node);

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
	Load(L"../Tests/test-data/garbage-bug-1.xml");
}


TEST_F(CodeTest, AnswerChecks){
	Load(L"../Tests/test-data/garbage-bug-1.xml");
	ASSERT_FALSE(mCode->Passes()) << L"Garbage bug 1";
	CheckAnswers();

	Load(L"../Tests/test-data/garbage-bug-2.xml");
	ASSERT_FALSE(mCode->Passes()) << L"Garbage bug 2";
	CheckAnswers();

	Load(L"../Tests/test-data/null-bug-1.xml");
	ASSERT_FALSE(mCode->Passes()) << L"Null bug 1";
	CheckAnswers();
}