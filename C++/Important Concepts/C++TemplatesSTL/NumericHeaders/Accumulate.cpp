/*
accumulate()

    This function returns the sum of all the values lying in a range between [first, last) 
	with the variable sum.

    Syntax 1:
        
        accumulate(first, last, sum);
    
        first, last : first and last elements of range whose elements are to be added
        
        sum :  initial value of the sum

    Syntax 2: This function returns the sum of all the values lying between [first, last) with 
	the variable sum.

        accumulate(first, last, sum, myfun); 
        
        myfun : 
        
            a function for performing any specific task. 
            For example, we can find product of elements between first and last.
*/

// C++ program to demonstrate working of accumulate()
#include <iostream>
#include <numeric>	
using namespace std;

// User defined function
int myfun(int x, int y)
{
	// for this example we have taken product
	// of adjacent numbers
	return x * y ;
}

int main()
{
	// Initialize sum = 1
	int sum = 1;
	int a[] = {5 , 10 , 15} ;
	
	// Simple default accumulate function
	cout << "\nResult using accumulate: ";
	cout << accumulate(a , a+3 , sum);
	
	// Using accumulate function with
	// defined function
	cout << "\nResult using accumulate with"
			"user-defined function: ";
	cout << accumulate(a, a+3, sum, myfun);
	
	// Using accumulate function with
	// pre-defined function
	cout << "\nResult using accumulate with "
			"pre-defined function: ";
	cout << accumulate(a, a+3, sum, std::minus<int>());
	
	return 0;
}

/*
Output:
Result using accumulate: 31
Result using accumulate with user-defined function: 750
Result using accumulate with pre-defined function: -29
*/