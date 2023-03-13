/**
 * @file BugRedundancy.h
 * @author npmar
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_BUGREDUNDANCY_H
#define PROJECT1_BUGSQUASHLIB_BUGREDUNDANCY_H

#include <wx/wx.h>
#include "Item.h"
#include "Bug.h"


/**
 * Class for a bug of type Redundancy
 */
class BugRedundancy : public Bug
{
private:

public:
	/// Default constructor (disabled)
	BugRedundancy() = delete;

	/// Copy constructor (disabled)
	BugRedundancy(const BugRedundancy &) = delete;

	/// Assignment operator
	void operator=(const BugRedundancy &) = delete;

	BugRedundancy(Level* level);

	double DistanceTo(std::shared_ptr<Item> item) override;

	wxXmlNode* XmlSave(wxXmlNode* node) override;

	void XmlLoad(wxXmlNode* node) override;
};

#endif //PROJECT1_BUGSQUASHLIB_BUGREDUNDANCY_H

