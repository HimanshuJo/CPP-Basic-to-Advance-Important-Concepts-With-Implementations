/*
Given an integer N, the task is to find the sum of exponents of prime factors of numbers 1 to N.

Examples:

    Input: N = 4

    Output: 4

    Explanation:

    	Numbers up to 4 are 1, 2, 3, 4 where

    	The exponent of 1 in the prime factorization of 1 is 0 (2^0),

    		For 2 it is 1 (2^1),
    		For 3 it is 1 (3^1), and
    		For 4 it is 2 (2^2).
    		The sum of the exponent of prime factors of each number up to 4 is 0 + 1 + 1 + 2 = 4.

    Input: N = 10

    Output: 15

    Explanation:

    	sum of the exponent of prime factors of each number up to 10 is 15.

-------

Approach: The idea is to use the concept of Prime factors and their powers.

	Below are the steps:

    	Iterate for each number from 2 to N and for each number do the following:

    		Find the power of prime factors for each number N.

        	Find the summation of each power in the above steps

    	Print the summation of all the powers of prime factors of N and print the sum.

*/

#include <bits/stdc++.h>
using namespace std;

// Function to implement sieve of
// erastosthenes
void sieveOfEratosthenes(int N, int s[])
{
	// Create a boolean array and
	// initialize all entries as false
	vector<bool> prime(N + 1, false);

	// Initializing smallest
	// factor equal to 2
	// for all the even numbers
	for (int i = 2; i <= N; i += 2)
		s[i] = 2;

	// Iterate for odd numbers
	// less then equal to n
	for (int i = 3; i <= N; i += 2) {

		if (prime[i] == false) {

			// s(i) for a prime is
			// the number itself
			s[i] = i;

			// For all multiples of
			// current prime number
			for (int j = i; j * i <= N; j += 2) {

				if (prime[i * j] == false) {
					prime[i * j] = true;

					// i is the smallest
					// prime factor for
					// number "i*j"
					s[i * j] = i;
				}
			}
		}
	}
}

int generatePrimeFactors(int N)
{
	// s[i] is going to store
	// smallest prime factor of i
	int s[N + 1];
	int sum = 0;

	sieveOfEratosthenes(N, s);

	// Current prime factor of N
	int curr = s[N];

	// Power of current prime factor
	int cnt = 1;

	// Calculating prime factors
	// and their powers sum
	while (N > 1) {

		N /= s[N];

		if (curr == s[N]) {

			// Increment the count and
			// continue the process
			cnt++;
			continue;
		}

		// Add count to the sum
		sum = sum + cnt;

		curr = s[N];

		// Reinitialize count
		cnt = 1;
	}

	// Return the result
	return sum;
}

void findSum(int N)
{

	int sum = 0;

	// Iterate for in [2, N]
	for (int i = 2; i <= N; i++) {
		sum += generatePrimeFactors(i);
	}
	cout << sum << endl;
}

int main()
{
	// Given Number N
	int N = 4;

	// Function Call
	findSum(N);
	return 0;
}

/*
-------

Output = 4

Time: O(N*LogN)
Space: O(N)
*/