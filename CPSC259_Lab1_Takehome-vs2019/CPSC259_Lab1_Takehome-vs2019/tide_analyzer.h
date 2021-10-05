/*
File:         tide_analyzer.h
Purpose:      Contains prototypes
Author:			  Your names
Student #s:		12345678 and 12345678
CS Accounts:  a1a1 and b2b2
Date:				  Add the date here
*/

/********************************************************************
YOU MAY EDIT THIS FILE (BUT YOU DON'T NEED TO)
******************************************************************/

#pragma once

/* Insert function prototypes here */
FILE* open_file(FILE* file_pointer, char* fileName, char* mode);
void process_file(double array_to_populate[], FILE* pointer_to_data_file);
void run_analysis();
