/*
 *  This is a simple application to demonstrate ADTs in C++.
 */

/* 
 * File:   stack.h
 * Author: Lillian Martinez
 */

#ifndef STACK_STACK_H
#define STACK_STACK_H

#define SIZE 10

class Stack
{
public:
    Stack();
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();

private:
    int top;
    int stack[SIZE]; //Maximum size of Stack
};

#endif //STACK_STACK_H