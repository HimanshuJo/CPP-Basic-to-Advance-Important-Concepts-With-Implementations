#include <bits/stdc++.h>
typedef long long int ll;
const unsigned int MOD = 1000000007;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        int n;
        cin >> n;

        int a[n];
        int b[n];

        ll me = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            me += a[i];
        }

        ll you = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            you += b[i];
        }

        sort(a, a + n);
        sort(b, b + n);

        int k = n / 4;

        for (int i = 0; i < k; i++)
        {
            me -= a[i];
            you -= b[i];
        }
        //cout<<me<<" "<<you<<"\n";

        if (me >= you)
        {
            cout << 0 << "\n";
            continue;
        }
        int x = k;
        int y = k - 1;
        int r = n;
        int ans = 0;

        int zero = 0;

        //cout << me << " " << you << " \n";
        while (true)
        {
            if (me >= you)
            {
                break;
            }
            me += 100;
            zero++;
            if (y >= 0)
            {
                you += b[y];
                y--;
            }
            r++;
            if (r / 4 > k)
            {
                k++;
                me -= a[x];
                x++;

                if (zero < k)
                {
                    you -= b[y + 1];
                    y++;
                }
            }
            ans++;
            //cout<<me<<" "<<you<<" a\n";
        }
        cout << ans << "\n";
    }
    return 0;
}