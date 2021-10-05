/*
File:           main.c
Purpose:        Driver for CPSC259 in-lab quiz 1
                DO NOT CHANGE THIS FILE
Author:         gctien
Student Number: 12345678
CS Account:     a1a1a
Date:           September 19, 2020
*/

#include <stdio.h>
#include <stdlib.h>

#include "quiz1-L1B.h"

#define FILE_NAME    "data.txt"

/*
Main function drives the program.
PRE:       NULL (no pre-conditions)
POST:      NULL (no side-effects)
RETURN:    IF the program exits correctly THEN 0 ELSE 1
*/
int main(void)
{
  // hand off the work to process(FILE_NAME)
  process(FILE_NAME);

  system("pause");
  return 0;
}