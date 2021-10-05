/*
 File:         linkedlist.c
 Purpose:      Implements the linked list functions whose prototypes
               are declared in the linked_list.h header file
 Author:       Nick Vo and Qingyang Li
 Student #s:   11056892 and 19308576
 CS Accounts:  oxygen16@students.cs.ubc.ca and g2d3b@student.cs.ubc.ca
 Date:         Oct 31, 2020
 */
 
/* Preprocessor directives */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

/******************************************************************
 PLEASE EDIT THIS FILE

 Comments that start with // should be replaced with code
 Comments that are surrounded by * are hints
 ******************************************************************/

/*
 Returns a pointer to a new, empty linked list of struct node.
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    A pointer to a new, empty linked list of struct node (NULL)
 */
struct node * create_linked_list()
{
    struct node* next = NULL;
    return next; // return NULL linked-list
}

/*
 Returns a dynamically allocated struct node that contains the specified
 struct airplane.  The node's next pointer doesn't point to anything
 e.g., it is equal to NULL.
 PARAM:     plane, a struct airplane
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    A pointer to a dynamically allocated struct node a) that contains
            the specified struct airplane, and b) whose next pointer points to NULL
 */
struct node * create_node(struct airplane plane)
{
	// Insert your code here
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->plane = plane; // pointers that contains struct airplane
    ptr->next = NULL; // next node is NULL
    // replace this line with something appropriate
    return ptr;
}

/*
 Prepends a struct node passed as a parameter to the list passed as a
 parameter, and returns a pointer to the result.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     new_node is a pointer to a struct node
 PRE:       new_node is not null
 POST:      The specified struct node is added to the beginning of the list
            and its next pointer points to the node that used to be first
 RETURN:    A pointer to a linked list which contains all of the nodes
            of the list passed as a parameter, plus a prepended node
 */
struct node * prepend_node(struct node * list, struct node * new_node)
{
    new_node->next = list; // list is added after new_node
    list = new_node; // list become NEW new_node

    // replace this line with something appropriate
    return list;
}

/*
 Deletes the first struct node in the specified list, and returns a pointer to
 the shortened list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL
 POST:      The list passed as a parameter has one fewer node, and the dynamically
            allocated memory which contained that removed node has been freed
 RETURN:    IF the list is empty
            THEN NULL
            ELSE a pointer to the shortened list
 */
struct node * delete_node(struct node * list)
{
	// Insert your code here
    if (list) {
        struct node* ptr;
        ptr = list;
        list = list->next; // list loses its first node
        free(ptr); // erase first node
    }
    return list;
}

/*
 Returns the number of nodes in the specified linked list of struct node.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    The length of the specified list, an int
 */
int get_length(struct node * list)
{
	// Insert your code here
    int count = 0;
    while (list) {
        count++;
        list = list->next; // list move to next node
    }
    // replace this line with something appropriate
    return count;
}

/*
 Deletes an entire list.  This function iterates along a list and deallocates the
 memory containing each struct node.  
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      The memory containing all of the nodes in the list has been freed
 RETURN:    an empty list (NULL)
 */
struct node * delete_list(struct node * list)
{
	// Insert your code here
    struct node* ptr;
    if (list) {
        ptr = list;
        while (ptr) {
            list = delete_node(ptr); // delete first node of list
            ptr = list;              // ptr equal to the new first-node-deleted list 
        }
    }

    // replace this line with something appropriate
    return list;
}

/*
 Prints the data stored in a node.  For the struct airplane in the node,
 prints the fields on separate lines.  For each field, prints the field name
 and the field value.  For the pointer, prints "Link = NULL\n" if the pointer points
 to null, else prints "Link points to address xxx\n", where xxx is the pointer address
 in hexademical.
 If node_to_print is NULL, prints "The node is empty\n".
 PARAM:     node_to_print is a pointer to a (possibly null) struct node
 PRE:       NULL (no pre-conditions)
 POST:      Information about node_to_print has been printed to standard output
 RETURN:    NULL
 */
void print_node(struct node * node_to_print)
{
	// Insert your code here
    struct node* ptr;
    ptr = node_to_print;
    if (node_to_print == NULL) { // check if node_to_print is empty
        printf("The node is empty\n");
        printf("Link = NULL\n");
    }
    else {
        printf("Link points to address: %p \n", node_to_print); // address of node_to_print
        // printing the content of node_to_print
        printf("Flight number: %d\n", ptr->plane.flight_number);
        printf("Flight number: %d\n", ptr->plane.flight_number);
        printf("Origin city: %s\n", ptr->plane.city_origin);
        printf("Destination city: %s\n", ptr->plane.city_destination);
        printf("Priority: %d\n", ptr->plane.priority);
        printf("Maximum speed (kph): %d\n", ptr->plane.maximum_speed_kph);
        printf("Cruising Altitude: %d\n", ptr->plane.cruising_altitude);
        printf("Plane capacity: %d\n", ptr->plane.capacity);
    }
}

/*
 Prints the data stored in all nodes in the specified list to print.
 For each node, prints the data inside the node the same way that it
 is printed by print_node.  If the list is empty, a suitable message
 is printed to standard output.
 PARAM:     node_to_print is a pointer to a (possibly empty) linked list of
            struct node
 PRE:       NULL (no pre-conditions)
 POST:      Information about list_to_print has been printed to standard output
 RETURN:    NULL
 */
void print_list(struct node * list_to_print)
{
	// Insert your code here
    struct node* ptr;
    ptr = list_to_print;
    while (ptr != NULL) {
        // printing the content of every nodes in list_to_print one by one
        print_node(ptr);
        ptr = ptr->next;
    }
}

/*
 Reverses a list. 
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      The order of the nodes in the list passed as a parameter has been
            reversed
 RETURN:    a list of struct node that is the reverse of the list passed as a
            parameter
 */
struct node * reverse(struct node * list)
{
	// Insert your code here
    struct node* prev = NULL;
    struct node* current = list;
    struct node* next = NULL;
    while (current) {
        next = current->next;
        // reverse current node pointer
        current->next = prev; 
        // move pointer one position ahead
        prev = current;
        current = next;
    }
    list = prev;
    // replace this line with something appropriate
    return list;
}

/*
 Removes every node from the list which contains an airplane destined for
 the city name passed in the second parameter.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     destination_city is a pointer to a null-terminated array of char
 PRE:       NULL (no pre-conditions)
 POST:      Any struct node in the list which contains an airplane struct
            destined for the destination_city is removed from the list, and
            the memory deallocated
 RETURN:    a list of struct node that does not contain any struct node that
            has an airplane destined for the destination_city
 */
struct node * remove_from_list(struct node * list, char * destination_city)
{
	// Insert your code here
    struct node* ptr;
    if (list == NULL) // check for empty list
        return NULL;
    if (list->plane.city_destination == destination_city) { // check for matching destination_city
        ptr = list->next;
        free(list); // remove match
        return ptr;
    }
    // goes back and remove matching destination_city if there are more matches
    list->next = remove_from_list(list->next, destination_city); 
    return list;
}

/*
 Returns a reference to the nth node (but does not remove it ) in the
 specified list.  If the list is too short, returns NULL.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     ordinality is an integer
 PRE:       ordinality > 0
 POST:      NULL (no side-effects)
 RETURN:    IF ordinality <= length of list
            THEN a pointer to the nth node
            ELSE NULL
 */
struct node * retrieve_nth(struct node * list, int ordinality)
{
	// Insert your code here
    int count = 1;
    struct node* ptr = list;
    if (ordinality <= get_length(ptr) && ptr) {
        while (ptr) {
            if (count == ordinality)
                return ptr; // return node at desired location
            count++;
            ptr = ptr->next; // move to next node if not at desired node
        }
    }
    else
        return NULL;
}

/*
 Inserts the specified node into the specified list of nodes at the specified
 ordinality.  For example, if ordinality = 1, this is a simple prepend_node
 operation.  If ordinality = 3, then when this function is finished, the third
 node in the list will be the node_to_insert.  If the ordinality = the length
 of the list + 1, then the node_to_insert is appended to the end of the list.
 If the ordinality > 1 + length of the list, the function returns a pointer
 to the unchanged list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     ordinality is an integer
 PRE:       ordinality > 0
 PRE:       node_to_insert is NEVER a null (it is always a correct node pointer)
 POST:      NULL (no side-effects)
 RETURN:    IF ordinality <= length of list + 1
            THEN a pointer to the list which contains the node_to_insert in the
			correct location
            ELSE a pointer to the unchanged list
 */
struct node * insert_nth(struct node * list, struct node * node_to_insert, int ordinality)
{
	// Insert your code here
    struct node* ptr = (struct node*)malloc(2*sizeof(struct node));
    ptr = list;
    struct node* curr = NULL;
    int count = 0;
    int length = get_length(list);

    if (ordinality > length + 1)
        return list; // return unchanged list when ordinality is greater than list lenght + 1
    else {
        if (ordinality == 1)
            list = prepend_node(list, node_to_insert); // prepend list when ordinality = 1
        else {
            // curr is the node before the location where new node is being inserted
            curr = retrieve_nth(list, ordinality - 1); 
            node_to_insert->next = curr->next; // new node pointing to where curr is pointing
            curr->next = node_to_insert; // curr now points at new node
        }
        return list;
    }
    // replace this line with something appropriate
}