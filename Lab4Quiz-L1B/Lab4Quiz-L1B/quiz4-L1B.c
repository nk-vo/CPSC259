/*
 File:           quiz4-L1B.c
 Purpose:        Implementation for CPSC259 in-lab quiz 4
                 COMPLETE THE REQUIRED FUNCTION RECURSIVELY
                 SUBMIT THIS FILE TO GRADESCOPE
 Author:         Nick Vo
 Student Number: 11056892
 CS Account:     oxygen16
 Date:           Nov 9, 2020
*/

/* Preprocessor directives */
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include "quiz4-L1B.h"

/*
 *  Recursively checks whether two lists have the same exact contents
 *
 *  PARAM:  the front of the first list to compare
 *  PARAM:  the front of the second list to compare
 *  RETURN: 1 if list1 and list2 contents are the same, and in the same order
 *          0 otherwise
 */
int equalLists(Node* list1, Node* list2)
{
    if (list1 == NULL && list2 == NULL)
        return 1;
    if ((list1 && !list2) || (!list1 && list2))
        return 0;
    if (list1->data != list2->data)
        return 0;
    return equalLists(list1->next, list2->next);
   
}