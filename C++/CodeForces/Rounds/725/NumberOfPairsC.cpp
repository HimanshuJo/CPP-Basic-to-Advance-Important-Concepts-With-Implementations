
/*
You are given an array a of n integers. 
Find the number of pairs (i,j) (1≤i<j≤n) where the sum of ai+aj is 
greater than or equal to l and less than or equal to r (that is, l≤ai+aj≤r).

For example, if n=3, a=[5,1,2], l=4 and r=7, then two pairs are suitable:

i=1 and j=2 (4≤5+1≤7);

i=1 and j=3 (4≤5+2≤7). 
*/

/*
The problem can be divided into two classic ones:

    Count the number of pairs ai+aj≤r;
    
    Count the number of pairs ai+aj≤l−1

    Let A— be the answer to the first problem, and B — be the answer to the second problem. 
    
        Then A−B is the answer to the original problem.

    The new problem can be solved by binary search. Iterate over the first element of the pair. 
    
    Then you need to count the number of elements such that aj≤r−ai
    
    If you sort the array, this value can be calculated by running a single binary search.
*/

#include <bits/stdc++.h>
#include "random"

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n);
    for (int &e : v)
    {
        cin >> e;
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += upper_bound(v.begin(), v.end(), r - v[i]) - v.begin();
        ans -= lower_bound(v.begin(), v.end(), l - v[i]) - v.begin();
        if (l <= 2 * v[i] && 2 * v[i] <= r)
        {
            ans--;
        }
    }
    cout << ans / 2 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}