// 2293. Min Max Game
/*
You are given a 0-indexed integer array nums whose length is a power of 2.

Apply the following algorithm on nums:

Let n be the length of nums. If n == 1, end the process. 
Otherwise, create a new 0-indexed integer array newNums of length n / 2.

For every even index i where 0 <= i < n / 2, assign the value of newNums[i] as min(nums[2 * i], nums[2 * i + 1]).
For every odd index i where 0 <= i < n / 2, assign the value of newNums[i] as max(nums[2 * i], nums[2 * i + 1]).

Replace the array nums with newNums.
Repeat the entire process starting from step 1.
Return the last number that remains in nums after applying the algorithm

Input: nums = [1,3,5,2,4,8,2,2]
Output: 1
Explanation: The following arrays are the results of applying the algorithm repeatedly.
First: nums = [1,5,4,2]
Second: nums = [1,4]
Third: nums = [1]
1 is the last remaining number, so we return 1.
Example 2:

Input: nums = [3]
Output: 3
Explanation: 3 is already the last remaining number, so we return 3.
 

Constraints:

1 <= nums.length <= 1024
1 <= nums[i] <= 10^9
nums.length is a power of 2.
*/

// TC: O(log(n)*log(n))  n: nums size
// SC: O(log(n))
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n=nums.size();
        vector<int>newNums(n/2, 0);
        while(n!=1){
            for(int i=0; i<n/2; ++i){
                if(i%2==0){
                    newNums[i]=min(nums[2*i], nums[2*i+1]);
                }
                if(i%2!=0){
                    newNums[i]=max(nums[2*i], nums[2*i+1]);
                }
            }
            nums=newNums;
            n=nums.size();
            newNums.resize(n/2, 0);
        }
        return nums[0];
    }
};

// TC: O(log(n)*log(n))  n: nums size
// SC: O(1)
class Solution2 {
public:
    int minMaxGame(vector<int>& nums) {
        int n=nums.size();
        vector<int>newNums(n/2, 0);
        for(int j=0; j<n/2; ++j){
            for(int i=0; i<n/2; ++i){
                if(i%2==0){
                    nums[i]=min(nums[2*i], nums[2*i+1]);
                }
                if(i%2!=0){
                    nums[i]=max(nums[2*i], nums[2*i+1]);
                }
            }
        }
        return nums[0];
    }
};

class Solution3 {
public:
    int minMaxGame(vector<int>& nums) {
        auto mn=[](int a, int b){
            return min(a, b);
        };
        
        auto mx=[](int a, int b){
            return max(a, b);
        };
        
        function<int(int, int, function<int(int, int)>)> op=[&](int i, int j, function<int(int, int)>f){
            return j-i==1?f(nums[i], nums[j]): f(op(i, i+(j-i)/2, mn), op(i+(j-i)/2+1, j, mx));
        };
        
        return nums.size()==1?nums.back():op(0, nums.size()-1, mn);
    }
};