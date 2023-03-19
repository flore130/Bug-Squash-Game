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
};


TEST_F(CodeTest, Construct){
	wxXmlDocument doc;
	ASSERT_TRUE(doc.Load(L"../Tests/test-data/garbage-bug-1.xml"));

	auto node = doc.GetRoot();
	mCode = make_shared<Code>(node);
}


TEST_F(CodeTest, Test1){
	wxXmlDocument doc;
	ASSERT_TRUE(doc.Load(L"../Tests/test-data/garbage-bug-1.xml"));

	auto node = doc.GetRoot();
	mCode = make_shared<Code>(node);

	cout << mCode->GetCurrentCode() << endl;

	ASSERT_FALSE(mCode->Passes());
}