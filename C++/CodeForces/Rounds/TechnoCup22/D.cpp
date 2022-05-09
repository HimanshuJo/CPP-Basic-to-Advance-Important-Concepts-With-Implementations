#include<bits/stdc++.h>
using namespace std;

int query(vector<int>&vec, int in, int n){
    string curr="? ";
    for(int i=0; i<vec.size(); ++i){
        curr+=to_string(vec[i]);
        curr+=" ";
    }
    cout<<curr<<endl;
    cin>>in;
    return in;
}

int main(){
    int n;          
    cin>>n;
    vector<int>ans(n);
    int in;
    ans[n-1]=n;
    for(int i=1; i<n; ++i){
        vector<int>temp(n, i+1);
        temp[n-1]=1;
        if(query(temp, in, n)==0){
            ans[n-1]=i;
            break;
        }
    }
    for(int i=1; i<ans[n-1]; ++i){
        vector<int>temp(n, i+1);
        temp[n-1]=1;      
        int pos=query(temp, in, n)-1;
        ans[pos]=ans[n-1]-i;
    }
    for(int i=1; i<=n-ans[n-1]; ++i){
        vector<int>temp(n, 1);
        temp[n-1]+=i;
        int pos=query(temp, in, n)-1;
        ans[pos]=ans[n-1]+i;
    }
    string res="! ";
    for(auto &nums: ans){
        res+=to_string(nums);
        res+=" ";
    }
    cout<<res<<endl;
}