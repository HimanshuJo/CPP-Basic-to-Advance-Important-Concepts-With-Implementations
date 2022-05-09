// Game on Tree 2
/*
We have a tree with N vertices numbered 1 through N. 
The i-th edge (1≤i≤N−1) connects Vertex ui and Vertex vi, 
and Vertex i (1≤i≤N) has an even number Ai written on it. 
Taro and Jiro will play a game using this tree and a piece.

Initially, the piece is on Vertex 1. With Taro going first, the players alternately move the piece to a vertex directly connected to the vertex on which the piece lies. However, the piece must not revisit a vertex it has already visited. 
The game ends when the piece gets unable to move.

Taro wants to maximize the median of the (multi-)set of numbers written on the vertices visited by the piece before the end of the game (including Vertex 1), and Jiro wants to minimize this value. 
Find the median of this set when both players play optimally.

Sample Input 1 
5
2 4 6 8 10
4 5
3 4
1 5
2 4
Sample Output 1 
7
When both players play optimally, the game goes as follows.

Taro moves the piece from Vertex 1 to Piece 5.
Jiro moves the piece from Vertex 5 to Piece 4.
Taro moves the piece from Vertex 4 to Piece 3.
Jiro cannot move the piece, so the game ends.
Here, the set of numbers written on the vertices visited by the piece is {2,10,8,6}. The median of this set is 7, which should be printed.
*/
/*
Let us assume Vertex 1 as the root. Then the piece can only move towards leaves, so the final position of the piece at the end of the game uniquely determines the set of vertices passed through so far and the median.

Once we find for every leaf the median after finishing the game at the vertex, 
we can solve the problem with a DP (Dynamic Programming) on the tree.

Therefore, during DFS, we want to process the following operations fast:

Add X to a (multi-)set S of integers.
Remove X from S.
Find the median of S.
The following two approaches are possible.
*/
#include <bits/stdc++.h>
using namespace std;

multiset<int> S, T; // Always S.size()==T.size() or S.size()==T.size()+1
void eval()
{
    if (S.size())
    {
        auto itr = S.end();
        itr--;
        T.insert(*itr);
        S.erase(itr);
    }
    while (S.size() < T.size())
    {
        S.insert(*T.begin());
        T.erase(T.begin());
    }
}
int val()
{
    auto itr = S.end();
    itr--;
    if (S.size() == T.size() + 1)
        return *itr;
    return (*itr + *T.begin()) / 2;
}
void erase(int x)
{
    auto itr = S.end();
    itr--;
    if (*itr < x)
        T.erase(T.lower_bound(x));
    else
        S.erase(S.lower_bound(x));
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    vector<int> dp(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    function<void(int, int, int)> dfs = [&](int i, int p, int d)
    {
        S.insert(A[i]);
        eval();
        int mi = 1000000005, ma = 0;
        for (int x : g[i])
            if (x != p)
            {
                dfs(x, i, d + 1);
                mi = min(mi, dp[x]);
                ma = max(ma, dp[x]);
            }
        if (ma == 0)
            dp[i] = val();
        else if (d & 1)
            dp[i] = mi;
        else
            dp[i] = ma;
        erase(A[i]);
        eval();
    };
    dfs(0, -1, 0);
    cout << dp[0] << endl;
}
