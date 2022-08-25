/*
You are given n integers a1,a2,…,an and an integer k. 
Find the maximum value of i⋅j−k⋅(ai|aj) over all pairs (i,j) of integers 
with 1≤i<j≤n. Here, | is the bitwise OR operator.

Input
The first line contains a single integer t (1≤t≤10000)  — the number of test cases.

The first line of each test case contains two integers n (2≤n≤10^5) 
and k (1≤k≤min(n,100)).

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤n).

It is guaranteed that the sum of n over all test cases doesn't exceed 3⋅10^5.

Output
For each test case, print a single integer  — the maximum possible 
value of i⋅j−k⋅(ai|aj).

Example
input
4
3 3
1 1 3
2 2
1 2
4 3
0 1 2 3
6 6
3 2 0 0 5 6

output
-1
-4
3
12
*/
/*
Let f(i,j)=i⋅j−k⋅(ai|aj) for i<j.

Do we really need to check all pairs?

The value of k is small, which is suspicious. There must be something revolving around it. 
What can that be?

In the equation, i⋅j can be O(n2), but k⋅(ai|aj) is O(n⋅100). 
That means the value of f(i,j) must be larger for bigger i,j. Can you deduce something from this?

What is the smallest i which can contribute to the result(f(i,j):i<j is the maximum)? 
Pause and think. Hint: try to maximize f(i,j) and minimize the heaviest pair, 
that is, f(n−1,n), and compare them.

Let's find it. What is the maximum possible value of a pair containing i?. 
It's when i pairs with n and ai=an=0. So, f(i,n)=i⋅n−k⋅0=i⋅n.

What is the minimum possible value of the heaviest pair f(n−1,n)? It's when an−1|an is 
maximum. And, since 0≤ai≤n, the maximum possible of value any ai|aj is ≤2n. 
So f(n−1,n)=(n−1)⋅n−k⋅2n=n2−2kn−n.

For i to contribute to the result, f(i,n) must be >f(n−1,n). And, when f(i,n)>f(n−1,n), 
then i⋅n>n2−2kn−n, or i>n−2k−1. So any of f(i,j) such that i<n−2k won't
 generate a value greater than f(n−1,n)!. This indicates us that we just 
 have to check the pairs f(i,j) such that i,j≥n−2k. And, there are only O(k^2)
  such pairs, so we can brute-force.

We have also allowed O(n⋅k) solutions to pass i.e. brute-forcing over all pairs such that 
1≤i≤n and n−2k≤j≤n.

Time Complexity: O(k^2)
*/

#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        long long ans = -1e12;
        int l = max(1, n - 2 * k);
        for (int i = l; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ans = max(ans, 1LL * i * j - 1LL * k * (a[i] | a[j]));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}