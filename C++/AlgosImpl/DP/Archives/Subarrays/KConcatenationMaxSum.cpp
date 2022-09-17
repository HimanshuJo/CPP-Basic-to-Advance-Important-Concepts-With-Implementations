// 1191. K-Concatenation Maximum Sum
/*
Given an integer array arr and an integer k, modify the array by repeating it k times.

For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

Return the maximum sub-array sum in the modified array. Note that the 
length of the sub-array can be 0 and its sum in that case is 0.

As the answer can be very large, return the answer modulo 10^9 + 7.

Example 1:

Input: arr = [1,2], k = 3
Output: 9
Example 2:

Input: arr = [1,-2,1], k = 5
Output: 2
Example 3:

Input: arr = [-1,-2], k = 7
Output: 0
 

Constraints:

1 <= arr.length <= 10^5
1 <= k <= 10^5
-10^4 <= arr[i] <= 10^4
*/

/*
TLE: 38 / 42

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int sz=arr.size();
        int mod=1e9+7;
        int nwsz=sz*k;
        long long ans=0;
        for(int i=0; i<sz; ++i){
            long long currsum=0;
            for(int j=i; j<sz; ++j){
                currsum=(currsum+arr[j]);
                ans=max(ans, currsum);
            }
            for(int x=0; x<k-1; ++x){
                for(int j=0; j<sz; ++j){
                    currsum=(currsum+arr[j]);
                    ans=max(ans, currsum);
                } 
            }
        }
        return ans%mod;
    }
};
*/

/*
Algo:

The maximum SubArray of concatenated_arr can be the sum of all its elements.
For e.g.. if A is {3, 2, -1} and K is 3, then B will be {3, 2, -1, 3, 2, -1, 3, 2, -1}.

The sum of all the elements in concatenated_arr will give us 12. 
To find this one we don't need to create the array concatenated_arr.

We can simply find the sum of all the elements in array A and we can mutilply it with K.

But wait, we can omit the last term in it so that the sum will become 13.
For this one we can use prefix and suffix calculations.

Eg:

A is repeated k times in concatenated_arr.

Consider the first repetition of A is A1, second is A2 and so on. 
So now our B array(if K=8) will be {A1, A2, A3, A4, A5, A6, A7, A8}. 
If you omit the first two elements in A1 and the last two elements in A8, you might also get the maxsub array.

So here we can check whether it is possible to omit some initial elements in A1 and some Final elements in A8. 
We use prefix and suffix variables for that to calculate the sum of A1 and A10 specifically and then adds 
the remaining elements 

i.e answer = {prefix + sum_of_elements(A2) + sum_of_elements(A3) + 
                       sum_of_elements(A4) + sum_of_elements(A5) + 
                       sum_of_elements(A6) + sum_of_elements(A7) + suffix} , 

            which in simplified form becomes {prefix + sum_of_elements(A)*(k-2) + suffix}.
*/  

using ll=long long;

class Solution {
    
    ll kadanes(vector<int>&arr){
        ll currSum=0;
        ll maxSum=INT_MIN;
        int sz=arr.size();
        for(int i=0; i<sz; ++i){
            currSum=currSum>0?(currSum+arr[i]):arr[i];
            maxSum=max(currSum, maxSum);
        }
        return maxSum<0?0:maxSum;
    }
    
    ll max_prefix_sum(vector<int>&arr){
        ll currSum=0;
        ll maxSum=INT_MIN;
        int sz=arr.size();
        for(int i=0; i<sz; ++i){
            currSum=(currSum+arr[i]);
            maxSum=max(maxSum, currSum);
        }
        return maxSum;
    }
    
    ll max_suffix_sum(vector<int>&arr){
        ll currSum=0;
        ll maxSum=INT_MIN;
        int sz=arr.size();
        for(int i=sz-1; i>=0; --i){
            currSum=(currSum+arr[i]);
            maxSum=max(currSum, maxSum);
        }
        return maxSum;
    }
    
public:
    
    int mod=1e9+7;
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        ll maxSum=kadanes(arr);
        if(k==1) return maxSum;
        ll maxPrefixSum=max_prefix_sum(arr);
        ll maxSuffixSum=max_suffix_sum(arr);
        ll sum=0;
        for(auto &vals: arr){
            sum+=vals;
        }
        if(sum>0){
            return (max((sum*(k-2)+maxPrefixSum+maxSuffixSum), maxSum)%mod);
        }
        return (max(maxPrefixSum+maxSuffixSum, maxSum)%mod);
    }
};