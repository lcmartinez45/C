/*
 * File: bintree.cpp
 * Author: Lillian Martinez
 *
 * Create a Binary Search Tree object that will work with the usual
 * struct data type
 */

#include "bintree.h"

BinTree::BinTree(){
    root = NULL;
    count = 0;
}

BinTree::~BinTree(){
    clear();
}

/*
 *************************************************************
 * Public
 *************************************************************
 */
bool BinTree::addNode(int id, string data){
    bool success = false;
    DataNode * newNode = new DataNode;
    newNode->data.id = id;
    newNode->data.information = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (addNode(newNode, &root) == true) {
        success = true;
    }
    return success;
}

bool BinTree::removeNode(int id){
    bool success = false;
    int tempCount = count;
    root = removeNode(id, root);
    if (tempCount > count) {
        success = true;
    }
    return success;
}

void BinTree::clear(){
    clear(root);
    count = 0;
}

bool BinTree::getNode(Data*tempData, int id){
    bool success = false;
    if (getNode(tempData, id, root) == true) {
        success = true;
    }
    return success;
}

int BinTree::getHeight(){
    return getHeight(root);
}

int BinTree::getCount(){
    return count;
}

bool BinTree::getRootData(Data*tempData){
    bool success = false;
    if (root != NULL) {
        tempData->id = root->data.id;
        tempData->information = root->data.information;
        success = true;
    }
    else {
        tempData->id = -1;
        tempData->information = "";
    }
    return success;
}

bool BinTree::contains(int id){
    bool success = false;
    if (contains(id, root) == true) {
        success = true;
    }
    return success;
}

bool BinTree::isEmpty(){
    bool empty = false;
    if (count == 0) {
        empty = true;
    }
    return empty;
}

void BinTree::displayPreOrder(){
    displayPreOrder(root);
}

void BinTree::displayPostOrder(){
    displayPostOrder(root);
}

void BinTree::displayInOrder(){
    displayPostOrder(root);
}

void BinTree::displayTree(){
    cout << "DISPLAY TREE" << endl;
    cout << "====================" << endl;
    if (isEmpty()) {
        cout << "Tree is empty " << endl;
    }
    else {
        cout << "Tree is not empty " << endl;
    }
    cout << "Height: " << getHeight() << endl;
    cout << "Node count: " << getCount() << endl;
    cout << "\nPre-order Traversal " << endl;
    cout << "====================" << endl;
    displayPreOrder();
    cout << "\nIn-order Traversal " << endl;
    cout << "====================" << endl;
    displayInOrder();
    cout << "\nPost-order Traversal " << endl;
    cout << "====================" << endl;
    displayPostOrder();
    cout << endl;
}


/*
 *************************************************************
 * Private
 *************************************************************
 */
bool BinTree::addNode(DataNode*newNode, DataNode**temproot){
    bool success = false;
    if ((*temproot) == NULL) {
        (*temproot) = newNode;
        success = true;
        count++;
    }
    else {
        if ((*temproot)->data.id > newNode->data.id) {
            success = addNode(newNode, &(*temproot)->left);
        }
        else if ((*temproot)->data.id < newNode->data.id) {
            success = addNode(newNode, &(*temproot)->right);
        }
    }
    return success;
}

DataNode* BinTree::removeNode(int id, DataNode*temproot){
    if (temproot != NULL) {
        if (temproot->data.id > id) {
            temproot->left = removeNode(id, temproot->left);
        }
        else if (temproot->data.id < id) {
            temproot->right = removeNode(id, temproot->right);
        }
        else {
            DataNode * temp;
            if (temproot->left == NULL) {
                temp = temproot->right;
                delete temproot;
                temproot = temp;
                count--;
            }
            else if (temproot->right == NULL) {
                temp = temproot->left;
                delete temproot;
                temproot = temp;
                count--;
            }
            else {
                temp = searchMin(temproot->right);
                temproot->data.id = temp->data.id;
                temproot->data.information = temp->data.information;
                temproot->right = removeNode(temp->data.id, temproot->right);
            }
        }
    }
    return temproot;
}

DataNode* BinTree::searchMin(DataNode* temproot) {
    while (temproot != NULL && temproot->left != NULL) {
        temproot = temproot->left;
    }
    return temproot;
}

void BinTree::clear(DataNode*temproot){
    if (temproot != NULL) {
        if (temproot->left != NULL) {
            clear(temproot->left);
        }
        if (temproot->right != NULL) {
            clear(temproot->right);
        }
        delete temproot;
    }
    root = NULL;
    count = 0;
}

bool BinTree::getNode(Data*tempData, int id, DataNode*temproot){
    bool success = false;
    if (temproot != NULL) {
        if (temproot->data.id == id) {
            tempData->id = temproot->data.id;
            tempData->information = temproot->data.information;
            success = true;
        }
        else if (temproot->data.id > id ) {
            success = getNode(tempData, id, temproot->left);
        }
        else if (temproot->data.id < id ) {
            success = getNode(tempData, id, temproot->right);
        }
    }
    return success;
}

int BinTree::getHeight(DataNode*temproot){
    int height = 0;
    if (temproot != NULL) {
        height = 1 + max(getHeight(temproot->left), getHeight(temproot->right));
    }
    return height;
}

bool BinTree::contains(int id, DataNode*temproot){
    bool success = false;
    if (temproot != NULL) {
        if (temproot->data.id == id) {
            success = true;
        }
        else if (temproot->data.id > id ) {
            success = contains(id, temproot->left);
        }
        else if (temproot->data.id < id ) {
            success = contains(id, temproot->right);
        }
    }
    return success;
}

void BinTree::displayPreOrder(DataNode* temproot) {
    if (temproot != NULL)
    {
        cout << temproot->data.id << " - " << temproot->data.information << endl;
        if (temproot->left != NULL) {
            displayPreOrder(temproot->left);
        }
        if (temproot->right != NULL) {
            displayPreOrder(temproot->right);
        }
    }
}

void BinTree::displayPostOrder(DataNode* temproot) {
    if (temproot != NULL)
    {
        if (temproot->left != NULL) {
            displayPostOrder(temproot->left);
        }
        if (temproot->right != NULL) {
            displayPostOrder(temproot->right);
        }
        cout << temproot->data.id << " - " << temproot->data.information << endl;
    }
}

void BinTree::displayInOrder(DataNode* temproot) {
    if (temproot != NULL)
    {
        if (temproot->left != NULL) {
            displayInOrder(temproot->left);
        }
        cout << temproot->data.id << " - " << temproot->data.information << endl;
        if (temproot->right != NULL) {
            displayInOrder(temproot->right);
        }
    }
}
