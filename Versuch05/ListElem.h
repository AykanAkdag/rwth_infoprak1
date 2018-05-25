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

public:
    ListElem(const Student &s, ListElem* const q); //constructor

    void setData(const Student &data_in); //gD
    void setNext(ListElem* const q); //gN

    Student getData() const; //sD
    ListElem* getNext() const; //sN
};

#endif
