//
// Created by tysse on 21.02.2018.
//

#ifndef OV10_SHAPE_H
#define OV10_SHAPE_H

#include <vector>


class Shape {
private:
    Color color;
public:
    explicit Shape(Color input);
    Color getColor() const;
    virtual void draw(Image &picture){};

};


class Line: public Shape {
private:
    int x1, y1, x2, y2;
public:
    Line(int x1, int y1, int x2, int y2, Color input);
    void draw(Image &picture);
};


class Rectangle: public Shape {
private:
    int x1, y1, x2, y2;
public:
    Rectangle(int x1, int y1, int x2, int y2, Color input);
    void draw(Image &picture);
};


class Circle: public Shape {
private:
    int x0, y0, r;
public:
    Circle(int x, int y, int r, Color input);
    void draw(Image &picture);
};


class Canvas {
private:
    std::vector<Shape*>figures;
public:
    Canvas() = default;
    ~Canvas() = default;
    void addShape(Shape *figure);
    void rasterizeTo(Image &picture);
};


#endif //OV10_SHAPE_H
