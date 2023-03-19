/**
 * @file FatNullBug.h
 * @author Kyle Nowak
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_FATNULLBUG_H
#define PROJECT1_BUGSQUASHLIB_FATNULLBUG_H

#include "BugNull.h"

/**
 * Fat null bug class
 */
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

	/// Constructor
	FatNullBug(Level* level);

	wxXmlNode* XmlSave(wxXmlNode* node) override;

	void XmlLoad(wxXmlNode* node) override;

	void Draw(std::shared_ptr<wxGraphicsContext> gc) override;

	/**
	 * Accept a visitor
	 * @param visitor The visitor to accept
	 */
	void Accept( ItemVisitor* visitor ) override {}

};

#endif //PROJECT1_BUGSQUASHLIB_FATNULLBUG_H
