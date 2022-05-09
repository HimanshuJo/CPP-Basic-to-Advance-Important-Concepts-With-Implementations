#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long HALF = 499122177;
template <typename T>
struct binary_indexed_tree
{
    int N;
    vector<T> BIT;
    binary_indexed_tree(int N) : N(N), BIT(N + 1, 0)
    {
    }
    void add(int i, T x)
    {
        i++;
        while (i <= N)
        {
            BIT[i] += x;
            i += i & -i;
        }
    }
    T sum(int i)
    {
        T ans = 0;
        while (i > 0)
        {
            ans += BIT[i];
            i -= i & -i;
        }
        return ans;
    }
    T sum(int L, int R)
    {
        return sum(R) - sum(L);
    }
};
int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<int> x(Q), y(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> x[i] >> y[i];
        x[i]--;
    }
    vector<int> B = A;
    sort(B.begin(), B.end());
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += (i * 2 - N + 1 + MOD) * B[i] % MOD * HALF % MOD;
    }
    ans %= MOD;
    vector<tuple<int, int, int>> C;
    for (int i = 0; i < N; i++)
    {
        C.push_back(make_tuple(A[i], 0, i));
    }
    for (int i = 0; i < Q; i++)
    {
        C.push_back(make_tuple(y[i], 1, i));
    }
    sort(C.begin(), C.end());
    vector<int> p1(N);
    for (int i = 0; i < N; i++)
    {
        p1[i] = lower_bound(C.begin(), C.end(), make_tuple(A[i], 0, i)) - C.begin();
    }
    vector<int> p2(Q);
    for (int i = 0; i < Q; i++)
    {
        p2[i] = lower_bound(C.begin(), C.end(), make_tuple(y[i], 1, i)) - C.begin();
    }
    binary_indexed_tree<int> BIT1(N + Q);
    binary_indexed_tree<long long> BIT2(N + Q);
    for (int i = 0; i < N; i++)
    {
        BIT1.add(p1[i], 1);
        BIT2.add(p1[i], A[i]);
    }
    vector<int> p = p1;
    for (int i = 0; i < Q; i++)
    {
        ans += MOD - BIT2.sum(p[x[i]] + 1, N + Q) % MOD;
        int c1 = BIT1.sum(0, p[x[i]]);
        ans += MOD - (c1 * 2 - N + 1 + MOD) * A[x[i]] % MOD * HALF % MOD;
        BIT1.add(p[x[i]], -1);
        BIT2.add(p[x[i]], -A[x[i]]);
        p[x[i]] = p2[i];
        A[x[i]] = y[i];
        BIT1.add(p[x[i]], 1);
        BIT2.add(p[x[i]], A[x[i]]);
        ans += BIT2.sum(p[x[i]] + 1, N + Q) % MOD;
        int c2 = BIT1.sum(0, p[x[i]]);
        ans += (c2 * 2 - N + 1 + MOD) * A[x[i]] % MOD * HALF % MOD;
        ans %= MOD;
        cout << ans << endl;
    }
}