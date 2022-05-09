/*
Problems with Simple Sieve:

	The Sieve of Eratosthenes looks good, but consider the situation when n is large,
	the Simple Sieve faces the following issues.

	An array of size Θ(n) may not fit in memory
	The simple Sieve is not cached friendly even for slightly bigger n.

	The algorithm traverses the array without locality of reference

-------

Segmented Sieve:

	The idea of a segmented sieve is to divide the range [0..n-1] in different segments
	and compute primes in all segments one by one.

	This algorithm first uses Simple Sieve to find primes smaller than or equal to Sqrt(n).

	-------

	Steps of segmented sieve:

		1. Use Simple Sieve to find all the primes up to the square root of 'n' and store
		these primes in an array "primes[]"

		2. We need all the primes in the range [0..n-1].
			We can divide this range into different segments such that the size of every segment is at most Sqrt(n)

		3. Do following for every segment [low..high]

			a. Create an array mark [high-low+1].
				Here we need only O(x) space where x is a number of elements in a given range

			b. Iterate through all the primes found in step 1.

				For every prime, mark its multiples in the given range [low..high]

	-------

	In Simple Sieve, we needed O(n) space which may be feasible for large n.

	Here we need O(Sqrt(n)) and we process smaller ranges at a time (locality of reference)

*/

#include <bits/stdc++.h>
using namespace std;

// fillPrime function fills primes from 2 to sqrt of high in chprime(vector) array
void fillPrimes(vector<int>& prime, int high)
{
	bool ck[high + 1];
	memset(ck, true, sizeof(ck));
	ck[1] = false;
	ck[0] = false;
	for (int i = 2; (i * i) <= high; i++) {
		if (ck[i] == true) {
			for (int j = i * i; j <= sqrt(high); j = j + i) {
				ck[j] = false;
			}
		}
	}
	for (int i = 2; i * i <= high; i++) {
		if (ck[i] == true) {
			prime.push_back(i);
		}
	}
}

// in segmented sieve we check for prime from range [low, high]
void segmentedSieve(int low, int high)
{
	if (low<2 and high >= 2) {
		low = 2;
	}//for handling corner case when low = 1 and we all know 1 is not prime no.
	bool prime[high - low + 1];
	//here prime[0] indicates whether low is prime or not similarly prime[1]
	//indicates whether low+1 is prime or not
	memset(prime, true, sizeof(prime));

	vector<int> chprime;
	fillPrimes(chprime, high);
	//chprimes has primes in range [2,sqrt(n)]
	//we take primes from 2 to sqrt[n] because the multiples of all primes below
	//high are marked by these
	//primes in range 2 to sqrt[n] for eg: for number 7 its multiples i.e
	//14 is marked by 2, 21 is marked by 3,
	//28 is marked by 4, 35 is marked by 5, 42 is marked 6, so 49 will be
	//first marked by 7 so all number before 49
	//are marked by primes in range [2,sqrt(49)]
	for (int i : chprime) {
		int lower = (low / i);
		//here lower means the first multiple of prime which is in range [low,high]
		//for eg: 3's first multiple in range [28,40] is 30
		if (lower <= 1) {
			lower = i + i;
		}
		else if (low % i) {
			lower = (lower * i) + i;
		}
		else {
			lower = (lower * i);
		}
		for (int j = lower; j <= high; j = j + i) {
			prime[j - low] = false;
		}
	}

	for (int i = low; i <= high; i++) {
		if (prime[i - low] == true) {
			cout << (i) << " ";
		}
	}
}

int main()
{
	// low should be greater than or equal to 2
	int low = 2;
	// low here is the lower limit
	int high = 100;
	// high here is the upper limit
	// in segmented sieve we calculate primes in range [low,high]
	// here we initially we find primes in range [2,sqrt(high)] to mark all
	// their multiples as not prime
	// then we mark all their(primes) multiples in range [low,high] as false
	// this is a modified sieve of eratosthenes, in standard sieve of eratosthenes
	// we find prime from 1 to n(given number)
	// in segmented sieve we only find primes in a given interval
	cout << "Primes in range " << low << " to " << high << " are\n";
	segmentedSieve(low, high);
}
