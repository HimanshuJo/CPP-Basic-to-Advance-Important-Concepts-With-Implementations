#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int seg_tree[(1 << 20) + 228];

void upd(int v, int left, int right, int i, int x)
{
    seg_tree[v] = max(seg_tree[v], x);
    if (left + 1 == right)
        return;
    int mid = (left + right) / 2;
    if (i < mid)
        upd(2 * v + 1, left, mid, i, x);
    else
        upd(2 * v + 2, mid, right, i, x);
}

int get(int v, int left, int right, int x, int y)
{
    if (y <= left || right <= x)
        return 0;
    if (x <= left && right <= y)
        return seg_tree[v];
    int mid = (left + right) / 2;
    return max(get(2 * v + 1, left, mid, x, y), get(2 * v + 2, mid, right, x, y));
}

vector<int> G[200000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        G[a - 1].emplace_back(b - 1);
    }
    for (int i = 0; i < n; ++i)
    {
        sort(G[i].rbegin(), G[i].rend());
        for (int j : G[i])
        {
            int x = get(0, 0, n, 0, j);
            upd(0, 0, n, j, x + 1);
        }  
    }
    cout << get(0, 0, n, 0, n) << '\n';
    return 0;
}
