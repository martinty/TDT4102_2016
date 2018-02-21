//
// Created by tysse on 14.02.2018.
//

#include "Image.h"

/*****************************************************
 * You _should_ change the functions in this file.   *
 * The following functions are provided so that      *
 * the code will compile, note however that the      *
 * program will not run before you have implemented  *
 * all the functions in this file.                   *
 *****************************************************/

Image::Image( unsigned int w, unsigned int h ) {
    width = w;
    height = h;
    data = new Pixel[width * height];
    for (unsigned int i = 0; i < width * height; i++){
        data[i].blue = 0;
        data[i].green = 0;
        data[i].red = 0;
    }
}

Image::~Image()  {
    delete [] data;
    data = nullptr;
    height = 0;
    width = 0;
}

unsigned int Image::getWidth() const {
    return width;
}

unsigned int Image::getHeight() const  {
    return height;
}

const Pixel *Image::getScanLine(unsigned int line) const  {
    return &data[(height - 1 - line) * width];
}

Pixel *Image::getScanLine(unsigned int line) {
    return &data[(height - 1 - line) * width];
}

Color Image::getPixelColor( unsigned int x, unsigned int y ) const {
    return data[(height - 1 - y) * width + x];
}

void Image::setPixelColor( unsigned int x, unsigned int y, const Color &color ) {
    data[(height - 1 - y) * width + x] = color;
}

void Image::fill( const Color &color ) {
    for (unsigned y = 0; y < height; y++){
        for(unsigned x = 0; x < width; x++){
            setPixelColor(x, y, color);
        }
    }
}
