/*
 File:            quiz3-L1B.c
 Purpose:         CPSC259 In-lab quiz 3
                  SUBMIT ONLY THIS FILE
 Author:          Nick Vo
 Student Number:  11056892
 CS Account:      oxygen16
 Date:            October 26, 2020
 */


/* Preprocessor directives */	
#include <string.h>
#include "stack_linkedlist.h"
#include "quiz3-L1B.h"

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
int is_balanced ( const char * string_to_test )
{
	/* Variables (don't declare any more!) */
	Stack_list stack;
	int length = strlen( string_to_test );
	int i = 0;
	initialize_list( &stack );
	while (&string_to_test[i]) {
		if (&string_to_test[i] == '(')
			push_list(&stack, string_to_test[i]);
		if (&string_to_test[i] == ')') {
			if (&stack == NULL)
				return 0;
			else if (!(&stack.top == '(' && string_to_test[i] == ')'))
				return 0;
		}
		pop_list(&stack);
		i++;
	}
	if (&stack == NULL)
		return 1;
	else
		return 0;
}
