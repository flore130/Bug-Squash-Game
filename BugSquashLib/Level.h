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


class Item;
class ItemVisitor;
class Program;

/**
 * Level class
 *
 * This is the class that will actually load the XML data,
 * as well as hold the items in the playing area
 */
class Level
{
private:
	/// The index that the first bug/feature is stored at
	/// This will be one index past all the programs for this level
	int mFirstBugIndex = -1;

	/// The name of this level, displayed for 2 seconds at the start of the round
	std::wstring mName;

	void XmlItem(wxXmlNode *node, std::shared_ptr<Program> parent);

	void XmlProgram(wxXmlNode *node);

	/// All of the items in the bug squash application
	std::vector<std::shared_ptr<Item>> mItems;

	/// The level that is currently loaded
	std::unique_ptr<Level> mLevel = nullptr;

public:
	void Add( std::shared_ptr< Item > item );

	void Save(const wxString &filename);

	void Load(const wxString &filename);

	void Clear();

	std::vector<std::shared_ptr< Item >>  GetItem();
};

#endif //PROJECT1_BUGSQUASHLIB_LEVEL_H

