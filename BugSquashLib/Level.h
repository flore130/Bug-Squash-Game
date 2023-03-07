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
class ItemVisitor;

class Level
{
private:
	/// The list storing all of the items displayed in our BugSquashView
	std::vector<std::shared_ptr<Item>> mItems;

	/// The index that the first bug/feature is stored at
	/// This will be one index past all the programs for this level
	int mFirstBugIndex = -1;

	/// The name of this level, displayed for 2 seconds at the start of the round
	std::wstring mName;

	void XmlItem(wxXmlNode *node);

	void XmlProgram(wxXmlNode *node);

public:
	void Load(const wxString &filename);

	void Accept( ItemVisitor* visitor );

};

#endif //PROJECT1_BUGSQUASHLIB_LEVEL_H
