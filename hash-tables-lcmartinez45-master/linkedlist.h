/*
 * File: linkedlist.h
 * Author: Lillian Martinez
 *
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include "data.h"

# include <iomanip>
# include <string>
# include <stdlib.h>
# include <new>
#include <iostream> // cout, endl
using std::cout;
using std::endl;


class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    bool addNode(int, string); // accepts id and data, and inserts to the list in order
    bool deleteNode(int); // accepts an id and deletes the node
    bool getNode(int, Data*); // retrieves the data from a node from a given id
    void printList(); // prints forward (default) or backward
    int getCount(); // reports the count (dynamically)
    bool clearList(); // deallocates all nodes and sets head to NULL
    bool exists(int); // tests for the existence of a node based on a given id

private:
    Node *head; // initialized in the constructor to NULL, a pointer to the first node or NULL if the list is empty.
    void headNode(int id, string data, Node *newNode, Node *current); // helper function head
    void middleNode(int id, string data, Node *newNode, Node *current); // helper function middle
    void tailNode(int id, string data, Node *newNode, Node *current); // helper function tail
    bool findId(int, Node*); // helper function to see if an id exists
};
#endif /* LINKEDLIST_H */
