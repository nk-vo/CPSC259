/*
 File:           quiz2-L1B.c
 Purpose:	       CPSC259 In-lab quiz 2
 Author:         Nick Vo
 Student Number: 11056892
 CS Account:     oxygen16@students.cs.ubc.ca
 Date:		     Oct 5, 2020
*/

 /* Preprocessor directives */
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

#include "quiz2-L1B.h"

/*
 * Determines the number of times the specified search character
 * appears in the specified DNA segment, and replaces each instance with the
 * specified replacement nucleotide.
 * PARAM: count, a pointer to an int
 * PARAM: segment, an array of char (a string)
 * PARAM: search_string, an array of char (a string)
 * PRE:   count is a pointer to an int
 * POST:  count stores the numbers of replacements made.
 * POST:  every 'A' (find_me) in the sequence has been replaced with a 'C' (replacement)
 */
void string_fun(int* count, char* segment, char find_me, char replacement)
{
	*count = 0;
	int size = strlen(segment);
	for (int i = 0; i < size; i++) {
		if (segment[i] == find_me) {
			segment[i] = replacement;
			*count += 1;
		}
	}
}