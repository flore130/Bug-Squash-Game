/**
 * @file Images.h
 * @author Kev
 *
 * Class to store the Images for all of the items that our program uses
 */

#ifndef PROJECT1_BUGSQUASHLIB_IMAGES_H
#define PROJECT1_BUGSQUASHLIB_IMAGES_H

#include <map>

/*
 * Image class to store all of the item's images
 */
class Images
{
private:
	/// The map that will hold all of the filename, image pointer pairs
	std::map< const std::wstring, std::shared_ptr< wxImage > > mItemImages = {};

public:
	Images();

	std::shared_ptr< wxImage > GetImage( const std::wstring& filename );
};

#endif //PROJECT1_BUGSQUASHLIB_IMAGES_H
