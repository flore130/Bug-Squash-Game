/**
 * @file BugNuke.h
 * @author npmar
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_BUGNUKE_H
#define PROJECT1_BUGSQUASHLIB_BUGNUKE_H

#include "Level.h"
#include "Item.h"

/**
 * Class for the nuke power up item
 */
class BugNuke : public Item
{
private:

public:
	/// Default constructor (disabled)
	BugNuke() = delete;

	/// Copy constructor (disabled)
	BugNuke(const BugNuke &) = delete;

	/// Assignment operator
	void operator=(const BugNuke &) = delete;

	BugNuke(Level* level);

	void XmlLoad(wxXmlNode* node) override;

	/**
	 * Accept a visitor
	 * @param visitor The visitor to accept
	 */
	void Accept( ItemVisitor* visitor ) override { visitor->VisitBugNuke( this ); }
};


#endif //PROJECT1_BUGSQUASHLIB_BUGNUKE_H
