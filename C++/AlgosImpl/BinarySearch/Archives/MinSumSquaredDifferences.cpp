// 2333. Minimum Sum of Squared Difference
/*
You are given two positive 0-indexed integer arrays nums1 and nums2, both of length n.

The sum of squared difference of arrays nums1 and nums2 is defined as the sum of 
(nums1[i] - nums2[i])2 for each 0 <= i < n.

You are also given two positive integers k1 and k2. You can modify any of the elements of 
nums1 by +1 or -1 at most k1 times. 

Similarly, you can modify any of the elements of nums2 by +1 or -1 at most k2 times.

Return the minimum sum of squared difference after modifying array nums1 at most k1 times 
and modifying array nums2 at most k2 times.

Note: You are allowed to modify the array elements to become negative integers.

Example 1:

Input: nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
Output: 579
Explanation: The elements in nums1 and nums2 cannot be modified because k1 = 0 and k2 = 0. 
The sum of square difference will be: (1 - 2)2 + (2 - 10)2 + (3 - 20)2 + (4 - 19)2 = 579.
Example 2:

Input: nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
Output: 43
Explanation: One way to obtain the minimum sum of square difference is: 
- Increase nums1[0] once.
- Increase nums2[2] once.
The minimum of the sum of square difference will be: 
(2 - 5)2 + (4 - 8)2 + (10 - 7)2 + (12 - 9)2 = 43.
Note that, there are other ways to obtain the minimum of the sum of square difference, but there is no way to obtain a sum smaller than 43.
 

Constraints:

n == nums1.length == nums2.length
1 <= n <= 10^5
0 <= nums1[i], nums2[i] <= 10^5
0 <= k1, k2 <= 10^9
*/

class Solution {
public:
    
    bool isValid(vector<int>&temp, int mid, int k){
        long long total=0;
        for(int i=0; i<temp.size(); ++i){
            if(temp[i]>mid){
                total+=temp[i]-mid;
            }
        }
        return total<=k;
    }
    
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int sz=nums1.size();
        vector<int>temp(sz);
        for(int i=0; i<sz; ++i){
            temp[i]=abs(nums1[i]-nums2[i]);
        }
        int left=0, right=*max_element(temp.begin(), temp.end());
        int ans=0;
        long long k=k1+k2;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isValid(temp, mid, k)){
                ans=mid;
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        long long res=0;
        for(int i=0; i<sz; ++i){
            if(temp[i]>ans&&k>0){
                int diff=temp[i]-ans;
                k-=diff;
                temp[i]-=diff;
            }
        }
        priority_queue<int>pq;
        for(int i=0; i<sz; ++i){
            pq.push(temp[i]);
        }
        while(k>0&&pq.top()>0){
            int l=pq.top();
            pq.pop();
            l-=1;
            pq.push(l);
            k--;
        }
        if(pq.top()==0) return 0;
        while(!pq.empty()&&pq.top()>0){
            res+=pq.top()*1LL*pq.top();
            pq.pop();
        }
        return res;
    }
};

// -------*******-------

class Solution2 {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int sz=nums1.size();
        vector<long long>temp(sz);
        for(int i=0; i<sz; ++i){
            temp[i]=abs(nums1[i]-nums2[i]);
        }
        long long left=0, right=1e5, extra_ops=0, res=0;
        long long ans=0;
        while(left<=right){
            long long mid=left+(right-left)/2, ops=0;
            for(auto &vals: temp){
                ops+=max(0LL, vals-mid);
            }
            if(ops<=k1+k2){
                ans=mid;
                right=mid-1;
                extra_ops=k1+k2-ops;
            } else{
                left=mid+1;
            }
        }
        for(auto &nums: temp){
            long long val=nums<ans?nums:max(0LL, ans-(--extra_ops>=0?1: 0));
            res+=val*val;
        }
        return res;
    }
};

// -------*******-------

class Solution3 {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long minSumSquare=0;
        vector<int>diffs(100001, 0);
        long long totalDiff=0, maxDiff=0;
        long long kSum=k1+k2;
        long long currDiff;
        int sz=nums1.size();
        for(int i=0; i<sz; ++i){
            currDiff=abs(nums1[i]-nums2[i]);
            if(currDiff>0){
                totalDiff+=currDiff;
                diffs[currDiff]++;
                maxDiff=max(maxDiff, currDiff);
            }
        }
        if(totalDiff<=kSum) return 0;
        for(int i=maxDiff;i>0&&kSum>0; --i){
            if(diffs[i]>0){
                if(diffs[i]>=kSum){
                    diffs[i]-=kSum;
                    diffs[i-1]+=kSum;
                    kSum=0;
                } else{
                    diffs[i-1]+=diffs[i];
                    kSum-=diffs[i];
                    diffs[i]=0;
                }
            }
        }
        for(int i=0; i<=maxDiff; ++i){
            if(diffs[i]>0){
                minSumSquare+=(long long)(pow((long long)i, 2))*diffs[i];
            }
        }
        return minSumSquare;
    }
};