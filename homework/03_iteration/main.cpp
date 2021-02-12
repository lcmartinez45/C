/*
Lillian Martinez
 Homework 3
 main.cpp
*/
//write include statements
#include <iostream>
#include "dna.h"

//write using statements
using namespace std;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
// main function
int main() {
    // declare variables
    int option;
    string dna;
    // repeating the execution till user wants to continue
    while (1) {
        // read DNA string
        cout << "Enter a DNA String: ";
        cin >> dna;
        // display options
        cout << "\nSelect option" << endl;
        cout << "1. GC Content" << endl;
        cout << "2. DNA Complement\n" << endl;
        // read option
        cout << "Enter option: ";
        cin >> option;
        // call function according to option selected
        // if 1 is selected
        if (option == 1) {
            // call get_gc_content and print result
            double content = get_gc_content(dna);
            cout << "GC content: " << content << endl;
        }
            // if 2 is selected
        else if (option == 2) {
            // call get_dna_complement and print result
            string complement = get_dna_complement(dna);
            cout << "Complement: " << complement << endl;
        }
            // if not 1 and 2 enter invalid input
        else{
            cout << "Invalid input!" << endl;
        }
        // reading user input to check if they want to continue or not
        char ch;
        cout << "\nTo continue preess (Y/y): ";
        cin >> ch;
        // if 'y' continue
        if(ch == 'Y' || ch == 'y') {
            cout << "\n" << endl;
            continue;
        }
            // break the loop otherwise
        else {
            break;
        }
    }
    return 0;
}

