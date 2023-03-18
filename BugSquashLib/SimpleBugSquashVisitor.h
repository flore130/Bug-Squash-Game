/**
 * @file SimpleBugSquashVisitor.h
 * @author Kev
 *
 * Class for the SimpleBugSquashVisitor
 */

#ifndef PROJECT1_BUGSQUASHLIB_SIMPLEBUGSQUASHVISITOR_H
#define PROJECT1_BUGSQUASHLIB_SIMPLEBUGSQUASHVISITOR_H

#include "ItemVisitor.h"

class BugGarbage;
class BugNull;
class BugGarbage;
class BugRedundancy;


class SimpleBugSquashVisitor : public ItemVisitor
{
private:
	/// Is the item clicked on a simple bug
	bool mIsSimpleBug = false;

public:
	/**
	 * Get whether it's a simple bug or not
	 * @return Is it a simple bug
	 */
	 bool IsSimpleBug() const { return mIsSimpleBug; }

	 /**
	  * Visit the BugGarbage object
	  * @param bug Bug we are visiting
	  */
	  void VisitBugGarbage( BugGarbage* bug ) { mIsSimpleBug = true; }

	 /**
	  * Visit the BugNull object
	  * @param bug Bug we are visiting
	  */
	 void VisitBugNull( BugNull* bug ) { mIsSimpleBug = true; }

	 /**
	  * Visit the BugRedundancy object
	  * @param bug Bug we are visiting
	  */
	  void VisitBugRedundancy( BugRedundancy* bug ) { mIsSimpleBug = true; }

	  /**
	   * Visit the Feature object
	   * @param feature Feature we are visiting
	   */
	   void VisitFeature( Feature* feature ) { mIsSimpleBug = true; }

};

#endif //PROJECT1_BUGSQUASHLIB_SIMPLEBUGSQUASHVISITOR_H
