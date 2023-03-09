/**
 * @file BugGarbage.h
 * @author Ajuisiwon Azantilow
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_BUGGARBAGE_H
#define PROJECT1_BUGSQUASHLIB_BUGGARBAGE_H

#include "Bug.h"

/**
 * Class for a bug of type Garbage
 */

class BugGarbage : public Bug
{
private:
	bool mIsSquashed = false;

public:
	/// Default constructor (disabled)
	BugGarbage() = delete;

	/// Copy constructor (disabled)
	BugGarbage(const BugGarbage &) = delete;

	/// Assignment operator
	void operator=(const BugGarbage &) = delete;

	BugGarbage(Level* level);

};

#endif //PROJECT1_BUGSQUASHLIB_BUGGARBAGE_H
