/*
 File:              pagerank.c
 Purpose:           Using matlab to calculate page ranks
 Author:			Nick Vo, Der-Chien Chang
 Student #s:		11056892 and 96925458
 CS Accounts:		oxygen16 and t7d3b
 Date:		        Nov 29, 2020
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"
#define  BUFSIZE 256
#define  WEB_FILE "web.txt"

/* Macro variables - for repetitive usage*/
#define eval(str) if (engEvalString(ep, str)) fprintf(stderr, "%s\n", "matlab error")
#define sq(x) x * x
#define end(x)  system("pause"); return x

/* Function prototypes */
int getNumOfLinks(FILE* webfile);
int charsInString(char* string, char sample);
double* parseMatrix(FILE* webfile, int size);
void printMatrix(mxArray* matrix, int size);
void printMatrixPtr(double* matrix, int size);
void rankpages(Engine* ep);
void printResult(Engine* ep);

int main(void) {
    /* Variables */
    FILE* web_file = NULL;  // a pointer to txt file
    Engine* ep = NULL; // A pointer to a MATLAB engine object
    mxArray* con_mat = NULL;
    double* connect_mat = NULL;
    int web_size;

    /* read text file */
    printf("Opening file...");
    if (fopen_s(&web_file, WEB_FILE, "r")) {
        fprintf(stderr, "Unable to open file: %s\n", WEB_FILE);
        end(1);
    }
    printf("Success\n");

    if (web_file) {
        // get size of matrix
        printf("Getting number of links...");
        web_size = getNumOfLinks(web_file);
        if (web_size <= 0) {
            printf("\nInvalid number of links \n");
            end(1);
        }
        else
            printf("%d web links found \n", web_size);

        // parse to 2D array
        printf("Parsing matrix to memory...");
        connect_mat = parseMatrix(web_file, web_size);
        printf("Success\n");

        // start matlab engine
        printf("Starting matlab engine...");
        if (!(ep = engOpen(NULL))) {
            fprintf(stderr, "\nCannot start MATLAB\n");
            end(1);
        }
        printf("Success\n");

        // create empty matrix with web_size dimension
        printf("Inserting matrix into MATLAB...");
        con_mat = mxCreateDoubleMatrix(web_size, web_size, mxREAL);

        // copy con_mat into memory
        memcpy(mxGetPr(con_mat), con_mat, sq(web_size) * sizeof(double));

        // copy matrix into MATLAB
        if (engPutVariable(ep, "con_mat", con_mat)) {
            fprintf(stderr, "\nCannot copy matrix into MATLAB\n");
            end(1);
        }
        printf("Success\n");

        // implementing 14 commands
        printf("Calculating...");
        rankpages(ep);
        printf("Success\n");

        // printing the result
        printResult(ep);

        // close MATLAB
        mxDestroyArray(con_mat);
        con_mat = NULL;
        if (engClose(ep)) {
            fprintf(stderr, "\nCannot close MATLAB\n");
        }
    }
    else {
        fprintf(stderr, "\nCannot open file\n");
        end(1);
    }

    // close file
    fclose(web_file);

    end(0);
}

/* The 14 matlab commands */
void rankpages(Engine* ep) {
    // transpose the matrix first
    eval("connectMat = connectMat'");

    // get size of matrix
    eval("dimension = size(connectMat, 1);");

    // get column sum
    eval("columnsums = sum(connectMat, 1);");
    eval("p = 0.85;");

    // *** get stochastic matrix
    // find non zero matrices
    eval("zerocolumns = find(columnsums ~= 0);");

    // generate sparse matrix with diagonal == inverse of each column sum
    eval("D = sparse(zerocolumns, zerocolumns, 1./columnsums(zerocolumns), dimension, dimension);");

    // multiply connectivity matrix with sparse matrix
    eval("stoMat = connectMat * D");

    // find zero clolumns of original connectivity matrix
    eval("[row, column] = find(columnsums == 0);");

    // finish up generating stochastic matrix
    eval("stoMat(:, column) = 1 ./ dimension;");

    // *** get transition matrix
    eval("Q = ones(dimension, dimension)");
    eval("transMat = p * stoMat + (1 - p) * (Q / dimension);");

    // get pagerank matrix
    eval("rank = ones(dimension, 1);");

    // multiply until rank remains constant
    eval("for i = 1:100 rank = transMat * rank; end");

    // normalize
    eval("rank = rank / sum(rank)");
}

/* return number of links in the connectivity matrix*/
int getNumOfLinks(FILE* webfile) {
    char line_buffer[BUFSIZE];

    // read the first line
    fgets(line_buffer, BUFSIZE, webfile);
    fseek(webfile, 0, SEEK_SET);

    // return length of line - total white space - 1
    return (int)strlen(line_buffer) - charsInString(line_buffer, ' ') - 1;
}

/* return number of character occurences in given string */
int charsInString(char* string, char sample) {
    int count;

    // while string[count] is not NULL
    // if string[count] is sample, count++ and move on to the next letter
    // if not, *string++ which is equivalent to count++ without incrementing count
    for (count = 0; string[count]; string[count] == sample ? count++ : *string++);
    return count;
}

/* returns a 1D pointer to the matrix of the parsed connect matrix */
double* parseMatrix(FILE* webfile, int size) {
    // for reading file
    char line_buffer[BUFSIZE];
    int row, column;
    double* webmatrix = NULL;

    // allocate memory for 1D array rep of 2D array
    webmatrix = malloc(sq(size) * sizeof(double));

    // copies web txt data to memory
    row = 0;
    while (fgets(line_buffer, BUFSIZE, webfile)) {
        for (column = 0; column < size; column++) {
            // column * 2 to account for whitespace
            webmatrix[row * size + column] = line_buffer[column * 2] - '0';
        }
        row++;
    }
    return webmatrix;
}

/* print matrix */
void printMatrix(mxArray* matrix, int size) {
    size_t i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) printf("%-8.4f", mxGetPr(matrix)[i * size + j]);
        printf("\n");
    }
}

/* print matrix pointer */
void printMatrixPtr(double* matrix, int size) {
    unsigned short int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) printf("%-8.4f", matrix[i * size + j]);
        printf("\n");
    }
}

/* retrieve vars from matlab and prints it */
void printResult(Engine* ep) {
    mxArray* result = NULL;
    size_t sizeOfResult = 0;
    size_t i = 0;

    // retrieve values
    if ((result = engGetVariable(ep, "rank")) == NULL) {
        fprintf(stderr, "failed to retrieve %s\n", "rank");
        return;
    }
    else {

        // print out line by line
        sizeOfResult = mxGetNumberOfElements(result);
        printf("\n\nNODE  RANK\n---   ----\n");
        while (i < sizeOfResult) {
            printf("%-5d ", i + 1);
            printf("%.4f\n", mxGetPr(result)[i++]);
        }
    }
}