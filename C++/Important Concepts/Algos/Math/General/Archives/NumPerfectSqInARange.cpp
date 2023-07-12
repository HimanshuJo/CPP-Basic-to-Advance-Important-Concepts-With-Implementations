/*
Number of perfect squares between two given numbers

Given two given numbers a and b where 1<=a<=b, find the number of perfect squares
between a and b (a and b inclusive).

Examples

Input :  a = 3, b = 8
Output : 1
The only perfect in given range is 4.

Input : a = 9, b = 25
Output : 3
The three squares in given range are 9,
16 and 25
*/
/*
Method 2 (Efficient) We can simply take square root of ‘a’ and square root of ‘b’
and count the perfect squares between them using

floor(sqrt(b)) - ceil(sqrt(a)) + 1

We take floor of sqrt(b) because we need to consider
numbers before b.

We take ceil of sqrt(a) because we need to consider
numbers after a.

For example, let b = 24, a = 8.
floor(sqrt(b)) = 4, ceil(sqrt(a)) = 3.

And number of squares is 4 - 3 + 1= 2. The two numbers are 9 and 16.

*/

#include <bits/stdc++.h>
using namespace std;

int countSquares(int a, int b)
{
	return (floor(sqrt(b)) - ceil(sqrt(a)) + 1);
}

int main()
{
	int a = 9, b = 25;
	cout << "Count of squares is "
	     << countSquares(a, b);
	return 0;
}

/*
Output :

Count of squares is 3

Time complexity of this solution is O(Log b).
*/