// 1984. Minimum Difference Between Highest and Lowest of K Scores
/*
You are given a 0-indexed integer array nums, where nums[i] represents the 
score of the ith student. You are also given an integer k.

Pick the scores of any k students from the array so that the difference 
between the highest and the lowest of the k scores is minimized.

Return the minimum possible difference.

Example 2:

Input: nums = [9,4,1,7], k = 2
Output: 2
Explanation: There are six ways to pick score(s) of two students:
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 4 = 5.
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 1 = 8.
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 7 = 2.
- [9,4,1,7]. The difference between the highest and lowest score is 4 - 1 = 3.
- [9,4,1,7]. The difference between the highest and lowest score is 7 - 4 = 3.
- [9,4,1,7]. The difference between the highest and lowest score is 7 - 1 = 6.
The minimum possible difference is 2.
*/

class Solution {
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int minDiff=nums[k-1]-nums[0];
        for (int i=k; i<nums.size(); ++i){
            int currMin=nums[i]-nums[i-k+1];
            minDiff=min(currMin, minDiff);
        }
        return minDiff;
    }
};

// -------*******-------

class Solution2
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        int sz = k;
        int minDiff = INT_MAX;
        sort(nums.begin(), nums.end());
        int index = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            vector<int> tmp;
            for (int j = i; j < i + sz; ++j)
            {
                if (j > nums.size() - 1)
                {
                    while (tmp.size() != sz)
                    {
                        tmp.push_back(nums[index]);
                        index++;
                    }
                    index = 0;
                    break;
                }
                tmp.push_back(nums[j]);
            }
            sort(tmp.begin(), tmp.end());
            int valEnd = tmp[tmp.size() - 1];
            int strt = tmp[0];
            if (valEnd - strt < minDiff)
            {
                minDiff = valEnd - strt;
            }
        }
        return minDiff;
    }
};