// 2281. Sum of Total Strength of Wizards
/*
As the ruler of a kingdom, you have an army of wizards at your command.

You are given a 0-indexed integer array strength, where strength[i] denotes 
the strength of the ith wizard. 

For a contiguous group of wizards (i.e. the wizards' strengths form a subarray of strength), 
the total strength is defined as the product of the following two values:

The strength of the weakest wizard in the group.
The total of all the individual strengths of the wizards in the group.
Return the sum of the total strengths of all contiguous groups of wizards. 

Since the answer may be very large, return it modulo 10^9 + 7.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: strength = [1,3,1,2]
Output: 44
Explanation: The following are all the contiguous groups of wizards:
- [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
- [3] from [1,3,1,2] has a total strength of min([3]) * sum([3]) = 3 * 3 = 9
- [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
- [2] from [1,3,1,2] has a total strength of min([2]) * sum([2]) = 2 * 2 = 4
- [1,3] from [1,3,1,2] has a total strength of min([1,3]) * sum([1,3]) = 1 * 4 = 4
- [3,1] from [1,3,1,2] has a total strength of min([3,1]) * sum([3,1]) = 1 * 4 = 4
- [1,2] from [1,3,1,2] has a total strength of min([1,2]) * sum([1,2]) = 1 * 3 = 3
- [1,3,1] from [1,3,1,2] has a total strength of min([1,3,1]) * sum([1,3,1]) = 1 * 5 = 5
- [3,1,2] from [1,3,1,2] has a total strength of min([3,1,2]) * sum([3,1,2]) = 1 * 6 = 6
- [1,3,1,2] from [1,3,1,2] has a total strength of min([1,3,1,2]) * sum([1,3,1,2]) = 1 * 7 = 7
The sum of all the total strengths is 1 + 9 + 1 + 4 + 4 + 4 + 3 + 5 + 6 + 7 = 44.

Example 2:

Input: strength = [5,4,6]
Output: 213
Explanation: The following are all the contiguous groups of wizards: 
- [5] from [5,4,6] has a total strength of min([5]) * sum([5]) = 5 * 5 = 25
- [4] from [5,4,6] has a total strength of min([4]) * sum([4]) = 4 * 4 = 16
- [6] from [5,4,6] has a total strength of min([6]) * sum([6]) = 6 * 6 = 36
- [5,4] from [5,4,6] has a total strength of min([5,4]) * sum([5,4]) = 4 * 9 = 36
- [4,6] from [5,4,6] has a total strength of min([4,6]) * sum([4,6]) = 4 * 10 = 40
- [5,4,6] from [5,4,6] has a total strength of min([5,4,6]) * sum([5,4,6]) = 4 * 15 = 60
The sum of all the total strengths is 25 + 16 + 36 + 36 + 40 + 60 = 213.
 

Constraints:

1 <= strength.length <= 10^5
1 <= strength[i] <= 10^9
*/

/*
TLE: 68 / 82

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        long long ans=0;
        long long mod=1e9+7;
        int sz=strength.size();
        for(int i=0; i<sz; ++i){
            ans+=(strength[i]%mod*strength[i]%mod)%mod;
            ans%=mod;
        }
        for(int i=0; i<sz; ++i){
            long long cursm=strength[i];
            long long curmin=strength[i];
            for(int j=i+1; j<sz; ++j){
                cursm+=strength[j];
                curmin=min(curmin, (long long)strength[j]);
                ans+=(cursm%mod*curmin%mod)%mod;
                ans%=mod;
            }
        }
        return ans%mod;
    }
};
*/

/*
    For each strength[i], we could find a non-empty index range (left, right) where strength[i]
    is the min value

    So for all the subarrays in this range including strength[i], the total strength is

        strength[i]*sum of those subarray sums

        left => is the first index on the left side i, where strength[left]<strength[i]

        right => is the first index on the right side i, where strength[right]<=strength[i]
        (<= to remove duplicates)

    -------

    Finding the sum of all subarrays in the range(left, right)

    range: ... left-1, left, left+1, left+2, ... , i-1, i, i+1, .... , right-1, right, right+1, ....

    let prefix[i] be the prefix sum of first i elements in strength:

        the sum of subarrays including i are:

            the subarrays that start with left+1:

                sum(left+1, ..., i)=prefix[i+1]-prefix[left+1]
                sum(left+1, ..., i+1)=prefix[i+2]-prefix[left+1]
                ...
                sum(left+1, ..., right-1)=prefix[right]-prefix[left]+1

            the subarrays that start with left+2:

                sum(left+2, ..., i)=prefix[i+1]-prefix[left+2]
                sum(left+2, ..., i+1)=prefix[i+2]-prefix[left+2]
                ...
                sum(left+2, ..., right-1)=prefix[right]-prefix[left+2]

            the subarrays that start with i

                sum(i, ..., i)=prefix[i+1]-prefix[i]
                sum(i, ..., i+1)=prefix[i+2]-prefix[i]
                ...
                sum(i, ..., right-1)=prefix[right]-prefix[i]

        -------

        positive parts:

            prefix[i+1]+prefix[i+2]+....+prefix[right]*(i-left)

        negative parts:

            prefix[left+1]+prefix[left+2]+...+prefix[i]*(right-i)
*/

// TC: O(N)  N: size of vector
// SC: O(N)

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        long long MOD=1e9+7;
        int sz=strength.size();
        vector<long long>prefix(sz+1, 0LL);
        for(int i=0; i<sz; ++i){
            prefix[i+1]=(prefix[i]+strength[i])%MOD;
        }
        vector<long long>smPrefixSm(sz+2, 0LL);
        for(int i=0; i<=sz; ++i){
            smPrefixSm[i+1]=(smPrefixSm[i]+prefix[i])%MOD;
        }
        vector<int>left(sz, -1);
        stack<int>stk;
        for(int i=0; i<sz; ++i){
            while(!stk.empty()&&strength[stk.top()]>=strength[i]){
                stk.pop();
            }
            left[i]=stk.empty()?-1:stk.top();
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        vector<int>right(sz, sz);
        for(int i=sz-1; i>=0; --i){
            while(!stk.empty()&&strength[stk.top()]>strength[i]){
                stk.pop();
            }
            right[i]=stk.empty()?sz:stk.top();
            stk.push(i);
        }
        long long res=0;
        for(int i=0; i<sz; ++i){
            res+=((smPrefixSm[right[i]+1]-smPrefixSm[i+1])*(i-left[i])%MOD+
                  MOD*2-(smPrefixSm[i+1]-smPrefixSm[left[i]+1])*(right[i]-i)%MOD)%MOD*strength[i]%MOD;
            res%=MOD;
        }
        return (int)res;
    }
};