// 2411. Smallest Subarrays With Maximum Bitwise OR
/*
You are given a 0-indexed array nums of length n, consisting of non-negative integers. 

For each index i from 0 to n - 1, you must determine the size of the minimum sized non-empty 
subarray of nums starting at i (inclusive) that has the maximum possible bitwise OR.

In other words, let Bij be the bitwise OR of the subarray nums[i...j]. You need to find the smallest 
subarray starting at i, such that bitwise OR of this subarray is equal to max(Bik) where i <= k <= n - 1.

The bitwise OR of an array is the bitwise OR of all the numbers in it.

Return an integer array answer of size n where answer[i] is the length of the minimum sized subarray 
starting at i with maximum bitwise OR.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,0,2,1,3]
Output: [3,3,2,2,1]
Explanation:
The maximum possible bitwise OR starting at any index is 3. 
- Starting at index 0, the shortest subarray that yields it is [1,0,2].
- Starting at index 1, the shortest subarray that yields the maximum bitwise OR is [0,2,1].
- Starting at index 2, the shortest subarray that yields the maximum bitwise OR is [2,1].
- Starting at index 3, the shortest subarray that yields the maximum bitwise OR is [1,3].
- Starting at index 4, the shortest subarray that yields the maximum bitwise OR is [3].
Therefore, we return [3,3,2,2,1]. 
Example 2:

Input: nums = [1,2]
Output: [2,1]
Explanation:
Starting at index 0, the shortest subarray that yields the maximum bitwise OR is of length 2.
Starting at index 1, the shortest subarray that yields the maximum bitwise OR is of length 1.
Therefore, we return [2,1].
 

Constraints:

n == nums.length
1 <= n <= 10^5
0 <= nums[i] <= 10^9
*/

/*
TLE: 53 / 59

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int sz=nums.size();
        vector<int>maxPrefixOR(sz+1, 0);
        for(int i=0; i<sz-1; ++i){
            int curOR=nums[i];
            int curmax=curOR;
            for(int j=i+1; j<sz; ++j){
                curOR|=nums[j];
                curmax=max(curmax, curOR);
            }
            maxPrefixOR[i]=curmax;
        }
        maxPrefixOR[sz-1]=nums[sz-1];
        vector<int>ans(sz, 0);
        for(int i=0; i<sz-1; ++i){
            int curxor=nums[i];
            int curlen=1;
            if(curxor>=maxPrefixOR[i]){
                ans[i]=curlen;
            } else{
                for(int j=i+1; j<sz; ++j){
                    curxor|=nums[j];
                    curlen++;
                    if(curxor>=maxPrefixOR[i]){
                        ans[i]=curlen;
                        break;
                    }
                }   
            }
        }
        ans[sz-1]=1;
        return ans;
    }
};
*/

/*
i   j--> 5 4 3 2 1 0
--------------------
9  ->    0 0 1 0 0 1
13 ->    0 0 1 1 0 1
55 ->    1 1 0 1 1 1
48 ->    1 1 0 0 0 0
56 ->    1 1 1 0 0 0

let see how we get length for first element (for 9) let's find it manually.

at bit position 0 -> what is the nearest element who is set to 1. the answer is 9 itself so nearest[0] = 0 (i position of 9)

at bit position 1 ->  what is the nearest element who is set to 1. the answer is 55(2nd element) nearest[1] = 2 
(i position of 55)

at bit position 2 ->  what is the nearest element who is set to 1. the answer is 13(1st element) nearest[2] = 1 
(i position of 13)

at bit position 3 ->  what is the nearest element who is set to 1. the answer is 9 itself so nearest[3] = 0 
(i position of 9)

at bit position 4 ->  what is the nearest element who is set to 1. the answer is 55(2nd element) nearest[4] = 2 
(i position of 55)

at bit position 5 ->  what is the nearest element who is set to 1. the answer is 55(2st element) nearest[5] = 2 
(i position of 55)

nearest[] = {0,2,1,0,2,2};
among them the farthest nearest[j] = 2;
so if we start OR operation from 0th index then first time we get our maximum value at 2nd index.
so the smallest subset is nums[0..2] => of size 3;

for maintaining the nearest array we have to traverse nums from right to left
and keep updating nearest[j] if current element have a set bit at jth position.
*/

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int sz=nums.size();
        vector<int>ans(sz, 0);
        vector<int>nearest(32, -1);
        for(int i=sz-1; i>=0; --i){
            for(int j=0; j<32; ++j){
                if(nums[i]&(1<<j)){
                    nearest[j]=i;
                }
            }
            int lastSetBit=i;
            for(int j=0; j<32; ++j){
                lastSetBit=max(lastSetBit, nearest[j]);
            }
            ans[i]=lastSetBit-i+1;
        }
        return ans;
    }
};