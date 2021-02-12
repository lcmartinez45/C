#include<vector>
#include<iostream>

using namespace std;
/*
Write a value return function prototype get_max_from_vector with a
const reference vector of ints parameter that returns an int

@param numbers is a const reference to a vector of integers
@return the max value in the vector
*/
int get_max_from_vector(const vector<int>& numbers);

/*
Write a function prototype named is_prime with an integer parameter
that given a number returns true if prime or false if not prime

@param number: Any whole number
@return: bool if prime False if not
*/
bool is_prime(int number);

/*
Write a function prototype named vector_of_primes with an integer
parameter that given a number returns all the prime numbers up to
the number

@param int integer value
@return vector of ints containing prime values up to a value
*/
vector<int> vector_of_primes(int number);
