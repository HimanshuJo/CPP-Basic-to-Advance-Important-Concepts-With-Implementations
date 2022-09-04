// C. Little Alawn's Puzzle
/*
When he's not training for IOI, Little Alawn enjoys playing with puzzles of various types to 
stimulate his brain. Today, he's playing with a puzzle that consists of a 2×n grid where each row is a 
permutation of the numbers 1,2,3,…,n.

The goal of Little Alawn's puzzle is to make sure no numbers on the same column or row are the same 
(we'll call this state of the puzzle as solved), and to achieve this he is able to swap the numbers 
in any column. However, after solving the puzzle many times, Little Alawn got bored and began wondering 
about the number of possible solved configurations of the puzzle he could achieve from an initial solved 
configuration only by swapping numbers in a column.

Unfortunately, Little Alawn got stuck while trying to solve this harder problem, so he was 
wondering if you could help him with it. Find the answer modulo 10^9+7.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤10^4). 
Description of the test cases follows.

The first line of each test case contains a single integer n (2≤n≤4⋅10^5).

The next two lines of each test case describe the initial state of the puzzle grid. 
Each line will be a permutation of the numbers 1,2,3,…,n and the numbers in each column and 
row will be pairwise distinct.

It is guaranteed that the sum of n over all test cases does not exceed 4⋅10^5.

Output
For each test case output a single integer, the number of possible solved configurations of 
the puzzle Little Alawn can achieve from an initial solved configuration only by swapping numbers 
in a column. As the answer can be very large, please output it modulo 10^9+7.

The answer for each test case should be on a separate line.

Example
input
2
4
1 4 2 3
3 2 1 4
8
2 6 5 1 4 3 7 8
3 8 7 5 1 2 4 6

output
2
8
Note
The two possible puzzle configurations for example 1 are:

[1,4,2,3] in the first row and [3,2,1,4] in the second;
[3,2,1,4] in the first row and [1,4,2,3] in the second.
*/

#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MN = 4e5 + 1;
const ll mod = 1e9 + 7;
bool seen[MN];
vector<int> adj[MN];
int arr[MN][2];

void dfs(int i)
{
    seen[i] = true;
    for (auto x : adj[i])
        if (!seen[x])
            dfs(x);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i][0];
            adj[i] = vector<int>();
            seen[i] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i][1];
        }
        for (int i = 1; i <= n; i++)
        {
            adj[arr[i][0]].push_back(arr[i][1]);
            adj[arr[i][1]].push_back(arr[i][0]);
        }
        ll ans = 1;
        for (int i = 1; i <= n; i++)
        {
            if (!seen[i])
            {
                ans = ans * ll(2) % mod;
                dfs(i);
            }
        }
        printf("%lli\n", ans);
    }
    return 0;
}