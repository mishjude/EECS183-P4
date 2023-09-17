/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <Sabrina Martell and Mish Jude>
 * <sabrinma and mishmish>
 *
 * <Functions to read and write points on a blank canvas>
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

Point::Point() {
    x = 0;
    y = 0;

}

Point::Point(int xVal, int yVal) {
    x = checkRange(xVal);
    y = checkRange(yVal);

}

void Point::setX(int xVal) {
    x = checkRange(xVal);
    return;

}

int Point::getX() {
    return x;

}

void Point::setY(int yVal) {
    y = checkRange(yVal);
    return;

}

int Point::getY() {
    return y;

}

void Point::read(istream& ins) {
    char junk;
    ins >> junk >> x >> junk >> y >> junk;
    x = checkRange(x);
    y = checkRange(y);

}

void Point::write(ostream& outs) {
    char p = '(';
    char endp = ')';
    outs << p << x << "," << y << endp;

}

int Point::checkRange(int val) {
    if (val >= 0 && val < DIMENSION) {
        return val;
    }
    else if (val < 0) {
        val = 0;
    }
    else if (val > DIMENSION) {
        val = DIMENSION - 1;
    }

    return val;
}

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
