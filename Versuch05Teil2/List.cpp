/**
 * @file List.cpp
 * content: linked list data structure
 */

 /*
  * Diese Datei gehört nicht zu Versuch05Teil, sondern wird in Versuch05Teil02 benötigt
  */
  
  
#include "List.h"

List::List(): head(NULL), tail(NULL)
{
}

/**
 * @brief Enqueue an element at the beginning of the list (head).
 *
 * 		This function gets a new element given by the user and enques it at the beginning of the list (head).
 * 		If the list is not empty:
 * 		1) The head element's prev pointer is set to the address of the new element.
 * 		2) The new element's next pointer is set to the head of the list.
 * 		3) The head pointer itself is changed to the new element, as now that is the new beginning of the queue.
 *
 * @param pData The @ref Student to be added.
 * @return void
 */
void List::enqueue_head(const Student &pData)
{
    ListElem* new_element = new ListElem(pData, NULL, NULL); //Data = pData, next = Null, prev = Null

    if (tail == NULL)// list empty?
    {
        tail = new_element;
    }
    else
    {
        new_element->setNext(head); //head must be next to new elem
        head->setPrev(new_element); //new elem must be prev to head
    }

    head = new_element;
    new_element->setPrev(NULL); // TO DO redundant?
}

/**
 * @brief Dequeue an element from the end of the list (tail).
 *
 *		This function deletes the first element in the list, as it is implemented as a queue (FIFO Structure).
 *		If the list is not empty:
 *		1) A temporary cursor is set to point to tail.
 *		2) Data is retrieved from the tail to show to the user which element is being deleted.
 *		3) tail is changed to be the previous element of the current tail.
 *		4) The next element of the new tail is set to NULL.
 *		5) Cursor, still pointing to the old tail, is deleted together with its data.
 *
 *
 *		BUG: no list empty error message
 *		BUG FIX provided by Jarek Ecke
 *
 *
 * @param pData The data will be stored here.
 * @return bool
 */
bool List::dequeue(Student& pData)
{
	ListElem* cursor = tail;

	if (tail == NULL) // list empty?
	{
		return false;
	}
	else
	{
		pData = tail->getData();
		tail = tail->getPrev();
		head->setNext(NULL);
		delete cursor;
	}

	return true;
}

/**
 * @brief Print content from first to last element.
 *
 * Prints to cout.
 *
 * @return void
 */
void List::print_forwards()
{
    ListElem* cursor = tail;

    while (cursor != NULL)
    {
        cursor->getData().print();

        cursor = cursor->getPrev();
    }
}

/**
 * @brief Print content from last to first element.
 *
 * Prints to cout.
 *
 * @return void
 */
void List::print_backwards()
{
    ListElem* cursor = head;

    while (cursor != NULL)
    {
        cursor->getData().print();

        cursor = cursor->getNext();
    }
}

/**
 * @brief Deletes the desired element
 *
 *		This function deletes an element of the list specified by the user. This is done via search by MatNr.
 *		If the list contains the given student with that MatNr, his/her data is saved to be displayed to the
 *		user. If the element was the head (tail) of the list, the new head (tail) should be the next (prev) element
 *		of the previous head (tail) and the prev (next) pointer of the next (prev) element must be set to be the
 *		prev (next) pointer of the deleted element. In the general case of the deleted element being somehwere in the
 *		middle of the list the next and prev pointers are reset accordingly to retain links.
 *
 * @return bool True if element found and deleted False if not found or list empty
 */
bool List::delete_element(const unsigned int searchMatNr, Student& delElem)
{
    ListElem* cursor = head;

    while (cursor != NULL)
    {
		Student currStudent = cursor->getData();
		if (currStudent.getMatNr() == searchMatNr)
		{
			delElem = currStudent; //save for display in main

			/*
			 * Resetting prev and next pointers to restore the double links in the list
			 */
			if (cursor == head) //special case
			{
				head = cursor->getNext();
				cursor->getNext()->setPrev(cursor->getPrev());
			}
			else if (cursor == tail) //special case
			{
				cursor->getPrev()->setNext(cursor->getNext());
				tail = cursor->getPrev();
			}
			else //general case
			{
				cursor->getPrev()->setNext(cursor->getNext());
				cursor->getNext()->setPrev(cursor->getPrev());
			}

			delete cursor; //deleting the found element
			return true;
		}
        cursor = cursor->getNext();
    }
    return false;
}

/**
 * @brief Enqueue an element at the end of the list (tail).
 *
 * 		This function gets a new element given by the user and enques it at the end of the list (tail).
 * 		If the list is not empty:
 * 		1) The tail element's next pointer is set to the address of the new element.
 * 		2) The new element's prev pointer is set to the tail of the list.
 * 		3) The tail pointer itself is changed to the new element, as now that is the new end of the queue.
 *
 * @param pData The @ref Student to be added.
 * @return void
 */
void List::enqueue_tail(const Student &pData)
{
    ListElem* new_element = new ListElem(pData, NULL, NULL); //Data = pData, next = Null, prev = Null

    if (tail == NULL)// list empty?
    {
        tail = new_element;
    }
    else
    {
    	tail->setNext(new_element); //new elem must be next to tail
        new_element->setPrev(tail); //tail must be prev to new elem
    }

    tail = new_element;
}
