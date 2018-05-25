/**
 * @file ListElem.cpp
 *
 * @brief ListElem Class methods
 */

#include "ListElem.h"

ListElem::ListElem(const Student &s, ListElem* const nextPointer, ListElem* const prevPointer):
    data(s), next(nextPointer), prev(prevPointer)
{
}

/**
 * @brief Setter method for the 'data' variable of the ListElem class
 *
 * @param data_in Student Information
 */
void ListElem::setData(const Student &data_in)
{
    data = data_in;
}

/**
 * @brief Setter method for the 'next' pointer of the ListElem class
 *
 * @param cursor Next pointer specified by the cursor
 */
void ListElem::setNext(ListElem* const cursor)
{
    next = cursor;
}

/**
 * @brief Setter method for the 'prev' pointer of the ListElem class
 *
 * @param cursor Prev pointer specified by the cursor
 */
void ListElem::setPrev(ListElem* const cursor)
{
    prev = cursor;
}

/**
 * @brief Getter method for the 'data' variable of the ListElem class
 *
 * @return data Student information
 */
Student ListElem::getData() const
{
    return data;
}

/**
 * @brief Getter method for the 'next' pointer of the ListElem class
 *
 * @return next Next Element pointer
 */
ListElem* ListElem::getNext() const
{
    return next;
}
/**
 * @brief Getter method for the 'prev' pointer of the ListElem class
 *
 * @return prev Previous Element pointer
 */
ListElem* ListElem::getPrev() const
{
    return prev;
}
