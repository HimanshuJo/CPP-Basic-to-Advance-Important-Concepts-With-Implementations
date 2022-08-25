#include <bits/stdc++.h>
#define ll long long
#include <iostream>

using namespace std;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        if (s.compare("TMT") == 0)
        {
            cout << "YES"
                 << "\n";
            continue;
        }
        else if (s.length() == 3 && s.compare("TMT") != 0)
        {
            cout << "NO"
                 << "\n";
            continue;
        }

        unordered_map<char, int> map;

        for (int i = 0; s[i]; ++i)
        {
            if (map.find(s[i]) == map.end())
            {
                map.insert(make_pair(s[i], 1));
            }
            else
            {
                map[s[i]]++;
            }
        }

        int TCount = map.count('T') != 0 ? map['T'] : 0;
        int MCount = map.count('M') != 0 ? map['M'] : 0;

        if ((2 * MCount) != TCount)
        {
            cout << "NO"
                 << "\n";
        }
        else
        {
            int countP = 0;
            int countM = 0;
            bool flag = false;

            for (int i = 0; i < s.length(); ++i)
            {
                if (s.at(i) == 'M')
                {
                    countM++;
                    if (countM > countP)
                    {
                        flag = true;
                    }
                }
                else
                {
                    countP++;
                }

                int countM2 = 0;
                int countP2 = 0;

                for (int i = n - 1; i >= 0; --i)
                {
                    if (s.at(i) == 'M')
                    {
                        countM2++;
                        if (countM2 > countP2)
                        {
                            flag = true;
                        }
                    }
                    else
                    {
                        countP2++;
                    }
                }
            }

            if (flag)
                cout << "NO"
                     << "\n";
            else
                cout << "YES"
                     << "\n";
        }
    }
}