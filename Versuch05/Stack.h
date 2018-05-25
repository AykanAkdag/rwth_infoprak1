#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include "ListElem.h"

class Stack
{
private:
	ListElem* head; //a
	ListElem* tail; //z

public:
	Stack(); //construct
	void push(Student& data); //push
	bool pop(Student& data); //pop
	void ausgabe() const; //ausgabe
};

#endif
