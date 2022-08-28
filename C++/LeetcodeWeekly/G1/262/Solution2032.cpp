// 2032. Two Out of Three
/*
Given three integer arrays nums1, nums2, and nums3, return a distinct array containing 
all the values that are present in at least two out of the three arrays. 

You may return the values in any order.

Example 1:

Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
Output: [3,2]
Explanation: The values that are present in at least two arrays are:
- 3, in all three arrays.
- 2, in nums1 and nums2.
Example 2:

Input: nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
Output: [2,3,1]
Explanation: The values that are present in at least two arrays are:
- 2, in nums2 and nums3.
- 3, in nums1 and nums2.
- 1, in nums1 and nums3.
Example 3:

Input: nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
Output: []
Explanation: No value is present in at least two arrays.
 

Constraints:

1 <= nums1.length, nums2.length, nums3.length <= 100
1 <= nums1[i], nums2[j], nums3[k] <= 100
*/

/*
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
*/

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        bool isPresent[3][101];
        bool seen[101];
        vector<int>res;
        for(int i=0; i<3; ++i){
            for(int j=0; j<=100; ++j){
                isPresent[i][j]=false;
                seen[j]=false;
            }   
        }
        for(auto &vals: nums1)
            isPresent[0][vals]=true;
        for(auto &vals: nums2){
            if(isPresent[0][vals]&&!seen[vals]){
                res.push_back(vals);
                seen[vals]=true;
            }
            isPresent[1][vals]=true;
        }
        for(auto &vals: nums3){
            if((isPresent[0][vals]||isPresent[1][vals])&&!seen[vals]){
                res.push_back(vals);
                seen[vals]=true;
            }
        }
        return res;
    }
};

// -------*******-------

class Solution2 {
public:
    
    vector<int> twoOutOfThreeGen(vector<vector<int>>&nums){
        int sz=nums.size();
        vector<vector<bool>>isPresent(sz, vector<bool>(101, false));
        bool seen[101]={false};
        vector<int>res;
        for(int i=0; i<sz; ++i){
            if(i==0){
                for(auto &vals: nums[0]){
                    isPresent[0][vals]=true;
                }
            } else{
                for(auto &vals: nums[i]){
                    for(int x=i-1; x>=0; --x){
                        if(isPresent[x][vals]&&!seen[vals]){
                            res.push_back(vals);
                            seen[vals]=true;
                            break;
                        }
                    }
                    isPresent[i][vals]=true;
                }
            }
        }
        return res;
    }
    
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<vector<int>>nums={nums1, nums2, nums3};
        return twoOutOfThreeGen(nums);
    }
};