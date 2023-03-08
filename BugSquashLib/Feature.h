/**
 * @file Feature.h
 * @author Ricardo Flores
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_FEATURE_H
#define PROJECT1_BUGSQUASHLIB_FEATURE_H
#include "pch.h"
#include "Bug.h"
#include "Level.h"

class Feature : public Bug
{
private:

public:

	/// Default constructor (disabled)
	Feature() = delete;

	/// Copy constructor (disabled)
	Feature(const Feature &) = delete;

	/// Assignment operator
	void operator=(const Feature &) = delete;

	///Constructor
	Feature(Level* level);

};

#endif //PROJECT1_BUGSQUASHLIB_FEATURE_H
