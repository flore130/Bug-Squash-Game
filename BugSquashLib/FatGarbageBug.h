/**
 * @file FatGarbageBug.h
 * @author Kyle Nowak
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_FATGARBAGEBUG_H
#define PROJECT1_BUGSQUASHLIB_FATGARBAGEBUG_H

#include "BugGarbage.h"

class FatGarbageBug : public BugGarbage
{
private:

public:
	/// Default constructor (disabled)
	FatGarbageBug() = delete;

	/// Copy constructor (disabled)
	FatGarbageBug(const FatGarbageBug &) = delete;

	/// Assignment operator
	void operator=(const FatGarbageBug &) = delete;

	FatGarbageBug(Level* level);

};

#endif //PROJECT1_BUGSQUASHLIB_FATGARBAGEBUG_H
