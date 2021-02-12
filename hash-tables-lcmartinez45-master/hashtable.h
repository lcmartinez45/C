/*
 * File: hashtable.h
 * Author: Lillian Martinez
 *
 * Create a Hash Table class/object with our standard struct
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "data.h"
#include "linkedlist.h"
#define ARRAY_SIZE 15

# include <string>
#include <iostream> // cout, endl
using std::cout;
using std::endl;


class HashTable {
public:
    HashTable();
    ~HashTable();

    bool insertEntry(int id, string data);
    string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();
    void clear();

private:
    int count;
    int hash(int);
    LinkedList*list[ARRAY_SIZE];
};
#endif /* HASH_TABLE_H */