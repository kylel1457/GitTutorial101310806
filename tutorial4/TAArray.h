#ifndef LIST_H
#define LIST_H

#define MAX_ARR 64

#include "TextArea.h"

class TAArray
{
  public:
    TAArray();
    ~TAArray();

    bool add(TextArea*);
    bool add(TextArea*, int);
    TextArea* get(string name);
    TextArea* get(int index);

    TextArea* remove(string name);
    TextArea* remove(int index);


    bool isFull(){return size == MAX_ARR;}
    int getSize(){return size;}
    void print();
    

  private:
    TextArea** elements;
    int size;
   
};

#endif

