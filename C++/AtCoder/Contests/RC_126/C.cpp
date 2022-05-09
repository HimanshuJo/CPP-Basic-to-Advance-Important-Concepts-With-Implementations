//Maximize GCD
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> cumsum(vector<ll> &A)
{
    vector<ll> B(A.size() + 1);
    for (int i = 0; i < A.size(); ++i)
    {
        B[i + 1] = B[i] + A[i];
    }
    return B;
}

int main()
{
    ll N, K;
    cin >> N >> K;

    const ll MAX = 300010;

    vector<ll> cnt(MAX);
    vector<ll> sum(MAX);
    for (int n = 0; n < N; ++n)
    {
        int a;
        cin >> a;
        cnt[a] += 1;
        sum[a] += a;
    }
    auto cnt_c = cumsum(cnt);
    auto sum_c = cumsum(sum);

    ll ANS = 1;
    for (int x = 2; x < MAX; ++x)
    {
        ll l = 1, r = x;
        ll cost = 0;
        while (l < MAX)
        {
            ll c = cnt_c[min(r, MAX)] - cnt_c[l];
            ll s = sum_c[min(r, MAX)] - sum_c[l];
            cost += r * c - s;
            l += x, r += x;
        }
        if (cost <= K)
            ANS = x;
    }

    ll cost_MAX = MAX * N - sum_c.back();
    if (cost_MAX <= K)
        ANS = MAX + (K - cost_MAX) / N;
    cout << ANS << endl;
}
