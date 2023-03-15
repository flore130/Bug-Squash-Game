/**
 * @file FatGarbageBug.h
 * @author Kyle Nowak
 *
 *
 */

#ifndef PROJECT1_BUGSQUASHLIB_FATGARBAGEBUG_H
#define PROJECT1_BUGSQUASHLIB_FATGARBAGEBUG_H

#include "BugGarbage.h"

/**
 * Fat garbage bug class
 */
class FatGarbageBug : public BugGarbage
{
private:

public:
	/// Default constructor (disabled)
	FatGarbageBug() = delete;

	/// Copy constructor (disabled)
	FatGarbageBug(const FatGarbageBug &) = delete;

	/// Assignment operator
	void operator=(const FatGarbageBug &) = delete;

	/// Constructor
	FatGarbageBug(Level* level);

	wxXmlNode* XmlSave(wxXmlNode* node) override;

	void XmlLoad(wxXmlNode* node) override;

	void Draw(std::shared_ptr<wxGraphicsContext> gc) override{};

};

#endif //PROJECT1_BUGSQUASHLIB_FATGARBAGEBUG_H

