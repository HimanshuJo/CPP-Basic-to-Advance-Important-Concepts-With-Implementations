// 2281. Sum of Total Strength of Wizards
/*
As the ruler of a kingdom, you have an army of wizards at your command.

You are given a 0-indexed integer array strength, where strength[i] 
denotes the strength of the ith wizard. For a contiguous group of wizards 
(i.e. the wizards' strengths form a subarray of strength), 
the total strength is defined as the product of the following two values:

The strength of the weakest wizard in the group.
The total of all the individual strengths of the wizards in the group.
Return the sum of the total strengths of all contiguous groups of wizards. 
Since the answer may be very large, return it modulo 109 + 7.

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
Solution:

For each strength[i], we could find a non-empty index range (left, right) 
where strength[i] is the min value. 

So for all subarrays in this range including strength[i], 
the total strength is strength[i] * the sum of those subarray sums.

left is the first index on the left side i where strength[left] < strength[i]

right is the first index on the right side of i where strength[right] <= strength[i]

These two indices can be pre-calculated using monotonic stack

The reason we use < on left but <= on right is to avoid duplicates.
Here is an example array: 1 '2 3 4 2' 3 4 2 1
For the highlighted subarray 2 3 4 2, we want to calculate the strength using the 2nd 2 but not the first 2.

How do we get the "sum of all subarrays including strength[i] in range (left, right)"?

Let's list the indices:
...left-1, left, left + 1, left + 2, ... i-1, i, i+1, ... right-1, right, right+1...

Let prefix[i] be the prefix sum of first i elements in strength.

The sum of subarrays including i are:

the subarrays that start with left+1:
sum(left+1, ... i) = prefix[i + 1] - prefix[left + 1]
sum(left+1, ... i+1) = prefix[i + 2] - prefix[left + 1]
...
sum(left+1, ... right-1) = prefix[right] - prefix[left + 1]

the subarrays that start with left+2:
sum(left+2, ... i) = prefix[i + 1] - prefix[left + 2]
sum(left+2, ... i+1) = prefix[i + 2] - prefix[left + 2]
...
sum(left+2, ... right-1) = prefix[right] - prefix[left + 2]
...

the subarrays that start with i:
sum(i, ... i) = prefix[i + 1] - prefix[i]
sum(i, ... i+1) = prefix[i + 2] - prefix[i]
...
sum(i, ... right-1) = prefix[right] - prefix[i]

Then we combine all above terms, we have:

positive parts:
(prefix[i + 1] + prefix[i + 2] + ... + prefix[right]) * (i - left)

negative parts:
(prefix[left + 1] + prefix[left + 2] + ... + prefix[i]) * (right - i)

The range sum of prefix can be optimized by pre-compute prefix-sum of prefix.

Time complexity: O(N): we have 5 passes of the input array length
Space complexity: O(N): two prefix arrays and a stack (vector) is used
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

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int res=0, runningSm=0, mod=1e9+7, n=strength.size();
        stack<int>stk;
        vector<int>acc(n+2, 0);
        for(int i=0; i<=n; ++i){
            int currNm=i<n?strength[i]:0;
            runningSm=(runningSm+currNm)%mod;
            acc[i+1]=(runningSm+acc[i])%mod;
            while(!stk.empty()&&strength[stk.top()]>currNm){
                int currIdx=stk.top();
                stk.pop();
                int l=stk.empty()?-1:stk.top();
                long long lacc=l<0?acc[currIdx]:acc[currIdx]-acc[l];
                long long racc=acc[i]-acc[currIdx];
                int ln=currIdx-l, rn=i-currIdx;
                res=(res+(racc*ln-lacc*rn)%mod*strength[currIdx]%mod)%mod;
            }
            stk.push(i);
        }
        return (res+mod)%mod;
    }
};

// -------*******-------

class Solution2 {
public:
    int totalStrength(vector<int>& strength) {
        int res=0, runningSm=0, mod=1e9+7, n=strength.size();
        vector<int>stack{}, acc(n+2, 0);
        for(int i=0; i<=n; ++i){
            int currNm=i<n?strength[i]:0;
            runningSm=(runningSm+currNm)%mod;
            acc[i+1]=(runningSm+acc[i])%mod;
            while(!stack.empty()&&strength[stack.back()]>currNm){
                int currIdx=stack.back();
                stack.pop_back();
                int l=stack.empty()?-1:stack.back();
                long long lacc=l<0?acc[currIdx]:acc[currIdx]-acc[l];
                long long racc=acc[i]-acc[currIdx];
                int ln=currIdx-l, rn=i-currIdx;
                res=(res+(racc*ln-lacc*rn)%mod*strength[currIdx]%mod)%mod;
            }
            stack.push_back(i);
        }
        return (res+mod)%mod;
    }
};

// -------*******-------

class Solution3 {
public:
    int totalStrength(vector<int>& strength) {
        int mod=1e9+7;
        const int N=strength.size();
        vector<long long>prefixSum(N+1, 0L);
        for(int i=0; i<N; ++i){
            prefixSum[i+1]=(prefixSum[i]+strength[i])%mod;
        }
        // sum of first k prefixes
        vector<long long>smPrefixSms(N+2, 0);
        for(int i=0; i<=N; ++i){
            smPrefixSms[i+1]=(smPrefixSms[i]+prefixSum[i])%mod;
        }
        vector<int>left(N, -1), right(N, N);
        stack<int>stk;
        for(int i=0; i<N; ++i){
            while(!stk.empty()&&strength[stk.top()]>strength[i]){
                stk.pop();
            }
            left[i]=stk.empty()?-1:stk.top();
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        for(int i=N-1; i>=0; --i){
            while(!stk.empty()&&strength[stk.top()]>=strength[i]){
                stk.pop();
            }
            right[i]=stk.empty()?N:stk.top();
            stk.push(i);
        }
        long long res=0;
        for(auto &vals: left)
            cout<<vals<<" ";
        cout<<"\n-------\n";
        for(auto &vals: right)
            cout<<vals<<" ";
        for(int i=0; i<N; ++i) {
            res+=((smPrefixSms[right[i]+1]-smPrefixSms[i+1])*(i-left[i])%mod-
                 (smPrefixSms[i+1]-smPrefixSms[left[i]+1])*(right[i]-i)%mod)%mod*strength[i]%mod;
            res=(res+mod)%mod;
        }
        return (int) res;
    }
};