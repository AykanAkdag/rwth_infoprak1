#include "Stack.h"

/**
 * @file Stack.cpp
 *
 * @brief Stack Class methods
 *
 * 		This file contatins the functions defined in the Stack Class.
 */
Stack::Stack() : head(NULL), tail(NULL)
{
}

/**
 *	@brief Pushes new data
 *
 *		This function pushes a new element on top of the stack. When called, it is first checked
 *		whether the stack is empty. If so, a special case condition is needed where the head of the
 *		stack is equal to the tail and the only element of the stack is the new element pushed by the user.
 *		Otherwise the new element's next pointer is set to the next pointer of the head and the head itself
 *		is then updated to be the new element due to the LIFO structure.
 *
 *	@param data Input student information
 */
void Stack::push(Student& data)
{
	ListElem* new_element = new ListElem(data, NULL);  //newElement student data, next pointer NULL
	if (head == NULL)
	{
		tail = new_element; // if stack empty, head = tail = new element
	}
	else
	{
		new_element->setNext(head); // if not, get next pointer of tail
	}
	head = new_element;
}

/**
 * @brief Outputs the contents of the stack
 *
 *		This function goes throught the contents of the stack and outputs it. When called, it is first checked
 *		whether the stack is empty. If so an message displayed to the user. Otherwise the cursor pointer is
 *		iterated over all the elements saved in the stack until the cursor points to NULL, which
 *		indicates the tail of the list, therefore the output terminates.
 *
 */
void Stack::ausgabe() const
{
	if (head == NULL) // empty?
	{
		std::cout << "Der Stack ist leer." << std::endl;
	}
	else
	{
		ListElem* cursor = head;
		while (cursor != NULL)
		{
			(cursor->getData()).print();
			cursor = cursor->getNext();
		}
	}
}

/**
 * @brief Pops the head of the stack
 *
 *		This function pops the uppermost element of the stack (head). When called, it is first checked
 *		whether the stack is empty. If so, there are no elements to pop. Otherwise, the head of the stack
 *		is saved in the temporary cursor variable and then the head is updated to be the next element pointed
 *		by the previous head. After that the cursor variable is deleted thereby completing the task.
 *
 * @param data Student information
 */
bool Stack::pop(Student& data)
{
	if (head == NULL) // empty?
	{
		return false;
	}
	else
	{
		data = head->getData();
		ListElem* cursor = head; //
		head = head->getNext();
		delete cursor;
	}
	return true;
}
