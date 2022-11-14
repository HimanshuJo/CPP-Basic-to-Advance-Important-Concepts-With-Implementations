// Check whether K-th bit is set or not
/*
Given a number n, check if the Kth bit of n is set or not.

Input : n = 5, k = 1
Output : SET
5 is represented as 101 in binary and has its first bit set.

Input : n = 2, k = 3
Output : NOT SET
2 is represented as 10 in binary, all higher i.e. beyond MSB, bits are NOT SET.

-------

Method 1 (Using Left Shift Operator)
Below are simple steps to find the value of Kth bit:

1) Left shift given number 1 by k-1 to create a number that has only set bit as k-th bit.
   temp = 1 << (k-1)

2) If bitwise AND of n and temp is non-zero, then result is SET else result is NOT SET.

Example:

n = 75 and k = 4
temp = 1 << (k-1) = 1 << 3 = 8
Binary Representation of temp = 0..00001000
Binary Representation of n = 0..01001011
Since bitwise AND of n and temp is non-zero, result is SET.
*/

#include <iostream>
using namespace std;

void isKthBitSetLeftShift(int n, int k)
{
	if (n & (1 << (k - 1)))
		cout << "SET";
	else
		cout << "NOT SET";
}

/*
Method 2 (Using Right Shift Operator)

If we right shift n by k-1, we get the last bit as 1 if Kth bit is set else 0.
*/

void isKthBitSetRightShift(int n, int k)
{
	if ((n >> (k - 1)) & 1)
		cout << "SET";
	else
		cout << "NOT SET";
}

int main()
{
	int n = 5, k = 1;
	isKthBitSetLeftShift(n, k);
	isKthBitSetRightShift(n, k);
	return 0;
}

/*
Time Complexity : O(1)

Auxiliary Space: O(1)
*/
