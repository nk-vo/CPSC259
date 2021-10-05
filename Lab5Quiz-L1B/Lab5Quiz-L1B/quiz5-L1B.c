/* File:        quiz5-L1B.h
 * Author:      Nick Vo
 * Student IDs: 11056892
 * Description: Function implementation for CPSC 259 Lab 5 quiz
 *
 *    COMPLETE THE REQUIRED FUNCTION IMPLEMENTATION
 *    AND SUBMIT THIS FILE
 */

#include <stdio.h>
#include <stdlib.h>
#include "quiz5-L1B.h"

// Function:  display_array
//
// Sample output:
//       3     6     9     8    10    98    99
//
// PARAM:  arr - an array of integers to be displayed
// PARAM:  size - the number of actual elements in the array
//               (size >= 1)
// RETURN: nothing
void print_array(int* arr, int size)
{
  int k;

  for (k = 0; k < size; k++)
    printf("%5d\t", arr[k]);

  printf("\n");
}

// Check whether the input array which has supposedly just
// returned from the two recursive calls of merge sort,
// is ready to be have its left and right halves merged.
//
// In the case of an odd array size, assume that the left
// half of the array contains the greater number of elements.
//
// PARAM: arr - the input array
// PARAM: size - the number of actual elements in the array
//               (size >= 1)
// RETURN: 1 if the contents of arr are consistent with having
//         completed the two recursive calls of merge sort,
//         0 otherwise.
int valid_split(int* arr, int size)
{
  // replace the line below with your completed implementation
    int left;
    int right = size / 2;
    int prev = 0;
    if (size == 1)
        return 1;
    if (size % 2 != 0)
        left = right + 1;
    else
        left = right;
    for (int i = 0; i < left; i++) {
        if (arr[i] < prev)
            return 0;
        prev = arr[i];
    }
    prev = 0;
    for (int i = 0; i < right; i++) {
        if (arr[i + left] < prev)
            return 0;
        prev = arr[i];
    }
    return 1;
}