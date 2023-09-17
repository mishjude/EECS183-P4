/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <Sabrina Martell and Mish Jude>
 * <sabrinma and mishmish>
 *
 * Contains functions for testing classes in the project. 
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;


void test_Circle();
void test_Color();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();

void startTests() {
    test_Point();
    test_Line();
    test_Color();
    test_Circle();
    test_Rectangle();
    test_Triangle();
    
    
    // call other test functions here
    
    return;
}

//testing functions in point.cpp

void test_Point() {

    cout << "Now testing point.cpp" << endl;
    // test of default constructor
    Point p1;
    cout << "Expected: (0,0), actual: " << p1 << endl;
    
    // test of the non-default constructor
    Point p2(3, 9);
    cout << "Expected: (3,9), actual: " << p2 << endl;

    Point p3(-3, 102);
    cout << "Expected: (0, 99), actual: " << p3 << endl;

    Point p4(102, -3);
    cout << "Expected: (99,0), actual: " << p4 << endl;

    // test of member function: setX() and getX()

    Point x1;
    x1.setX(5);

    cout << "Expected: 5,  actual: " << x1.getX() << endl;

    Point x2;
    x2.setX(-3);

    cout << "Expected: 0, actual:  " << x2.getX() << endl;

    Point x3;
    x3.setX(400);
    cout << "Expected: 99, actual: " << x3.getX() << endl;


    // test of member function: setY() and getY()

    Point y1;
    y1.setY(5);

    cout << "Expected: 5,  actual: " << y1.getY() << endl;

    Point y2;
    y2.setY(-7);

    cout << "Expected: 0, actual:  " << y2.getY() << endl;

    Point y3;

    y3.setY(300);
    cout << "Expected: 99, actual: " << y3.getY() << endl;

    // test of member functions getX() and getY() - given point
    p1.setX(5);
    p1.setY(3);
    cout << "Expected: (5,3), actual: ";
    cout << "( " << p1.getX()
         << ", " << p1.getY()
         << " )" << endl;
    

    //testing for checkRange
    Point pt1;
    pt1.setX(15);
    cout << "Expected: (15,0), actual :" << pt1 << endl;

    ifstream input_file;
    input_file.open("data1.txt");
    pt1.read(input_file);
    cout << "Expected: (42,7), actual :" << pt1 << endl;

    Point pt2;
    cout << "Expected: (0,0), actual: " << pt2 << endl;

    Point pt3;
    pt3.setY(15);
    cout << "Expected: (0,15), actual: " << pt3 << endl;

    Point pt4;
    pt4.setY(-7);
    pt4.setX(102);
    cout << "Expected: (99,0), actual: " << pt4 << endl;

    Point pt5;
    pt5.setX(-3);
    pt5.setY(707);
    cout << "Expected: (0,99), actual: " << pt5 << endl;

    Point pt6;
    cout << "Expected: (0,0), actual: " << Point(pt6) << endl;

    pt6.setX(4);
    pt6.setY(7);

    cout << "Expected: (4,7), actual: " << Point(pt6) << endl;

    Point pt7;

    pt7.setX(-3);
    pt7.setY(107);

    cout << "Expected: (0,99), actual: " << Point(pt7) << endl;

    pt7.setX(107);
    pt7.setY(-3);

    cout << "Expected: (99,0), actual: " << Point(pt7) << endl;


    cout << "Finished testing point.cpp" << endl << endl;

    return;
}


//testing functions in line.cpp

void test_Line() {

    cout << "Now testing line.cpp" << endl;

    //points and colors to use for test cases
    Point pt1;
    Point pt2(3, 9);
    Color color1;
    Color color2(176, 8, 105);

    // test of default constructor
    Line l1;
    cout << "Expected: (0,0) (0,0) 0 0 0, actual: " << l1 << endl;

    

    // test of the non-default constructor
    Line l2(pt1, pt2, color2);
    cout << "Expected: (0,0) (3,9) 176 8 105, actual: " << l2 << endl;


    // test of member function: setStart()
    l1.setStart(pt1);
    
    Line l3;
    Point pt3(-4, 107);
    l3.setStart(pt3);

    Line l4;
    Point pt4(107, -4);
    l4.setStart(pt4);

    // test of member function: setEnd()
    l1.setEnd(pt2);
    l3.setEnd(pt4);
    l4.setEnd(pt3);


    // test of member function: setColor()
    l1.setColor(color2);
    l3.setColor(color2);
    l4.setColor(color2);

    // test of member functions getStart(), getEnd(), and getColor()
    cout << "Expected: (0,0) (3,9) 176 8 105, actual: " << l1.getStart() << " " 
        << l1.getEnd() << " " << l1.getColor() << endl;

    cout << "Expected: (0,99) (99,0) 176 8 105, actual: " << l3.getStart() << " "
        << l3.getEnd() << " " << l3.getColor() << endl;

    cout << "Expected: (99,0) (0,99) 176 8 105, actual: " << l4.getStart() << " "
        << l4.getEnd() << " " << l4.getColor() << endl;
    
    cout << "Finished testing line.cpp" << endl << endl;
}




//testing functions in color.cpp

void test_Color() {

    cout << "Now testing color.cpp" << endl;

    Color color1;
    Color color4;
    Color color5;
   

    // test of default constructor
    
    cout << "Expected: 0 0 0, actual: " << color1 << endl;



    // test of the non-default constructor
    Color color2(176, 8, 105);
    cout << "Expected: 176 8 105, actual: " << color2 << endl;

    Color color3(-6, 41, 307);
    cout << "Expected: 0 41 255, actual: " << color3 << endl;


    // test of member function: setRed()
    color1.setRed(24);
    color4.setRed(-5);
    color5.setRed(347);


    // test of member function: setGreen()
    color1.setGreen(47);
    color4.setGreen(-12);
    color5.setGreen(432);


    // test of member function: setBlue()
    color1.setBlue(176);
    color4.setBlue(-345);
    color5.setBlue(527);


    // test of member functions getRed(), getGreen(), and getBlue()
    cout << "Expected: 24 47 176, actual: " << color1.getRed() << " " 
        << color1.getGreen() << " " << color1.getBlue() << endl;
    cout << "Expected: 0 0 0, actual: " << color4.getRed() << " "
        << color4.getGreen() << " " << color4.getBlue() << endl;
    cout << "Expected: 255 255 255, actual: " << color5.getRed() << " "
        << color5.getGreen() << " " << color5.getBlue() << endl;

    cout << "Finished testing color.cpp" << endl << endl;
}


//testing functions in circle.cpp

void test_Circle() {

    cout << "Now testing circle.cpp" << endl;
    //variables needed for testing 
    Point pt1(6, 9);
    Point pt2(7, 7);
    Point pt3(-3, 407);
    int r1 = 7;
    int r2 = -6;
    Color color1(176, 8, 105);
    Color color2(27, 85, 169);
    Color color3(-7, 43, 302);
    Circle circle3;

    // test of default constructor
    Circle circle1;
    circle1.setRadius(r1);


    
    cout << "Expected: (0,0) 7 0 0 0, actual: " << circle1.getCenter() 
        << " " << circle1.getRadius() << " " << circle1.getColor() << endl;



    // test of the non-default constructor
    Circle circle2(pt1, r1, color1);
    cout << "Expected: (6,9) 7 176 8 105, actual: " << circle2 << endl;

    Circle circle4(pt3, r2, color3);
    cout << "Expected: (0,99) 6 0 43 255, actual: " << circle4 << endl;

    // test of member function: setCenter()
    circle1.setCenter(pt2);
    circle3.setCenter(pt3);

    // test of member function: setColor()
    circle1.setColor(color2);
    circle3.setColor(color2);


    // test of member function: setRadius()
    circle1.setRadius(r2);
    circle3.setRadius(r1);


    // test of member functions getCenter(), getColor(), and getRadius()
    cout << "Expected: (7,7) 6 27 85 169, actual: " << circle1.getCenter() 
        << " " << circle1.getRadius() << " " << circle1.getColor() << endl;

    cout << "Expected: (0,99) 7 27 85 169, actual: " << circle3.getCenter()
        << " " << circle3.getRadius() << " " << circle3.getColor() << endl;

    cout << "Finished testing circle.cpp" << endl << endl;
}

//testing functions in rectangle.cpp

void test_Rectangle() {

    cout << "Now testing rectangle.cpp" << endl;

    //Testing setters and getters

    Color color1(-1, 37, 523);

    Point pt1(-0, 100);
    Point pt2(2, 5);

    Rectangle rectangle1(pt1, pt2, color1);

    rectangle1.setStart(pt1);
    cout << "Expected: (0, 99), actual: " << rectangle1.getStart() << endl;

    rectangle1.setEnd(pt2);
    cout << "Expected: (2, 5), actual: " << rectangle1.getEnd() << endl;

    rectangle1.setColorTopLeft(color1);
    cout << "Expected: 0 37 255 , actual: " << rectangle1.getColorTopLeft() << endl;

    rectangle1.setColorTopRight(color1);
    cout << "Expected: 0 37 255 , actual: " << rectangle1.getColorTopRight() << endl;

    rectangle1.setColorBottomRight(color1);
    cout << "Expected: 0 37 255 , actual: " << rectangle1.getColorBottomRight() << endl;

    rectangle1.setColorBottomLeft(color1);
    cout << "Expected: 0 37 255 , actual: " << rectangle1.getColorBottomLeft() << endl;


    Color colorTL2(5, 6, 7);
    Color colorTR2(256, 256, 256);
    Color colorBR2(235, -2, -255);
    Color colorBL2(20, 37, 180);

    Point pt3(0, 0);
    Point pt4(59, 90);

    Rectangle rectangle2(pt1, pt2, colorTL2, colorTR2, colorBR2, colorBL2);
    rectangle2.setStart(pt3);
    cout << "Expected: (0, 0), actual: " << rectangle2.getStart() << endl;

    rectangle2.setEnd(pt4);
    cout << "Expected: (59, 90), actual: " << rectangle2.getEnd() << endl;

    rectangle2.setColorTopLeft(colorTL2);
    cout << "Expected: 5 6 7 , actual: " << rectangle2.getColorTopLeft() << endl;

    rectangle2.setColorTopRight(colorTR2);
    cout << "Expected: 255 255 255 , actual: " << rectangle2.getColorTopRight() << endl;

    rectangle2.setColorBottomRight(colorBR2);
    cout << "Expected: 235 0 0 , actual: " << rectangle2.getColorBottomRight() << endl;

    rectangle2.setColorBottomLeft(colorBL2);
    cout << "Expected: 20 37 80 , actual: " << rectangle2.getColorBottomLeft();

    //Testing constructors
    Color colorTL3(-8, 22, 7);
    Color colorTR3(256, 55, 191);
    Color colorBR3(898, -2, -25);
    Color colorBL3(20, 37, 99);
    Point pt5(99, 0);
    Point pt6(-999, 999);

    Rectangle rectangle3(pt5, pt6, colorTL3, colorTR3, colorBR3, colorBL3);
    cout << "Expected: (99, 0) (0, 99) 0 22 7  255 55 191  255 0 0  20 37 99"
        << rectangle3 << endl;


    Color color2(760, -3, 38);
    Point pt7(67, 981);
    Point pt8(-45, 37);

    Rectangle rectangle4(pt7, pt8, color2);
    cout << "Expected: (67, 99) (0, 37) 255 0 38" << rectangle3 << endl;

    return;
}


//testing functions in triangle.cpp

void test_Triangle() {

    cout << "Now testing triangle.cpp" << endl;

    Color color1(0, 0, 0);
    Color color2(255, 255, 255);
    Color color3(66, 280, -5);

    Point pt1(0, 0);
    Point pt2(33, 33);
    Point pt3(17, 22);

    //Testing member functions for setVertexes and getVertexes using dif colors
    Triangle triangle1(pt1, color1, pt2, color2, pt3, color3);
    triangle1.setVertexOneColor(color1);
    cout << "Expected: 0 0 0, actual: " << triangle1.getVertexOneColor()
        << endl;

    triangle1.setVertexTwoColor(color2);
    cout << "Expected: 255 255 255, actual: " << triangle1.getVertexTwoColor()
        << endl;

    triangle1.setVertexThreeColor(color3);
    cout << "Expected: 66 255 0 actual: " << triangle1.getVertexThreeColor()
        << endl;


    Color color4(256, 0, -5);
    Color color5(37, 9, 59);
    Color color6(-255, 829, 0);

    Point pt4(7, 8);
    Point pt5(0, 100);
    Point pt6(-5, -5);

    Triangle triangle2(pt4, color4, pt5, color5, pt6, color6);
    triangle2.setVertexOne(pt4);
    cout << "Expected: (7, 8) actual: " << triangle2.getVertexOne() << endl;

    triangle2.setVertexTwo(pt5);
    cout << "Expected: (0, 99) actual: " << triangle2.getVertexTwo() << endl;

    triangle2.setVertexThree(pt6);
    cout << "Expected: (0, 0) actual: " << triangle2.getVertexThree() << endl;


    Color color16(88, 723, -99);
    Point pt16(28, -28);
    Point pt17(99, 10);
    Point pt18(-86, 654);

    Triangle triangle6(pt16, pt17, pt18, color16);
    triangle6.setVertexOne(pt16);
    cout << "Expected: (28, 0) actual: " << triangle6.getVertexOne() << endl;

    triangle6.setVertexTwo(pt17);
    cout << "Expected: (99, 10) actual: " << triangle6.getVertexTwo() << endl;

    triangle6.setVertexThree(pt18);
    cout << "Expected: (0, 99) actual: " << triangle6.getVertexThree() << endl;

    //Testing member function setVertexes and getVertexes using same color
    Color color7(378, 90, -22);
    Point pt7(0, 0);
    Point pt8(48, 57);
    Point pt9(256, -5);

    Triangle triangle3(pt7, pt8, pt9, color7);

    triangle3.setVertexOne(pt7);
    cout << "Expected: (0, 0) actual: " << triangle3.getVertexOne() << endl;

    triangle3.setVertexTwo(pt8);
    cout << "Expected: (48, 57) actual: " << triangle3.getVertexTwo() << endl;

    triangle3.setVertexThree(pt9);
    cout << "Expected: (99, 0) actual: " << triangle3.getVertexThree() << endl;

    triangle3.setVertexOneColor(color7);
    cout << "Expected: 255 90 0, actual: " << triangle3.getVertexOneColor()
        << endl;

    triangle3.setVertexTwoColor(color7);
    cout << "Expected: 255 90 0, actual: " << triangle3.getVertexTwoColor()
        << endl;

    triangle3.setVertexThreeColor(color7);
    cout << "Expected: 255 90 0, actual: " << triangle3.getVertexThreeColor()
        << endl;

    Color color8(99, 37, 24);
    Color color9(269, -5, 1004);
    Color color10(-3, 8, 8);
    Point pt10(-1, 1);
    Point pt11(77, 770);
    Point pt12(-21, -21);

    Triangle triangle4(pt10, color8, pt11, color9, pt12, color10);
    cout << "Expected: (0, 1) 99 37 24 (77, 99) 255 0 255 (0, 0) 0 8 8"
        << triangle4 << endl;

    Color color13(121, -7004, 80000);
    Point pt13(85, 320);
    Point pt14(-75, 24);
    Point pt15(301, 455);

    Triangle triangle5(pt13, pt14, pt15, color13);
    cout << "Expected: (85, 99) (0, 24) (99, 99) 121 0 255"
        << triangle5 << endl;

    //Testing constructors
    cout << "Expected: (7, 8) 255 0 0 (0, 99) 37 9 59 (0, 0) 0 255 0, actual: "
        << triangle2 << endl;
    cout << "Expected: (28, 0) (99, 10) (0, 99), actual: "
        << triangle6 << endl;

    cout << "Finished testing triangle.cpp" << endl;

    return;
}

