#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

void psuedoBinary(int n)
{
    while (n > 0)
    {
        int temp = n, m = 0, p = 1;
        while (temp)
        {
            int rem = temp % 10;
            temp = temp / 10;

            if (rem != 0)
                m += p;

            p *= 10;
        }
        ans.push_back(m);
        n = n - m;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n < 9)
        {
            cout << n << "\n";
            continue;
        }
        bool flag = false;
        string temp1 = to_string(n);
        int count = 0;
        for (int i = 0; i < temp1.length(); ++i)
        {
            if (temp1.at(i) == '0' || temp1.at(i) == '1')
            {
                count++;
            }
        }
        if (count == temp1.length())
        {
            flag = true;
        }
        if (flag)
        {
            cout << 1 << "\n";
            continue;
        }
        psuedoBinary(n);
        cout << ans.size() << "\n";
        ans.clear();
    }
}