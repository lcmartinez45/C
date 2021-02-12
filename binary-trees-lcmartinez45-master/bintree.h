/*
 * File: bintree.h
 * Author: Lillian Martinez
 *
 * Create a Binary Search Tree object that will work with the usual
 * struct data type
 */

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

# include "data.h"
# include <iostream>
# include <algorithm>
# include <iomanip>

using std::string;
using std::max;
using std::cout;
using std::endl;

class BinTree{
public:

    BinTree();
    ~BinTree();

    bool addNode(int, string);
    bool removeNode(int);
    void clear();
    bool getNode(Data*, int);
    int getHeight();
    int getCount();
    bool getRootData(Data*);
    bool contains(int);
    bool isEmpty();
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();
    void displayTree();

private:

    DataNode*root;
    int count;
    DataNode *searchMin(DataNode *temproot);

    // Overload functions for recursion
    bool addNode(DataNode*, DataNode**);
    DataNode*removeNode(int, DataNode*);
    void clear (DataNode*);
    bool getNode(Data*, int, DataNode*);
    int getHeight(DataNode*);
    bool contains(int, DataNode*);
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);

};

#endif /* BINTREE_BINTREE_H */

