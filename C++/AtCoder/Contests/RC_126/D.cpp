#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define popcnt __builtin_popcount

#define FOR(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define FOR_R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define all(x) x.begin(), x.end()

int main()
{
    int N, K;
    cin >> N >> K;
    vi A(N);
    FOR(i, 0, N)
    {
        cin >> A[i];
        --A[i];
    }
    int INF = 1 << 30;
    int ANS = INF;
    int half = K / 2;

    auto calc_cost = [&](auto I) -> int
    {
        /*
    0, 1, ..., K-1 のもとの位置 I[0], ..., I[K-1]
    が与えられたときの、最小操作回数をかえす
    */
        FOR(i, 0, K)
        if (I[i] == -1) return INF;
        int cost = 0;
        FOR(j, 0, K)
        FOR(i, 0, j) cost += I[i] > I[j];
        sort(all(I));
        FOR(i, 0, K)
        {
            int to = I[half] - half + i;
            cost += abs(to - I[i]);
        }
        return cost;
    };

    FOR(n, 0, N)
    {
        // n の左側から使う場合の位置、右側から使う場合の位置
        vi LID(K, -1), RID(K, -1);
        FOR(i, 0, n + 1)
        LID[A[i]] = i;
        FOR_R(i, n, N)
        RID[A[i]] = i;

        FOR(s, 0, 1 << K)
        {
            // 半分を左側の最寄り、半分を右側の最寄りから使う。
            // K/2 元集合は、O(2^K / K^{0.5}) 通り存在する。
            if (popcnt(s) != half)
                continue;
            vi I(K);
            FOR(i, 0, K)
            I[i] = (s & 1 << i ? LID[i] : RID[i]);
            ANS = min(ANS, calc_cost(I));
        }
    }
    cout << ANS << endl;
    return 0;
}
