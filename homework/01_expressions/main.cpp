//write include statements
#include <iostream> //use standard library
#include "expressions.h"

//write namespace using statement for cout
using std::cout;

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	int result = multiply_numbers(10, 10);

	cout << "Result: " << result;

	return 0;
}
