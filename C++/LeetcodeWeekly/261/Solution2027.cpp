#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMoves(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != 'O')
            {
                if (i + 2 <= s.length())
                {
                    bool flag = false;
                    for (int j = i; j <= i + 2; ++j)
                    {
                        if (s[j] == 'X')
                        {
                            flag = true;
                        }
                        s[j] = 'O';
                    }
                    if (flag)
                        ans++;
                }
                else
                {
                    bool flag = false;
                    for (int j = i; j < s.length(); ++j)
                    {
                        if (s[j] == 'X')
                        {
                            flag = true;
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

/*
    class Solution
{
public:
    int minimumMoves(string s)
    {
        int n = s.length();
        int dp[3];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < s.length(); ++i)
        {
            int id = i % 3;
            if (s[i] == 'X')
            {
                dp[id]++;
            }
            else
            {
                dp[id] = dp[(i + 2) % 3];
            }
        }
        return dp[(n - 1) % 3];
    }
};
*/

int main()
{
    Solution obj;
    string s = "XXX";
    obj.minimumMoves(s);
}