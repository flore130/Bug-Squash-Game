/**
 * @file ItemVisitor.h
 * @author Kev
 *
 * Item Visitor base class
 */

#ifndef PROJECT1_BUGSQUASHLIB_ITEMVISITOR_H
#define PROJECT1_BUGSQUASHLIB_ITEMVISITOR_H

// Forward reference to all item types
class GarbageBug;
class RedundancyBug;
class NullBug;
class Feature;
class Program;


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
	 ItemVisitor();

public:
	virtual ~ItemVisitor();

	/**
	 * Visit the GarbageBug object
	 * @param bug GarbageBug we are visiting
	 */
	 virtual void VisitGarbageBug( GarbageBug* bug ) {}

	 /**
	  * Visit the RedundancyBug object
	  * @param bug RedundancyBug we are visiting
	  */
	  virtual void VisitRedundancyBug( RedundancyBug* bug ) {}

	  /**
	   * Visit the NullBug object
	   * @param bug NullBug we are visiting
	   */
	   virtual void VisitNullBug( NullBug* bug ) {}

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

};

#endif //PROJECT1_BUGSQUASHLIB_ITEMVISITOR_H
