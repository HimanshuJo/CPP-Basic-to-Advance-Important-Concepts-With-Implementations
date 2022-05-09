// Number of Ways to Separate Numbers
/*
You wrote down many positive integers in a string called num. However, you realized that you forgot to add 
commas to seperate the different numbers. You remember that the list of integers 
was non-decreasing and that no integer had leading zeros.

Return the number of possible lists of integers that you could have written down 
to get the string num. Since the answer may be large, return it modulo 109 + 7.

Example 1:

Input: num = "327"
Output: 2
Explanation: You could have written down the numbers:
3, 27
327
Example 2:

Input: num = "094"
Output: 0
Explanation: No numbers can have leading zeros and all numbers must be positive.
Example 3:

Input: num = "0"
Output: 0
Explanation: No numbers can have leading zeros and all numbers must be positive.
Example 4:

Input: num = "9999999999999"
Output: 101

Constraints:

1 <= num.length <= 3500
num consists of digits '0' through '9'.
*/

/*I found it curious that a simple dynamic programming approach works if you use a fast 
string compare function like memcmp.

Array a[i][j] is the subsolution where the first number starts at i and ends at j.
Array b[i][j] is the suffix sum of a[i][j].
With these i and j, the second number starts at j+1. If it is longer, it can follow the 
first number. 
If it is shorter, it can't. The problem is when the numbers have the same length. 
We need to compare the two numbers fast.

The trick is to compare them using memcmp, which happens to be faster than, say, 
strncmp, or a naive comparison loop, 
or if extracting substrings and comparing them using <=. Perhaps this is a hack. 
I get less than 300 ms.*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfCombinations(string num)
    {
        int n = num.length();
        vector<vector<int>>a(n, vector<int>(n, 0)), b(n, vector<int>(n, 0));
        int MOD = 1000000007;
        for (int i = n - 1; i >= 0; i--)
        {
            if (num[i] == '0')
                continue;
            for (int j = n - 1, sum = 0; j >= i; j--)
            {
                if (j == n - 1)
                    a[i][j] = 1;
                else
                {
                    int len = j - i + 1, first = j + 1, last = first + len, cnt = 0;
                    if (last <= n && memcmp(&num[i], &num[first], len) <= 0)
                        cnt = (cnt + a[first][last - 1]) % MOD;
                    if (last < n)
                        cnt = (cnt + b[first][last]) % MOD;
                    a[i][j] = cnt;
                }
                b[i][j] = sum = (sum + a[i][j]) % MOD;
            }
        }
        return b[0][0];
    }
};