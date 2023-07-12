/*
Ugly Numbers:

	These are the numbers whose only prime factors are 2, 3 or 5

	The sequence

		1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ...  --> 7, 11, 13, 14 missing

		shows the first 11 ugly numbers

	By convention 1 is included

-------

Given a number n, the task is to find the n'th ugly number

E.g.:

	n = 7
	output: 8

	n = 10
	output: 12

-------

Naive:

	Loop for all the positive integers until ugly number count is smaller than n
		if an integer is ugly than increment ugly number count

	To check if a number is ugly, divide the number by the
		greatest divisible powers of 2, 3 and 5

		if the number becomes 1 then it is an ugly number else not

	-------

	E.g.:

		How to check for 300, whether it is ugly or not

		Greatest divisible power of 2 for 300 is 4
			after dividing 300 by 4 we get 75

		Greatest divisible power of 3 for 75 is 3
			after diving 75 by 3 we get 25

		Greatest divisible power of 5 for 25 is 25
			after dividing 25 by 25 we get 1

		Since finally we get 1, therefore 300 is an ugly number

*/
/*
class CFG {

	static int maxDivide(int a, int b) {
		while (a % b == 0) {
			a = a / b;
		}

		return a;
	}

	static int isUgly(int num) {
		num = maxDivide(num, 2);
		num = maxDivide(num, 3);
		num = maxDivide(num, 5);

		return (num == 1) ? 1 : 0;
	}

	static int getNthUglyNum(int n) {
		int i = 1;

		int count = 1;

		while (n > count) {
			i++;
			if (isUgly(i) == 1) {
				count++;
			}
		}

		return i;
	}
}
*/
/*
Above method is not time efficient, as it checks for all the integers until ugly number
	count becomes n, but space complexity is O(1)

-------

Dynamic Programming:

	Here is the time efficient solution with O(n) extra space

	The ugly number sequence is 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15

		because every number can only be divided by 2, 3, 5 one way to look at the sequence is to
			split the sequence to three groups as below

		1. 1x2, 2x2, 3x2, 4x2, 5x2
		2. 1x3, 2x3, 3x3, 4x3, 5x3
		3. 1x5, 2x5, 3x5, 4x5, 5x5

		We can find that every subsequence is the ugly-sequence itself
			(1, 2, 3, 4, 5....) multiply 2, 3, 5

		The we can use similar merge method as merge sort, to get every ugly number from the
			three subsequence

	-------

	1. Declare an array for ugly numbers: ugly[n]

	2. Initialize first ugly no: ugly[0] = 1

	3. Initialize three array index variable
			i2, i3, i5 to point to the first element of the ugly array

			i2 = i3 = i5 = 0

	4. Initialize 3 choices for the next ugly no:
			next_multiple_of_2 = ugly[i2] * 2;
			next_multiple_of_3 = ugly[i3] * 3;
			next_multiple_of_5 = ugl2[i5] * 5;

	5. Now we go in the loop to fill all the ugly numbers till 150

		for (int i = 1; i < 150; ++i) {

			next_ugly_no == min(next_multiple_of_2, next_multiple_of_3, next_multiple_of_5);

			ugly[i] = next_ugly_no;

			if (next_ugly_no == next_multiple_of_2) {
				i2 = i2 + 1;
				next_multiple_of_2 = ugly[i2] * 2;
			}

			if (next_ugly_no == next_multiple_of_3) {
				i3 = i3 + 1;
				next_multiple_of_3 = ugly[i3] * 3;
			}

			if (next_ugly_no == next_multiple_of_5) {
				i5 = i5 + 1;
				next_multiple_of_5 = ugly[i5] * 5;
			}
		}

	6.	return next_ugly_no;

*/
/*
Example:

initialize

   ugly[] =  | 1 |

   i2 =  i3 = i5 = 0;

   First iteration:

	   ugly[1] = Min(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5)
	            = Min(2, 3, 5)
	            = 2
	   ugly[] =  | 1 | 2 |
	   i2 = 1,  i3 = i5 = 0  (i2 got incremented)

   Second iteration:

	    ugly[2] = Min(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5)
	             = Min(4, 3, 5)
	             = 3
	    ugly[] =  | 1 | 2 | 3 |
	    i2 = 1,  i3 =  1, i5 = 0  (i3 got incremented)

    Third iteration:

	    ugly[3] = Min(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5)
	             = Min(4, 6, 5)
	             = 4
	    ugly[] =  | 1 | 2 | 3 |  4 |
	    i2 = 2,  i3 =  1, i5 = 0  (i2 got incremented)

    Fourth iteration:

	    ugly[4] = Min(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5)
	              = Min(6, 6, 5)
	              = 5
	    ugly[] =  | 1 | 2 | 3 |  4 | 5 |
	    i2 = 2,  i3 =  1, i5 = 1  (i5 got incremented)

    Fifth iteration:

	    ugly[4] = Min(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5)
	              = Min(6, 6, 10)
	              = 6
	    ugly[] =  | 1 | 2 | 3 |  4 | 5 | 6 |
	    i2 = 3,  i3 =  2, i5 = 1  (i2 and i3 got incremented)

*/

import java.lang.Math;

class UglyNumber {

	int getNthUglyNo(int n) {
		int ugly[] = new int[n];
		int i2 = 0, i3 = 0, i5 = 0;
		int nextMultiple2 = 2;
		int nextMultiple3 = 3;
		int nextMultiple5 = 5;
		int nextUglyNo = 1;
		ugly[0] = 1;
		for (int i = 1; i < n; ++i) {
			nextUglyNo = Math.min(nextMultiple2, Math.min(nextMultiple3, nextMultiple5));
			ugly[i] = nextUglyNo;
			if (nextUglyNo == nextMultiple2) {
				i2 = i2 + 1;
				nextMultiple2 = ugly[i2] * 2;
			}
			if (nextUglyNo == nextMultiple3) {
				i3 = i3 + 1;
				nextMultiple3 = ugly[i3] * 3;
			}
			if (nextUglyNo == nextMultiple5) {
				i5 = i5 + 1;
				nextMultiple5 = ugly[i5] * 5;
			}
		}
		return nextUglyNo;
	}

	public static void main(String[] args) {
		int n = 150;
		UglyNumber obj = new UglyNumber();
		System.out.println(obj.getNthUglyNo(n));
	}
}
