// 2035. Partition Array Into Two Arrays to Minimize Sum Difference
/*
You are given an integer array nums of 2 * n integers. 

You need to partition nums into two arrays of length n to minimize the absolute 
difference of the sums of the arrays. 

To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.

Input: nums = [3,9,7,3]
Output: 2
Explanation: One optimal partition is: [3,9] and [7,3].
The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.

Input: nums = [-36,36]
Output: 72
Explanation: One optimal partition is: [-36] and [36].
The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.

Input: nums = [2,-1,0,4,-2,-9]
Output: 0
Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.

Constraints:

1 <= n <= 15
nums.length == 2 * n
-107 <= nums[i] <= 10^7
*/
/*
Algorithm

High Level Approach:

*  We divide the input array into two arbitary parts. 
*  Then, We take one subset from each part, such that, sum of size of both subset = n. 
*  And with that subset we try to minimise the absolute difference.

-------

Detailed:

    Divide the original array in two arbitary parts, each of size n. 

    LeftPart: [0, n-1], RightPart[n, 2*n-1]

    -------

    Find all possible sums in each part.

        As each part will be of size <= 15
        We can safely enumerate all possible sums in each part.

        For each part, store the sum of a subset along with the size of the subset.

        In Code:
        I have used two 2-D vectors, left and right, to store sums of all possible subset.

        Left[ i ]: stores all possible sums of the subset of size i, in the left part.

        Similarly, for right part.

        Requirement: 

            We need to divide the original array in two parts of size n, each. 
            Such that the absolute difference of sum is minimised.

-------

Let say from left part we take a subset of size sz (Let's say its sum is a), 
then from right part we need to take a subset of size of n-sz (Let's say its sum is b). 

Then, Part1Sum = a+b.

We have to minimise abs(Part1Sum - Part2Sum)

Now, Part1Sum = a+b and Part2Sum = TotalSum - (a+b)

Thus we have to minimise, abs(TotalSum -2a - 2b)

Now we iterate over a, and binary search b in the vector right

TC:

    O(2^n * log(2^n))

This technique commonly known as Meet In Middle. Commonly used when 25 <= array_size <= 40
*/

/*
TLE: 74/201

class Solution {
    
    vector<vector<int>>res__;
    public:
    
    void dfs(vector<int>&nums, int sz, int idx, vector<int>&allsubseqs){
        if(idx==sz){
            if(allsubseqs.size()==sz/2){
                res__.push_back(allsubseqs);
            }
            return;
        }
        allsubseqs.push_back(idx);
        dfs(nums, sz, idx+1, allsubseqs);   
        allsubseqs.pop_back();
        dfs(nums, sz, idx+1, allsubseqs);
    }
    
    int minimumDifference(vector<int>& nums) {
        int sz=nums.size();
        vector<int>allsubseqs;
        dfs(nums, sz, 0, allsubseqs);
        int res=INT_MAX;
        int sz_=res__.size();
        for(int i=0; i<sz_; ++i){
            int cursm=0;
            vector<int>curr=res__[i];
            vector<bool>seen(curr.size(), false);
            for(auto &vals: curr){
                cursm+=nums[vals];
                seen[vals]=true;
            }
            if(i+1<=sz_-1){
                for(int j=i+1; j<sz_; ++j){
                    int nxtsm=0;
                    bool flag=false;
                    vector<int>next=res__[j];
                    for(auto &vals: next){
                        if(seen[vals]){
                            nxtsm=0;
                            flag=true;
                            break;
                        }
                        nxtsm+=nums[vals];
                    }
                    if(!flag){
                        int tochk=abs(cursm-nxtsm);
                        res=min(res, tochk);   
                    }
                }   
            }
        }
        return res;
    }
};
*/

class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size(), res = 0, sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);

        int N = n / 2;
        vector<vector<int>> left(N + 1), right(N + 1);

        //storing all possible sum in left and right part
        for (int mask = 0; mask < (1 << N); ++mask)
        {
            int sz = 0, l = 0, r = 0;
            for (int i = 0; i < N; ++i)
            {
                if (mask & (1 << i))
                {
                    sz++;
                    l += nums[i];
                    r += nums[i + N];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        for (int sz = 0; sz <= N; ++sz)
        {
            sort(right[sz].begin(), right[sz].end());
        }

        res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0]));

        //iterating over left part
        for (int sz = 1; sz < N; ++sz)
        {
            for (auto &a : left[sz])
            {
                int b = (sum - 2 * a) / 2, rsz = N - sz;
                auto &v = right[rsz];
                auto itr = lower_bound(v.begin(), v.end(), b); //binary search over right part

                if (itr != v.end())
                    res = min(res, abs(sum - 2 * (a + (*itr))));
                if (itr != v.begin())
                {
                    auto it = itr;
                    --it;
                    res = min(res, abs(sum - 2 * (a + (*it))));
                }
            }
        }
        return res;
    }
};