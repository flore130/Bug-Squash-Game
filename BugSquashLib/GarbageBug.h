/**
 * @file GarbageBug.h
 * @author Ajuisiwon Azantilow
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_GARBAGEBUG_H
#define PROJECT1_BUGSQUASHLIB_GARBAGEBUG_H

#include "Bug.h"

/**
 * Class for a bug of type Garbage
 */

class GarbageBug : public Bug
{
private:

public:
	/// Default constructor (disabled)
	GarbageBug() = delete;

	/// Copy constructor (disabled)
	GarbageBug(const GarbageBug &) = delete;

	/// Assignment operator
	void operator=(const GarbageBug &) = delete;

	GarbageBug(Level* level);

};

#endif //PROJECT1_BUGSQUASHLIB_GARBAGEBUG_H
