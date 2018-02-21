#include <iostream>
using namespace std;

#include "Matrix.h"
#include "Vector.h"
#include "Image.h"
#include "Shape.h"

int main(){

    Color crayolaFuchsia(193, 84, 193);
    Color white(255,255,255);
    Color red(255,0,0);
    Color green(0,255,0);
    Color blue(0,0,255);
    Color black(0,0,0);

    Image img(1000, 1000);
    img.fill(white);

    Line line(10,10, 200, 200, green);
    Line line2(790,10, 990, 100, red);
    Line line3(10, 790, 100, 990, red);
    Rectangle rectangle(10, 10, 200, 200, blue);
    Circle circle(890, 890, 100, crayolaFuchsia);

    line.draw(img);
    line2.draw(img);
    line3.draw(img);
    rectangle.draw(img);
    circle.draw(img);

    Circle head(500, 500, 400, blue);
    Circle leftEye(350, 600, 100, red);
    Circle rightEye(650, 600, 100, red);
    Line mouth(400, 400, 600, 400, black);

    Canvas canvas;
    canvas.addShape(&head);
    canvas.addShape(&leftEye);
    canvas.addShape(&rightEye);
    canvas.addShape(&mouth);

    canvas.rasterizeTo(img);
    saveImage(img, "img.bmp");

    Image lenna(512, 512);
    lenna = *loadImage("lenna.bmp");
    Line mustache(280, 175, 320, 175, black);
    mustache.draw(lenna);
    saveImage(lenna, "lenna_edited.bmp");


    return 0;
}
