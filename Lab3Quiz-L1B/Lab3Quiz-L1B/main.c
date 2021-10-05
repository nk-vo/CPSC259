/*
 File:            main.c
 Purpose:         CPSC259 In-lab quiz 3
 Author:          Your Name
 Student Number:  12345678
 CS Account:      a1a1
 Date:            Add the date here
 */


 /* Preprocessor directives */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_linkedlist.h"
#include "quiz3-L1B.h"

/*
 * Main function drives the program.
 * PRE:       NULL (no pre-conditions)
 * POST:      NULL (no side-effects)
 * RETURN:    IF the program exits correctly
 *            THEN 0 ELSE 1
 */
int main(void)
{
	/* Variable list */
	char* test_string_one = "Parentheses may be nested (with one set (such as this) \
		                      inside another set). This is not commonly used in formal writing \
							  (though sometimes other brackets (especially parentheses) will be \
							  used for one or more inner set of parentheses (in other words, secondary \
							  (or even tertiary) phrases can be found within the main sentence)).";

	char* test_string_two = "(DEFINEQ((FACTORIAL \
								(LAMBDA (N) \
								(COND ((ZEROP N) 1)) \
								(T (TIMES N (FACTORIAL (SUB1 N))))))))"; // Should pass

	char* test_string_three = "()()()(())()(()())()(())((())"; // Should fail

	/* Code that tests your function.  You don't need to write more tests. */
	printf("test_string_one is %sbalanced.\n", (is_balanced(test_string_one) ? "" : "not "));
	printf("test_string_two is %sbalanced.\n", (is_balanced(test_string_two) ? "" : "not "));
	printf("test_string_three is %sbalanced.\n", (is_balanced(test_string_three) ? "" : "not "));

	system("pause");
	return 0;
}