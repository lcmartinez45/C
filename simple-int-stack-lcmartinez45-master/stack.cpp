/*
 *  This is a simple application to demonstrate ADTs in C++.
 */

/* 
 * File:   stack.cpp
 * Author: Lillian Martinez
 */

#include "stack.h"

Stack::Stack(){
    top = -1;
}

// function to insert data into stack
bool Stack::push(int x)
{
    bool value;

    if(top >= (SIZE-1))
    {
        value = false;
    }
    else
    {
        stack[++top] = x;
        value = true;
    }
    return value;
}

// function to remove data from the top of the stack
int Stack::pop()
{
    if(top < 0)
    {
        throw -2;
    }
    int d = stack[top--];
    return d;
}

// function to peek at the data from the top of the stack
int Stack::peek()
{
    if(top < 0)
    {
        throw -2;
    }
    int d = stack[top];
    return d;
}

// function to check if stack is empty
bool Stack::isEmpty()
{
    bool success;

    if(top < 0)
    {
        success = true;
    }
    else
    {
        success = false;
    }
    return success;
}
