#ifndef RGB_H
#define RGB_H

#include <string>
#include <iostream>
#include "defs.h"

using namespace std;

class RGB{
    public:
        RGB(int r, int g, int b);
        RGB(CuColour colour);
        RGB();
        CuColour getColour() const;    
        int getR()const;
        int getB()const;
        int getG()const;
        void setColour(CuColour colour);
        void setR(int r);
        void setG(int g);
        void setB(int b);
        static RGB WHITE();
        static RGB BLACK();
        static RGB RED();
        static RGB GREEN();
        static RGB BLUE();

    private:
        int red;
        int green;
        int blue;
};

#endif