#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<int>&cookies, int k, int sz, int idx, vector<int>&subdivvec, int &ans){
    if(idx>=sz){
        int curmax=INT_MIN;
        for(int i=0; i<k; ++i){
            curmax=max(curmax, subdivvec[i]);
        }
        ans=min(ans, curmax);
        return;
    }
    for(int i=0; i<k; ++i){
        subdivvec[i]+=cookies[idx];
        dfs(cookies, k, sz, idx+1, subdivvec, ans);
        subdivvec[i]-=cookies[idx];
    }
}

class Solution{
    public:
    int distributeCookies(vector<int>&cookies, int k){
        int sz=cookies.size();
        int idx=0;
        vector<int>subdivvec(k, 0);
        int ans=INT_MAX;
        dfs(cookies, k, sz, idx, subdivvec, ans);
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int>cookies{8, 15, 10, 20, 8};
    int k=2;
    int ans=obj.distributeCookies(cookies, k);
    cout<<ans<<endl;
}