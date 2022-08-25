/*
You are given an array a of n (n≥2) positive integers and an integer p. 
Consider an undirected weighted graph of n vertices numbered from 1 to n for which the 
edges between the vertices i and j (i<j) are added in the following manner:

If gcd(ai,ai+1,ai+2,…,aj) = min(ai,ai+1,ai+2,…,aj), then there is an edge of weight 
    min(ai,ai+1,ai+2,…,aj) between i and j

If i+1=j, then there is an edge of weight p between i and j.

Note that there could be multiple edges between i and j if both of the above conditions are true, 
and if both the conditions fail for i and j, then there is no edge between these vertices.

The goal is to find the weight of the minimum spanning tree of this graph.

Input

The first line contains a single integer t(1≤t≤10^4) — the number of test cases.

The first line of each test case contains two integers n (2≤n≤2⋅105) and p (1≤p≤109) — 
the number of nodes and the parameter p

The second line contains n integers a1,a2,a3,…,an (1≤ai≤10^9)

It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5.

Output

Output t lines. For each test case print the weight of the corresponding graph.

Example
Input

4
2 5
10 10
2 5
3 3
4 5
5 2 4 9
8 8
5 3 3 6 10 100 9 15

Output

5
3
12
46
*/

/*
    We can iterate from the smallest to the largest number like in krushkal's algorithm.
        By this we can consider the edges with the smallest weight first

    Now while iterating, we will assume that the current value as the gcd we want to get, let's
        say 'g' and we will go left and then right while going left/right,

        if  gcd(newElement, g) = g, we will add an edge in the graph between the corresponding
            positions of the 'newElement' and 'g'

        Also while adding edge we must keep in mind that we shouldn't create a cycle.

        If we are forming a cycle, we shouldn't add this edge and stop spanning in that direction

        We can use a DSU to check this but in this particular problem, this is not required

        We can simply check previously whether there is any edge connected to newElement.

            If so, we will add this edge and stop spanning further entry forms a cycle
                (We are adding edges in segments kind of fashion)

        Also we need to stop when the current g we are considering is greater than the parameter 'p'
            since we can connect the currently connected components by edges with the weight p

    The total number of edges considered would be O(N), and then the overall time complexity
        of finding MST would be O(N log N) due to sorting
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    // we need a boolean array to tell whether vertices i and i + 1 are connected for 0<=i<n-1
    vector<bool> isConnected(n);
    vector<pair<int, int>> vals;
    for (int i = 0; i < n; ++i)
    {
        vals.push_back(make_pair(a[i], i));
    }
    sort(vals.begin(), vals.end());
    long long int ans = 0;
    for (auto p : vals)
    {
        int curVal = p.first;
        int i = p.second;
        if (curVal >= x)
        {
            break;
        }
        while (i > 0)
        {
            if (isConnected[i - 1])
            {
                break;
            }
            if (a[i - 1] % curVal == 0)
            {
                isConnected[i - 1] = true;
                ans += curVal;
                i--;
            }
            else
            {
                break;
            }
        }
        i = p.second;
        while (i < n - 1)
        {
            if (isConnected[i])
                break;
            if (a[i + 1] % curVal == 0)
            {
                isConnected[i] = true;
                ans += curVal;
                i++;
            }
            else
            {
                break;
            }
        }
    }
    for (int i = 0; i < n - 1; ++i)
    {
        if (!isConnected[i])
        {
            ans += x;
        }
    }
    cout << ans << "\n";
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}