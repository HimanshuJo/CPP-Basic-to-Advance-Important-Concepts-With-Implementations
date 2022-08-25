// 2091. Removing Minimum and Maximum From Array
/*
You are given a 0-indexed array of distinct integers nums.

There is an element in nums that has the lowest value and an element that has the highest value. 
We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.

A deletion is defined as either removing an element from the front of the array or 
removing an element from the back of the array.

Return the minimum number of deletions it would take to remove both the minimum 
and maximum element from the array.

Example 1:

Input: nums = [2,10,7,5,4,1,8,6]
Output: 5
Explanation: 
The minimum element in the array is nums[5], which is 1.
The maximum element in the array is nums[1], which is 10.
We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
This results in 2 + 3 = 5 deletions, which is the minimum number possible.
Example 2:

Input: nums = [0,-4,19,1,8,-2,-3,5]
Output: 3
Explanation: 
The minimum element in the array is nums[1], which is -4.
The maximum element in the array is nums[2], which is 19.
We can remove both the minimum and maximum by removing 3 elements from the front.
This results in only 3 deletions, which is the minimum number possible.
Example 3:

Input: nums = [101]
Output: 1
Explanation:  
There is only one element in the array, which makes it both the minimum and maximum element.
We can remove it with 1 deletion.
 

Constraints:

1 <= nums.length <= 10^5
-10^5 <= nums[i] <= 10^5
The integers in nums are distinct.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
		int n=nums.size();
        int hfLen=n/2;
		int minInd=0, maxInd=0;
		int minn=INT_MAX, maxx=INT_MIN;
		for(int i=0; i<n; ++i){
			if(nums[i]<minn){
				minn=nums[i];
				minInd=i;
			}
			if(nums[i]>maxx){
				maxx=nums[i];
				maxInd=i;
			}
		}
		int ans=0;
		int maxbt=max(minInd, maxInd);
        int tmpminbt=min(minInd, maxInd);
		if(maxbt<=hfLen){
			return maxbt+1;
		} else{
            if(minInd<hfLen&&maxInd>=hfLen||(minInd>=hfLen&&maxInd<hfLen)){
                int minbt=min(minInd, maxInd);
                ans+=(minbt+1);
                ans+=(n-maxbt);   
            } else if(minInd>=hfLen&&maxInd>=hfLen){
                int minBt=min(minInd, maxInd);
                ans+=(n-minBt);
            }
		}
		return (min(ans, min(maxbt+1, (n-tmpminbt))));
    }
};

int main(){}

