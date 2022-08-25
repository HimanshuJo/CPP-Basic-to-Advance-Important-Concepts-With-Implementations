// 2310. Sum of Numbers With Units Digit K
/*
Given two integers num and k, consider a set of positive integers with the following properties:

The units digit of each integer is k.
The sum of the integers is num.
Return the minimum possible size of such a set, or -1 if no such set exists.

Note:

The set can contain multiple instances of the same integer, and the sum of an empty set is considered 0.
The units digit of a number is the rightmost digit of the number.

Example 1:

Input: num = 58, k = 9
Output: 2
Explanation:
One valid set is [9,49], as the sum is 58 and each integer has a units digit of 9.
Another valid set is [19,39].
It can be shown that 2 is the minimum possible size of a valid set.
Example 2:

Input: num = 37, k = 2
Output: -1
Explanation: It is not possible to obtain a sum of 37 using only integers that have a units digit of 2.
Example 3:

Input: num = 0, k = 7
Output: 0
Explanation: The sum of an empty set is considered 0.
 

Constraints:

0 <= num <= 3000
0 <= k <= 9
*/

class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0) return 0;
        vector<int>res;
        for(int i=num; i>0; --i){
            string temp=to_string(i);
            int tochk=temp[temp.length()-1]-'0';
            if(tochk==k){
                res.push_back(i);
            }
        }
        int sz=INT_MAX;
        for(auto &entries: res){
            int sm=entries, cursz=1;
            if(sm!=num){
                int remain=num-sm;
                if(k!=0){
                    if(remain%k==0){
                        cursz+=remain/k;
                        sz=min(sz, cursz);
                    }   
                }
            } else {
                sz=min(sz, cursz);
            }
        }
        if(sz==INT_MAX){
            if(k!=0){
                if(num%k==0) return num/k;   
            }
            return -1;
        }
        return sz;
    }
};