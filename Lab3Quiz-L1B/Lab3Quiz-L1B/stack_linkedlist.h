/*
 * File:           stack_linkedlist.h
 * Purpose:        CPSC 259 In-Lab Quiz 3
                   Contains the definition of a Stack ADT built on
                   a singly-linked list
                   THIS FILE WILL NOT BE SUBMITTED
                   DO NOT MAKE OTHER CHANGES TO THIS FILE
 */

#pragma once

struct Node
{
  char data;
  struct Node* next;
};

typedef struct {
  struct Node* top;
} Stack_list;

/*
 * Initializes a new stack_list by setting its top to NULL
 * PARAM:     Stack*     --  a pointer to the stack
 * POST:      stack's top points to NULL
 */
void initialize_list( Stack_list* stack );

/*
 * States whether the stack is empty or not
 * PARAM:     Stack*     --  a pointer to the stack
 *
 * RETURN:    1 if the stack is empty and 0 otherwise
 */
int isEmpty_list( Stack_list* stack );

/*
 * Adds a new item to the stack
 * PARAM:     Stack*     --  a pointer to the stack
 * PARAM:     char       --  the character to be added
 *
 * RETURN:    1 if the item was successfully added and 0 otherwise
 */
int push_list( Stack_list* stack, char value );

/*
 * Returns the current top of the stack
 * PARAM:     Stack*     --  a pointer to the stack
 *
 * RETURN:    the char on top of stack or NULL if it is empty
 */
char peek_list( Stack_list* stack );

/*
 * Removes an item from the top of the stack
 * PARAM:     Stack*     --  a pointer to the stack
 *
 * RETURN:    1 if the item was successfully removed and 0 otherwise
 */
int pop_list( Stack_list* stack );
