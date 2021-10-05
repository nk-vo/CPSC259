/* File:        main.c
 * Author:      (your names here)
 * Student IDs: (your student numbers here)
 * Description: Main driver and test cases for CPSC 259 Lab 5 quiz
 *
 *    DO NOT MODIFY OR SUBMIT THIS FILE
 */

/* Preprocessor directives */
#include <stdio.h>
#include <stdlib.h>
#include "quiz5-L1B.h"

/* Function prototypes */
void run_test(int testnum, int* arr, int size);

/*
 Main function drives the program.
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    IF the program exits correctly
            THEN 0 ELSE 1
*/
int main(void)
{
	int size1 = 2;
	int size2 = 2;
	int size3 = 5;
	int size4 = 7;
	int size5 = 8;
	int size6 = 12;


	/*  Some arrays to test */
	int mergesort_list1[] = { 5, 8 };
	int mergesort_list2[] = { 4, 2 };
	int mergesort_list3[] = { 2, 6, 6, 6, 9 };
	int mergesort_list4[] = { 3, 6, 9, 8, 10, 98, 99 };
	int mergesort_list5[] = { 3, 4, 12, 5, 8, 9, 10, 11 };
	int mergesort_list6[] = { -4, -17, 3, 0, 12, 13, 22, 18, 55, 61, 78, 73 };

	run_test(1, mergesort_list1, size1);

	run_test(2, mergesort_list2, size2);

	run_test(3, mergesort_list3, size3);

	run_test(4, mergesort_list4, size4);

	run_test(5, mergesort_list5, size5);

	run_test(6, mergesort_list6, size6);

	system("pause");
	return 0;
}

void run_test(int testnum, int* arr, int size)
{
	int result;
	printf("Test %d:\n", testnum);
	printf("Array contents: ");
	print_array(arr, size);
	result = valid_split(arr, size);
	if (result == 1)
		printf("Array is ready to be merged.\n");
	else if (result == 0)
		printf("Array is NOT ready to be merged.\n");
	else
		printf("I don't know if the array is ready to be merged.\n");
	printf("\n");
}