/**
 * @file ItemTest.cpp
 * @author Kyle Nowak
 */

#include <pch.h>
#include <Item.h>
#include <BugSquash.h>
#include "gtest/gtest.h"

const std::wstring LaptopImage = L"../images/laptop.png";

class ItemMock : public Item
{
public:
	ItemMock(Level *level) : Item(level, LaptopImage) {}

	/// Do nothing with the visitor currently
	virtual void Accept( ItemVisitor* visitor ) override {};
};

TEST(ItemTest, Construct)
{
	BugSquash bugSquash;
	Level newLevel( &bugSquash );
	ItemMock myItem(&newLevel);
}

TEST(ItemTest, GetterSetters)
{
	BugSquash bugSquash;
	Level newLevel( &bugSquash );
	ItemMock item(&newLevel);

	// Test initial values
	ASSERT_NEAR(0, item.GetX(), 0.0001);
	ASSERT_NEAR(0, item.GetY(), 0.0001);

	// Test SetLocation, GetX, and GetY
	item.SetLocation(10.5, 17.2);
	ASSERT_NEAR(10.5, item.GetX(), 0.0001);
	ASSERT_NEAR(17.2, item.GetY(), 0.0001);

	// Test a second with different values
	item.SetLocation(-72, -107);
	ASSERT_NEAR(-72, item.GetX(), 0.0001);
	ASSERT_NEAR(-107, item.GetY(), 0.0001);
}

