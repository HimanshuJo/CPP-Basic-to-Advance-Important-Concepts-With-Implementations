// Find Unique Binary String
/*
Given an array of strings nums containing n unique binary strings each of length n, 
return a binary string of length n that does not appear in nums. 
If there are multiple answers, you may return any of them.

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.

Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
*/
/*
The trick to do this question is somewhat similar to Cantor's Diagonalization

Since we are given that number of bits in the number is equal to number of elements.
What we can do is we create a binary string which differs from first binary at 1st position, 
second binary at 2nd position, third binary at 3rd position,...and so on.

This will make sure that the binary we have made is unique (as it differs from all others at atleast one position).

We create an empty string first.
And simply iterate through the binary strings while putting the flipped bit of ith bit of "binary at ith position".

	for(int i=0; i<nums.size(); i++) 
		ans+= nums[i][i]=='0' ? '1' : '0';

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans="";
        for(int i=0; i<nums.size(); i++) 
            ans+= nums[i][i]=='0' ? '1' : '0';          // Using ternary operator
			// ans+=to_string(1-(nums[i][i]-'0'));     // Alternate:  or use to_string & 1-x to flip
        return ans;
    }
};
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<long long>actNums;
        for (string str: nums){
            unsigned long tmp = std::bitset<64>(str).to_ulong();
            actNums.push_back(tmp);
        }
        sort(actNums.begin(), actNums.end());
        long long res=-1;
        long long fnNum=actNums[actNums.size()-1];
        for (long long i=0; i<=actNums[actNums.size()-1]; ++i){
            if (i!=actNums[i]){
                res=i;
                break;
            }
        }
        if (res==-1){
            res=fnNum+1;
        }
        string tmp=bitset<64>(res).to_string();
        if (tmp.length()!=nums[0].length()){
            string finalTmp="";
            for (int i=64-nums[0].length(); i<64; ++i){
                finalTmp+=tmp[i];
            }
            return finalTmp;
        }
        return tmp;
    }
};

int main(){
    Solution obj;
    vector<string>nums={"01","10"};
    obj.findDifferentBinaryString(nums);
}