#include "list.h"
#include <iostream>

List::List()
{
    head = nullptr;
    size = 0;
}

List::~List()
{

    for(int i = 0; i < size; i++)
        pop_back();
    delete this;
}

valueType List::getSize()
{
    return size;
}

void List::push_back(valueType x)
{
    ListElement *newElem = new ListElement;
    newElem->setKey(x);
    if (isEmpty()) {
        newElem->setNext(newElem);
        newElem->setPrev(newElem);

        head = newElem;
        last = newElem;
    }
    else {
        newElem->setPrev(last);
        last->setNext(newElem);
        last = newElem;
        last->setNext(head);
        head->setPrev(last);
    }

    size++;
}

void List::push_front(valueType x)
{
    ListElement *newElem = new ListElement;
    newElem->setKey(x);

    if (isEmpty()) {
        newElem->setNext(newElem);
        newElem->setPrev(newElem);
        head = newElem;
        last = newElem;
    }
    else {
        newElem->setNext(head);
        head->setPrev(newElem);
        head = newElem;
        head->setPrev(last);
        last->setNext(head);
    }

    size++;
}

void List::pop_front()
{
    if(!isEmpty()) {
        ListElement *temp = head;
        head = head->getNext();
        head->setPrev(last);
        delete temp;
        size--;
    }
}

void List::pop_back()
{
    if(!isEmpty()) {
        ListElement *temp = last;
        last = last->getPrev();
        last->setNext(head);
        delete temp;
        size--;
    }
}

void List::insert(ListElement *pos, valueType x)
{
    ListElement *newElem = new ListElement;
    newElem->setKey(x);
    newElem->setNext(pos->getNext());
    newElem->setPrev(pos);

    pos->getNext()->setPrev(newElem);
    pos->setNext(newElem);
    size++;
}

void List::insert(ListElement *pos, int n, valueType x)
{
    for(int i = 0; i < n; i++) {
        ListElement *newElem = new ListElement;
        newElem->setKey(x);
        newElem->setNext(pos->getNext());
        newElem->setPrev(pos);
        pos->getNext()->setPrev(newElem);
        pos->setNext(newElem);
        size++;
    }
}

void List::erase(ListElement *pos)
{
    if(!isEmpty()) {
        pos = pos->getNext();
        ListElement *temp = pos;
        pos->getPrev()->setNext(pos->getNext());
        pos->getNext()->setPrev(pos->getPrev());
        delete temp;
        size--;
    }
}

ListElement *List::find(valueType x)
{
    ListElement *temp = head;

    for(int i = 0; i < size; i++, temp = temp->getNext())
        if(temp->getKey() == x) {
            return temp;
        }

    delete temp;
    return nullptr;
}

ListElement *List::getNListElem(int n)
{
    ListElement *temp = head;
    for(int i = 0; i < n; i++, temp = temp->getNext())
    {

    }

    return temp;
}

bool List::isEmpty()
{
    return (size == 0);
}

void List::show()
{
    ListElement *t = head;

    for(int i = 0; i < size; i++, t = t->getNext()) {
        std::cout << t->getKey() << " ";
    }
    std::cout << std::endl;

    delete t;
}

ListElement *List::Head() const
{
    return head;
}

ListElement *List::Last() const
{
    return last;
}





