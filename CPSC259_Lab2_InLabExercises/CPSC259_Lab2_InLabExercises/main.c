/*
 File:				main.c
 Purpose:			Driver for lab 2 in-lab.
              You may add your own function calls for testing.
 Author:			Your names
 Student #s:	12345678 and 12345678
 CS Accounts:	a1a1 and b2b2
 Date:				Add the date here
 */

#include "lab2_in-lab_exercises.h"
#include <stdlib.h>

#define SMALL_ARRAY 25

 /*
  Main function drives the program.  Every C program must have one
  main function.  A project will not compile without one.
  PRE:    NULL (no pre-conditions)
  POST:	 NULL (no side-effects)
  RETURN: IF the program exits correctly
      THEN 0 ELSE 1
  */
int main(void)
{
  /* We start every function with a list of variables */
  int i = 0;
  int* pointer_to_some_ints;

  /* Then we do things, like invoke functions and assigns their return
     values to variables.  You don't need to change these two lines */
  pointer_to_some_ints = (int*)malloc(SMALL_ARRAY * sizeof(int));
  for (i = 0; i < SMALL_ARRAY; ++i) {
    *(pointer_to_some_ints + i) = i;
  }

  // You can set a breakpoint here later in order to test the debugger 'watch' tab for pointers

  /* The system command forces the system to pause before closing executable window */
  system("pause");
  return 0;
}