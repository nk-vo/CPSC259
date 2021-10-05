/*
 File:            quiz3-L1B.h
 Purpose:         CPSC259 In-lab quiz 3
                  THIS FILE WILL NOT BE SUBMITTED
                  DO NOT MAKE OTHER CHANGES TO THIS FILE
 Author:          Your Name
 Student Number:  12345678
 CS Account:      a1a1
 Date:            Add the date here
 */

#pragma once

 /*
  * Determines whether the string passed as a parameter contains balanced
  * parentheses.  Use a stack in your implementation.
  *
  * Reminder: parentheses are the symbols above the 9 and 0 on your keyboard.
  *
  * For example, the program should return 1 for strings like
  * "()", "(())”, "(()())", and 0 for strings like "(()".
  *
  * PARAM:  string_to_test, a pointer to an array of characters that terminates
  *         with a null character '\0'
  * PRE:    string_to_test points an array of char that terminates with '\0'
  * POST:   string_to_test is unchanged
  * RETURN: If string_to_test is balanced
  *         THEN RETURN 1
  *         ELSE RETURN 0
  */
int is_balanced(const char* string_to_test);