#include "StackArrays.h"

StackArrays::StackArrays(){
    size = 0;
}

TextArea* StackArrays::getObjectArray(){
    return textAreas;
}

TextArea** StackArrays::getPointerArray(){
    return textAreaPointers;
}

TextArea* StackArrays::getPointer(int index){
    return textAreaPointers[index];
}

TextArea& StackArrays::getReference(int index){
    return textAreas[index];
}

void StackArrays::addTextArea(TextArea text){
    if(size < MAX_ARRAY){
        textAreas[size] = text;
        textAreaPointers[size] = new TextArea(text);
        size++;
    }
}

StackArrays::~StackArrays(){
    while(size > 0){
        delete textAreaPointers[size-1];
        size--;
    }
}