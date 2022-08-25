// Web of Lies
/*
There are n nobles, numbered from 1 to n. Noble i has a power of i. 
There are also m "friendships". A friendship between nobles a and b is always mutual.

A noble is defined to be vulnerable if both of the following conditions are satisfied:

the noble has at least one friend, and all of that noble's friends have a higher power.
You will have to process the following three types of queries.

Add a friendship between nobles u and v.
Remove a friendship between nobles u and v.
Calculate the answer to the following process.
The process: all vulnerable nobles are simultaneously killed, and all their friendships end. 
Then, it is possible that new nobles become vulnerable. The process repeats 
itself until no nobles are vulnerable. It can be proven that the process will 
end in finite time. After the process is complete, you need to calculate the 
number of remaining nobles.

Note that the results of the process are not carried over between queries, that is, 
every process starts with all nobles being alive!

Input
The first line contains the integers n and m (1≤n≤2⋅10^5, 0≤m≤2⋅10^5) — 
the number of nobles and number of original friendships respectively.

The next m lines each contain the integers u and v (1≤u,v≤n, u≠v), 
describing a friendship. No friendship is listed twice.

The next line contains the integer q (1≤q≤2⋅10^5) — the number of queries.

The next q lines contain the queries themselves, each query has one of the following 
three formats.

1 u v (1≤u,v≤n, u≠v) — add a friendship between u and v. 
It is guaranteed that u and v are not friends at this moment.
2 u v (1≤u,v≤n, u≠v) — remove a friendship between u and v. 
It is guaranteed that u and v are friends at this moment.
3 — print the answer to the process described in the statement.
Output
For each type 3 query print one integer to a new line. 
It is guaranteed that there will be at least one type 3 query.

Examples
input
4 3
2 1
1 3
3 4
4
3
1 2 3
2 3 1
3
output
2
1

input
4 3
2 3
3 4
4 1
1
3
output
1
*/
/*
Due to the queries, actually simulating the process each time will be too expensive.

Proof that the Process will End: Assume after round x, xi nobles are killed. 
If xi=0, then the state of the graph doesn't change, so the process will have ended. 
If xi>0, then the number of nobles decreases. Thus, the maximum number of rounds the process can last is N, so it must end.

Lemma 1:

    At the end of the process, no two nobles will still be friends

    Proof by contradiction:

        Assume that nobles u and v (u < v) are still friends and the process is over.

        In order for u to avoid being killed, there must be a nobel weaker than u that is also a friend of u

        The same logic applies to w. There are only a finite number of nobles weaker than u, so there will be a contradiction

Lemma 2:

    If all of a nobel's friend are weaker than it, that nobel cannot be killed

    Direct proof:

        Since none of the nobel's friends are stronger than it, it is impossible for all of them to be stronger
        at any point in the process

Final Idea:

    By combining the lemmas 1 and 2, we can prove that if all of a nobel's friends are weaker than it, that nobel survives
        , otherwise it will die

    Solution:

        We will maintain an array the number of nobles weaker than nobel i.

        Since the updates gurantee that the edge being removed/added does/doesn't exist respectively
            we only need to keep track of the number of edges of each nobel.

        Essentially a nobel survives if and only if:
            weaker[i] == edges[i]

    The time complexity is O(N+M+Q).
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n, m;
    cin >> n >> m;
    map<int, int> mp1;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        if (u < v)
        {
            // num of stronger friends of u
            mp1[u]++;
        }
        else
        {
            // num of stronger friends of v
            mp1[v]++;
        }
    }
    int q;
    cin >> q;
    cout << "earlier" << endl;
    for (auto &entry : mp1)
    {
        cout << entry.first << " " << entry.second;
        cout << "\n";
    }
    cout << endl;
    while (q--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int u1, v1;
            cin >> u1 >> v1;
            if (u1 < v1)
            {
                mp1[u1]++;
            }
            else
            {
                mp1[v1]++;
            }
        }
        if (a == 2)
        {
            int u2, v2;
            cin >> u2 >> v2;
            if (u2 < v2)
            {
                mp1[u2]--;
                if (mp1[u2] == 0)
                    mp1.erase(u2);
            }
            else
            {
                mp1[v2]--;
                if (mp1[v2] == 0)
                    mp1.erase(v2);
            }
        }
        if (a == 3)
        {
            cout << "later" << endl;
            for (auto &entry : mp1)
            {
                cout << entry.first << " " << entry.second;
                cout << "\n";
            }
            cout << endl;
            cout << n - mp1.size() << endl;
        }
    }
}