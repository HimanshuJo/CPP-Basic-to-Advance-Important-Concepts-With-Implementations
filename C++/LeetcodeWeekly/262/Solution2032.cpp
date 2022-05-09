#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int>res;
        for(auto &nums: nums1){
            int curr=nums;
            auto it1=find(nums2.begin(), nums2.end(), curr);
            auto it2=find(nums3.begin(), nums3.end(), curr);
            if(it1!=nums2.end()){
                res.insert(nums);
            }
            if(it2!=nums3.end()){
                res.insert(nums);
            }
        }
        for(auto &nums: nums2){
            int curr=nums;
            auto it1=find(nums1.begin(), nums1.end(), curr);
            auto it2=find(nums3.begin(), nums3.end(), curr);
            if(it1!=nums1.end()){
                res.insert(nums);
            }
            if(it2!=nums3.end()){
                res.insert(nums);
            }
        }
        for(auto &nums: nums3){
            int curr=nums;
            auto it1=find(nums1.begin(), nums1.end(), curr);
            auto it2=find(nums2.begin(), nums2.end(), curr);
            if(it1!=nums1.end()){
                res.insert(nums);
            }
            if(it2!=nums2.end()){
                res.insert(nums);
            }
        }
        vector<int>ans;
        if(res.size()!=0){
            for(auto &vals: res){
                ans.push_back(vals);
            }
        }
        return ans;
    }
};