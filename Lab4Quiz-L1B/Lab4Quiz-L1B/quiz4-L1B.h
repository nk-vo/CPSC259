/*
 File:           quiz4-L1B.h
 Purpose:        Definitions for CPSC259 in-lab quiz 4
                 DO NOT MODIFY THIS FILE
                 THIS FILE WILL NOT BE SUBMITTED
 Author:         Your Name
 Student Number: 12345678
 CS Account:     a1a1
 Date:           Add the date here
 */

#pragma once

// Structure definition for a singly-linked list node
typedef struct Node {
  int data;
  struct Node* next;
} Node;

// Function to implement in quiz4-L1B.c
int equalLists(Node* list1, Node* list2);