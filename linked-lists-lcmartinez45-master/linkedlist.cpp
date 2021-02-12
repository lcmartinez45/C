/*
 * File: linkedlist.cpp
 * Author: Lillian Martinez
 *
 * Create a fully functional doubly linked list class as described in class and in your text.
 * Create a linked list object from your class.
 * Demonstrate complete testing and full functionality of your linked list
 */

#include "linkedlist.h"

/*
 * ****************************************
 * Constructors / Destructors
 * ****************************************
 */

LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::~LinkedList() {
    clearList();
}

/*
 * ****************************************
 * Public
 * ****************************************
 */

/*
 * Pass this method an int id (positive integer) and some non-empty
 * string data. Return true or false to indicate success or failure. Nodes added must be in
 * ascending order of id. Memory for the node must be allocated inside the linked list object. This
 * method must do proper error checking. Ids cannot be negative and duplicate ids are not
 * allowed. The test code will test this.
*/
bool LinkedList::addNode(int id, string data){
    bool success;
    if(exists(id) || id < 0 || data == ""){
        success = false;
    }else{
        Node *current = head;
        Node *newNode = new Node;
        newNode->data.id = id;
        newNode->data.data = data;
        newNode->next = NULL;
        newNode->prev = NULL;

        //head cases
        if(current == NULL){
            head = newNode;
        }else if(newNode->data.id <= current->data.id){
            headNode(id, data, newNode, current);
        }else{
            //middle cases
            current = head;
            while(current != NULL){
                if(current->next != NULL && current->data.id < id && id < current->next->data.id){
                    middleNode(id, data, newNode, current);
                    //tail cases
                }else if(current->next == NULL && current->data.id < id){
                    tailNode(id, data, newNode, current);
                }else{
                    current = current->next;
                }
            }
        }
        success = true;
    }
    return success;
}

/*
 * Pass this method an id to delete. Return true or false to indicate success
 * or failure. Delete the memory the node was using.
 */
bool LinkedList::deleteNode(int id) {
    bool deleted = false;
    Node* current = head;
    Node* prv = NULL;

    while (current != NULL)
    {
        if (current->data.id == id)
        {
            if(prv != NULL)
            {
                prv->next=current->next;
            }
            else
            {
                head=current->next;
            }
            delete current;
            deleted = true;
        }
        prv=current;
        current=current->next;
    }
    return deleted;
}

/*
 * Pass this method an id and an empty struct Data passed by reference from main().
 * If the id is found, fill the empty struct Data passed by reference, and return true.
 * If the id is not found, place a -1 in the id and empty string in the string and return false
*/
bool LinkedList::getNode(int id, Data *returnData){
    bool success;
    Node *current = head;

    if(current == NULL){
        success = false;
    }else{
        while(current->next != NULL && current->data.id != id){
            current = current->next;
        }
        if(current->data.id != id){
            returnData->id =  -1;
            returnData->data = "";
            success = false;
        }else{
            returnData->id = current->data.id;
            returnData->data = current->data.data;
            success = true;
        }
    }
    return success;
}

/*
 * Will print out the entire list in order either forward or backward
 * based on the bool passed in. Make the bool default to false (forward).
 */
void LinkedList::printList(bool print){
    Node *current = head;

    if(!print){
        while(current != NULL){
            cout << current->data.id << " : " << current->data.data << endl;
            current = current->next;
        }
    }else{
        while (current->next != NULL) {
            current = current->next;
        }
        while(current != NULL){
            cout << current->data.id << " : " << current->data.data << endl;
            current = current->prev;
        }
    }
}

/*
 * Get a count of the nodes in the list. You must calculate count on the fly each
 * time this is called. You may not maintain a count variable.
 */
int LinkedList::getCount(){
    Node *current = head;
    int count = 0;

    if(head != NULL){
        count = 1;

        while ((current = current->next)){
            count++;
        }
    }
    return count;
}

// Resets the linked list, deletes all allocated memory and sets head = NULL.
bool LinkedList::clearList(){
    bool clear = false;
    Node *current, *temp;
    current = head;

    // Go through the list and delete all nodes
    while (current != NULL) {
        temp = current->next;
        delete(current);
        current = temp;
        clear = true;
    }
    delete head;
    head = NULL;
    return clear;
}

// Checks to see if an id exists in the list.
bool LinkedList::exists(int id){
    bool found = false;
    Node *current = head;

    while(current != NULL && !found){
        if(id == current->data.id){
            found = true;
        }
        current = current->next;
    }
    return found;
}

/*
 * ****************************************
 * Private
 * ****************************************
 */

 //Private Helper function: adding node as head node
void LinkedList::headNode(int id, string data, Node *newNode, Node *current) {
    newNode->next = current;
    current->prev = newNode;
    newNode->prev = NULL;
    head = newNode;
}

//Private Helper function: adding node as middle node
void LinkedList::middleNode(int id, string data, Node *newNode, Node *current) {
    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;
    newNode->next->prev = newNode;
}

//Private Helper function: adding node as tail node
void LinkedList::tailNode(int id, string data, Node *newNode, Node *current) {
    newNode->prev = current;
    current->next = newNode;
}