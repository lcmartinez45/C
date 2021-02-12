#include<vector>
#include "vectors.h"

using namespace std;

/*
Write a value return function get_max_from_vector with a const reference
vector of ints parameter that returns the max value in a vector

@param numbers is a const reference to a vector of integers
@return the max value in the vector
*/
int get_max_from_vector(const vector<int>& numbers)
{
    int max_num=numbers.at(0);
    for(int i:numbers)
    {
        if(i>max_num)
            max_num=i;
    }
    return max_num;
}

/*
Write a function named is_prime with an integer parameter that
given a number returns true if prime or false if not prime

@param number: Any whole number
@return: bool if prime false if not
*/
bool is_prime(int n)
{
    int i;
    if(n==2 || n==3)
    {
        return true;
    }
    else if(n%2==0)
    {
        return false;
    }
    else if(n%6==1 || n%6==5)
    {
        for(i=2;i<n;i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    else
        return false;
}

/*
Write a function named vector_of_primes with an integer parameter
that given a number returns all the prime numbers up to the number

Example given number 10 returns a vector with elements 2,3,5,7,

@param int integer value
@return vector of ints containing prime values up to a value

Make sure to use the is_prime function to determine if current
number is prime.
*/
vector<int> vector_of_primes(int n)
{
    int i;
    vector<int> result;
    for(i=2;i<=n;i++)
    {
        if(is_prime(i))
            result.push_back(i);
    }
    return result;
}
