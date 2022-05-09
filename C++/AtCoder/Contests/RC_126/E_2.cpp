#include <bits/stdc++.h>
//#include <atcoder/all>

#define all(x) x.begin(), x.end()

using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

/*
segtree を用いて、直接答を計算する
区間に対して、区間内の A_i に対する
・|A_i - A_j| の総和
・A_i の個数
・A_i の総和
を持つ
*/

struct T
{
    mint ans, cnt, sum;
};
T seg_f(T x, T y)
{
    mint v = x.ans + y.ans + x.cnt * y.sum - x.sum * y.cnt;
    return T({v, x.cnt + y.cnt, x.sum + y.sum});
}
T seg_e() { return T({0, 0, 0}); }

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N), X(Q), Y(Q);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < Q; ++i)
        cin >> X[i] >> Y[i];

    // 座標圧縮用
    vector<ll> val = A;
    val.insert(val.end(), all(Y));
    sort(all(val));

    vector<int> cnt(val.size());
    segtree<T, seg_f, seg_e> seg(val.size());

    auto add = [&](int x, int k)
    {
        // 多重集合に x を k 個追加する
        int i = lower_bound(all(val), x) - val.begin();
        cnt[i] += k;
        T t = T({0, cnt[i], cnt[i] * val[i]});
        seg.set(i, t);
    };

    for (int i = 0; i < N; ++i)
        add(A[i], 1);

    for (int q = 0; q < Q; ++q)
    {
        int i = X[q] - 1;
        add(A[i], -1);
        A[i] = Y[q];
        add(A[i], +1);

        T t = seg.all_prod();
        mint ANS = t.ans / 2;
        cout << ANS.val() << endl;
    }
    return 0;
}
