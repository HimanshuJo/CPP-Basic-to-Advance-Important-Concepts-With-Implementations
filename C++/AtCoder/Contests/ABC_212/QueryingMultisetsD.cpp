#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Q;
    cin >> Q;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll toAdd = 0;
    while (Q--)
    {
        int in;
        cin >> in;
        if (in == 1)
        {
            ll temp;
            cin >> temp;
            pq.push(temp - toAdd);
        }
        else if (in == 2)
        {
            ll temp;
            cin >> temp;
            toAdd += temp;
        }
        else if (in == 3)
        {
            ll num = 0;
            num = pq.top();
            pq.pop();
            cout << num + toAdd << "\n";
        }
    }
    return 0;
}