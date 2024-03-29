/**
 * @file ItemVisitor.h
 * @author Kev
 *
 * Item Visitor base class
 */

#ifndef PROJECT1_BUGSQUASHLIB_ITEMVISITOR_H
#define PROJECT1_BUGSQUASHLIB_ITEMVISITOR_H

// Forward reference to all item types
class BugGarbage;
class BugRedundancy;
class BugNull;
class FatGarbageBug;
class FatNullBug;
class Feature;
class Program;
class BugNuke;

/**
 * Base class for our Item Visitor
 */
class ItemVisitor
{
private:

protected:
	/**
	 * Constructor
	 * Ensures that this will be an abstract class
	 */
	 ItemVisitor() {}

public:
	virtual ~ItemVisitor() {}

	/**
	 * Visit the BugGarbage object
	 * @param bug BugGarbage we are visiting
	 */
	 virtual void VisitBugGarbage( BugGarbage* bug ) {}

	 /**
	  * Visit the FatGarbageBug object
	  * @param bug FatGarbageBug to visit
	  */
	 virtual void VisitFatGarbage( FatGarbageBug* bug ) {}

	 /**
	  * Visit the BugRedundancy object
	  * @param bug BugRedundancy we are visiting
	  */
	  virtual void VisitBugRedundancy( BugRedundancy* bug ) {}

	  /**
	   * Visit the BugNull object
	   * @param bug BugNull we are visiting
	   */
	   virtual void VisitBugNull( BugNull* bug ) {}

	   /**
	    * Visit the FatNullBug object
	    * @param bug FatNullBug to visit
	    */
	   virtual void VisitFatNull ( FatNullBug* bug ) {}

	   /**
	    * Visit the Feature object
	    * @param feature Feature we are visiting
	    */
	    virtual void VisitFeature( Feature* feature ) {}

		/**
		 * Visit the Program object
		 * @param program Program we are visiting
		 */
		 virtual void VisitProgram( Program* program ) {}

		/**
		* Visit the BugNuke object
		* @param nuke The BugNuke power up we are visiting
		*/
		virtual void VisitBugNuke( BugNuke* nuke ) {}

};

#endif //PROJECT1_BUGSQUASHLIB_ITEMVISITOR_H
