#include "TextArea.h"

TextArea::TextArea(int x, int y, int width, int height, string id, string label, RGB fill, RGB border){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->id = id;
    this->text = label;
    this->fill = fill;
    this->border = border;
}

TextArea::TextArea(Rectangle rect, string id, string label, RGB fill, RGB border){
    this->x = rect.x;
    this->y = rect.y;
    this->width = rect.width;
    this->height = rect.height;
    this->id = id;
    this->text = label;
    this->fill = fill;
    this->border = border;
}

TextArea::TextArea(){
    this->x = 0;
    this->y = 0;
    this->width = 80;
    this->height = 50;
    this->id = "";
    this->text = "";
    this->fill = RGB::WHITE();
    this->border = RGB::BLACK();
}

TextArea::TextArea(const TextArea &textArea){
    this->x = textArea.x;
    this->y = textArea.y;
    this->width = textArea.width;
    this->height = textArea.height;
    this->id = textArea.id;
    this->text = "DUPLICATE" + textArea.text; 
    this->fill = textArea.fill;
    this->border = textArea.border;
}


bool TextArea::overlaps(const TextArea& ta) const{
    if (x < ta.x + ta.width && x + width > ta.x && y < ta.y + ta.height && y + height > ta.y){
            return true;
        }
        if (ta.x < x + width && ta.x + ta.width > x && ta.y < y + height && ta.y + ta.height > y){
            return true;
        }
        return false;
}

void TextArea::print() const{
    cout << "TextArea id: " << id << endl;
    cout << "Preferred Location: " << x << ", " << y << endl;
    cout << "Size: " << width << ", " << height << endl;
    cout << "Text: " << text << endl;
}

void TextArea::setX(int x) {
    this->x = x;
}

void TextArea::setY(int y) {
    this->y = y;
}

void TextArea::setWidth(int width) {
    this->width = width;
}

void TextArea::setHeight(int height) {
    this->height = height;
}

void TextArea::setText(string text) {
    this->text = text;
}

void TextArea::setId(string id) {
    this->id = id;
}

void TextArea::setFill(RGB fill) {
    this->fill = fill;
}

void TextArea::setBorder(RGB border) {
    this->border = border;
}