/*
Check if a number is a power of another number

Given two positive numbers x and y, check if y is a power of x or not.
Examples : 
 
Input:  x = 10, y = 1
Output: True
x^0 = 1

Input:  x = 10, y = 1000
Output: True
x^3 = 1

Input:  x = 10, y = 1001
Output: False

*/
/*
A simple solution is to repeatedly compute powers of x. 
If a power becomes equal to y, then y is a power, else not.
*/

#include <bits/stdc++.h>
using namespace std;

/* Returns 1 if y is a power of x */
bool isPower(int x, long int y)
{
	// The only power of 1 is 1 itself
	if (x == 1)
		return (y == 1);

	// Repeatedly compute power of x
	long int pow = 1;
	while (pow < y)
		pow *= x;

	// Check if power of x becomes y
	return (pow == y);
}

int main()
{
	cout << isPower(10, 1) << endl;
	cout << isPower(1, 20) << endl;
	cout << isPower(2, 128) << endl;
	cout << isPower(2, 30) << endl;
	return 0;
}

/*
Output: 

1
0
1
0
*/
/*
Time complexity of above solution is O(Log(base x)y)

-------

Optimization:

	We can optimize above solution to work in O(Log Log y). 

	The idea is to do squaring of power instead of multiplying it with x, 
		i.e., compare y with x^2, x^4, x^8, … etc. 

	If x becomes equal to y, return true.

	If x becomes more than y, then we do binary search for power of x between previous power 
		and current power, i.e., between x^i and x^(i/2).

Following are detailed step:

	1) Initialize pow = x, i = 1
	
	2) while (pow < y)
	   {
	      pow = pow*pow 
	      i *= 2
	   }    
	
	3) If pow == y
	     return true;
	
	4) Else construct an array of powers
	   from x^i to x^(i/2)
	
	5) Binary Search for y in array constructed
	   in step 4. If not found, return false. 
	   Else return true.

*/

#include <iostream>
#include <math.h>
using namespace std;

bool isPower(int x, int y)
{
	// logarithm function to calculate value
	int res1 = log(y) / log(x);
	double res2 = log(y) / log(x); // Note : this is double

	// compare to the result1 or result2 both are equal
	return (res1 == res2);
}

int main()
{
	cout << isPower(27, 729) << endl;
	return 0;
}

/*
Output: 
	
	1
*/