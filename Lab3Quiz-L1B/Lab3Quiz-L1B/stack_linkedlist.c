/*
 * File:           stack_linkedlist.c
 * Purpose:        CPSC 259 In-Lab Quiz 3
 *                 Contains the implementation of a Stack ADT built on
 *                 a singly-linked list
 *                 THIS FILE WILL NOT BE SUBMITTED
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack_linkedlist.h"

#define TRUE 1
#define FALSE 0

void initialize_list( Stack_list* stack )
{
	stack->top = NULL;
}

int isEmpty_list( Stack_list* stack )
{
  if ( stack->top == NULL )
	{
    return TRUE;
	}
	else
  {
		return FALSE;
	}
}

int push_list( Stack_list* stack, char value )
{
    struct Node* new_node = ( struct Node* ) malloc ( sizeof( struct Node ) );
    if (new_node == NULL)
    {
      return FALSE;
    }
    new_node->data = value;
    new_node->next = stack->top;
    stack->top = new_node;
    return TRUE;
}

char peek_list( Stack_list* stack )
{
  if ( !isEmpty_list( stack ) )
	{
    return stack->top->data;
  }
  else
  {
    return NULL;
  }       
}

int pop_list( Stack_list* stack )
{
  if ( !isEmpty_list( stack ) )
  {
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    temp = NULL;
    return TRUE;
  }
  return FALSE;
}
