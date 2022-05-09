// Three Divisors
/*
Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.

An integer m is a divisor of n if there exists an integer k such that n = k * m.

Example 1:

Input: n = 2
Output: false
Explantion: 2 has only two divisors: 1 and 2.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPrime(long int n)
    {
        if (n == 1)
        {
            return false;
        }
        int i = 2;
        while (i * i <= n)
        {
            if (n % i == 0)
            {
                return false;
            }
            i += 1;
        }
        return true;
    }

    vector<int> addDivisors(int n)
    {
        vector<int> allDivs;
        for (int i = 1; i * i < n; i++)
        {
            if (n % i == 0)
                allDivs.push_back(i);
        }
        for (int i = sqrt(n); i >= 1; i--)
        {
            if (n % i == 0)
                allDivs.push_back(n / i);
        }
        return allDivs;
    }

    bool isThree(int n)
    {
        if (n == 1)
            return false;
        if (isPrime(n))
        {
            return false;
        }
        else
        {
            vector<int> divs;
            divs = addDivisors(n);
            if (divs.size() > 3)
            {
                return false;
            }
            return true;
        }
    }
};