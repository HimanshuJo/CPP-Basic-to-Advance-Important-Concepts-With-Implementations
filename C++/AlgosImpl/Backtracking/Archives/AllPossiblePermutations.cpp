/*
Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(vector<int>&arr, vector<int>&currPermu, vector<vector<int>>&allPermus, int sz){
    if(currPermu.size()==arr.size()){
        allPermus.push_back(currPermu);
    } else{
        for(int i=0; i<sz; ++i){
            auto it=find(currPermu.begin(), currPermu.end(), arr[i]);
            if(it!=currPermu.end()) continue;
            currPermu.push_back(arr[i]);
            dfs(arr, currPermu, allPermus, sz);
            currPermu.pop_back();
        }
    }
}

vector<vector<int>> genAllPossiblePermutations(vector<int>&arr){
    vector<vector<int>>allPermus;
    vector<int>currPermu;
    int sz=arr.size();
    dfs(arr, currPermu, allPermus, sz);
    return allPermus;
}

int main(){
    vector<int>arr{1, 2, 3, 4};
    vector<vector<int>>allPossiblePermutations=genAllPossiblePermutations(arr);
    for(auto &entries: allPossiblePermutations){
        for(auto &vals: entries){
            cout<<vals<<" ";
        }
        cout<<endl;
    }
}