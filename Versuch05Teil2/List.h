/**
 * @file List.h
 * content: linked list data structure
 */
 
 /*
  * Diese Datei gehört nicht zu Versuch05Teil, sondern wird in Versuch05Teil02 benötigt
  */
 

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include "Student.h"
#include "ListElem.h"

/**
 * @brief doubly linked list data structure
 */
class List
{
private:
    ListElem* head;                                         ///< pointer to the first list element
    ListElem* tail;                                         ///< pointer to the last list element
public:
    List();                                                 ///< constructor with pointer initialisation
    void enqueue_head(const Student &pData);
    bool dequeue(Student& pData);
    void print_forwards();
    void print_backwards();
    bool delete_element(const unsigned int searchMatNr, Student& delElem);
    void enqueue_tail(const Student &pData);
};

#endif /*LIST_H_*/
