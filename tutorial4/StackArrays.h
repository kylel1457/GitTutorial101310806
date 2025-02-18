#ifndef STACKARRAYS_H
#define STACKARRAYS_H

#include <string>
#include <iostream>
#include "defs.h"
#include "TextArea.h"

using namespace std;

class StackArrays{
    private:
        TextArea textAreas[MAX_ARRAY];
        TextArea* textAreaPointers[MAX_ARRAY];
        int size;

    public:
        StackArrays();
        ~StackArrays();
        TextArea* getObjectArray();
        TextArea** getPointerArray();
        TextArea* getPointer(int index);
        TextArea& getReference(int index);
        void addTextArea(TextArea text);
};

#endif