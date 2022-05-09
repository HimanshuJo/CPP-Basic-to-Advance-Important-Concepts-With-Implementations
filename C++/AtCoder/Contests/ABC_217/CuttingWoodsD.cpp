/*
Problem Statement
We have a long piece of timber with a length of L meters.
For each x=1,2,…,L−1, there is a mark called Mark x at x meters 
from the left end of the piece.
You are given Q queries, the i-th of which is represented as a 
pair of numbers (ci,xi).
Process the queries in ascending order of i as described below.
If ci=1: cut the piece at Mark xi into two.
If ci=2: choose the piece with Mark xi on it and print its length.
Here, for both kinds of queries ci=1,2, it is guaranteed that there 
will have been no cut at Mark xi when the query is to be processed.

Sample Input 3 
100 10
1 31
2 41
1 59
2 26
1 53
2 58
1 97
2 93
1 23
2 84
Sample Output 3 
69
31
6
38
38
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<int> s;
    int l;
    cin >> l;
    s.insert(0);
    s.insert(l);
    int qq;
    cin >> qq;
    for (int i = 0; i < qq; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        else
        {
            int x;
            cin >> x;
            auto it = s.lower_bound(x);
            if (it == s.begin())
            {
                cout << *it << '\n';
            }
            else
            {
                cout << *it - *prev(it) << '\n';
            }
        }
    }
    return 0;
}