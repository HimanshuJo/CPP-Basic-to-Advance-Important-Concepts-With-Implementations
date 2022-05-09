// 2195. Append K Integers With Minimal Sum
/*
You are given an integer array nums and an integer k. 
Append k unique positive integers that do not appear in nums to nums such 
that the resulting total sum is minimum.

Return the sum of the k integers appended to nums.

Example 1:

Input: nums = [1,4,25,10,25], k = 2
Output: 5
Explanation: The two unique positive integers that do not appear in nums which we append are 2 and 3.
The resulting sum of nums is 1 + 4 + 25 + 10 + 25 + 2 + 3 = 70, which is the minimum.
The sum of the two integers appended is 2 + 3 = 5, so we return 5.
Example 2:

Input: nums = [5,6], k = 6
Output: 25
Explanation: The six unique positive integers that do not appear in nums which we append are 1, 2, 3, 4, 7, and 8.
The resulting sum of nums is 5 + 6 + 1 + 2 + 3 + 4 + 7 + 8 = 36, which is the minimum. 
The sum of the six integers appended is 1 + 2 + 3 + 4 + 7 + 8 = 25, so we return 25.

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= k <= 10^8
*/


class Solution {
public:
    
    long long getSum(long long end){
        return (end*(end+1)/2);
    }
    
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums[0]>k){
            return (getSum(k));
        }
        long long res=0;
        int sz=nums.size();
        int end=nums[sz-1];
        long long counterI=0, counterK=0;
        int idx=0;
        if(nums[0]!=1){
          long long av=nums[0]-1;
            if(av<=k){
                counterK+=av;
                long long end=nums[0]-1;
                long long sm=getSum(end);
                res+=sm;
                counterI=nums[idx];
            } else{
                long long end1=(k-counterK)+counterI;
                long long smfrstN=getSum(end);
                long long smfrstB=getSum(counterI);
                res+=(smfrstN-smfrstB);
                counterK=k;
            }
        }
        if(counterK!=k){
            for(int i=0; i<sz-1; ++i){
                if(abs(nums[i]-nums[i+1])!=1&&(nums[i]!=nums[i+1])){
                    long long av=(nums[i+1]-nums[i])-1;
                    long long remain=k-counterK;
                    if(av<=remain){
                        long long bgn=nums[i];
                        long long end=nums[i+1]-1;
                        long long smfrstN=getSum(end);
                        long long smfrstB=getSum(bgn);
                        res+=(smfrstN-smfrstB);
                        counterK+=av;
                        if(counterK==k) break;
                    } else{
                        long long bgn=nums[i];
                        long long end=(k-counterK)+nums[i];
                        long long smfrstN=getSum(end);
                        long long smfrstB=getSum(bgn);
                        res+=(smfrstN-smfrstB);
                        counterK=k;
                        break;
                    }
                }
            }   
        }
        if(counterK!=k){
            counterI=nums.back();
            long long end=(k-counterK)+counterI;
            long long smfrstN=getSum(end);
            long long smfrstB=getSum(counterI);
            res+=(smfrstN-smfrstB);
        }
        return res;
    }
};