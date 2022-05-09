#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dfs(int src, vector<vector<int>>&gr, vector<int>&sizes){
        int ans=1;
        for(auto &child: gr[src]){
            ans+=dfs(child, gr, sizes);
        }
        return sizes[src]=ans;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<int>sizes(n, 0);
        vector<vector<int>>gr(n);
        for(int i=1; i<n; ++i){
            gr[parents[i]].push_back(i);
        }
        dfs(0, gr, sizes);
        long long cnt=0, maxx=0;
        for(int i=0; i<n; ++i){
            long long prod=1;
            prod=max(prod, (long long) n-sizes[i]);
            for(auto &node: gr[i]){
                prod=prod*sizes[node];
            }
            if(prod>maxx){
                maxx=prod;
                cnt=1;
            } else if(prod==maxx){
                cnt++;
            }
        }
        return cnt;
    }
};