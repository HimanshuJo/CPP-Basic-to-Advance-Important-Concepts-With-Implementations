/*
Represent a number as sum of minimum possible psuedobinary numbers

Given a number, you have to represent this number as sum of minimum
number of possible psuedobinary numbers.

A number is said to be psuedobinary number if its decimal number consists
of only two digits (0 and 1).

Example: 11,10,101 are all psuedobinary numbers.

Examples :-

Input : 44
Output : 11 11 11 11

Explanation : 44 can be represented as sum of
minimum 4 psuedobinary numbers as 11+11+11+11

Input : 31
Output : 11 10 10

Explanation : 31 can be represented as sum of
minimum 3 psuedobinary numbers as 11+10+10

-------

The idea to do this is to first observe carefully that we need to
calculate minimum number of possible psuedobinary numbers.

To do this we find a new number 'm' such that if for a place in given number 'n',
the digit is non-zero then the digit in that place in m is 1 otherwise zero.

For example, if n = 5102, then m will be 1101.
Then we will print this number 'm' and subtract 'm' from 'n'.
We will keep repeating these steps until 'n' is greater than zero.
*/

#include<iostream>
using namespace std;

// function to represent a given
// number as sum of minimum possible
// psuedobinary numbers
void psuedoBinary(int n)
{
	// Repeat below steps until n > 0
	while (n > 0)
	{
		// calculate m (A number that has same
		// number of digits as n, but has 1 in
		// place of non-zero digits 0 in place
		// of 0 digits)
		int temp = n, m = 0, p = 1;
		while (temp)
		{
			int rem = temp % 10;
			temp = temp / 10;

			if (rem != 0)
				m += p;

			p *= 10;
		}

		cout << m << " ";

		// subtract m from n
		n = n - m;
	}
}

int main()
{
	int n = 31;

	psuedoBinary(n);

	return 0;
}
