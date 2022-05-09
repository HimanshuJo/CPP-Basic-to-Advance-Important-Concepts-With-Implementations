/*
To check a number is palindrome or not without using any extra space

Given a number ‘n’ and our goal is to find out it is palindrome or not without using
any extra space. We can’t make a new copy of number

Examples:

Input  : 2332
Output : Yes it is Palindrome.
Explanation:
original number = 2332
reversed number = 2332
Both are same hence the number is palindrome.

Input :1111
Output :Yes it is Palindrome.

Input : 1234
Output : No not Palindrome.
*/
/*
1) We can compare the first digit and the last digit, then we repeat the process.
2) For the first digit, we need the order of the number. Say, 12321.
	Dividing this by 10000 would get us the leading 1.
	The trailing 1 can be retrieved by taking the mod with 10.
3) Now, to reduce this to 232.

(12321 % 10000)/10 = (2321)/10 = 232

4) And now, the 10000 would need to be reduced by a factor of 100.
Here is the implementation of the above algorithm:
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int);

bool isPalindrome(int n)
{
	// Find the appropriate divisor
	// to extract the leading digit
	int divisor = 1;
	while (n / divisor >= 10)
		divisor *= 10;

	while (n != 0)
	{
		int leading = n / divisor;
		int trailing = n % 10;

		// If first and last digit
		// not same return false
		if (leading != trailing)
			return false;

		// Removing the leading and trailing
		// digit from number
		n = (n % divisor) / 10;

		// Reducing divisor by a factor
		// of 2 as 2 digits are dropped
		divisor = divisor / 100;
	}
	return true;
}

int main()
{
	isPalindrome(1001) ? cout << "Yes, it is Palindrome" :
	                     cout << "No, not Palindrome";
	return 0;
}

/*
Output:

Yes, it is Palindrome
*/