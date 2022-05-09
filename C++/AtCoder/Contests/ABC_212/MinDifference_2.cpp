#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define INF 1010000000
#define rep(i, n) for (int i = 0; i < n; ++i)
int main(void)
{
    int n, m;
    int a[N];
    int b[N];
    int ans = INF;
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int x = 0;
    int y = 0;
    while ((x < n) && (y < m))
    {
        ans = min(ans, abs(a[x] - b[y]));
        if (a[x] > b[y])
            y++;
        else
            x++;
    }
    cout << ans << endl;
    return 0;
}