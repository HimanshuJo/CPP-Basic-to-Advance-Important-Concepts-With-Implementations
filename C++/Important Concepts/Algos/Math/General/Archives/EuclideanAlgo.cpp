/*
GCD of two numbers is the largest number that divides both of them.

A simple way to find GCD is to factorize both numbers and multiply common prime factors.

-------

Basic Euclidean Algorithm for GCD

The algorithm is based on the below facts.

    If we subtract a smaller number from a larger (we reduce a larger number),
    GCD doesn’t change.

    So if we keep subtracting repeatedly the larger of two, we end up with GCD.

    Now instead of subtraction, if we divide the smaller number,
    the algorithm stops when we find remainder 0.

	Below is a recursive function to evaluate gcd using Euclid’s algorithm.

	-------

	#include <bits/stdc++.h>
	using namespace std;

	int gcd(int a, int b)
	{
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}

	int main()
	{
		int a = 10, b = 15;
		cout << "GCD(" << a << ", "
			 << b << ") = " << gcd(a, b)
							<< endl;
		a = 35, b = 10;
		cout << "GCD(" << a << ", "
			 << b << ") = " << gcd(a, b)
							<< endl;
		a = 31, b = 2;
		cout << "GCD(" << a << ", "
			 << b << ") = " << gcd(a, b)
							<< endl;
		return 0;
	}

	Output:

		GCD(10, 15) = 5
		GCD(35, 10) = 5
		GCD(31, 2) = 1

	Time Complexity: O(Log min(a, b))

-------

Extended Euclidean Algorithm:

	Extended Euclidean algorithm also finds integer coefficients x and y such that:

  		ax + by = gcd(a, b)

	Examples:

		Input: a = 30, b = 20
		Output: gcd = 10
		        x = 1, y = -1
		(Note that 30*1 + 20*(-1) = 10)

		Input: a = 35, b = 15
		Output: gcd = 5
		        x = 1, y = -2
		(Note that 35*1 + 15*(-2) = 5)

	The extended Euclidean algorithm updates results of gcd(a, b)
	using the results calculated by recursive call gcd(b%a, a).

	Let values of x and y calculated by the recursive call be x1 and y1.

	x and y are updated using the below expressions.

		x = y1 - ⌊b/a⌋ * x1
		y = x1

	-------

	import java.util.*;
	import java.lang.*;

	class GFG
	{
		// extended Euclidean Algorithm
		public static int gcdExtended(int a, int b, int x, int y)
		{
			// Base Case
			if (a == 0)
			{
				x = 0;
				y = 1;
				return b;
			}

			int x1=1, y1=1; // To store results of recursive call (0, 0 can also be used)
			int gcd = gcdExtended(b%a, a, x1, y1);

			// Update x and y using results of recursive
			// call
			x = y1 - (b/a) * x1;
			y = x1;

			return gcd;
		}

		public static void main(String[] args)
		{
			int x=1, y=1;
			int a = 35, b = 15;
			int g = gcdExtended(a, b, x, y);
			System.out.print("gcd(" + a + " , " + b+ ") = " + g);

		}
	}

*/

#include <bits/stdc++.h>
using namespace std;

// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
	// Base Case
	if (a == 0)
	{
		*x = 0;
		*y = 1;
		return b;
	}

	int x1, y1; // To store results of recursive call
	int gcd = gcdExtended(b % a, a, &x1, &y1);

	// Update x and y using results of
	// recursive call
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

int main()
{
	int x, y, a = 35, b = 15;
	int g = gcdExtended(a, b, &x, &y);
	cout << "GCD(" << a << ", " << b
	     << ") = " << g << endl;
	return 0;
}

/*
Output :

	gcd(35, 15) = 5
*/