/*
Given an array of both positive and negative numbers, the task is to find out the 
subarray whose sum is closest to 0. 
There can be multiple such subarrays, we need to output just 1 of them. 
Examples: 
 

Input : arr[] = {-1, 3, 2, -5, 4}
Output : 1, 3
Subarray from index 1 to 3 has sum closest to 0 i.e.
3 + 2 + -5 = 0

Input : {2, -5, 4, -6, 3} 
Output : 0, 2
2 + -5 + 4 = 1 closest to 0
*/
/*
#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;

pair<int, int> subArrWithSumClosestToZero(vector<int>&in){
    map<int, vector<pair<int, int>>>mp;
    int sz=in.size();
    for(int i=0; i<sz; ++i){
        int curSum=0;
        curSum+=in[i];
        if(i+1<=sz-1){
            for(int j=i+1; j<sz; ++j){
                curSum+=in[j];
                mp[curSum].push_back({i, j});
            }
        } else{
            mp[curSum].push_back({i, i});
        }
    }
    int distTZero=INT_MAX;
    pair<int, int>ans;
    for(auto &entries: mp){
        int curDist=entries.first<0?0-entries.first:entries.first-0;
        if(curDist<distTZero){
            distTZero=curDist;
            for(auto &vals: entries.second){
                ans.first=vals.first, ans.second=vals.second;
                break;
            }
        }   
    }
    return ans;
}

int main(){
    vector<int>in{2, -5, 4, -6, 3};
    pair<int, int>ans=subArrWithSumClosestToZero(in);
    cout<<ans.first<<" "<<ans.second<<endl;
}
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

struct PrefixSum{
    int sum;
    int idx;
};

bool comp(PrefixSum A, PrefixSum B){
    return A.sum<B.sum;
}

pair<int, int> subArrWithSumClosestToZero(vector<int>&in){
    int sz=in.size();
    vector<PrefixSum>prefixSumArr(sz+1);
    prefixSumArr[0].sum=0, prefixSumArr[0].idx=-1;
    for(int i=1; i<=sz; ++i){
        prefixSumArr[i].sum=prefixSumArr[i-1].sum+in[i-1];
        prefixSumArr[i].idx=i-1;
    }
    sort(prefixSumArr.begin(), prefixSumArr.end(), comp);
    int diff=INT_MAX, bgnIdx=-1, endIdx=-1;
    for(int i=1; i<=sz; ++i){
        int currDiff=prefixSumArr[i].sum-prefixSumArr[i-1].sum;
        if(currDiff<diff){
            diff=currDiff;
            bgnIdx=prefixSumArr[i-1].idx;
            endIdx=prefixSumArr[i].idx;
        }
    }
    return {bgnIdx+1, endIdx};
}

int main(){
    vector<int>in{2, -5, 4, -6, 3};
    pair<int, int>ans=subArrWithSumClosestToZero(in);
    cout<<ans.first<<" "<<ans.second;
}