#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int tmpSm=0;
        for(auto &vals: rolls){
            tmpSm+=vals;
        }
        int smNumToFn=mean*(n+rolls.size())-tmpSm;
        if (smNumToFn < n || smNumToFn > 6*n) return {};
        int part = smNumToFn / n, rem = smNumToFn % n;
        vector<int> ans(n, part);
        for (int i = 0; i < rem; ++i) 
            ++ans[i];
        return ans;
    }
};