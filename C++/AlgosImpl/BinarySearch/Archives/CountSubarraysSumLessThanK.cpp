// 2302. Count Subarrays With Score Less Than K
/*
The score of an array is defined as the product of its sum and its length.

For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.

Given a positive integer array nums and an integer k, return the number of non-empty 
subarrays of nums whose score is strictly less than k.

A subarray is a contiguous sequence of elements within an array.

Example 1:

Input: nums = [2,1,4,3,5], k = 10
Output: 6
Explanation:
The 6 subarrays having scores less than 10 are:
- [2] with score 2 * 1 = 2.
- [1] with score 1 * 1 = 1.
- [4] with score 4 * 1 = 4.
- [3] with score 3 * 1 = 3. 
- [5] with score 5 * 1 = 5.
- [2,1] with score (2 + 1) * 2 = 6.
Note that subarrays such as [1,4] and [4,3,5] are not considered because their scores are 10 and 36 respectively, 
while we need scores strictly less than 10.

Example 2:

Input: nums = [1,1,1], k = 5
Output: 5
Explanation:
Every subarray except [1,1,1] has a score less than 5.
[1,1,1] has a score (1 + 1 + 1) * 3 = 9, which is greater than 5.
Thus, there are 5 subarrays having scores less than 5.
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
1 <= k <= 10^15
*/

/*
TLE: 152 / 167

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int sz=nums.size();
        long long ans=0;
        vector<long long>prefSm(sz, 0);
        prefSm[0]=nums[0];
        for(int i=1; i<sz; ++i){
            prefSm[i]=prefSm[i-1]+nums[i];
        }
        for(int i=0; i<sz; ++i){
            if(nums[i]<k) ans++;
        }
        for(int i=0; i<sz-1; ++i){
            for(int j=i+1; j<sz; ++j){
                if(i-1>=0){
                    int len=(j-i)+1;
                    long long currprefSm=prefSm[j]-prefSm[i-1];
                    if((long long)currprefSm*len<k) ans++;
                    else break;
                } else{
                    int len=j+1;
                    long long currprefSm=prefSm[j];
                    if((long long)currprefSm*len<k) ans++;
                    else break;
                }
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    
    bool isValid(int i, int mid, long long k, vector<long long>&prefSm){
        if(i-1>=0){
            int len=(mid-i)+1;
            long long currprefSm=prefSm[mid]-prefSm[i-1];
            if((long long)currprefSm*len<k) return true;
            return false;   
        } else{
            int len=mid+1;
            long long currprefSm=prefSm[mid];
            if((long long)currprefSm*len<k) return true;
            return false;
        }
        return false;
    }
    
    int binarySearch(vector<long long>&prefSm, int i, int j, long long k){
        int left=i, right=j-1;
        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isValid(i, mid, k, prefSm)){
                ans=mid;
                left=mid+1;
            } else{
                right=mid-1;
            }
        }
        if(ans>0)
            return ans-i;
        return ans;
    }
    
    long long countSubarrays(vector<int>& nums, long long k) {
        int sz=nums.size();
        long long ans=0;
        vector<long long>prefSm(sz, 0);
        prefSm[0]=nums[0];
        if(nums[0]<k) ans++;
        for(int i=1; i<sz; ++i){
            if(nums[i]<k) ans++;
            prefSm[i]=prefSm[i-1]+nums[i];
        }
        for(int i=0; i<sz; ++i){
            int curres=binarySearch(prefSm, i, sz, k);
            ans+=curres;
        }
        return ans;
    }
};