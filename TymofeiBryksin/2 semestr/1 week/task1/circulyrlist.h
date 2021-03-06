#pragma once
#include "list.h"

typedef double valueType;
class CirculyrList: public List
{

public:

    CirculyrList();
    ~CirculyrList();

    void pushBack(valueType x);
    void pushFront(valueType x);
    void popFront();
    void popBack();
    void reverse();
    void erase(int pos);
    void erase(valueType x);
    void add(int pos, valueType x);

private:
    void pushInit(ListElement *newElem); //вставляет в пустой список первый элемент
    ListElement *getNListElem(int pos);

};

