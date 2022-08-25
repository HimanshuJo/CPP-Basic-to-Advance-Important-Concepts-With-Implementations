/*
    You are given a sequence A, where its elements are either in the form + x or -, where x is an integer.

    For such a sequence S where its elements are either in the form + x or -,
        define f(S) as follows:

    iterate through S's elements from the first one to the last one, and maintain a multiset T
        as you iterate through it.
    
    for each element, if it's in the form + x, add x to T; otherwise, erase the smallest element from T (if T
        is empty, do nothing).
    
    after iterating through all S's elements, compute the sum of all elements in T. f(S) is defined as the sum. 

    The sequence b is a subsequence of the sequence a if b can be derived from a by removing zero 
        or more elements without changing the order of the remaining elements.
        
    For all A's subsequences B, compute the sum of f(B), modulo 998244353

Input

The first line contains an integer n (1≤n≤500) — the length of A

Each of the next n lines begins with an operator + or -. 
    If the operator is +, then it's followed by an integer x (1≤x<998244353).
    
    The i-th line of those n lines describes the i-th element in A

Output

Print one integer, which is the answer to the problem, modulo 998244353

Examples
Input

4
-
+ 1
+ 2
-

Output

16

-------

Input

15
+ 2432543
-
+ 4567886
+ 65638788
-
+ 578943
-
-
+ 62356680
-
+ 711111
-
+ 998244352
-
-

Output

750759115

-------

Note

In the first example, the following are all possible pairs of B and f(B)

B={}, f(B)=0

B={-}, f(B)=0

B={+ 1, -}, f(B)=0

B={-, + 1, -}, f(B)=0

B={+ 2, -}, f(B)=0

B={-, + 2, -}, f(B)=0

B={-}, f(B)=0

B={-, -}, f(B)=0

B={+ 1, + 2}, f(B)=3

B={+ 1, + 2, -}, f(B)=2

B={-, + 1, + 2}, f(B)=3

B={-, + 1, + 2, -}, f(B)=2

B={-, + 1}, f(B)=1

B={+ 1}, f(B)=1

B={-, + 2}, f(B)=2

B={+ 2}, f(B)=2

The sum of these values is 16

*/

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int read()
{
    int n;
    cin >> n;
    return n;
}
char readc()
{
    char c;
    cin >> c;
    return c;
}
signed main()
{
    int n = read();
    int a[n + 1];
    char m[n + 1];
    for (int i = 1; i <= n; i++)
    {
        m[i] = readc();
        if (m[i] == '+')
        {
            a[i] = read();
        }
        else
        {
            a[i] = 0;
        }
    }
    int ans = 0;
    for (int t = 1; t <= n; t++)
    {
        if (a[t] == 0)
        {
            continue;
        }
        int f[n + 2][n + 2];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (a[i] == 0)
                {
                    if ((i <= t) || (j > 0))
                    {   // f(i−1,j)→f(i,max(j−1,0)) (here, i<I, and the i-th element of A is -, 
                        // so the number of numbers in T less than x decreases by one. If there is no such number, s remains 0)
                        f[i][max(j - 1, 0ll)] = (f[i][max(j - 1, 0ll)] + f[i - 1][j]) % mod;
                    }
                }
                else
                {
                    if ((a[i] < a[t]) || ((a[i] == a[t]) && (i < t)))
                    {   // f(i−1,j)→f(i,j+1) (here, the i-th element of A is + and its x is less than x or 
                        // [equal to x but $i>I$] ) [this is to deal with same elements]
                        f[i][j + 1] = (f[i][j + 1] + f[i - 1][j]) % mod;
                    }
                    else
                    {  // f(i−1,j)→f(i,j) (here, the i-th element of A is + and its x is greater than X)
                        f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
                    }
                }
                if (i != t)
                {   // f(i−1,j)→f(i,j) (when we don't include the i-th element is S, here i≠I)
                    f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
                }
            }
        }
        for (int i = 0; i <= n; i++)
        {
            ans += (f[n][i] * a[t]);
            ans %= mod;
        }
    }
    cout << ans;
    return 0;
}