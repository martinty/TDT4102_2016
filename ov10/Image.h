//
// Created by tysse on 14.02.2018.
//

#ifndef OV10_IMAGE_H
#define OV10_IMAGE_H


#pragma once

/////////////////////////////////////////////////////////////////////
//  NB! Include this file and the file ImageIO.cpp in your project.//
//  You should *NOT* do any changes to this file.                  //
//                                                                 //
//  Disclaimer: Provided as is etc. etc. No rights reserved.       //
/////////////////////////////////////////////////////////////////////

#include <string>

// Color struct, used to set and retrieve colors from the image.
struct Color {
    Color( unsigned char r, unsigned char g, unsigned char b ) : red( r ), green( g ), blue( b ) {}
    Color() : red( 0 ), green( 0 ), blue( 0 ) {}
    unsigned char red, green, blue;
};
typedef Color Pixel; //In this aplication a Color and a Pixel are the same.

class Image {
public:
    Image( unsigned int w, unsigned int h );
    ~Image();

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    const Pixel* getScanLine(unsigned int line) const;
    Pixel *getScanLine(unsigned int line);

    Color getPixelColor( unsigned int x, unsigned int y ) const;
    void setPixelColor( unsigned int x, unsigned int y, const Color &color );

    void fill( const Color &color );

private:
    Pixel *data;
    unsigned int width, height;
};

// The following functions are provided in the file ImageIO.cpp and may be used as is.

/** SaveImage saves the data in image as a BMP file with the filename supplied.
 *  This function returns 0 if the image was saved correctly,
 *  otherwise it will return -1 and print an error message to std::cerr.
 */
int saveImage( const Image &image, const std::string &filename );

/** LoadImage loads an image from the BMP file with the filename supplied.
 *  This function returns a dynamically allocated image if the image was
 *  loaded successfully, otherwise it will return NULL, and print an error
 *  message to std::cerr. It is the caller's (read your) responsibility to
 *  delete the dynamically allocated image.
 */
Image *loadImage( const std::string &filename );


#endif //OV10_IMAGE_H
