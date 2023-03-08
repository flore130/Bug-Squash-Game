/**
 * @file Program.h
 * @author Ricardo Flores
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_PROGRAM_H
#define PROJECT1_BUGSQUASHLIB_PROGRAM_H
#include "Level.h"
#include "Item.h"

class Program : public Item
{
private:

	/// Default constructor (disabled)
	Program() = delete;

	/// Copy constructor (disabled)
	Program(const Program &) = delete;

	/// Assignment operator
	void operator=(const Program &) = delete;

public:

	Program(Level* level);

};

#endif //PROJECT1_BUGSQUASHLIB_PROGRAM_H
