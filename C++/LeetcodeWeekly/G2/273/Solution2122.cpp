// 2122. Recover the Original Array
/*
Alice had a 0-indexed array arr consisting of n positive integers. 
She chose an arbitrary positive integer k and created two new 0-indexed integer arrays lower and higher in the following manner:

lower[i] = arr[i] - k, for every index i where 0 <= i < n
higher[i] = arr[i] + k, for every index i where 0 <= i < n
Unfortunately, Alice lost all three arrays. However, she remembers the integers that were present in the arrays lower and higher, 
but not the array each integer belonged to. Help Alice and recover the original array.

Given an array nums consisting of 2n integers, where exactly n of the integers were present in lower and the remaining in higher, 
return the original array arr. In case the answer is not unique, return any valid array.

Note: The test cases are generated such that there exists at least one valid array arr.


Example 1:

Input: nums = [2,10,6,4,8,12]
Output: [3,7,11]
Explanation:
If arr = [3,7,11] and k = 1, we get lower = [2,6,10] and higher = [4,8,12].
Combining lower and higher gives us [2,6,10,4,8,12], which is a permutation of nums.
Another valid possibility is that arr = [5,7,9] and k = 3. In that case, lower = [2,4,6] and higher = [8,10,12]. 
Example 2:

Input: nums = [1,1,3,3]
Output: [2,2]
Explanation:
If arr = [2,2] and k = 1, we get lower = [1,1] and higher = [3,3].
Combining lower and higher gives us [1,1,3,3], which is equal to nums.
Note that arr cannot be [1,3] because in that case, the only possible way to obtain [1,1,3,3] is with k = 0.
This is invalid since k must be positive.
Example 3:

Input: nums = [5,435]
Output: [220]
Explanation:
The only possible combination is arr = [220] and k = 215. Using them, we get lower = [5] and higher = [435].
 

Constraints:

2 * n == nums.length
1 <= n <= 1000
1 <= nums[i] <= 10^9
The test cases are generated such that there exists at least one valid array arr.
*/

/*
For any valid k value we take lower[i] element and search for their higher[i] in nums
such that lower[i] = higher[i] + 2*k explain below

I would like to explain you with example

nums = [11, 6, 3, 4, 8, 7, 8, 7, 9, 8, 9, 10, 10, 2, 1, 9] n = 16

since k is subtracting and adding from each nums[i] to create lower and higher array respectively.
k is same for all so the smallest value belongs to the lower array.
firstly we sort the given array so it becomes

[1, 2, 3, 4, 6, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 11]

Little Maths Equations

lower[i] =   nums[i] - k		 (given in ques)                 
nums[i]  =  lower[i] + k          ....1)       	   
 
higher[i] =  nums[i]  + k        (given in ques)
nums[i]  =   higher[i] - k        ....2)   

using 1 and  2
  lower[i] + k     =  higher[i] - k
  lower[i] + 2k    =  higher[i]   
  
higher[i] = lower[i] + 2k // so we can say that for every higher there is a match in lower or vice versa.

we use above equation to find the match with every lower

also for getting k value
k = (higher[i] - lower[i])/2  (using above equation)

Instead of trying for every possible value we only need to try with smallest element to find a valid k value. 
(since at least one ans possible)

So lets dry run the above example
nums[] = [1, 2, 3, 4, 6, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 11]

smallest = nums[0] = 1

  k = (nums[i] - smallest)/2

for checking valid k
we check if k>0 && smallest + 2*k == nums[i]

from each index i = 1 to n in nums:

i= 1:

			 nums[i] = 2
			 k = (2 - 1)/2;
			 k = 0 (not valid); 


i = 2:

			 nums[i] = 3
			 k = (3-1)/2;
			 k = 1 (valid)

Now we try to find match of every lower with higher

for each i = 0 to n in nums

	target = nums[i] + 2*k;  // we search  target value in nums (since for every lower there is a match in higher if we find valid k)
	ans =  [] 

i= 0:
	nums[i] =1

		target =  1 + 2*1 = 3 (present in nums[2] mark as visited)
		push (nums[i] + k) in ans array

		nums[i] + k = 2
		ans = [2]

i= 1: 
	nums[i] =2

		target =  2 + 2*1 = 4 (present in nums[3] mark as visited)
		push (nums[i] + k) in ans array

		nums[i] + k =3
		ans = [2,3]

i= 2:
	   nums[i] = 3  (already visited (matched with index 0) so  skip it

i= 3:
		nums[i] = 4 (already visited (matched with index 1) so  skip it

i= 4:
		nums[i] = 6

		target =  6 + 2*1 = 8 (present in nums[7] mark as visited)
		Note : here we find multiple 8 but we start from the leftmost.

		push (nums[i] + k ) in ans array

		nums[i] + k = 7;
		ans = [2,3,7]

i= 5:
		nums[i] = 7

		target =  7 + 2*1 = 9 (present in nums[10] mark as visited)
		again we find multiple value equals to target but start from the leftmost

		push (nums[i] + k) in ans array

		nums[i] + k = 8
		ans = [2,3,7,8]

i= 6:
		nums[i] = 7

		target =  7 + 2*1 = 9 (present in nums[11] mark as visited)
		push (nums[i] + k) in ans array

		nums[i] + k = 8
		ans = [2,3,7,8,8]

i=7:
		nums[i] = 8 (already visited (matched with index 4) so  skip it

i=8:
		nums[i] = 8

		target =  8 + 2*1 = 10 (present in nums[13] mark as visited)
		push (nums[i] + k) in ans array

		nums[i] + k = 9
		ans = [2,3,7,8,8,9]

i=9:
		nums[i] = 8

		target =  8 + 2*1 = 10 (present in nums[14] mark as visited)
		push (nums[i] + k which 9) in ans array

		nums[i] + k = 9
		ans = [2,3,7,8,8,9,9]

i=10:
		nums[i] = 9 (already visited (matched with index 5) so  skip it

i=11:
		nums[i] = 9 (already visited (matched with index 6) so  skip it

i=12:
		nums[i] = 9

		target =  9 + 2*1 = 11 (present in nums[15] mark as visited)
		push (nums[i] + k) in ans array

		nums[i] + k = 10
		ans = [2,3,7,8,8,9,9,10]


i = 13,14 15   
				already visited so skip it

	ans = [2,3,7,8,8,9,9,10] // bingo  our ans array size equals to n/2  hence we found a valid array.
*/

class Solution{
public:
	int search(vector<int>&nums, bool seen[], int left, int right, int target){
		int idx=-1;
		while(left<=right){
			int mid=left+(right-left)/2;
			/*
				here we are visiting target from left to right so in case of multiple target with same value we sure that 
				we not miss any element.
    			example from the mentioned array in case of [9, 9, 9] 
    			if we visit  middle 9 then for the next 9  we can't predict whether to go right or left.
    			In case we choose of moving right then we miss searching left 9 in next binarySearch with target 9 
   				OR if we choose of moving left then we miss right 9 in next binarySearch with target 9
			*/
			if(nums[mid]==target){
				if(seen[mid]){
					left=mid+1;
				} else{
					idx=mid;
					right=mid-1;
				}
				continue;
			}
			if(nums[mid]>target){
				right=mid-1;
			} else{
				left=mid+1;
			}
		}
		return idx;
	}

	vector<int> recoverArray(vector<int>&nums){
		int n=nums.size();
		sort(nums.begin(), nums.end());
		int smallest=nums[0];
		for(int i=1; i<n; ++i){
			int k=(nums[i]-smallest)/2;
			if(k<=0||(smallest+2*k!=nums[i])) continue;
			bool seen[1001];
			for(int ii=0; ii<1001; ++ii)
				seen[ii]=false;
			vector<int>ans;
			for(int j=0; j<n; ++j){
				if(seen[j]) continue;
				int target=nums[j]+2*k;
				int idx=search(nums, seen, j+1, n-1, target);
				if(idx==-1) break;
				seen[idx]=true;
				/*
				storing value  as an ans.(explained above why we storing nums[j] + k)
				lower[i] = nums[i] - k   =>  nums[i] = lower[i] + k // so we get one valid num[i] element
				*/
				ans.push_back(nums[j]+k);
			}
			if(ans.size()==n/2) return ans;
		}
		return {};
	}
};