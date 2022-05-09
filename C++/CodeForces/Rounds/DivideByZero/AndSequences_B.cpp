
/*

A sequence of n non-negative integers (n≥2) a1,a2,…,an is called good if for all i from 1 to n−1 the
    following condition holds true:

        a1 & a2 & … & ai = ai+1 & ai+2 & … & an

where & denotes the bitwise AND operation.

You are given an array a of size n (n≥2). Find the number of permutations p of numbers ranging from 1 to n,
for which the sequence ap1, ap2, ... ,apn is good. Since this number can be large, output it modulo 10e9+7.

Input

The first line contains a single integer t(1≤t≤104), denoting the number of test cases.

The first line of each test case contains a single integer n (2≤n≤2⋅10^5) — the size of the array.

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤10^9) — the elements of the array.

It is guaranteed that the sum of n over all test cases doesn't exceed 2⋅10^5

Output

Output t lines, where the i-th line contains the number of good permutations in the i-th test case modulo 10^9+7.

Example
Input

4
3
1 1 1
5
1 2 3 4 5
5
0 2 0 3 0
4
1 3 5 1

Output

6
0
36
4


Note

In the first test case, since all the numbers are equal, whatever permutation we take, the sequence is good.
There are a total of 6 permutations possible with numbers from 1 to 3:
    [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]

In the second test case, it can be proved that no permutation exists for which the sequence is good.

In the third test case, there are a total of 36 permutations for which the sequence is good. One of them is
the permutation [1,5,4,2,3] which results in the sequence s=[0,0,3,2,0]

This is a good sequence because

s1=s2&s3&s4&s5=0,

s1&s2=s3&s4&s5=0,

s1&s2&s3=s4&s5=0,

s1&s2&s3&s4=s5=0

*/

/*

Consider an arbitrary sequence b1, b2, b3,... bn

    First let us define the array AND_pref and AND_suf of length n where

    AND_pref = b1 & b2 & b3,...& bi and

    AND_suf = bi & bi+1 & bi+2,... & bn

    According to the definition of good sequence

        AND_pref1 = AND_suf2

            that basically means that:

                b1 = b2 & b3 & b4 ... & bn
                b1 & b2 = b3 & b4 & b5 ... & bi ... & bn
                b1 & b2 & b3 = b4 & b5 .... & bi ... & bn
                and so on

    Now

        AND_pref2 <= AND_pref1 = AND_suf2 <= AND_suf3

            Suppose we have an array -> 1 1 1

                so, b1 = 1
                    b1 & b2 = 1 & 1 = 1
                    b1 & b2 & b3 = 1 & 1 & 1 (the values will always be either equal or less but never greater)

    Also according to the definition of good sequence,

        AND_pref2 = AND_suf3 (which means b1 = b2 & b3 & ... & bn)

            That means that b1 = AND_pref2 = AND_suf3

        Similarly for all i from 1 to n we get

            AND_prefi = b1

            ANd_sufi = b1

    Therefore for the sequence to be good b1 = bn and the bi must be a super mask of b1 for all i from 2 to n - 1

    -------

    Initially we have an array a1, a2, a3....,an

    Let the minimum value among these elements be x

    Let the number of elements that have the value of x be cnt

    In order to rearrange the elements of a1, a2, a3...., an to a good sequence
        we need to have cnt >= 2 and the remaining elements need to be super mask of x

    If we don't meet this criterion, then the answer is 0

    Else the answer will be

        (cnt * (cnt - 1) * (n - 2)!) % (10^9 + 7)

*/

#include<bits/stdc++.h>
using namespace std;

void solve ()
{
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];    
    int min1 = *min_element(a.begin(), a.end());
    int cnt = 0;
    for (int x : a)
    {
        if (min1 == x) cnt++;
        if ((min1 & x) != min1)
        {
            printf("0\n");
            return;
        }
    }
    int fact = 1;
    for (int i = 1; i <= n - 2; ++i)
    {
        fact = (1LL * fact * i) % mod;
    }
    int ans = (1LL * cnt * (cnt - 1)) % mod;
    ans = (1LL * ans * fact) % mod;
    printf("%d\n", ans);
}

int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}