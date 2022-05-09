/*
Given a prime number n, print all the primes smaller than or equal to n

	It is also given that n is a small number

	Example: n = 10

	Output: 2 3 4 5 7

	Input: n = 20

	Output: 2 3 5 7 11 13 17 19

-------

The sieve of Eratosthenes is one of the most efficient ways to find all the primes smaller than n when
	n is smaller than 10 million

	Suppose n = 50, and we need to print all the prime numbers smaller than or equal to 50

	Initially we can create a list of all the numbers from 2 to 50

		Then according to the algorithm, we will mark all the numbers which are divisible by 2 and are
			greater than or equal to the square of it

		Next we will move to our next unmarked number 3 and mark all the numbers which are multiples of 3 and
			are greater than or equal to the square of it

		We can then move to our next unmarked number 5 and mark all the multiples of 5 and are greater than or
			equal to the square of it

		We can continue like this until we have reached to the required number or a number less than it

		-------

		Finally all the prime numbers are: 2,3,5,7, 11,13,17,19, 23,29, 31,37, 41,43,47

*/
/*
class SieveOfEratosthenes {

	void sieveOfEratosthenes(int n) {

		// create a boolean array "prime[0..n]" and initialize all the entries it as true
		// A value in prime[i] will finally be false if i is Not a prime else true

		boolean prime[] = new boolean[n + 1];
		for (int i = 0; i <= n; ++i) {
			prime[i] = true;
		}

		for (int p = 2; p * p <= n; ++p) {
			// if prime[p] is not changed, then it is a prime number
			if (prime[p] == true) {
				// update all the multiples of p
				for (int i = p * p; i <= n; i += p) {
					prime[i] = false;
				}
			}
		}

		for (int i = 0; i <= n; ++i) {
			if (prime[i] == true) {
				System.out.println(i + " ");
			}
		}
	}

	public static void main(String args[])
	{
		int n = 30;
		System.out.print("Following are the prime numbers ");
		System.out.println("smaller than or equal to " + n);
		SieveOfEratosthenes g = new SieveOfEratosthenes();
		g.sieveOfEratosthenes(n);
	}
}
*/
/*
Output

	Following are the prime numbers smaller than or equal to 30
	2 3 5 7 11 13 17 19 23 29

*/
/*
Time Complexity:

	O(n*log(log(n)))

-------

** Sieve of Eratosthenes in O(n) time complexity

	The classical Sieve of Eratosthenes algorithm takes O(n log (log n)) 
	time to find all the prime numbers less than N

		A modified version works in O(N) time

	-------

	For every number i where i varies from 2 to N-1

		we can check if the number is prime

		if the number is prime, we can store it in prime array

	For every prime numbers j less than or equal to the smallest prime factor p of i

		We can mark all the j*p as non_prime

		Mark smallest prime factor of j*p as j

*/
/*
Find N'th prime number

#include<bits/stdc++.h>
using namespace std;
#define N 20
bool prime[N + 1];

void createSieve() {
    for (int i = 0; i <= N; ++i) {
        prime[i] = true;
    }

    for (int p = 2; p * p <= N; ++p) {
        if (prime[p] == true) {
            for (int i = p * p; i <= N; i += p) {
                prime[i] = false;
            }
        }
    }
}

int main() {
    createSieve();
    int index = 0;
    int count = 0;
    for (bool val : prime) {
        if (val == 1) {
            cout << "count: " << count << " Number: " << index << endl;
            //cout << "index: " << index << " value: " << "true" << endl;
            count++;
        }
        index++;
    }
}

Output:

count: 0 Number: 0
count: 1 Number: 1
count: 2 Number: 2
count: 3 Number: 3
count: 4 Number: 5
count: 5 Number: 7
count: 6 Number: 11
count: 7 Number: 13
count: 8 Number: 17
count: 9 Number: 19
*/

#include <bits/stdc++.h>
using namespace std;
#define N 20

bool prime[N + 1];

void createSieve()
{
	for (int i = 0; i <= N; ++i)
	{
		prime[i] = true;
	}

	for (int p = 2; p * p <= N; ++p)
	{
		if (prime[p] == true)
		{
			for (int i = p * p; i <= N; i += p)
			{
				prime[i] = false;
			}
		}
	}
}

int main()
{
	createSieve();
	int num = 0;
	for (bool val : prime)
	{
		cout << "Number: " << num << " value: " << (val == 1 ? "true" : "false") << endl;
		num++;
	}
}

/*
Output:

Number: 0 value: true
Number: 1 value: true
Number: 2 value: true
Number: 3 value: true
Number: 4 value: false
Number: 5 value: true
Number: 6 value: false
Number: 7 value: true
Number: 8 value: false
Number: 9 value: false
Number: 10 value: false
Number: 11 value: true
Number: 12 value: false
Number: 13 value: true
Number: 14 value: false
Number: 15 value: false
Number: 16 value: false
Number: 17 value: true
Number: 18 value: false
Number: 19 value: true
Number: 20 value: false
*/
