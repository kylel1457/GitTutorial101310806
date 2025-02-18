#include "RGB.h"

RGB::RGB(int r, int g, int b){
    red = r;
    green = g;
    blue = b;
}

RGB::RGB(CuColour colour){
    red = (255 & (colour>>16));
    green = (255 & (colour>>8));
    blue = (255 & colour);
}

RGB::RGB(){
    red = 0;
    green = 0;
    blue = 0;
}

CuColour RGB::getColour()const {
    CuColour colour = (((0 | (red << 16)) | green << 8) | blue);
    return colour;
}

void RGB::setColour(CuColour colour){
    red = (255 & (colour>>16));
    green = (255 & (colour>>8));
    blue = (255 & colour);
}

int RGB::getB()const {
    return blue;
}

int RGB::getG()const {
    return green;
}

int RGB::getR()const {
    return red;
}

void RGB::setB(int b){
    blue = b;
}

void RGB::setG(int g){
    green = g;
}

void RGB::setR( int r){
    red = r;
}

RGB RGB::WHITE(){
    return RGB(255,255,255);
}

RGB RGB::BLACK(){
    return RGB(0,0,0);
}

RGB RGB::RED(){
    return RGB(255,0,0);
}

RGB RGB::BLUE(){
    return RGB(0,0,255);
}

RGB RGB::GREEN(){
    return RGB(0,255,0);
}