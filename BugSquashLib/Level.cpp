/**
 * @file Level.cpp
 * @author Kyle Nowak
 */

#include "pch.h"

#include "Level.h"
#include "Item.h"


/**
 * Accepts a visitor into this level
 * @param visitor the visitor that is visiting this level
 */
void Level::Accept(BugVisitor *visitor)
{
	for (auto item : mItems)
	{
		item->Accept(visitor);
	}
}