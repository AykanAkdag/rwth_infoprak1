/**
 * @file ListElem.h
 *
 * content: List element to be used in a data structure
 */

#ifndef _LISTELEM_H_
#define _LISTELEM_H_

#include "Student.h"

class ListElem
{
private:
	Student data;
    ListElem* next;
    ListElem* prev;

public:
    ListElem(const Student &s, ListElem* const nextPointer, ListElem* const prevPointer); //constructor

    void setData(const Student &data_in); //gD
    void setNext(ListElem* const nextPointer); //gN
    void setPrev(ListElem* const prevPointer);

    Student getData() const; //sD
    ListElem* getNext() const; //sN
    ListElem* getPrev() const;
};

#endif
