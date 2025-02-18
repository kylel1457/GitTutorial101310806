#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <string>
#include <iostream>
#include "defs.h"
#include "RGB.h"

using namespace std;

class TextArea{
    private:
        Rectangle dimensions;
        int x;
        int y;
        int width;
        int height;
        string text;
        string id;
        RGB fill;
        RGB border;

    public:
        void setX(int);
        void setY(int);
        void setWidth(int);
        void setHeight(int);
        void setText(string);
        void setId(string);
        void setFill(RGB);
        void setBorder(RGB);
        TextArea(int x, int y, int width, int height, string id, string label,  RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
        TextArea(Rectangle rect, string id, string label,  RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
        TextArea();
        TextArea(const TextArea& textArea);
        //void draw (Display *display, Window win, GC gc, int x, int y)const;
        bool overlaps (const TextArea& ta)const;
        void print()const;
};

#endif