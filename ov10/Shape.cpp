//
// Created by tysse on 21.02.2018.
//
#include <cmath>
using namespace std;

#include "Image.h"
#include "Shape.h"

Shape::Shape(Color input): color(input) {}

Color Shape::getColor() const {
    return color;
}

Line::Line(int x1, int y1, int x2, int y2, Color input):
        Shape(input), x1(x1), y1(y1), x2(x2), y2(y2){}

void Line::draw(Image &picture){
    auto dy = double(y2 - y1) / double(x2 - x1);
    if (dy <= 1){
        for(int x = x1; x <= x2; x++){
            picture.setPixelColor(x, int(dy * (x - x1)) + y1, getColor());
        }
    } else{
        auto dx = double(x2 - x1) / double(y2 - y1);
        for(int y = y1; y <= y2; y++){
            picture.setPixelColor(int(dx * (y - y1)) + x1, y, getColor());
        }
    }

}

Rectangle::Rectangle(int x1, int y1, int x2, int y2, Color input):
        Shape(input), x1(x1), y1(y1), x2(x2), y2(y2) {}

void Rectangle::draw(Image &picture) {
    for(int x = x1; x <= x2; x++){
        picture.setPixelColor(x, y1, getColor());
        picture.setPixelColor(x, y2, getColor());
    }
    for(int y = y1; y <= y2; y++){
        picture.setPixelColor(x1, y, getColor());
        picture.setPixelColor(x2, y, getColor());
    }
}

Circle::Circle(int x, int y, int r, Color input):
        Shape(input), x0(x), y0(y), r(r) {}

void Circle::draw(Image &picture) {
    for (int x = x0 - r; x <= x0 + r; x++) {
        double y1 = sqrt(pow(r, 2) - pow((x - x0), 2)) + y0;
        double y2 = -sqrt(pow(r, 2) - pow((x - x0), 2)) + y0;
        picture.setPixelColor(x, y1, getColor());
        picture.setPixelColor(x, y2, getColor());
    }
    for (int y = y0 - r; y <= y0 + r; y++) {
        double x1 = sqrt(pow(r, 2) - pow((y - y0), 2)) + x0;
        double x2 = -sqrt(pow(r, 2) - pow((y - y0), 2)) + x0;
        picture.setPixelColor(x1, y, getColor());
        picture.setPixelColor(x2, y, getColor());
    }
}

void Canvas::addShape(Shape *figure) {
    figures.push_back(figure);
}

void Canvas::rasterizeTo(Image &picture) {
    for(unsigned int i = 0; i < figures.size(); i++){
        figures[i]->draw(picture);
    }
}