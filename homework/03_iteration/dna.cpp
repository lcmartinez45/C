/*
Lillian Martinez
 Homework 3
 dna.cpp
*/
#include "dna.h"
using std::string; using std::cout;using std::swap;
/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/
double get_gc_content(const string &dna) {
    // declare variables
    double content = 0.0;
    int len = 0;
    int i = 0;
    // loop through the DNA string and count the G and C
    while(dna[i] != '\0') {
        if (dna[i] == 'G' || dna[i] == 'C') {
            content += 1;
        }
        i += 1;
        len += 1;
    }
    // return the GC / length ratio
    return content / len;
}
/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/
string get_reverse_string(string dna) {
    string rev = "";
    // loop through the string DNA in reverse order and copy the characters in the new string rev
    for (int i = dna.size() - 1; i >= 0; i--) {
        rev += dna[i];
    }
    // return the resulting string
    return rev;
}

/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string
*/
string get_dna_complement(string dna) {
    // first create a reversed string using get_reverse_string function
    string b = get_reverse_string(dna);
    string complement = "";
    // loop through the string and copy the content in the string complement
    for (int i = 0; i < b.length(); i++) {
        // replace A with T
        if (b[i] == 'A') {
            complement +='T';
        }
            // replace T with A
        else if(b[i] == 'T') {
            complement += 'A';
        }
            // replace G with C
        else if(b[i] == 'G') {
            complement += 'C';
        }
            // replace C with G
        else if(b[i] == 'C') {
            complement += 'G';
        }
    }
    // return the complemented string
    return complement;
}