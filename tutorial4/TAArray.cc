#include <iostream>
using namespace std;

#include "TAArray.h"

TAArray::TAArray(){
    size = 0;
    elements = new TextArea*[MAX_ARR];
}

TAArray::~TAArray(){
    delete [] elements;
}

bool TAArray::add(TextArea* s){
    if (size >= MAX_ARR)return false;
    elements[size] = s;
    size++;
    return true
}

bool TAArray::add(TextArea* s, int index){
    if (size >= MAX_ARR || index > size || index < 0)return false;
    for(int i = size; i > index; i --){
        elements[i] = elements[i-1];
    }
    elements[index] = s;
    size++;
    return true
}


TextArea* TAArray::get(string id){
    for (int i = 0; i < size; ++i){
        if (elements[i]->id == id){
            return elements[i];
        }
    }
    return NULL;
}

TextArea* TAArray::get(int index){
    if (index < 0 || index >= size) return NULL;
    return elements[index];
}

TextArea* TAArray::remove(string id){

    //we want to find the index of the element to remove
    for(int i = 0; i < size; i++){
        if(elements[i]->id == id){
            return remove(i);
        }
    }
    return nullptr;
}

TextArea* TAArray::remove(int index){

    //did we fall off the end of the StudentArray?
    if (index<0 || index >=size) return nullptr;

    //we have found what we wanted to remove,
    //assign the output value
    TextArea *stu = elements[index];

    //copy everything after index left one position
    while (index < size - 1){
        elements[index] = elements[index + 1];
        ++index;
    }
    --size;
    return stu;

}


void TAArray::print()
{
  cout << endl << endl << "TextAreas:" << endl;
  for (int i=0; i<size; ++i)
    elements[i]->print();

  cout << endl;
}