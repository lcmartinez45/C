/*
 * This is a simple application to demonstrate ADTs in C++.
 */

/* 
 * File:   main.cpp
 * Author: Lillian Martinez
 */

#include "main.h"

int main(int argc, char** argv) {
    srand(time(0));
    Stack s1;
    int count = 0, input = 0, popped, option, value;
    bool pushed;

    std::cout << "Testing the stack... " << std::endl;
    std::cout << "Checking if the stack is empty -> ";
    if (s1.isEmpty() == true) {
        std::cout << "I'm empty!" << std::endl;;
    } else {
        std::cout << "Not empty!" << std::endl;;
    }

    std::cout << "\nTesting the stack, checking overflow... " << std::endl; //push()
    std::cout << "Pushing values into the stack...\n" << std::endl;

    while (count <= (SIZE)){
        pushed = s1.push(count);
        if (pushed){
            std::cout << "Value was added to the stack -> " << count << std::endl;
        }
        else{
            std::cout << "Sorry, stack overflow cannot push more items. " << std::endl;
        }
        count++;
    }

    std::cout << "\nChecking if the stack is empty -> ";
    if (s1.isEmpty() == true) {
        std::cout << "I'm empty!" << std::endl;
    } else {
        std::cout << "Not empty!" << std::endl;
    }

    try{
        std::cout << "Peaking at the value at the top of the stack: " << s1.peek() << std::endl;
    } catch (int e) {
        std::cout<< "Sorry, there are no items to peek the stack is empty. " << std::endl;
    }

    std::cout << "\nTesting the stack, checking underflow... " << std::endl; //pop()
    do {
        try{
            popped = s1.pop();
            std::cout << "Popping value from the stack -> " << popped << std::endl;

        } catch (int e) {
            std::cout << "Sorry, stack is in underflow there are no items to pop. " << std::endl;
        }
        input++;
    }while(input <= (SIZE));

    std::cout << "\nChecking if the stack is empty -> ";
    if (s1.isEmpty() == true) {
        std::cout << "I'm empty!" << std::endl;
    } else {
        std::cout << "Not empty!" << std::endl;
    }

    try{
        std::cout << "Peaking at the value at the top of the stack: " << s1.peek() << std::endl;
    } catch (int e) {
        std::cout<< "Sorry, there are no items to peek because the stack is empty. " << std::endl;
    }

    count = 0;
    std::cout << "\nTesting the stack by testing each function randomly..." << std::endl;
    while(count <= 30){
        option = rand() % 5 + 1;
        switch(option) {
            case 1: std::cout << "\nTesting push..." << std::endl;
                    for (int i = 0; i < 15; i++) {
                        int random = rand() % 99 + 1;
                        pushed = s1.push(random);
                        if (pushed) {
                            std::cout << "Pushing value -> " << random << std::endl;
                            count++;
                        } else {
                            std::cout << "Stack overflow, no more items to push. " << std::endl;
                        }
                    }
            case 2: std::cout << "\nTesting pop..." << std::endl;
                for (int i = 0; i < 18; i++) {
                    try {
                        popped = s1.pop();
                        std::cout << "Popping value -> " << popped << std::endl;
                    }
                    catch (int e) {
                        std::cout << "Stack underflow, no more items to pop." << std::endl;
                    }
                }
            case 3: std::cout << "\nTesting peek..." << std::endl;
                try {
                    value = s1.peek();
                    std::cout << "Value " << value << " is at the top of the stack." << std::endl;
                }
                catch (int e) {
                    std::cout << "The stack is empty, there is nothing to peek. " << std::endl;
                }
            case 4: std::cout << "\nTesting if the stack is empty..." << std::endl;
                if (s1.isEmpty() == true) {
                    std::cout << "The stack is empty!" << std::endl;
                } else {
                    std::cout << "The stack is not empty!" << std::endl;
                }
            case '\n': break;
        default: std::cout << "Error with a random input." << std::endl;
        }
    }
    std::cout << "\nTesting the stack is complete. " << std::endl;

    return 0;
}
