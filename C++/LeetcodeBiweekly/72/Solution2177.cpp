// 2177. Find Three Consecutive Integers That Sum to a Given Number
/*
Given an integer num, return three consecutive integers (as a sorted array) that sum to num. 
If num cannot be expressed as the sum of three consecutive integers, return an empty array.

Example 1:

Input: num = 33
Output: [10,11,12]
Explanation: 33 can be expressed as 10 + 11 + 12 = 33.
10, 11, 12 are 3 consecutive integers, so we return [10, 11, 12].
Example 2:

Input: num = 4
Output: []
Explanation: There is no way to express 4 as the sum of 3 consecutive integers.
 

Constraints:

0 <= num <= 10^15
*/

/*
TLE:

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        string temp=to_string(num);
        int lenstr=temp.length();
        long long bgn=(long long) pow(10, lenstr-2);
        long long end=num/2;
        vector<long long>res;
        for(long long i=bgn; i<end-2; ++i){
            if(i+(i+1)+(i+2)==num){
                res.push_back(i);
                res.push_back(i+1);
                res.push_back(i+2);
                break;
            } 
        }
        return res;
    }
};
*/

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3!=0) return {};
        long long mid=num/3;
        return {mid-1, mid, mid+1};
    }
};

