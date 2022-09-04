// D. Lost Tree
/*
This is an interactive problem.

Little Dormi was faced with an awkward problem at the carnival:
he has to guess the edges of an unweighted tree of n
nodes! The nodes of the tree are numbered from 1 to n.

The game master only allows him to ask one type of question:

    Little Dormi picks a node r (1≤r≤n), and the game master will reply with
    an array d1,d2,…,dn, where di is the length of the shortest path
    from node r to i, for all 1≤i≤n.

Additionally, to make the game unfair challenge Little Dormi the game
master will allow at most ⌈n/2⌉ questions, where ⌈x⌉ denotes the smallest
integer greater than or equal to x.

Faced with the stomach-churning possibility of not being able to guess
the tree, Little Dormi needs your help to devise a winning strategy!

Note that the game master creates the tree before the game starts,
and does not change it during the game.

Input

The first line of input contains the integer n (2≤n≤2000),
the number of nodes in the tree.

You will then begin interaction.

Output

When your program has found the tree, first output a line consisting
of a single "!" followed by n−1 lines each with two space separated
integers a and b, denoting an edge connecting nodes a and b (1≤a,b≤n).

Once you are done, terminate your program normally immediately after
flushing the output stream.

You may output the edges in any order and an edge (a,b)
is considered the same as an edge (b,a). Answering is not considered as a query.

-------

Interaction

After taking input, you may make at most ⌈n/2⌉ queries. Each query is made in the format "? r",
where r is an integer 1≤r≤n that denotes the node you want to pick for that query.

You will then receive n space separated integers d1,d2,…,dn, where di is the length of the shortest
path from node r to i, followed by a newline.

After printing a query do not forget to output end of line and flush the output.
Otherwise, you will get Idleness limit exceeded. To do this, use:

fflush(stdout) or cout.flush() in C++;
System.out.flush() in Java;
flush(output) in Pascal;
stdout.flush() in Python;
see documentation for other languages.

If at any point you make an invalid query or try to make more than ⌈n/2⌉ queries,
the interaction will terminate immediately and you will receive a Wrong Answer verdict.

Hacks

To hack a solution, use the following format.

The first line contains the integer n (2≤n≤2000).

The next n−1 lines contain two integers u and v (1≤u,v≤n) denoting an edge between u and v (u≠v).
These n−1 edges must form a tree.

Examples
input
4

0 1 2 2

1 0 1 1

output
? 1

? 2

!
4 2
1 2
2 3

input
5

2 2 1 1 0

output
? 5

!
4 5
3 5
2 4
1 3
*/

/*
Hints:

    1. All trees are bipartite
    2. Find a 2-coloring of a tree in one query
    3. We can find all the nodes adjacent to one node in one query
    4. The min(number of black, number of white) nodes is <= floor(n/2)

Intuition:
    If we had n queries, solving this problem would be easy as we could
        just query every single node and add edges when di = 1

    However, notice that as long as we make a query for at least 1 endpoint
        of every edge, we will be able to find all the edges using this
        method

    key observation here is to note that the tree is a bipartite, so we would be
        able to achieve a bound of ceiling(n/2) as long as we only query the
        smaller bipartite set.

    To figure out which set is smaller, we can just query any node and look
        at which nodes have odd depth and which ones have even depth

    Lastly we should be careful with the queries so that the worst-case bound
        is ceil(n/2) rather than floor(n/2) + 1

    One way to do this is to not include the initial node we query in either
        bipartite set (so we are perfectly working with n - 1 nodes rather than
        n)

Time: O(n^2)

*/

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

template <typename C>
void UNIQUE(vector<C> &v)
{
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
}

const int maxSize = 2001;
int N, dis[maxSize];
mt19937 mt(69696969);
vector<pair<int, int>> edges;

void read(int r)
{
    cout << ('?') << ' ' << (r) << '\n';
    cout.flush();
    for (auto i = 1; i <= N; ++i)
    {
        cin >> dis[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    read(1);
    vector<int> s[2];
    for (auto i = 2; i <= N; ++i)
    {
        s[dis[i] & 1].push_back(i);
    }
    if (s[0].size() > s[1].size())
    {
        swap(s[0], s[1]);
    }
    for (auto i = 1; i <= N; ++i)
    {
        if (dis[i] == 1)
        {
            edges.emplace_back(1, i);
        }
    }
    for (auto x : s[0])
    {
        read(x);
        for (auto i = 1; i <= N; ++i)
        {
            if (dis[i] == 1)
            {
                int a = x, b = i;
                if (a > b)
                {
                    swap(a, b);
                }
                edges.emplace_back(a, b);
            }
        }
    }
    UNIQUE(edges);
    shuffle(all(edges), mt);
    uniform_int_distribution<int> dis(0, 1);
    for (auto &[a, b] : edges)
    {
        if (dis(mt))
        {
            swap(a, b);
        }
    }
    cout << ('!') << '\n';
    for (auto &[a, b] : edges)
    {
        cout << (a) << ' ' << (b) << '\n';
    }
}