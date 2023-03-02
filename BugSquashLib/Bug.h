/**
 * @file Bug.h
 * @author Kyle Nowak
 *
 * Base bug class
 */

#ifndef PROJECT1_BUGSQUASHLIB_BUG_H
#define PROJECT1_BUGSQUASHLIB_BUG_H

#include "Item.h"

/**
 * Base bug class
 */
class Bug : public Item
{
private:

public:
	bool HitTest(double x, double y);

};

#endif //PROJECT1_BUGSQUASHLIB_BUG_H