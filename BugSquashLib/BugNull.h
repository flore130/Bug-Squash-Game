/**
 * @file BugNull.h
 * @author npmar
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_BUGNULL_H
#define PROJECT1_BUGSQUASHLIB_BUGNULL_H

#include <wx/wx.h>
#include "Item.h"
#include "Bug.h"


/**
 * Class for a bug of type Null
 */
class BugNull : public Bug
{
private:

public:
	/// Default constructor (disabled)
	BugNull() = delete;

	/// Copy constructor (disabled)
	BugNull(const BugNull &) = delete;

	/// Assignment operator
	void operator=(const BugNull &) = delete;

	BugNull(Level* level);

};

#endif //PROJECT1_BUGSQUASHLIB_BUGNULL_H
