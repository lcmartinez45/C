/*
 * File: main.cpp
 * Author: Lillian Martinez
 *
 * Testing Hash Table class with linked list class
 */

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    // create your hash table object here
    HashTable hashtable;

    cout << "Hashtable" << endl;
    cout << "------------------" << endl;

    // show it is empty by calling getCount and printTable
    cout << "Total # of entries currently in the hash table: " << hashtable.getCount() << endl;
    cout << "\nTable " << endl;
    cout << "------------------" << endl;
    hashtable.printTable();

    // try and put ALL the data into the table and show what happens
    int tempId, idArray [25], count = 0, del = 0;
    string tempData;

    cout << "\nCreating hashtable " << endl;
    cout << "-----------------------------------------------------" << endl;

    for(int i = 0; i < testdatasize; i++){
        idArray[i] = tempId;
        tempId = ids[i];
        tempData = strs[i];
        cout << "INDEX [" << tempId%ARRAY_SIZE << "]: " << "ID -> " << tempId << ", DATA -> " << tempData << ": ";

        if(hashtable.insertEntry(tempId,tempData)){
            cout << "Successful!";
            count++;
        }else{
            cout << "Failed!";
        }
        cout << endl;
    }

    // return the number of total entries currently in the hash table
    cout << "Total # of entries currently in the hash table: " << hashtable.getCount() << endl;

    // continue using and testing your table, add and remove data, make more test data if you need to.
    cout << "\nGetting data from random IDs" << endl;
    cout << "-----------------------------------------" << endl;
    for(int i = 0; i < ARRAY_SIZE; i++){
        tempId = rand()%100;
        cout << "ID -> " << tempId << ", DATA -> " << hashtable.getData(tempId);
        cout << endl;
    }

    cout << "\nPrinting the hashtable" << endl;
    cout << "-----------------------------------------" << endl;
    hashtable.printTable();
    cout << "Total # of entries currently in the hash table: " << hashtable.getCount() << endl;

    cout << "\nRemoving data from random IDs" << endl;
    cout << "-----------------------------------------" << endl;
    for(int i = 0; i < ARRAY_SIZE; i++){
        tempId = rand()%100;
        cout << "ID -> " << tempId << ", Data -> " << hashtable.getData(tempId) << " : ";

        if(hashtable.removeEntry(tempId)){
            cout << "Successful!";
            del++;
        }else{
            cout << "Failed!";
        }
        cout << endl;
    }

    cout << "\nPrinting list after deletions" << endl;
    cout << "-----------------------------------------" << endl;
    hashtable.printTable();
    cout << "Total # of entries currently in the hash table: " << hashtable.getCount() << "\n";
    cout << "Total # of Deletions: " << del << endl;

    /*
    * Show test data
    */
    cout << "\nShowing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }

    cout << "\nGetting random data from test data" << endl;
    cout << "-----------------------------------------" << endl;
    for(int i = 0; i < testdatasize; i++){
        tempId = idArray[rand()%testdatasize];
        cout << "ID -> " << tempId << ", DATA -> " << hashtable.getData(tempId) << endl;
    }

    cout << "\nRemoving random data from test data" << endl;
    cout << "-----------------------------------------" << endl;
    for(int i = 0; i < testdatasize; i++){
        try{
            tempId = idArray[rand()%count];
            cout << "ID -> " << tempId << ", Data -> " << hashtable.getData(tempId) << " : ";

            if(hashtable.removeEntry(tempId)){
                cout << "Successful!";
                del++;
            }else{
                cout << "Failed!";
            }
        }catch(int e){
            cout << "ERROR";
        }
        cout << endl;
    }

    cout << "\nDone testing the hashtables. \n";

    return 0;
}
