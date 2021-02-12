/*
 * File: hashtable.cpp
 * Author: Lillian Martinez
 *
 * Create a Hash Table class/object with our standard struct
 */

#include "hashtable.h"

HashTable::HashTable(){
    count=0;

    for(int i=0;i<ARRAY_SIZE;i++){
        list[i]=nullptr;
    }
}


HashTable::~HashTable(){
    clear();
}


bool HashTable::insertEntry(int id, string data){
    bool insert = false;

    if (id > 0) {
        int position = this->hash(id);
        if (!list[position]) {
            list[position] = new LinkedList;
        }
        insert = list[position]->addNode(id, data);
    }
    if (insert) count++;
    return insert;
}


string HashTable::getData(int id) {
    string dataString = " ";
    bool success = false;
    Data*myData = new Data;
    int position = hash(id);

    if(id > 0 && list[position]){
        success = list[position]->getNode(id,myData);
    }
    if(success){
        dataString = myData->data;
    }
    return dataString;
}


bool HashTable::removeEntry(int id) {
    bool del = false;
    int position = this->hash(id);

    if(list[position]){
        if(list[position]->getCount()==1 && list[position]->exists(id)){
            delete list[position];
            list[position] = NULL;
            del = true;
        }
        else if(list[position]->exists(id)){
            del = list[position]->deleteNode(id);
        }
        if(del){
            count--;
        }
    }else{
        del = false;
    }
    return del;
}


// return the number of total entries currently in the hash table
int HashTable::getCount(){
    return count;
}


void HashTable::printTable() {
    for (int i = 0; i < ARRAY_SIZE; i++){
        cout << "Entry " << i+1 << ": ";

        if(!list[i]){
            cout << "EMPTY";
        }
        else{
            list[i]->printList();
        }
        cout << endl;
    }
}

void HashTable::clear() {
    for(int i = 0; i < ARRAY_SIZE; i++){
        if(list[i]){
            delete list[i];
        }
    }
}

int HashTable::hash(int id){
    return id % ARRAY_SIZE;
}