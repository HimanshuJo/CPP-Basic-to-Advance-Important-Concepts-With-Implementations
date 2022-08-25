/*
An array b of length k is called good if its arithmetic mean is equal to 1. 

More formally, if b1+⋯+bkk=1.

Note that the value b1+⋯+bk is not rounded up or down. For example, the array [1,1,1,2] has an 
arithmetic mean of 1.25, which is not equal to 1

You are given an integer array a of length n

In an operation, you can append a non-negative integer to the end of the array.

What's the minimum number of operations required to make the array good?

We have a proof that it is always possible with finitely many operations.
Input

The first line contains a single integer t (1≤t≤1000) — the number of test cases. 

Then t test cases follow.

The first line of each test case contains a single integer n
(1≤n≤50) — the length of the initial array a

The second line of each test case contains n integers a1,…,an (−10^4≤ai≤10^4), the elements of the array.

Output

For each test case, output a single integer — the minimum number of non-negative integers you have to append to the array 
so that the arithmetic mean of the array will be exactly 1

Example
Input

4
3
1 1 1
2
1 2
4
8 4 6 2
1
-2

Output

0
1
16
1

Note

In the first test case, we don't need to add any element because the arithmetic mean of the array is already 1
, so the answer is 0

In the second test case, the arithmetic mean is not 1
initially so we need to add at least one more number. 

If we add 0 then the arithmetic mean of the whole array becomes 1, so the answer is 1

In the third test case, the minimum number of elements that need to be added is 16
since only non-negative integers can be added.

In the fourth test case, we can add a single integer 4
The arithmetic mean becomes −2+42 which is equal to 1.
*/

/*
    To make arithmetic mean ne equal to exactly 1, the sum needs to be equal to the number of elements
        in the array

    Let's consider 3 cases for this problem:
        1. The sum of the array equals to n: Here the answer is 0 since the arithmetic mean of the array is
            initially 1

        2. The sum of the array is smaller than n:

            The answer is always 1 since we can add a single integer k such that
                sum + k = n + 1 is satisfied

                specifically k = n - sum + 1

        3. The sum of the array is greater than n:

            If we add any number apart from 0, will add to the sum more or equal than to the number of elements

            The number of 0's to add can be found by a loop of adding 0's until the number of elements
                is equal to the sum or by the simple formula of:
                    sum - n
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            sum += a;
        }
        if (sum < n)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << sum - n << "\n";
        }
    }
}