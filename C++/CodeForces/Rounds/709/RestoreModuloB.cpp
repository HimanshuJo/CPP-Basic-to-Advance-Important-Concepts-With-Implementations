#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        set<int> st;

        int a[n + 1];

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        if (n <= 2)
        {
            cout << 0 << "\n";
        }

        else
        {
            int mx = a[1];

            for (int i = 2; i <= n; i++)
            {
                mx = max(mx, a[i]);
                st.insert(a[i] - a[i - 1]);
            }
            if (st.size() > 2)
            {
                cout << -1 << "\n";
            }
            else
            {
                if (st.size() == 1)
                {
                    cout << 0 << "\n";
                }
                else
                {
                    int a1 = *st.begin();
                    st.erase(st.begin());

                    int a2 = *st.begin();

                    if (a1 >= 0 && a2 >= 0)
                    {
                        cout << -1 << "\n";
                    }

                    else if (a1 <= 0 && a2 <= 0)
                    {
                        cout << -1 << "\n";
                    }
                    else
                    {
                        if (a1 < a2)
                            swap(a1, a2);
                        if (mx > a1 - a2)
                        {
                            cout << -1 << "\n";
                        }
                        else
                        {
                            cout << a1 - a2 << " " << a1 << "\n";
                        }
                    }
                }
            }
        }
    }

    return 0;
}