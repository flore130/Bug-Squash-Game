/**
 * @file Level.h
 * @author Kyle Nowak
 *
 * Level class
 *
 * This is the class that will actually load the XML data,
 * as well as hold the items in the playing area
 */

#ifndef PROJECT1_BUGSQUASHLIB_LEVEL_H
#define PROJECT1_BUGSQUASHLIB_LEVEL_H

#include <memory>

/**
 * Level class
 *
 * This is the class that will actually load the XML data,
 * as well as hold the items in the playing area
 */
class Item;
class BugVisitor;

class Level
{
private:
	/// The list storing all of the items displayed in our BugSquashView
	std::vector<std::shared_ptr<Item>> mItems;

	/// The index that the first bug/feature is stored at. In other words,
	/// the index that is one past the index of the last program
	int mFirstBugIndex = -1;

	void XmlItem(wxXmlNode *node);

public:
	void Load(const wxString &filename);

	void Accept(BugVisitor *visitor);

};

#endif //PROJECT1_BUGSQUASHLIB_LEVEL_H
