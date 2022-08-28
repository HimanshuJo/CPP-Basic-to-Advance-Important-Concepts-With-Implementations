#include <string>
#include <bits/stdc++.h>
using namespace std;

int maximumRemovals(string s, string p, vector<int> &rem)
{
    int l = 0, r = rem.size();
    vector<int> map(s.size(), INT_MAX);
    for (int i = 0; i < rem.size(); ++i)
        map[rem[i]] = i;
    while (l < r)
    {
        int m = (l + r + 1) / 2, j = 0;
        for (int i = 0; i < s.size() && j < p.size(); ++i)
            if (map[i] >= m && s[i] == p[j])
                ++j;
        if (j == p.size())
            l = m;
        else
            r = m - 1;
    }
    cout << l << "\n";
    return l;
}

int main()
{
    vector<int> vect{3, 1, 0};
    maximumRemovals("abcacb", "ab", vect);
    return 0;
}
