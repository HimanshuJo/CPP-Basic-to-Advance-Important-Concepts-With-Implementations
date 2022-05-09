#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> A(M), B(M), S(M), T(M);
    vector<vector<pair<int, int>>> bus(N + 1);
    for (int i = 0; i < M; i++)
    {
        cin >> A[i] >> B[i] >> S[i] >> T[i];
        bus[A[i]].push_back(make_pair(S[i], i));
    }
    for (auto &p : bus)
        sort(p.begin(), p.end());
    vector<vector<int>> edge(M);
    vector<bool> isroot(M);
    for (int i = 0; i < M; i++)
    {
        auto itr = lower_bound(bus[B[i]].begin(), bus[B[i]].end(), make_pair(T[i], -1));
        if (itr == bus[B[i]].end())
            isroot[i] = true;
        else
            edge[(*itr).second].push_back(i);
    }
    vector<int> X(Q), Y(Q), Z(Q);
    vector<vector<int>> ans(Q), mem(M);
    for (int i = 0; i < Q; i++)
    {
        cin >> X[i] >> Y[i] >> Z[i];
        auto itr = lower_bound(bus[Y[i]].begin(), bus[Y[i]].end(), make_pair(X[i], -1));
        if (itr == bus[Y[i]].end() || Z[i] <= (*itr).first)
            ans[i] = {Y[i]};
        else
            mem[(*itr).second].push_back(i);
    }
    vector<int> time, city;
    function<void(int)> dfs = [&](int now)
    {
        time.push_back(T[now]);
        time.push_back(S[now]);
        city.push_back(B[now]);
        city.push_back(A[now]);
        for (auto i : mem[now])
        {
            int idx = lower_bound(time.rbegin(), time.rend(), Z[i]) - time.rbegin();
            if (idx == time.size())
                ans[i] = {*city.begin()};
            else if (idx % 2 == 0)
                ans[i] = {*(city.rbegin() + idx)};
            else
                ans[i] = {*(city.rbegin() + idx - 1), *(city.rbegin() + idx)};
        }
        for (auto next : edge[now])
        {
            dfs(next);
        }
        time.pop_back();
        time.pop_back();
        city.pop_back();
        city.pop_back();
    };
    for (int i = 0; i < M; i++)
    {
        if (!isroot[i])
            continue;
        dfs(i);
    }
    for (auto p : ans)
    {
        for (auto q : p)
            cout << q << " ";
        cout << endl;
    }
}
