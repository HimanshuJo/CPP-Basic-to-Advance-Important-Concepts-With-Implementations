// Destruction
/*
Problem Statement
We have a connected undirected graph with N vertices and M edges.
The vertices are numbered 1 through N, and the edges are numbered 1 through M. 
Edge i connects Vertices Ai and Bi

Takahashi is going to remove zero or more edges from this graph.

When removing Edge i, a reward of Ci is given if Ci≥0, and a fine of ∣Ci∣ is incurred if Ci<0.

Find the maximum total reward that Takahashi can get when the graph must be 
connected after removing edges.

Sample Input 1 
4 5
1 2 1
1 3 1
1 4 1
3 2 2
4 2 2

Sample Output 1 
4
Removing Edges 4 and 5 yields a total reward of 4. You cannot get any more, so the answer is 4.
*/
/*
Let’s first remove all the edges and receive the reward, and consider that 
“we have to pay a fine of Ci when restoring (decide not to remove) Edge i.” 
Then the original problem can be boiled down to a problem to minimize the 
amount of fine required to make the graph connected, which can be solved by 
finding the minimum spanning tree of graph with the cost of Edge i defined as Ci.

Note that we do not remove the edges Ci<0 even if it is not included in the 
minimum spanning tree.

Note that this problem can also be solved greedily by 
“inspecting the edge in the decreasing order of Ci, and remove it if the graph 
remains connected after removing the edge.” However an advanced algorithm is 
required to determine the connectivity after removing an edge fast enough.

*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Edge
{
    int u, v, w;
} edge[200002];
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int n, m, ans, f[200002];
int find(int x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}
map<int, bool> book;
int tot = 0;
void run()
{
    sort(edge + 1, edge + m + 1, cmp);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= m; i++)
    {
        if (find(edge[i].u) == find(edge[i].v))
            continue;
        book[i] = 1;
        f[find(edge[i].u)] = find(edge[i].v);
        ans += edge[i].w;
    }
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
        tot += edge[i].w;
    }
    run();
    for (int i = 1; i <= m; i++)
    {
        if (book[i] || edge[i].w < 0)
        {
            tot -= edge[i].w;
        }
    }
    cout << tot << "\n";
    system("pause -> u");
}