/*
You are given n integers a1,a2,…,an. Find the maximum value of
 max(al,al+1,…,ar)⋅min(al,al+1,…,ar) 
over all pairs (l,r) of integers for which 1≤l<r≤n.

Example
input
4
3
2 4 3
4
3 2 3 1
2
69 69
6
719313 273225 402638 473783 804745 323328

output
12
6
4761
381274500335
*/

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int K;
        cin >> n;
        vector<ll> arr;
        for (int i = 0; i < n; ++i)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        ll currMax = 0L;
        for (int i = 0; i < n - 1; ++i) {
            currMax = max(currMax, arr.at(i) * arr.at(i + 1));
        }
        cout << currMax << "\n";
    }
}