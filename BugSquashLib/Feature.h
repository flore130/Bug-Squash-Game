/**
 * @file Feature.h
 * @author Ricardo Flores
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_FEATURE_H
#define PROJECT1_BUGSQUASHLIB_FEATURE_H

#include "Bug.h"
#include "Level.h"

/**
 * Feature item class
 */
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

	wxXmlNode* XmlSave(wxXmlNode* node) override;

	void XmlLoad(wxXmlNode* node) override;

};

#endif //PROJECT1_BUGSQUASHLIB_FEATURE_H
