/*
Sum of all substrings of a string representing a number

	Given an integer represented as a string, we need to get the sum of all possible substrings of this string.
	Examples:  

	Input  : num = “1234”
	Output : 1670
	Sum = 1 + 2 + 3 + 4 + 12 + 23 +
	       34 + 123 + 234 + 1234 
	    = 1670

	Input  : num = “421”
	Output : 491
	Sum = 4 + 2 + 1 + 42 + 21 + 421 = 491

	We can solve this problem by using dynamic programming. 
	We can write a summation of all substrings on basis of the digit at which they are ending in that case, 
	
	Sum of all substrings = sumofdigit[0] + sumofdigit[1] + sumofdigit[2] … + sumofdigit[n-1] 
	where n is length of string.
	
		Where sumofdigit[i] stores the sum of all substring ending at ith index digit, in the above example,

			Example : num = "1234"
			sumofdigit[0] = 1 = 1
			sumofdigit[1] = 2 + 12  = 14
			sumofdigit[2] = 3 + 23  + 123 = 149
			sumofdigit[3] = 4 + 34  + 234 + 1234  = 1506
			Result = 1670

		Now we can get the relation between sumofdigit values and can solve the question iteratively. 

		Each sumofdigit can be represented in terms of previous value as shown below, 

			For above example,
			sumofdigit[3]  = 4 + 34 + 234 + 1234
				           = 4 + 30 + 4 + 230 + 4 + 1230 + 4
				           = 4*4 + 10 * (3 + 23 + 123)
				           = 4*4 + 10 * sumofdigit[2]
			In general, 
				
				sumofdigit[i]  =  (i+1) * num[i] + 10 * sumofdigit[i-1]
*/

// C++ program to print sum of all substring of
// a number represented as a string
#include <bits/stdc++.h>
using namespace std;

int toDigit(char ch)
{
	return (ch - '0');
}

// Returns sum of all substring of num
int sumOfSubstrings(string num)
{
	int n = num.length();
	int prev = toDigit(num[0]);
	int res = prev;
	int current = 0;

	// substrings sum upto current index
	// loop over all digits of string
	for (int i = 1; i < n; i++) {
		int numi = toDigit(num[i]);

		// update each sumofdigit from previous value
		current = (i + 1) * numi + 10 * prev;

		// add current value to the result
		res += current;
		prev = current; // update previous
	}

	return res;
}

int main()
{
	string num = "1234";
	cout << sumOfSubstrings(num) << endl;
	return 0;
}

//Output: 1670