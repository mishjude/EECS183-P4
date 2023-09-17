/**
 * Rectangle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <Sabrina Martell and Mish Jude>
 * <sabrinma and mishmish>
 *
 * <Functions to read points and colors to draw rectangles>
 */

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;


Rectangle::Rectangle() {

}


Rectangle::Rectangle(Point pt1, Point pt2, Color color) {
    start = pt1;
    end = pt2;
    colorTopLeft = color;
    colorTopRight = color;
    colorBottomRight = color;
    colorBottomLeft = color;

}


Rectangle::Rectangle(Point pt1, Point pt2, Color cTopLeft, Color cTopRight,
    Color cBottomRight, Color cBottomLeft) {
    start = pt1;
    end = pt2;
    colorTopLeft = cTopLeft;
    colorTopRight = cTopRight;
    colorBottomRight = cBottomRight;
    colorBottomLeft = cBottomLeft;

}


void Rectangle::setStart(Point pt) {
    start = pt;

}


Point Rectangle::getStart() {
    return start;

}


void Rectangle::setEnd(Point pt) {
    end = pt;
    
}


Point Rectangle::getEnd() {
    return end;
    
}


void Rectangle::setColor(Color color) {
    colorTopLeft = color;
    colorTopRight = color;
    colorBottomRight = color;
    colorBottomLeft = color;
    
}


void Rectangle::setColorTopLeft(Color color) {
    colorTopLeft = color;
    
}


Color Rectangle::getColorTopLeft() {
    return colorTopLeft;

}


void Rectangle::setColorTopRight(Color color) {
    colorTopRight = color;
    
}


Color Rectangle::getColorTopRight() {
    return colorTopRight;

}


void Rectangle::setColorBottomRight(Color color) {  
    colorBottomRight = color;
    
}


Color Rectangle::getColorBottomRight() {
    return colorBottomRight;

}


void Rectangle::setColorBottomLeft(Color color) {
    colorBottomLeft = color;
    
}


Color Rectangle::getColorBottomLeft() {
    return colorBottomLeft;

}


void Rectangle::read(istream& ins) {
    ins >> start >> end >> colorTopLeft;
    ins >> colorTopRight;

    if (ins.fail()) {
        //first form
        ins.clear();

        colorTopRight = colorTopLeft;
        colorBottomRight = colorTopLeft;
        colorBottomLeft = colorTopLeft;
        
    }
    else {
        //second form
        ins >> colorBottomRight >> colorBottomLeft;
    }
    
}


void Rectangle::write(ostream& outs) {
    outs << start << " " << end << " " << colorTopLeft << " " << colorTopRight
        << " " << colorBottomRight << " " << colorBottomLeft;

}
   

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Rectangle& rectangle)
{
    rectangle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Rectangle rectangle)
{
    rectangle.write(outs);
    return outs;
}

void Rectangle::draw(Graphics & drawer)
{
    // four points of rectangles
    Point topLeft = start;
    Point topRight(end.getX(), start.getY());
    Point bottomRight = end;
    Point bottomLeft(start.getX(), end.getY());

    // center point and color by averaging
    Point center((start.getX() + end.getX()) / 2,
                 (start.getY() + end.getY()) / 2);
    Color colorCenter((colorTopLeft.getRed() + colorTopRight.getRed() +
                       colorBottomRight.getRed() +
                       colorBottomLeft.getRed()) / 4,
                      (colorTopLeft.getGreen() + colorTopRight.getGreen() +
                       colorBottomRight.getGreen() +
                       colorBottomLeft.getGreen()) / 4,
                      (colorTopLeft.getBlue() + colorTopRight.getBlue() +
                       colorBottomRight.getBlue() +
                       colorBottomLeft.getBlue()) / 4);

    // four triangles to represent rectangle
    Triangle top(topLeft, colorTopLeft, topRight, colorTopRight,
                 center, colorCenter);
    Triangle bottom(bottomLeft, colorBottomLeft, bottomRight, colorBottomRight,
                    center, colorCenter);
    Triangle left(topLeft, colorTopLeft, bottomLeft, colorBottomLeft,
                  center, colorCenter);
    Triangle right(topRight, colorTopRight, bottomRight, colorBottomRight,
                   center, colorCenter);
    top.draw(drawer);
    bottom.draw(drawer);
    left.draw(drawer);
    right.draw(drawer);
}
