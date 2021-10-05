/*
File:              multmatrix.c
Purpose:           Exercises for CPSC259 lab 5
Author:			Nick Vo and Der-Chien Chang
Student #s:		11056892 and 96925458
CS Accounts:		oxygen16 and t7d3b
Date:				Nov 16, 2020
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"
#define  BUFSIZE 256


void printMatrix(mxArray* matrix);
int main(void) {
    /* Variables */
    Engine* ep = NULL; // A pointer to a MATLAB engine object
    mxArray* testArray = NULL, * result = NULL; // mxArray is the fundamental type underlying MATLAB data
    double time[3][3] = { { 1.0, 2.0, 3.0 }, {4.0, 5.0, 6.0 }, {7.0, 8.0, 9.0 } }; // Our test 'matrix', a 2-D array
    char buffer[BUFSIZE + 1];

    // Todo 3
    mxArray* matOne = NULL;
    mxArray* matTwo = NULL;
    mxArray* matThree = NULL;
    double matrixOne[3][3] = {
      {1.0, 4.0, 7.0},
      {2.0, 5.0, 8.0},
      {3.0, 6.0, 9.0}
    };
    double matrixTwo[3][3] = {
      {2.0, 3.0, 4.0},
      {2.0, 3.0, 4.0},
      {2.0, 3.0, 4.0}
    };

    /* Starts a MATLAB process */
    if (!(ep = engOpen(NULL))) {
        fprintf(stderr, "\nCan't start MATLAB engine\n");
        system("pause");
        return 1;
    }
    // Todo 2
    printf("*** TODO 2 ***");
    // Create 3x3 empty matrix 
    testArray = mxCreateDoubleMatrix(3, 3, mxREAL);

    // Copy the 'time' 2D array MATLAB 2D array, testArray
    memcpy((void*)mxGetPr(testArray), (void*)time, 9 * sizeof(double));

    // Putting variable into MATLAB engine, the copy does not need to be freed from memory
    if (engPutVariable(ep, "testArray", testArray)) {
        fprintf(stderr, "\nCannot write test array to MATLAB\n");
        system("pause");
        exit(1); // Same as return 1;
    }

    // using matlab engine to get eigenvalues
    if (engEvalString(ep, "testArrayEigen = eig(testArray)")) {
        fprintf(stderr, "\nError calculating eigenvalues\n");
        system("pause");
        exit(1); // Same as return 1;
    }

    // using the enginegetvariable to retrieve the eigenvector
    printf("\nRetrieving eigenvalues\n");
    if ((result = engGetVariable(ep, "testArrayEigen")) == NULL) {
        fprintf(stderr, "\nFail to retrieve eigenvalue vector\n");
        system("pause");
        exit(1); // Same as return 1;
    }
    else {
        size_t sizeOfResult = mxGetNumberOfElements(result);
        size_t i = 0;
        printf("The eigenvalues are:\n");
        for (i = 0; i < sizeOfResult; i++) printf("%f\n", mxGetPr(result)[i]);
    }

    // Todo 3
    printf("\n*** TODO 3 ***\n");
    // Initialize MATLAB variable
    matOne = mxCreateDoubleMatrix(3, 3, mxREAL);
    matTwo = mxCreateDoubleMatrix(3, 3, mxREAL);

    // Copy the 'time' 2D array MATLAB 2D array, testArray
    memcpy((void*)mxGetPr(matOne), (void*)matrixOne, 9 * sizeof(double));
    memcpy((void*)mxGetPr(matTwo), (void*)matrixTwo, 9 * sizeof(double));

    // Display matrix
    printf("Matrix one: \n");
    printMatrix(matOne);
    printf("Matrix two: \n");
    printMatrix(matTwo);

    // Place test array to MATLAB
    if (engPutVariable(ep, "Matrix One", matOne)) {
        fprintf(stderr, "\nCannot write matrix one to MATLAB \n");
        system("pause");
        exit(1); // Same as return 1;
    }
    if (engPutVariable(ep, "Matrix Two", matTwo)) {
        fprintf(stderr, "\nCannot write matrix two to MATLAB \n");
        system("pause");
        exit(1); // Same as return 1;
    }
    // Calculate matrix multiplication
    if (engEvalString(ep, "matrixProduct = matOne' * matTwo'")) {
        fprintf(stderr, "\nError calculating matrix product  \n");
        system("pause");
        exit(1);
    }

    // Put variable to MATLAB workspace
    printf("\nRetrieving product of two matrices\n");
    if ((result = engGetVariable(ep, "matrixProduct")) == NULL) {
        fprintf(stderr, "\nFailed to retrieve matrix product\n");
        system("pause");
        exit(1);
    }
    else {
        size_t sizeOfResult = mxGetNumberOfElements(result);
        printf("The matrix product is:\n");
        printMatrix(result);
    }

    // Ensure buffer is null terminated
    if (engOutputBuffer(ep, buffer, BUFSIZE)) {
        fprintf(stderr, "\nCan't create buffer for MATLAB output\n");
        system("pause");
        return 1;
    }
    buffer[BUFSIZE] = '\0';

    engEvalString(ep, "whos"); // whos is a handy MATLAB command that generates a list of all current variables
    printf("%s\n", buffer);

    // free memomy and close connection to MATLAB
    mxDestroyArray(testArray);
    mxDestroyArray(result);
    testArray = NULL;
    result = NULL;
    if (engClose(ep)) {
        fprintf(stderr, "\nFailed to close MATLAB engine\n");
    }

    system("pause"); // So the terminal window remains open long enough for you to read it
    return 0; // Because main returns 0 for successful completion
}

void printMatrix(mxArray* matrix) {
    size_t i, j;
    for (i = 0; i < 3; i++) {
        printf("");
        for (j = 0; j < 3; j++) printf("%12.6f", mxGetPr(matrix)[i * 3 + j]);
        printf("\n");
    }
}