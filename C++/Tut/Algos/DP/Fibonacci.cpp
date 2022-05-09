/*
The Fibonacci numbers are the numbers in the following integer sequence.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..

In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation 

	Fn = Fn-1 + Fn-2

with seed values 

	F0 = 0 and F1 = 1.

-------

Given a number n, print n-th Fibonacci Number. 

Examples: 

Input  : n = 2
Output : 1

Input  : n = 9
Output : 34

*/
/*
Method 2: Space Optimized

We can optimize the space used in method 1 by storing the previous two numbers only 
because that is all we need to get the next Fibonacci number in series

#include<bits/stdc++.h>
using namespace std;

int fib(int n) {
	int a = 0, b = 1, c, i;
	if (n == 0) {
		return a;
	}
	for (i = 2; i <= n; ++i) {
		c = a + b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int n = 9;
	cout << fib(n);
	return 0;
}

Output

34

Time Complexity:O(n)

Extra Space: O(1)
*/
/*
Method 3: Using power of the matrix {{1, 1}, {1, 0}}

This another O(n) method which relies on the fact that if we n times multiply the 
matrix M = {{1, 1}, {1, 0}} to itself (in other words we calculate the power(M, n)), 
then we get the (n + 1)th Fibonacci number as the element at row and column (0, 0) in the resultant matrix

{{1,1},{1,0}}^n = {{F(n+1),Fn},{Fn,F(n-1)}}

#include<bits/stdc++.h>
using namespace std;

Helper function that calculate F[][] raise to the power n and puts the result in F[][]. 
Only applicable for fib() and won't work as general power function

void power(int F[2][2], int n) {
	int i;
	int M[2][2] = {{1, 1}, {1, 0}};
	// n-1 times multiply the matrix to {{1,0}, {0,1}}
	for (i = 2; i <= n; ++i) {
		multiply(F, M);
	}
}

void multiply(int F[2][2], int M[2][2]) {
	// (0th row, 0th column * 0th row, 0th column) + (0th row, 1st column * 1st row, 0th column)
	int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
	// (0th row, 0th column * 0th row, 1st column) + (0th row, 1st column * 1st row, 1st column)
	int y = F[0][0] * M[0][1] + F[0][1] + M[1][1];
	// (1st row, 0th column * 0th row, 0th column) + (1st row, 1st column * 1st row, 0th column)
	int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
	// (1st row, 0th column * 0th row, 1st column) + (1st row, 1st column * 1st row, 1st column)
	int w = F[1, 0] * M[0][1] + F[1][1] * M[1][1];
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

int fib(int n) {
	int F[2][2] = {{1, 1}, {1, 0}};
	if (n == 0) {
		return 0;
	}
	power(F, n - 1);
	return F[0][0];
}

int main() {
	int n = 9;
	cout << " " << fib(n);
	return 0;
}

Output

34

Time Complexity: O(n) 
Extra Space: O(1)
*/
/*
Method 4: Using formula
In this method we directly implement the formula for nth term in the fibonacci series. 
	Fn = {[(√5 + 1)/2] ^ n} / √5

#include<iostream>
#include<cmath>
using namespace std;

int fib(int n) {
	double phi = (1 + sqrt(5)) / 2;
	return round(pow(phi, n) / sqrt(5));
}

int main ()
{
	int n = 9;
	cout << fib(n) << endl;
	return 0;
}

Output

34

Time Complexity: O(logn), this is because calculating phi^n takes logn time
Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class CFG {
	public:
	int fib(int n) {
		/* Declare an array to store the Fibonacci numbers 1 extra to handle case, when n = 0 */
		int f[n + 2];
		int i;
		f[0] = 0;
		f[1] = 1;
		for (i = 2; i <= n; ++i) {
			f[i] = f[i - 1] + f[i - 2];
		}
		return f[n];
	}
};

int main() {
	CFG g;
	int n = 9;
	cout << g.fib(n);
	return 0;
}

/*
Output

34

Time Complexity:O(n)

Extra Space: O(n)
*/