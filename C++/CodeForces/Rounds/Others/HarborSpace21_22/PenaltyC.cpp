#include <bits/stdc++.h>
using namespace std;

int calRes(string s, int i, int score1, int score2, int ans)
{
    if (i == s.length() - 1)
    {
        return ans;
    }
    if (i % 2 != 0 && s.at(i) == '1')
    {
        score1++;
    }
    if (i % 2 == 0 && s.at(i) == '1')
    {
        score2++;
    }
    if (score1 > score2 && i % 2 == 0 && score2 + (s.length() - i) / 2 < score1)
    {
        ans = i;
        return ans;
    }
    if (score2 > score1 && i % 2 == 0 && score1 + (s.length() - i) / 2 < score2)
    {
        ans = i;
        return ans;
    }
    if (score1 > score2 && i % 2 == 0 && score2 + (s.length() - i) / 2 >= score1)
    {
        ans = calRes(s, i + 1, score1, score2, ans);
    }
    if (score2 > score1 && i % 2 == 0 && score1 + (s.length() - i) / 2 >= score2)
    {
        ans = calRes(s, i + 1, score2, score1, ans);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s.at(i) == '1')
            {
                count1++;
            }
            if (s.at(i) == '?')
            {
                count2++;
            }
        }
        if (count1 == s.length())
        {
            cout << 10 << "\n";
            continue;
        }
        if (count2 == s.length())
        {
            cout << 6 << "\n";
            continue;
        }
        int score1 = 0;
        int score2 = 0;
        int ans = INT_MAX;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s.at(i) == '?')
            {
                s.at(i) = '1';
                int temp1 = min(calRes(s, i, score1, score2, ans), calRes(s, i, score2, score1, ans));
                s.at(i) = '0';
                int temp2 = min(calRes(s, i, score1, score2, ans), calRes(s, i, score2, score1, ans));
                ans = min(temp1, temp2);
            }
            if (i % 2 != 0 && s.at(i) == '1')
            {
                score1++;
            }
            if (i % 2 == 0 && s.at(i) == '1')
            {
                score2++;
            }
        }
        cout << ans << "\n";
    }
}