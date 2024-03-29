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
class Program;
class BugNuke;

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

	/// The number of programs that belong to the level
	int mNumPrograms = 0;

	/// The number of bugs (and features) that belong on the level
	int mNumBugs = 0;

public:
	Level(BugSquash* bugSquash);

	void Load(const wxString &filename);

	/**
 	* Obtains the number of program objects that exist on the level
 	* @return The count of programs on the level
 	*/
	int GetNumPrograms() {return mNumPrograms;}
	/**
 	* Obtains the number of bug objects that exist on the level
 	* @return The count of bugs/features on the level
 	*/
	int GetNumBugs() {return mNumBugs;}

	/**
	 * Get the bug squash class associated with the level
	 * @return the bug squash class the level belongs to
	 */
	 BugSquash* GetBugSquash()
	 {
		 return mBugSquash;
	 }

	void DrawLevel(std::shared_ptr<wxGraphicsContext> graphics, std::wstring label);

	void Draw(std::shared_ptr<wxGraphicsContext> graphics);

	std::shared_ptr< wxImage > GetImage( const std::wstring& filename );

	/**
	 * Gets the name of the current level
	 * @return mName
	 */
	std::wstring GetName() const { return mName; }

	bool GetIsEditingCode();
};

#endif //PROJECT1_BUGSQUASHLIB_LEVEL_H

