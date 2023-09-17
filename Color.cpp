/**
 * Color.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <Sabrina Martell and Mish Jude>
 * <sabrinma and mishmish>
 *
 * < Class functions to read and evaluate colors as RGB values>
 */

#include "Color.h"



int Color::checkRange(int val) {
    if (val >= 0 && val <= 255) {
        return val;
    }
    else if (val < 0) {
        val = 0;
    }
    else if (val > 255) {
        val = 255;
    }

    return val;
}

Color::Color() {
    red = 0;
    green = 0;
    blue = 0;

}

Color::Color(int redVal, int greenVal, int blueVal) {
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);

}

void Color::setRed(int redVal) {
    red = checkRange(redVal);
    
}


int Color::getRed() {
    return red;

}


void Color::setGreen(int greenVal) {
    green = checkRange(greenVal);

}


int Color::getGreen() {
    return green;

}


void Color::setBlue(int blueVal) {
    blue = checkRange(blueVal);

}


int Color::getBlue() {
    return blue;
    
}


void Color::read(istream& ins) {
    //user input variables
    int redInput;
    int blueInput;
    int greenInput;

    ins >> redInput >> greenInput >> blueInput;

    //assigning user input numbers with the values of red 
    setRed(redInput);
    setGreen(greenInput);
    setBlue(blueInput);

}


void Color::write(ostream& outs) {
    outs << red << " " << green << " " << blue;
   
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}
