#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M;
    cin >> M;
    int u, v;
    vector<vector<int>> edg(10);
    for (int i = 0; i < M; ++i)
    {
        cin >> u >> v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    int p; string s = "999999999";
    for(int i = 1; i <= 8; i++){
        cin >> p;
        s[p-1] = i + '0';
    }
    cout<<s<<endl;
    queue<string> Q;
    Q.push(s);
    map<string, int> mp;
    mp[s] = 0;
    while (Q.size())
    {
        string s = Q.front();
        Q.pop();
        for (int i = 1; i <= 9; i++)
            if (s[i - 1] == '9')
                v = i;
        for (auto u : edg[v])
        {
            string t = s;
            swap(t[u - 1], t[v - 1]);
            if (mp.count(t))
                continue;
            mp[t] = mp[s] + 1;
            Q.push(t);
        }
    }
    if (mp.count("123456789") == 0)
        cout << -1 << endl;
    else
        cout << mp["123456789"] << endl;
    return 0;
}