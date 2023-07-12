/*
Modular Exponentiation (Power in Modular Arithmetic)

Given three numbers x, y and p, compute (x^y) % p.

Examples :

Input:  x = 2, y = 3, p = 5
Output: 3
Explanation: 2^3 % 5 = 8 % 5 = 3.

Input:  x = 2, y = 5, p = 13
Output: 6
Explanation: 2^5 % 13 = 32 % 13 = 6.

-------

Iterative solutions:

	int power(int x, int y) {
		int res = 1;
		while(y) {
			// if y is odd, multiply x with the result
			if (y & 1) {
				res = (res * x);
			}
			y = y >> 1;
			x = (x * x);
		}
		return res;
	}

	Efficient Approach:

		The problem with above solutions is, overflow may occur for large value of n or x.

		Therefore, power is generally evaluated under modulo of a large number.

		Below is the fundamental modular property that is used for 
		efficiently computing power under modular arithmetic.

		-------

		(ab) mod p = ((a mod p) (b mod p)) mod p

		For example a = 50,  b = 100, p = 13
		50  mod 13  = 11
		100 mod 13  = 9

		(50 * 100) mod 13 = ((50 mod 13) * (100 mod 13)) mod 13
		or (5000) mod 13 = (11 * 9) mod 13
		or 8 = 8

	-------

	// Iterative and efficient implementation
	#include<bits/stdc++.h>
	using namespace std;

	// Iterative function to calculate (x^y) % p in O(log y) time
	int power(long long x, unsigned int y, int p) {
		int res = 1;
		// update x if it is more than or equal to p
		x = x % p;
		if (x == 0) {
			return 0;
		}
		while (y > 0) {
			if (y & 1) {
				res = (res * x) % p;
			}
			y = y >> 1;
			x = (x * x) % p;
		}
		return res;
	}

	int main() {
		int x = 2;
		int y = 5;
		int p = 13;
		cout << "Power is " << power(x, y, p);
		return 0;
	}

	Output

		Power is 6

-------

Recursive Implementation:

	Given three numbers a, b and c, we need to find (a^b) % c

	Now why do “% c” after exponentiation, because ab will be really 
	large even for relatively small values of a, b and that is a problem 
	because the data type of the language that we try to code the problem, 
	will most probably not let us store such a large number.

	Examples:

		Input : a = 2312 b = 3434 c = 6789
		Output : 6343

		Input : a = -3 b = 5 c = 89
		Output : 24

	-------

	The idea is based on below properties.

		Property 1:

			(m * n) % p has a very interesting property:

		 	(m * n) % p = ((m % p) * (n % p)) % p

		Property 2:

			if b is even:

				(a^b) % c = ((a^b/2) * (a^b/2)) % c

			if b is odd:

				(a^b) % c = (a * (a^(b-1)) % c

		Property 3:

			If we have to return the mod of a negative number x whose absolute value is less than y:
				then (x + y) % y will do the trick

		Note:

			Also as the product of (a^b/2) * (a^b/2) and a * (a^(b-1)) may cause overflow, hence we must be careful about those scenarios

*/

#include<bits/stdc++.h>
using namespace std;

int exponentMod(int A, int B, int C) {
	// Base cases
	if (A == 0) {
		return 0;
	}
	if (B == 0) {
		return 1;
	}

	// if B is even
	long y;
	if (B % 2 == 0) {
		y = exponentMod(A, B / 2, C);
		y = (y * y) % C;
	}

	// if B is odd
	else {
		y = A % C;
		y = (y * exponentMod(A, B - 1, C) % C) % C;
	}
	return (int) ((y + C) % C);
}

int main() {
	int A = 2, B = 5, C = 13;
	cout << "Power is " << exponentMod(A, B, C);
	return 0;
}

/*
Output:

	Power is 6
*/