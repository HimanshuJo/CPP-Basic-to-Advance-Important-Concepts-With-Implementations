/*
Problem Statement
AtCoder in another world holds 10 types of contests called AAC, ..., AJC. 
There will be N contests from now on.
The types of these N contests are given to you as a string S: if the i-th character of S is x, 
the i-th contest will be AxC.
AtCoDeer will choose and participate in one or more contests from the N so that the following condition is satisfied.

In the sequence of contests he will participate in, the contests of the same type are consecutive.
Formally, when AtCoDeer participates in x contests and the i-th of them is of type Ti, 
    for every triple of integers (i,j,k) such that 1≤i<j<k≤x, Ti=Tj must hold if Ti=Tk
​
Find the number of ways for AtCoDeer to choose contests to participate in, modulo 998244353.
Two ways to choose contests are considered different when there is a contest c such that AtCoDeer 
participates in c in one way but not in the other.

Constraints
1≤N≤1000
∣S∣=N
S consists of uppercase English letters from A through J.

Sample Input 1 
4
BGBH

Sample Output 1 
13
For example, participating in the 1-st and 3-rd contests is valid, and so is participating in the 2-nd and 4-th contests.
On the other hand, participating in the 1-st, 2-nd, 3-rd, and 4-th contests is invalid, since the participations 
in ABCs are not consecutive, violating the condition for the triple (i,j,k)=(1,2,3).
Additionally, it is not allowed to participate in zero contests.
In total, there are 13 valid ways to participate in some contests.
*/
/*
// Following bitDP is possible
dp[for the first i contests][set of contests participated so far][the kind of last participated contest]=
{the number of possible combinations}

The transition of DP is as follows.

Let x be the kind of i-th contest.

    For every set U and every kind of contest j, add dp[i−1][U][j] to dp[i][U][j] 
        (corresponding to when he does not participate in the i-th contest)
        
        If j=x, add dp[i−1][U][j] to it too (corresponding to when he participate in the i-th contest, 
            which is the same kind of contest to that he participated last time)
        
    For every set V that does not include x and every kind of contest j, 
        add dp[i−1][V][j] to dp[i][V′][x], 
        
        where V′ is V with x added (corresponding to when he participate in the i-th contest, 
            which is the different kind of contest to that he participated last time)

    Add 1 to dp[i][W][x], where W is a set only containing x (corresponding to the case where the first contest he 
        participate in is the i-th one)

    For the bitDP with the transitions above, the final solution is the sum of dp[N][U][j] over every set U and 
        every kind of contest j.
    
    The total computational complexity is O(2^KNK)(K=10, the number of contest types), which fits in the time limit.
*/
#include <bits/stdc++.h>
#define mod 998244353
using ll = long long;
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    long long dp[100][100][10] = {0};
    for (int i = 1; i <= n; i++)
    {
        int x = s[i - 1] - 'A';
        for (int u = 0; u < 100; u++)
        {
            for (int j = 0; j < 10; j++)
            {
                dp[i][u][j] = dp[i - 1][u][j];
                if (j == x)
                {
                    dp[i][u][j] += dp[i - 1][u][j];
                    dp[i][u][j] %= mod;
                }
            }
        }
        for (int v = 0; v < 100; v++)
        {
            if (v & (1 << x))
            {
                continue;
            }
            for (int j = 0; j < 10; j++)
            {
                dp[i][v | (1 << x)][x] += dp[i - 1][v][j];
                dp[i][v | (1 << x)][x] %= mod;
            }
        }
        dp[i][(1 << x)][x]++;
        dp[i][(1 << x)][x] %= mod;
    }
    long long res = 0;
    for (int u = 0; u < 100; u++)
    {
        for (int j = 0; j < 10; j++)
        {
            res += dp[n][u][j];
            res %= mod;
        }
    }
    cout << res << '\n';
    return 0;
}
