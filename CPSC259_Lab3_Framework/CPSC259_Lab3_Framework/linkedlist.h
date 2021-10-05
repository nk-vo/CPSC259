/*
 File:         linkedlist.h
 Purpose:      Prototypes for a linked list implementation
 Author:       Your names
 Student #s:   19308576 and 12345678
 CS Accounts:  a1a1 and b2b2
 Date:         Add the date here
 */

#pragma once

/******************************************************************
 PLEASE EDIT THIS FILE

 Comments that start with // should be replaced with code
 Comments that are surrounded by * are hints
 ******************************************************************/

/* Insert your airplane structure here.  Use the correct types and names for the elements! */
struct airplane {
	// Add your member elements here
	int flight_number;
	char* city_origin;
	char* city_destination;
	int priority;
	int maximum_speed_kph;
	int cruising_altitude;
	int capacity;
};

/* Insert your node structure here.  Use the correct types and names for the elements! */
struct node {
	// Add your member elements here
	struct node* next;
	struct airplane plane;
};

/* Prototypes for in-lab functions (do not add anything here) */
struct node * create_linked_list();
struct node * create_node(struct airplane plane);
struct node * prepend_node(struct node * list, struct node * new_node);
struct node * delete_node(struct node * list);

/* Prototypes for take-home functions (do not add anything here) */
int get_length(struct node * list);
struct node * delete_list(struct node * list);
void print_node(struct node * node_to_print);
void print_list(struct node * list_to_print);
struct node * reverse(struct node * list);
struct node * remove_from_list(struct node * list, char * destination_city);
struct node * retrieve_nth(struct node * list, int ordinality);
struct node * insert_nth(struct node * list, struct node * node_to_insert, int ordinality);
