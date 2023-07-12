// 1987. Number of Unique Good Subsequences
/*
You are given a binary string binary.
A subsequence of binary is considered good if it is not empty
and has no leading zeros (with the exception of "0").

Find the number of unique good subsequences of binary.

For example, if binary = "001", then all the good subsequences
are ["0", "0", "1"], so the unique good subsequences are "0" and "1".
Note that subsequences "00", "01", and "001" are not good because they
 have leading zeros.
Return the number of unique good subsequences of binary.
Since the answer may be very large, return it modulo 10^9 + 7.

A subsequence is a sequence that can be derived from another
sequence by deleting some or no elements without changing the order
of the remaining elements.

Example 3:

Input: binary = "101"
Output: 5
Explanation: The good subsequences of binary are ["1", "0", "1", "10", "11", "101"].
The unique good subsequences are "0", "1", "10", "11", and "101".

Constraints:

1 <= binary.length <= 105
binary consists of only '0's and '1's.
*/
/*
dp[i][j] denote the number of distinct subsequences
starting with 'i' and end with 'j'

Here's the dp transition:
Case '0':
If the current character is '0', since we are counting distinct subsequences
and there shouldn't be any leading zeros in the subsequences,
we set dp[0][0] = 1, ex: string "000000" only have a subsequence '0'
dp[1][0] = dp[1][0] + dp[1][1] because it will be the number of ways
that we add a '0' to a subsequence starting with '1' and ends with
either '0' or '1'

Case '1':
If the current character is '1', since we can't have leading zeros,
dp[0][1] is always 0 ("0001" is not a valid subsequence)
The transition will be dp[1][1] = dp[1][0] + dp[1][1] + 1.
As we can see, dp[1][0] + dp[1][1] part is same as the case ending with zero.
Since we append a '1' to every subsequence dp[1][0] and dp[1][1],
we are missing the subsequence "1" with length 1; therefore, we add a one to it.

Note that all calculation above should be done with modulo.

Time Complexity: O(n)
Space Complexity: O(1)
*/

/*
TLE: 25 / 69

class Solution
{
    public:
    set<string> res;
    int mod=1e9+7;
    
    void allSubSeqRec(string str, int n, int index, string curr)
    {
        if (index == n || (curr.length()>1&&curr[0]=='0')) return;
        if (!curr.empty())
        {
            res.insert(curr);
        }
        for (int i = index + 1; i < n; i++)
        {
            curr += str[i];
            if (curr.length()==1){
                allSubSeqRec(str, n, i, curr);
            }
            if (curr.length()>1&&curr[0]!='0')
                allSubSeqRec(str, n, i, curr);

            curr = curr.erase(curr.size() - 1);
        }
        return;
    }

    void allSubSeq(string str)
    {
        allSubSeqRec(str, str.size(), -1, "");
    }

    int numberOfUniqueGoodSubsequences(string binary) {
        allSubSeq(binary);
        int ans=0;
        for (auto &entry: res){
            if (entry.length()==1){
                ans++;
            } else {
                if (entry[0]!='0'){
                    ans++;
                }
            }
        }
        return ans%mod;
    }
};
*/

typedef int64_t ll;

class Solution
{
public:
    int numberOfUniqueGoodSubsequences(string s)
    {
        const int mod = 1e9 + 7;
        ll dp[2][2] = {};
        for (char c : s)
        {
            int a = c - '0';
            if (a == 0)
            {
                dp[0][0] = 1;
                dp[1][0] = (dp[1][0] + dp[1][1]) % mod;
            }
            else
            {
                dp[1][1] = (dp[1][0] + dp[1][1] + 1) % mod;
            }
        }
        return (dp[0][0] + dp[0][1] + dp[1][0] + dp[1][1]) % mod;
    }
};