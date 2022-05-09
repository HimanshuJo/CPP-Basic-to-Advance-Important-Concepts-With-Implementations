#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void subsetsUtil(vector<int> &A, vector<vector<int>> &res, vector<int> &subset, int index)
    {
        res.push_back(subset);
        for (int i = index; i < A.size(); ++i)
        {
            subset.push_back(A[i]);
            subsetsUtil(A, res, subset, i + 1);
            subset.pop_back();
        }
        return;
    }

    vector<vector<int>> subsets(vector<int> &A)
    {
        vector<int> subset;
        vector<vector<int>> res;
        int index = 0;
        subsetsUtil(A, res, subset, index);
        return res;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        vector<vector<int>> res = subsets(nums);
        map<int, int>mp;
        for (int i = 0; i < res.size(); ++i)
        {
            vector<int>tmp;
            for (int j = 0; j < res[i].size(); ++j)
            {
                tmp.push_back(res[i][j]);
            }
            int currXOR=0;
            for(auto &nums: tmp){
                currXOR|=nums;
            }
            mp[currXOR]++;
        }
        return prev(mp.end())->second;
    }
};