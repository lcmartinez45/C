#include<iostream>
#include<vector>
#include "vectors.h"

/*
use a vector of int with values 8, 4, 20, 88, 66, 99

Prompt user for 1 for Get Max from vector and 2 for Get primes.
Prompt user for a number and return max value or list of primes
and display them to screen.
Program continues until user decides to exit.
*/
int main()
{
    vector<int> numbers={8,4,20,88,66,99};
    vector<int> result;
    int choice=0,num,i;

    while(choice!=-1)
    {
    cout<<"Enter 1 to get max value from vector or 2 to get primes, Enter -1 to exit\n";
    cout<<"Enter your choice: ";

    cin>>choice;
        
    switch (choice)
    {
    case 1:cout<<"Maximum value in the vector is "<<get_max_from_vector(numbers)<<endl<<endl;
            break;
            
    case 2:cout<<"Enter number to get primes till that number: ";
            cin>>num;
            result=vector_of_primes(num);
            cout<<"\nVector with values ";
            for(i=0;i<result.size();i++)
            {
                if(i==result.size()-1)
                    cout<<result[i];
                
                else
                   cout<<result[i]<<", ";
            }
            cout<<"\n\n";
            break;

    case -1:exit(0);
    default:cout<<"Invalid choice";
    }
    }
    return 0;
}
