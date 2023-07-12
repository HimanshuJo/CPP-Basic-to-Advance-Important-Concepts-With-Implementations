// 2104. Sum of Subarray Ranges
/*
You are given an integer array nums. The range of a subarray of nums is the 
difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
 

Constraints:

1 <= nums.length <= 1000
-10^9 <= nums[i] <= 10^9
 

Follow-up: Could you find a solution with O(n) time complexity?
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:

	vector<int> fndNxtSmLftInd(vector<int>&nums){
		stack<int>decStack;
		int n=nums.size();
		vector<int>res(n);
		for(int i=0; i<n; ++i){
			while(!decStack.empty()&&nums[decStack.top()]>nums[i]){
				decStack.pop();
			}
			if(decStack.empty()){
				res[i]=-1;
			} else{
				res[i]=decStack.top();
			}
			decStack.push(i);
		}
		return res;
	}

	vector<int> fndNxtSmRghtInd(vector<int>&nums){
		stack<int>decStack;
		int n=nums.size();
		vector<int>res(n);
		for(int i=n-1; i>=0; --i){
			while(!decStack.empty()&&nums[decStack.top()]>=nums[i]){
				decStack.pop();
			}
			if(decStack.empty()){
				res[i]=n;
			} else{
				res[i]=decStack.top();
			}
			decStack.push(i);
		}
		return res;
	}

	vector<int> fndNxtLargLftInd(vector<int>&nums){
		stack<int>incStack;
		int n=nums.size();
		vector<int>res(n);
		for(int i=0; i<n; ++i){
			while(!incStack.empty()&&nums[incStack.top()]<nums[i]){
				incStack.pop();
			}
			if(incStack.empty()){
				res[i]=-1;
			} else{
				res[i]=incStack.top();
			}
			incStack.push(i);
		}
		return res;
	}

	vector<int> fndNxtLargRghtInd(vector<int>&nums){
		stack<int>incStack;
		int n=nums.size();
		vector<int>res(n);
		for(int i=n-1; i>=0; --i){
			while(!incStack.empty()&&nums[incStack.top()]<=nums[i]){
				incStack.pop();
			}
			if(incStack.empty()){
				res[i]=n;
			} else{
				res[i]=incStack.top();
			}
			incStack.push(i);
		}
		return res;
	}


    long long subArrayRanges(vector<int>& nums) {
        long long res=0;
		vector<int>nxtSmLft=fndNxtSmLftInd(nums);
		vector<int>nxtSmRght=fndNxtSmRghtInd(nums);
		vector<int>nxtLargLft=fndNxtLargLftInd(nums);
		vector<int>nxtLargRght=fndNxtLargRghtInd(nums);
		int n=nums.size();
		for(int i=0; i<n; ++i){
			long long minLftCnt=(i-nxtSmLft[i])-1;
			long long minRghtCnt=(nxtSmRght[i]-i)-1;
			long long maxLftCnt=(i-nxtLargLft[i])-1;
			long long maxRghtCnt=(nxtLargRght[i]-i)-1;
			long long totalMinCnt=minLftCnt+minRghtCnt+(minLftCnt*minRghtCnt);
			long long totalMaxCnt=maxLftCnt+maxRghtCnt+(maxLftCnt*maxRghtCnt);
			res+=(totalMaxCnt-totalMinCnt)*nums[i];
		}
		return res;
    }
};

