/*
Print all perfect squares from the given range

Given a range [L, R], the task is to print all the perfect squares from the given range.
Examples:


Input: L = 2, R = 24
Output: 4 9 16
Input: L = 1, R = 100
Output: 1 4 9 16 25 36 49 64 81 100
*/
/*
Efficient approach:

This method is based on the fact that the very first perfect
square after number L will definitely be the square of ⌈sqrt(L)⌉.

In very simple terms, the square root of L will be very close to the number whose
square root we are trying to find. Therefore, the number will be pow(ceil(sqrt(L)), 2).

The very first perfect square is important for this method. Now the original answer
is hidden over this pattern i.e. 0 1 4 9 16 25
the difference between 0 and 1 is 1
the difference between 1 and 4 is 3
the difference between 4 and 9 is 5 and so on…
which means that the difference between two perfect squares is always an odd number.

Now, the question arises what must be added to get the next number and the answer is
(sqrt(X) * 2) + 1 where X is the already known perfect square.

Let the current perfect square be 4 then the next perfect square will definitely
be 4 + (sqrt(4) * 2 + 1) = 9.

Here, number 5 is added and the next number to
be added will be 7 then 9 and so on… which makes a series of odd numbers.
Addition is computationally less expensive than performing multiplication
or finding square roots of every number.
*/

#include <bits/stdc++.h>
using namespace std;

void perfectSquares(float l, float r)
{
	// Getting the very first number
	int number = ceil(sqrt(l));

	// First number's square
	int n2 = number * number;

	// Next number is at the difference of
	number = (number * 2) + 1;

	// While the perfect squares
	// are from the range
	while ((n2 >= l && n2 <= r)) {

		// Print the perfect square
		cout << n2 << " ";

		// Get the next perfect square
		n2 = n2 + number;

		// Next odd number to be added
		number += 2;
	}
}

int main()
{
	int l = 2, r = 24;

	perfectSquares(l, r);

	return 0;
}

/*
Output:
4 9 16
*/