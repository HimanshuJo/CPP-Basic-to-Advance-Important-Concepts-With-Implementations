/*
GCD or HCF:

	of two numbers is the largest number that divides both of them

		36 = 2 * 2 * 3 * 3

		60 = 2 * 2 * 3 * 5

			here GCD will be multiplication of the common factors
				= 2 * 2 * 3

	-------

	Simple Solution:

		is to find all the prime factors of both the numbers, the find the intersection of all the factors
			present in both of them

			finally return the product of elements in the intersection

	-------

	Efficient Solution:

		is to use the Euclidean algorithm

			the idea is two numbers doesn't change if smaller number is subtracted by the bigger number

	-------

	class Solution {

		static int gcd(int a, int b) {

			if (a == 0) return b;

			if (b == 0) return a;

			if (a == b) return a;

			if (a > b) return gcd(a - b, a);

			return gcd(a, b - a);
		}
	}

	-------

	More efficient approach is to use the modulo operator in Euclidean algorithm

	class Solution {

		static int gcd(int a, int b) {

			if (b == 0) return a;

			return gcd(b, a % b);
		}
	}

	Time Complexity:

		The time complexity of the above algorithm is O(log(max(a, b)))

		What we do is we ask what are the 2 least numbers that take 1 step, those would be (1,1)

		If we want to increase the number of steps to 2 while keeping the numbers as low as possible as we can take
			the numbers to be (1,2)

		Similarly, for 3 steps, the numbers would be (2,3)

		4 would be (3,5), 5 would be (5,8)

		So we can notice a pattern here, for the nth step the numbers would be (fib(n), fib(n+1))

		So the worst-case time complexity would be O(n) where a >= fib(n) and b >= fib(n+1)

		-------

		Now Fibonacci series is an exponentially growing series where the ratio of

			n'th/(n-1)'th term

				approaches (sqrt(5)-1)/2 which is also called the golden ratio

			So we can see that the time complexity of the algorithm increases linearly as the terms grow
				exponentially hence the time complexity would be log(max(a,b))

-------

GCD of more than two numbers:

	The GCD of three or more numbers is equals to the product of the prime factors common to all the numbers,
		but it can also be calculated by repeatedly taking the GCDs of pairs of numbers

		gcd(a, b, c) = gcd(a, gcd(b, c))
					 = gcd(gcd(a, b), c)
					 = gcd(gcd(a, c), b)

 	-------

 	for an array of elements we can do the following

 		we will also check for the result if the result at any step becomes 1, we will just return 1
 			as gcd(1, x) = 1

*/

public class Solution {

	static int gcd(int a, int b) {

		if (a == 0) return b;

		return (a, a % b);
	}

	static int findGCD(int arr[], int n) {

		int result = 0;

		for (int element : arr) {

			result = gcd(result, element);

			if (result == 1) return 1;
		}

		return result;
	}
}