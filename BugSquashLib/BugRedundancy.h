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
	/// When this is false, it means that it is the parent and will spawn children when squashed.
	/// When it is true, it means that this redundancy bug's parent is squashed, and it's a child from it.
	/// Squashing it now will not spawn additional children.
	bool mParentSquashed = false;

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

	void Draw(std::shared_ptr<wxGraphicsContext> gc) override {};

	/**
	 * Accept a visitor
	 * @param visitor The visitor to accept
	 */
	void Accept( ItemVisitor* visitor ) override { visitor->VisitBugRedundancy( this ); }

	/**
	 * Returns the status of mParentSquashed
	 * @return mParentSquashed
	 */
	bool GetParentSquashedStatus() { return mParentSquashed; }
};

#endif //PROJECT1_BUGSQUASHLIB_BUGREDUNDANCY_H


