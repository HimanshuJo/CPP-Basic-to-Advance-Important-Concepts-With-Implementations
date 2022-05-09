// 698. Partition to K Equal Sum Subsets
/*
Given an integer array nums and an integer k, return true if it is possible to divide 
this array into k non-empty subsets whose sums are all equal.

Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
*/

/*
    public boolean canPartitionKSubsets(int[] a, int k) {
        int sum = IntStream.of(a).sum();
        return k != 0 && sum % k == 0 && canPartition(0, a, new boolean[a.length], k, 0, sum / k);
    }

    boolean canPartition(int start, int[] a, boolean[] seen, int k, int sum, int target) {
        if (k == 1) return true;
        if (sum == target)
            return canPartition(0, a, seen, k - 1, 0, target);
        for (int i = start; i < a.length; i++)
            if (!seen[i]) {
                seen[i] = true;
                if (canPartition(i + 1, a, seen, k, sum + a[i], target))
                    return true;
                seen[i] = false;
            }
        return false;
    }
*/

class Solution {
public:

	bool canPartition(int idx, vector<int>&nums, vector<bool>&seen, int k, int currSm, int target){
		if(k==0) return true;
		if(currSm==target){
			return canPartition(0, nums, seen, k-1, 0, target);
		}
		for(int i=idx; i<nums.size(); ++i){
			if(!seen[i]&&currSm+nums[i]<=target){
				seen[i]=true;
				if(canPartition(i+1, nums, seen, k , currSm+nums[i], target))
					return true;
				seen[i]=false;
			}
		}
		return false;
	}

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(auto &vals: nums)
        	sum+=vals;
        if(k==0||sum%k!=0) return false;
        int n=nums.size();
        vector<bool>seen(n);
        int target=sum/k;
        bool res=canPartition(0, nums, seen, k, 0, target);
        return res;
    }
};