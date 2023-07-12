/*
partial_sum( )

    This function assigns partial sum of the corresponding elements of an array to every position of 
        the second array.
    
    It returns the partial sum of all the set of values lying between [first, last) and stores 
        it in another array b.
    
    For example, if x represents an element in [first, last) and y represents an element in result, 
        the ys can be calculated as:

        y0 = x0 
        y1 = x0 + x1 
        y2 = x0 + x1 + x2 
        y3 = x0 + x1 + x2 + x3 
        y4 = x0 + x1 + x2 + x3 + x4

    Syntax :

        partial_sum(first, last, b);
        partial_sum(first, last, b, myfun);
        first, last : first and last element of range whose elements are to be added
        b : index of array where  corresponding partial sum will be stored;
        myfun : a user defined function for performing any specific task
*/

// C++ program to demonstrate working of partial_sum()
#include <iostream>
#include <numeric>	
using namespace std;

//user defined function
int myfun(int x, int y)
{
	// the sum of element is twice of its
	// adjacent element
	return x + 2 * y;
}

int main ()
{
	int a[] = {1, 2, 3, 4, 5} ;
	int b[5];
	
	// Default function
	partial_sum(a , a+5 , b);

	cout << "Partial Sum - Using Default function: ";
	for (int i=0; i<5; i++)
		cout << b[i] << ' ';
	cout << '\n';
	
	// Using user defined function
	partial_sum(a , a+5 , b , myfun) ;

	cout << "Partial sum - Using user defined function: ";
	for (int i=0; i<5; i++)
		cout << b[i] << ' ';
	cout << '\n';

	return 0;
}

/*
Output:
Partial Sum - Using Default function: 1 3 6 10 15 
Partial sum - Using user defined function: 1 5 11 19 29 
*/