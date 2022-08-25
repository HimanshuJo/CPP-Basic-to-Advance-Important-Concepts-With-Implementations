/*
Finally, you have defeated Razor and now, you are the Most Wanted street racer. 
Sergeant Cross has sent the full police force after you in a deadly pursuit. 
Fortunately, you have found a hiding spot but you fear that Cross and his force will eventually find you. 
To increase your chances of survival, you want to tune and repaint your BMW M3 GTR.

The car can be imagined as a permuted n-dimensional hypercube. A simple n-dimensional hypercube is an 
undirected unweighted graph built recursively as follows:

    Take two simple (n−1)-dimensional hypercubes one having vertices numbered from 0 to 2n−1−1 and the other 
    having vertices numbered from 2n−1 to 2n−1. A simple 0-dimensional Hypercube is just a single vertex.

Add an edge between the vertices i and i+2n−1 for each 0≤i<2n−1

A permuted n-dimensional hypercube is formed by permuting the vertex numbers of a simple n-dimensional 
hypercube in any arbitrary manner.

Note that a permuted n-dimensional hypercube has the following properties:

    There are exactly 2n vertices.
    There are exactly n⋅2^(n−1)edges.
    Each vertex is connected to exactly n other vertices.
    There are no self-loops or duplicate edges. 

Let's denote the permutation used to generate the permuted n
-dimensional hypercube, representing your car, from a simple n-dimensional hypercube by P

Before messing up the functionalities of the car, you want to find this permutation so that you can 
restore the car if anything goes wrong. But the job isn't done yet.

You have n different colours numbered from 0 to n−1. You want to colour the vertices of this permuted 
n-dimensional hypercube in such a way that for each and every vertex u satisfying 0≤u<2n and for each and 
every colour c satisfying 0≤c<n, there is at least one vertex v adjacent to u having a colour c

In other words, from each and every vertex, it must be possible to reach a vertex of any colour by 
just moving to an adjacent vertex.

Given the permuted n-dimensional hypercube, find any valid permutation P and colouring.
Input

The first line of input contains a single integer t(1≤t≤4096) — the number of test cases.

For each test case, the first line contains a single integer n
(1≤n≤16).

Each of the next n⋅2^(n−1) lines contain two integers u and v (0≤u,v<2n) denoting that there is an edge 
between the vertices numbered u and v

It is guaranteed that the graph described in the input is a permuted n -dimensional hypercube.

Additionally, it is guaranteed that the sum of 2n over all test cases does not exceed 2^16=65536

Output

For each test case, print two lines.

In the first line, output any permutation P of length 2n that can be used to transform a simple 
n-dimensional hypercube to the permuted n -dimensional hypercube given in the input. 
Two permuted hypercubes are considered the same if they have the same set of edges. 
If there are multiple answers, output any of them.

In the second line, print the colouring. If there is no way to colour the vertices satisfying the conditions, output −1
Otherwise, output a single line containing 2n space separated integers. 
The i-th integer must be the colour of the vertex numbered (i−1) in the permuted n-dimensional hypercube. 
If there are multiple answers, output any of them.

Example
Input

3
1
0 1
2
0 1
1 2
2 3
3 0
3
0 1
0 5
0 7
1 2
1 4
2 5
2 6
3 5
3 6
3 7
4 6
4 7

Output

0 1
0 0
0 1 3 2
0 0 1 1
5 3 0 7 2 6 1 4
-1

*/
/*
    H1: 
        In a simple n-Dimensional Hypercube, two vertices are connected if and only if they 
        differ by exactly 1 bit in their binary representation.

    H2:
    
        The n-Dimensional Hypercubes are highly symmetric and all vertices are equivalent.

    H3:
    
        If we select a particular vertex, then all directions in which the edges 
        connected to it goes are also equivalent.

    H4:
        
        For any two vertices a and b separated at a distance of exactly 2, 
        there are exactly 2 vertices connected to both a and b.

    H5:
    
        Any permuted n-Dimensional Hypercube is isomorphic to the simple n-Dimensional Hypercube. 
        So, its structure is same as the simple n-Dimensional Hypercube.

    Before moving to the solution, notice a very important property of simple 
    n-Dimensional Hypercubes — Two vertices a and b are connected if and only if a and b differ 
    by exactly one bit in their binary representations.

    The permutation can be found using the following greedy algorithm — 
    First, assign any arbitrary vertex as p0
    This is obvious since all vertices are equivalent. Then, in the simple n-Dimensional Hypercube, 
    all powers of 2 must be connected to the vertex 0. 
    Moreover, these vertices are added only when we are adding another dimension to the cube. 
    Since all directions are also equivalent, it does not matter in which direction we add a new dimension. 
    So, we can assign all the n vertices connected to p0 in the permuted n-Dimensional Hypercube 
    as p1, p2, p4, p8, …, p2n−1 in any arbitrary order. 
    Now, we will find pu for the remaining vertices in increasing order of u

    In order to find pu, first find a set S of vertices v such that v<u and v is connected to u 
    in the simple n-Dimensional Hypercube. 
    Then find any vertex w connected to all the vertices pv such that v∈S in the permuted 
    n-Dimensional Hypercube and assign pu=w. 
    I claim that we can never make a wrong choice because we will never have a choice! 
    There will only be one such vertex w for any u. Let's prove it.

    Proof

        Consider two vertices v1 and v2 in the set S. These vertices will differ by exactly 2 bits in their 
        binary representation. Let the bits in which they differ be bx and by. 
        Then, they will have the form v1=…bx…by… and v2=…b′x…b′y… where … represent the same bits. 
        Now, only two vertices u1=…bx…b′y… and u2=…b′x…by… can be connected to both v1 and v2. 
        Since a permuted n-Dimensional Hypercube is isomorphic to a simple n-Dimensional Hypercube, 
        there will only be two vertices connected to both pv1 and pv2 in the permuted n-Dimensional Hypercube also.

        If we iterate over u in increasing order, then bx≠by, otherwise one of v1 or v2 will be greater than 
        u which is a contradiction. So, the only vertices connected to both v1 and v2 will have the forms 
        u1=…0…0… and u2=…1…1…. Now since u1<v1 and u1<v2, pu1 has already been calculated and so, one of the 
        vertex connected to both pv1 and pv2 in the permuted n-Dimensional Hypercube has already been used. 
        So, we are left with only one choice for such a vertex w.

    H7:

        Instead of colouring the permuted n-Dimensional Hypercube, try to colour the simple 
        n-Dimensional Hypercube and map these colours to the permuted one in the end using the 
        permutation found in Part 1.

    H8:

        The number of vertices of each colour will be equal.

    H9:

        Try to colour a simple 4-Dimensional Hypercube. This is not a graph problem, rather a constructive problem.

    H10:

        The way in which vertices are connected in a simple n-Dimensional Hypercube suggests 
        something related to Bitwise XOR.

    -------

    Tutorial: Part 2 - Colouring the Hypercube

        Let's try to colour the simple n-Dimensional Hypercube instead of the permuted one. 
        We can map the colours to the permuted one in the end using the permutation found in Part 1.

        I claim that if n is not a power of 2, then no colouring exists. A simple explanation is that the graph 
        is symmetric and also the colours. So, it is natural that the number of vertices of each colour must be 
        equal meaning 2n must be divisible by n or in other words, n must be a power of 2 itself. 
        
        But if symmetry doesn't satisfy you, I have a formal proof too.
    
    Proof

        According to the condition, every vertex must be connected to at least one vertex of every 
        colour or equivalently, exactly one vertex of every colour since there are n
        colours and n neighbours of each vertex. So, if we consider the set of neighbours of any vertex, 
        every colour will appear exactly once in that set. 
        If we consider the multi-set of neighbours of all vertices, every colour will appear 2n times in that set. 
        But every vertex has been counted n times in this multi-set because a particular vertex is the 
        neighbour of n other vertices. So, if we consider the set of all vertices, every colour will appear 2n 
        times in that set. Obviously, this number must be a whole number. So, 2^n must be divisible by n 
        or in other words, n must itself be a power of 2 for a colouring to exist. 
        Otherwise, it doesn't exist. To show that a colouring exists if n is a power of 2, we will 
        construct a colouring.
*/

#include <bits/stdc++.h>
using namespace std;

void permuteHypercube(int n, int m, vector<int> adj[], set<int> s[], int p[])
{
    for (int i = 0; i < m; i++)
        p[i] = -1;
    bool used[m];
    for (int i = 0; i < m; i++)
        used[i] = false;
    p[0] = 0;
    used[0] = true;
    for (int u = 1; u < m; u++)
    {
        vector<int> req;
        for (int i = 0; i < n; i++)
        {
            int v = u ^ (1 << i);
            if (v < u)
                req.push_back(v);
        }
        if (req.size() == 1)
        {
            int v = req[0];
            for (int i = 0; i < adj[p[v]].size(); i++)
            {
                int w = adj[p[v]][i];
                if (used[w])
                    continue;
                p[u] = w;
                used[w] = true;
                break;
            }
        }
        else
        {
            int v = req[0];
            for (int i = 0; i < adj[p[v]].size(); i++)
            {
                int w = adj[p[v]][i];
                if (used[w])
                    continue;
                if (s[w].find(p[req[1]]) != s[w].end())
                {
                    p[u] = w;
                    used[w] = true;
                    break;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m = (1 << n);
        int p[m];
        set<int> s[m];
        vector<int> adj[m];
        for (int i = 0; i < n * m / 2; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            s[u].insert(v);
            s[v].insert(u);
        }
        permuteHypercube(n, m, adj, s, p);
        for (int i = 0; i < m; i++)
            cout << p[i] << " ";
        cout << '\n';
        if (n != 1 && n != 2 && n != 4 && n != 8 && n != 16)
        {
            cout << -1 << '\n';
            continue;
        }
        int temp[m];
        for (int i = 0; i < m; i++)
        {
            int clr = 0;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                    clr = clr ^ j;
            }
            temp[i] = clr;
        }
        int c[m];
        for (int i = 0; i < m; i++)
            c[p[i]] = temp[i];
        for (int i = 0; i < m; i++)
            cout << c[i] << " ";
        cout << '\n';
    }
}