/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, 
which means you could search circularly to find its next greater number. 
If it doesn't exist, return -1 for this number.

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.

Brutr Force:

public class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            res[i] = -1;
            for (int j = 1; j < nums.length; j++) {
                if (nums[(i + j) % nums.length] > nums[i]) {
                    res[i] = nums[(i + j) % nums.length];
                    break;
                }
            }
        }
        return res;
    }
}
*/

/*
Optimized approach: 2 Pass

Stack<Integer> stack = new Stack<>();

public int[] nextGreaterElements(int[] nums) {

    int[] res = new int[nums.length];
    for(int i=0;i<nums.length;i++) {
        while(!stack.isEmpty() && nums[stack.peek()] < nums[i]) {
            res[stack.pop()] = nums[i];
        }
        stack.push(i);
    }
    
    for(int i=0;i<nums.length;i++) {
        while(!stack.isEmpty() && nums[stack.peek()] < nums[i]) {
            res[stack.pop()] = nums[i];
        }
    }

    while(!stack.isEmpty()) {
        res[stack.pop()] = -1;
    }
    return res;
}
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        stack<int>stk;
        for(int i=2*n-1; i>=0; --i){
            while(!stk.empty()&&nums[stk.top()]<=nums[i%n]){
                stk.pop();
            }
            res[i%n]=stk.empty()?-1:nums[stk.top()];
            stk.push(i%n);
        }
        return res;
    }
};

class Solution2{
public:
	vector<int> nextGreaterElements(vector<int>&nums){
		int n=nums.size();
		vector<int>res(n);
		stack<int>stk;
		for(int i=0; i<n; ++i){
			while(!stk.empty()&&nums[stk.top()]<nums[i]){
				res[stk.top()]=nums[i];
				stk.pop();
			}
			stk.push(i);
		}
		for(int i=0; i<n; ++i){
			while(!stk.empty()&&nums[stk.top()]<nums[i]){
				res[stk.top()]=nums[i];
				stk.pop();
			}
		}
        while(!stk.empty()) {
            res[stk.top()] = -1;
            stk.pop();
        }
		return res;
	}
};