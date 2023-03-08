/**
 * @file FatNullBug.h
 * @author Kyle Nowak
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_FATNULLBUG_H
#define PROJECT1_BUGSQUASHLIB_FATNULLBUG_H

#include "BugNull.h"

class FatNullBug : public BugNull
{
private:

public:
	/// Default constructor (disabled)
	FatNullBug() = delete;

	/// Copy constructor (disabled)
	FatNullBug(const FatNullBug &) = delete;

	/// Assignment operator
	void operator=(const FatNullBug &) = delete;

	FatNullBug(Level* level);

};

#endif //PROJECT1_BUGSQUASHLIB_FATNULLBUG_H
