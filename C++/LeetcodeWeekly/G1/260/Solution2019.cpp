#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;
class Solution
{
public:
    int scoreOfStudents(string s, vector<int> &answers)
    {
        int n=s.length()/2+1;
        unordered_map<int, int>mp;
        unordered_set<int>st[n][n];
        int res1 = 0;
        stack<int> st1;
        for (int i = 0; i < s.length(); ++i)
        {
            if (isdigit(s[i]))
            {
                st1.push(s[i] - '0');
            }
            else
            {
                char sgn = s[i];
                if (sgn == '*')
                {
                    int curr = st1.top();
                    st1.pop();
                    while (true)
                    {
                        if (isdigit(s[i + 1]))
                        {
                            ++i;
                            break;
                        }
                        else
                        {
                            ++i;
                            if (i == s.length() - 1)
                            {
                                break;
                            }
                        }
                    }
                    curr *= s[i] - '0';
                    st1.push(curr);
                }
            }
        }
        while (!st1.empty())
        {
            res1 += st1.top();
            st1.pop();
        }
        for(int i=n-1; i>=0; --i){
            st[i][i].insert(s[i<<1]-'0');
            for(int j=i+1; j<n; ++j){
                for(int k=i; k<j; ++k){
                    for(auto& lf: st[i][k]){
                        for(auto& rght: st[k+1][j]){
                            int ans=s[(k<<1)|1]=='*'?lf*rght:lf+rght;
                            if(ans<=1000){
                                st[i][j].insert(ans);
                            }
                        }
                    }
                }
            }
        }
        mp[res1]=5;
        int fnres=0;
        for(auto &nums: answers){
            auto it=mp.find(nums);
            if(it!=mp.end()){
                fnres+=mp[nums];
            } else{
                if(st[0][n-1].count(nums)){
                    fnres+=2;
                }
            }
        }
        return fnres;
    }
};