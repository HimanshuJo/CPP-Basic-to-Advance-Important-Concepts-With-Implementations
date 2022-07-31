// 2040. Kth Smallest Product of Two Sorted Arrays
/*
Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, 
return the kth (1-based) smallest product of nums1[i] * nums2[j] 
where 0 <= i < nums1.length and 0 <= j < nums2.length.
 

Example 1:

Input: nums1 = [2,5], nums2 = [3,4], k = 2
Output: 8
Explanation: The 2 smallest products are:
- nums1[0] * nums2[0] = 2 * 3 = 6
- nums1[0] * nums2[1] = 2 * 4 = 8
The 2nd smallest product is 8.
Example 2:

Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
Output: 0
Explanation: The 6 smallest products are:
- nums1[0] * nums2[1] = (-4) * 4 = -16
- nums1[0] * nums2[0] = (-4) * 2 = -8
- nums1[1] * nums2[1] = (-2) * 4 = -8
- nums1[1] * nums2[0] = (-2) * 2 = -4
- nums1[2] * nums2[0] = 0 * 2 = 0
- nums1[2] * nums2[1] = 0 * 4 = 0
The 6th smallest product is 0.
Example 3:

Input: nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
Output: -6
Explanation: The 3 smallest products are:
- nums1[0] * nums2[4] = (-2) * 5 = -10
- nums1[0] * nums2[3] = (-2) * 4 = -8
- nums1[4] * nums2[0] = 2 * (-3) = -6
The 3rd smallest product is -6.
 

Constraints:

1 <= nums1.length, nums2.length <= 5 * 10^4
-105 <= nums1[i], nums2[j] <= 10^5
1 <= k <= nums1.length * nums2.length
nums1 and nums2 are sorted.
*/

/*
TLE: 79 / 112

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
       vector<long long>ans;
        int sz1=nums1.size(), sz2=nums2.size();
        for(int i=0; i<sz1; ++i){
            for(int j=0; j<sz2; ++j){
                ans.push_back((long long)nums1[i]*nums2[j]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};
*/

/*
TLE: 79 / 112

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        if(nums1.size()==1&&nums2.size()==1){
            return (long long)nums1[0]*nums2[0];
        }
        vector<long long>ans;
        int sz1=nums1.size(), sz2=nums2.size();
        if(nums1.size()==1||nums2.size()==1){
            for(int i=0; i<sz1; ++i){
                for(int j=0; j<sz2; ++j){
                    ans.push_back((long long)nums1[i]*nums2[j]);
                }
            }
            sort(ans.begin(), ans.end());
            return ans[k-1];
        }
        int left1=0, right1=sz1-1;
        int left2=0, right2=sz2-1;
        while(left1<=right1){
            if(left1!=right1){
                while(left2<=right2){
                    if(left2!=right2){
                        ans.push_back((long long)nums1[left1]*nums2[left2]);
                        ans.push_back((long long)nums1[left1]*nums2[right2]);
                        ans.push_back((long long)nums1[right1]*nums2[left2]);
                        ans.push_back((long long)nums1[right1]*nums2[right2]);
                        left2++, right2--;   
                    } else{
                        ans.push_back((long long)nums1[left1]*nums2[left2]);
                        ans.push_back((long long)nums1[right1]*nums2[left2]);
                        left2++, right2--;  
                    }
                }
                left2=0, right2=sz2-1;
                left1++, right1--;  
            } else{
                while(left2<=right2){
                    if(left2!=right2){
                        ans.push_back((long long)nums1[left1]*nums2[left2]);
                        ans.push_back((long long)nums1[left1]*nums2[right2]);
                        left2++, right2--;
                    } else{
                        ans.push_back((long long)nums1[left1]*nums2[left2]);
                        left2++, right2--;   
                    }
                }
                left2=0, right2=sz2-1;
                left1++, right1--; 
            } 
        }
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};
*/

class Solution {
public:
    
    int findMinIndex(vector<int>&nums, long long val, long long midVal){
        int left=0, right=nums.size()-1, res=right+1;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(nums[mid]*val<=midVal){
                res=mid;
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        return nums.size()-res;
    }
    
    int findMaxIndex(vector<int>&nums, long long val, long long midVal){
        int left=0, right=nums.size()-1, res=-1;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(nums[mid]*val<=midVal){
                res=mid;
                left=mid+1;
            } else{
                right=mid-1;
            }
        }
        return res+1;
    }
    
    bool isValid(long long mid, vector<int>&nums1, vector<int>&nums2, long long k){
        int sz=nums1.size();
        long long cnt=0;
        for(int i=0; i<sz; ++i){
            if((long long)nums1[i]==0&&mid>=0){
                cnt+=nums2.size();
            }
            else if((long long)nums1[i]>0){
                cnt+=findMaxIndex(nums2, (long long)nums1[i], mid);
            } else if((long long)nums1[i]<0){
                cnt+=findMinIndex(nums2, (long long)nums1[i], mid);
            }
        }
        return cnt>=k;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left=-1e10, right=1e10, res=-1;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(isValid(mid, nums1, nums2, k)){
                res=mid;
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        return res;
    }
};

// -------*******-------

class Solution2 {
public:
    
    long long count(vector<long long>&arr1, vector<long long>&arr2, long long x){
        long long res=0, j=arr2.size()-1;
        for(long long i=0; i<arr1.size(); ++i){
            while(j>=0&&arr1[i]*arr2[j]>x){
                --j;
            }
            res+=j+1;
        }
        return res;
    }    
    
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int m=nums1.size(), n=nums2.size();
        auto it1=lower_bound(nums1.begin(), nums1.end(), 0);
        auto it2=lower_bound(nums2.begin(), nums2.end(), 0);
        vector<long long>negnums1(nums1.begin(), it1);
        vector<long long>negnums2(nums2.begin(), it2);
        vector<long long>posnums1(it1, nums1.end());
        vector<long long>posnums2(it2, nums2.end());
        for_each(negnums1.begin(), negnums1.end(), [](long long &x) {x*=-1;});
        for_each(negnums2.begin(), negnums2.end(), [](long long &x) {x*=-1;});
        reverse(negnums1.begin(), negnums1.end());
        reverse(negnums2.begin(), negnums2.end());
        long long negcnt=negnums1.size()*posnums2.size()+negnums2.size()*posnums1.size();
        bool negtarget;
        // target>=0
        if(k>negcnt){
            /*
                searching in the positive parts
                i.e negnums1*negnums2 & posnums1*posnums2
            */
            k-=negcnt;
            negtarget=0;
        } else{
            // target<0
            /*
                searching in the negative parts
                we will search in the negnums1*posnums1 & negnums2*posnums2 and
                search as positives, so k should be reversed
                switch negnums2 and posnums2 to keep the code consistent
            */
            k=negcnt-k+1;
            vector<long long>tmp=negnums2;
            negnums2=posnums2;
            posnums2=tmp;
            negtarget=1;
        }
        long long left=0, right=1e10;
        long long ans=left;
        while(left<right){
            long long mid=left+(right-left)/2;
            if(count(negnums1, negnums2, mid)+count(posnums1, posnums2, mid)>=k){
                right=mid;
                //ans=mid;
                //left=mid+1;
            } else{
                //right=mid-1;
                left=mid+1;
            }
        }
        return negtarget?-left:left;
    }
};