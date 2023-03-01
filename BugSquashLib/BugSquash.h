/**
 * @file BugSquash.h
 * @author npmar
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_BUGSQUASH_H
#define PROJECT1_BUGSQUASHLIB_BUGSQUASH_H

#include <wx/wx.h>
#include <memory>
#include <random>

class Item;

/**
 * The main BugSquash class.
 */
class BugSquash
{
private:
	/// All of the items in the bug squash application
	std::vector<std::shared_ptr<Item>> mItems;

public:
	void Add(std::shared_ptr<Item>);
	void Load(const wxString &filename);
	void XmlItem(wxXmlNode *node);

};

#endif //PROJECT1_BUGSQUASHLIB_BUGSQUASH_H
