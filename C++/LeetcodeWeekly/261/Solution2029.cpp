#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3]={};
        for(auto &stone: stones){
            cnt[stone%3]++;
        }
        if(min(cnt[1], cnt[2])==0){
            return max(cnt[1], cnt[2])>2 and cnt[0]%2>0;
        }
        return abs(cnt[1]-cnt[2])>2 or cnt[0]%2==0;
    }
};