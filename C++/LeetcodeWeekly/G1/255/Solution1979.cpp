// 1979. Find Greatest Common Divisor of Array
/*
Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

Example 1:

Input: nums = [2,5,6,9,10]
Output: 2
Explanation:
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.
*/

/*
class Solution{
    public:
        int findGCD(vector<int>& n) {
            return __gcd(*min_element(begin(n), end(n)), *max_element(begin(n), end(n)));
        }
    }  
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int gcd(int a, int b){
        if (b==0){
            return a;
        } else {
            return gcd(b, a%b);
        }
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        cout<<gcd(nums[0], nums[nums.size()-1]);
        return gcd(nums[0], nums[nums.size()-1]);
    }
};

int main(){
    Solution obj;
    vector<int>nums={3,3};
    obj.findGCD(nums);
}
