// Given a number n and a value k, turn off the k’th bit in n. Please note that k = 1 means the rightmost bit.
/*
Input:  n = 15, k = 1
Output: 14

Input:  n = 14, k = 1
Output: 14
The rightmost bit was already off, so no change.

Input:  n = 15, k = 2
Output: 13

Input:  n = 15, k = 3
Output: 11

Input:  n = 15, k = 4
Output: 7

Input:  n = 15, k >= 5
Output: 15

The idea is to use bitwise <<, & and ~ operators.

Using expression “~(1 << (k – 1))“, we get a number which has all bits set,
except the k’th bit.

If we do bitwise & of this expression with n, we get a number which has all bits same
as n except the k’th bit which is 0.
*/

#include <iostream>
using namespace std;

// Returns a number that has all bits same as n
// except the k'th bit which is made 0
int turnOffK(int n, int k)
{
	// k must be greater than 0
	if (k <= 0) return n;

	// Do & of n with a number with all set bits except
	// the k'th bit
	return (n & ~(1 << (k - 1)));
}

int main()
{
	int n = 15;
	int k = 4;
	cout << turnOffK(n, k);
	return 0;
}
