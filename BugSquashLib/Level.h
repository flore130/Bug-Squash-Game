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

class BugSquash;
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
	std::wstring mName = L"";

	void XmlItem(wxXmlNode *node, std::shared_ptr<Program> parent);

	void XmlProgram(wxXmlNode *node);

	/// The BugSquash that owns the level
	BugSquash* mBugSquash = nullptr;

public:
	void Load(const wxString &filename);

	/**
 	* Sets mBugSquash to be the current BugSquash application so we can pass up for loading
	 * @param bugSquash The bugSquash program we are looking at
 	*/
	void SetBugSquash( BugSquash* bugSquash ) { mBugSquash = bugSquash; }
};

#endif //PROJECT1_BUGSQUASHLIB_LEVEL_H

