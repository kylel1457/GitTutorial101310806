#include "HeapArrays.h"

HeapArrays::HeapArrays(){
    size = 0;
    textAreas = new TextArea[MAX_ARRAY];
    textAreaPointers = new TextArea*[MAX_ARRAY];
}

TextArea* HeapArrays::getObjectArray(){
    return textAreas;
}

TextArea** HeapArrays::getPointerArray(){
    return textAreaPointers;
}

TextArea* HeapArrays::getPointer(int index){
    return textAreaPointers[index];
}

TextArea& HeapArrays::getReference(int index){
    return textAreas[index];
}

void HeapArrays::addTextArea(TextArea text){
    if(size < MAX_ARRAY){
        textAreas[size] = text;
        textAreaPointers[size] = new TextArea(text);
        size++;
    }
}

HeapArrays::~HeapArrays(){
    while(size > 0){
        delete textAreaPointers[size-1];
        size--;
    }
    delete [] textAreas;
    delete[] textAreaPointers;
}