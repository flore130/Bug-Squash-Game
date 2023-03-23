/**
 * @file BugNukeVisitor.h
 * @author npmar
 *
 * Class for a BugNuke Power up visitor
 */

#ifndef PROJECT1_BUGSQUASHLIB_BUGNUKEVISITOR_H
#define PROJECT1_BUGSQUASHLIB_BUGNUKEVISITOR_H

#include "ItemVisitor.h"

/**
 *
 * Class BugNukeVisitor, visits and activates BugNuke objects
 *
 */
class BugNukeVisitor : public ItemVisitor
{
private:

public:
	void VisitBugNuke( BugNuke* nuke ) override;

};

#endif //PROJECT1_BUGSQUASHLIB_BUGNUKEVISITOR_H
