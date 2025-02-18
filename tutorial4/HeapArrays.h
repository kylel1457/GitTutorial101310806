#ifndef HEAPARRAYS_H
#define HEAPARRAYS_H

#include <string>
#include <iostream>
#include "defs.h"
#include "TextArea.h"

using namespace std;

class HeapArrays{
    private:
        TextArea* textAreas;
        TextArea** textAreaPointers;
        int size;

    public:
        HeapArrays();
        ~HeapArrays();
        TextArea* getObjectArray();
        TextArea** getPointerArray();
        TextArea* getPointer(int index);
        TextArea& getReference(int index);
        void addTextArea(TextArea text);

};



#endif