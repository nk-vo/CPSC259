/*
File:           quiz1-L1B.c
Purpose:        Implementation of submissible functions for CPSC259 in-lab quiz 1
                COMPLETE THE IMPLEMENTATIONS IN THIS FILE
Author:         Your Name
Student Number: 12345678
CS Account:     a1a1a
Date:           Add the date here
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "quiz1-L1B.h"

#define BUFFERLINESIZE      32    // maximum length of line in file
#define VALUES_PER_LINE     3
#define VALUES_IN_FILE      18

/*
Runs the steps of the main program logic.
PRE:       NULL (no pre-conditions)
POST:      NULL (no side-effects)
PARAMS:    filename is the name of a file in the same directory
RETURN:    the average computed from get_average
*/
double process(char* filename)
{
  /* Variables */
  double    readings[VALUES_IN_FILE];
  char      line_buffer[BUFFERLINESIZE];
  FILE*     file_pointer = NULL;
  int       i = 0;
  double    average = 0.0;

  /* Opens data file for reading */
  fopen_s(&file_pointer, filename, "r"); // USE THIS LINE FOR VISUAL STUDIO
  // file_pointer = fopen(filename, "r"); // USE THIS LINE FOR GRADESCOPE

  /* Copies the file, one line at a time, to a line buffer using fgets in a while loop */
  // INSERT YOUR CODE HERE

  /* Uses sscanf inside the loop to copy the integer in each line to a cell in the readings array */
  // INSERT YOUR CODE HERE

  /* If the file pointer does not equal NULL THEN closes the pointer */
  if (file_pointer != NULL)
    fclose(file_pointer);

  /* Finds the average of the integers in the readings array */
  // INSERT YOUR CODE HERE

  /* Prints your result here */
  // INSERT YOUR CODE HERE
  
  /* Return the computed average */
  return average;
}

/*
Returns the average value of the elements in the array
PRE:       array_length is the correct length of the array
POST:      NULL (no side-effects)
RETURN:    the average (a double) of the elements in the array
*/
double get_average(double array[], int array_length)
{
  // INSERT YOUR CODE HERE (REPLACE THIS LINE)
  return 0.0;
}